
#include "acFoxgloveStudio.h"
#include "FoxgloveStudio_c_types.h"

#include "foxglove_server.h"
#include "convertor.h"

std::unique_ptr<foxglove::FoxgloveWebsocketServer> server = std::make_unique<foxglove::FoxgloveWebsocketServer>();
std::unique_ptr<Convertor> convertor = std::make_unique<Convertor>(server->getBuilder());

/* --- Task main -------------------------------------------------------- */

/** Codel wait_for_ports of task main.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_server, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
wait_for_ports(FoxgloveStudio_ids *ids,
               const FoxgloveStudio_frames *frames,
               const genom_context self)
{
  // Check if there are any input ports connected
  if (ids->ports._length == 0)
  {
    return FoxgloveStudio_pause_start;
  }

  // Print out the ports
  for (int i = 0; i < ids->ports._length; i++)
  {
    printf("Port %d: %s\n", i, ids->ports._buffer[i].name);
  }

  // Wait for frame list based on types
  for (uint8_t i = 0; i < ids->ports._length; i++)
  {
    FoxgloveStudio_Port port = ids->ports._buffer[i];
    if (port.type == FoxgloveStudio_or_sensor_frame)
    {
      if (frames->read(port.name, self) != genom_ok)
      {
        std::cerr << "Failed to read frame " << port.name << std::endl;
        return FoxgloveStudio_pause_start;
      }
    }
  }

  if (!ids->start_foxglove_server)
  {
    return FoxgloveStudio_pause_start;
  }

  return FoxgloveStudio_server;
}

/** Codel setup_server_configuration of task main.
 *
 * Triggered by FoxgloveStudio_server.
 * Yields to FoxgloveStudio_setup.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
setup_server_configuration(const FoxgloveStudio_ids *ids,
                           const genom_context self)
{
  server->startServer("0.0.0.0", 8765);
  return FoxgloveStudio_setup;
}

/** Codel setup_port_serialization of task main.
 *
 * Triggered by FoxgloveStudio_setup.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
setup_port_serialization(const FoxgloveStudio_ids *ids,
                         const FoxgloveStudio_frames *frames,
                         const genom_context self)
{
  for (uint8_t i = 0; i < ids->ports._length; i++)
  {
    FoxgloveStudio_Port port = ids->ports._buffer[i];
    if (port.type == FoxgloveStudio_or_sensor_frame)
    {
      server->addChannel(port.name, "foxglove.RawImage");
    }
  }

  server->addChannels();

  return FoxgloveStudio_publish;
}

/** Codel publish_data of task main.
 *
 * Triggered by FoxgloveStudio_publish.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
publish_data(const FoxgloveStudio_ids *ids,
             const FoxgloveStudio_frames *frames,
             const genom_context self)
{
  for (uint8_t i = 0; i < ids->ports._length; i++)
  {
    // Read image frame
    or_sensor_frame *image_frame;
    FoxgloveStudio_Port port = ids->ports._buffer[i];
    if (port.type == FoxgloveStudio_or_sensor_frame)
    {
      if (frames->read(port.name, self) == genom_ok)
      {
        image_frame = frames->data(port.name, self);
      }
      else
      {
        std::cerr << "Failed to read frame " << port.name << std::endl;
        return FoxgloveStudio_publish;
      }
      // Create flatbuffer raw image
      auto timestamp = foxglove::Time(image_frame->ts.sec, image_frame->ts.nsec);
      auto image = convertor->convert(image_frame);

      server->sendData(port.name, *image, image_frame->ts.sec * 1000000000 + image_frame->ts.nsec);

      // Release frame
      delete image, image_frame;

      server->getBuilder().Clear();
    }
  }

  return FoxgloveStudio_publish;
}

/* --- Activity add_port ------------------------------------------------ */

/** Codel setup_port_info of activity add_port.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_ether.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
setup_port_info(const char port_name[128],
                FoxgloveStudio_PortType port_type,
                sequence_FoxgloveStudio_Port *ports,
                const FoxgloveStudio_frames *frames,
                const genom_context self)
{
  if (genom_sequence_reserve(ports, ports->_length + 1))
  {
    FoxgloveStudio_e_OUT_OF_MEM_detail *msg;
    snprintf(msg->message, sizeof(msg->message), "%s", "Failed to reserve memory for ports");
    return FoxgloveStudio_e_OUT_OF_MEM(msg, self);
  }

  // Add the port to the list if it doesn't already exist
  for (int i = 0; i < ports->_length; i++)
  {
    if (strcmp(ports->_buffer[i].name, port_name) == 0)
    {
      std::cerr << "Port already exists" << std::endl;
      return FoxgloveStudio_ether;
    }
  }

  FoxgloveStudio_Port port;
  port.type = port_type;
  strncpy(port.name, port_name, 128);

  ports->_buffer[ports->_length] = port;
  ports->_length++;

  return FoxgloveStudio_ether;
}
