
#include "FoxgloveStudio_c_types.h"
#include "acFoxgloveStudio.h"
#include "convertor.h"
#include "foxglove_server.h"

std::unique_ptr<foxglove::FoxgloveWebsocketServer> server =
    std::make_unique<foxglove::FoxgloveWebsocketServer>();
std::unique_ptr<Convertor> convertor =
    std::make_unique<Convertor>(server->getBuilder());

/* --- Task main -------------------------------------------------------- */

/** Codel setup_server_configuration of task main.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_ether.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event setup_server_configuration(const char *server_ip,
                                       uint16_t server_port,
                                       const genom_context self) {
  server->startServer("0.0.0.0", 8765);
  return FoxgloveStudio_ether;
}

/* --- Activity add_port ------------------------------------------------ */

/** Codel setup_port_info of activity add_port.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_ready, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event setup_port_info(const char port_name[128],
                            FoxgloveStudio_PortType port_type,
                            sequence_FoxgloveStudio_Port *ports,
                            const genom_context self) {
  if (genom_sequence_reserve(ports, ports->_length + 1)) {
    FoxgloveStudio_e_OUT_OF_MEM_detail *msg;
    snprintf(msg->message, sizeof(msg->message), "%s",
             "Failed to reserve memory for ports");
    return FoxgloveStudio_e_OUT_OF_MEM(msg, self);
  }

  // Add the port to the list if it doesn't already exist
  for (int i = 0; i < ports->_length; i++) {
    if (strcmp(ports->_buffer[i].name, port_name) == 0) {
      std::cerr << "Port name already exists" << std::endl;
      return FoxgloveStudio_ether;
    }
  }

  FoxgloveStudio_Port port;
  port.type = port_type;
  strncpy(port.name, port_name, 128);

  ports->_buffer[ports->_length] = port;
  ports->_length++;

  switch (port.type) {
    case FoxgloveStudio_or_sensor_frame:
      server->addChannel(port.name, "foxglove.CompressedImage");
      break;
    case FoxgloveStudio_or_sensor_imu:
      server->addChannel(port.name, "foxglove.Imu");
      break;
    case FoxgloveStudio_or_sensor_magnetometer:
      server->addChannel(port.name, "foxglove.TimedVector3");
      break;
    case FoxgloveStudio_or_pose_estimator_state:
      server->addChannel(port.name, "foxglove.PoseInFrame");
      break;
    case FoxgloveStudio_or_sensor_gps:
      server->addChannel(port.name, "foxglove.LocationFix");
      break;
    default:
      break;
  }

  return FoxgloveStudio_ready;
}

/** Codel wait_for_publishing of activity add_port.
 *
 * Triggered by FoxgloveStudio_ready.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_ready,
 *           FoxgloveStudio_ether.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event wait_for_publishing(bool start_foxglove_server,
                                const genom_context self) {
  if (start_foxglove_server) {
    server->addChannels();
    return FoxgloveStudio_publish;

  } else
    return FoxgloveStudio_ready;
}

/** Codel publish_data of activity add_port.
 *
 * Triggered by FoxgloveStudio_publish.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event publish_data(bool start_foxglove_server,
                         const sequence_FoxgloveStudio_Port *ports,
                         const FoxgloveStudio_frames *frames,
                         const FoxgloveStudio_measure *measure,
                         const FoxgloveStudio_states *states,
                         const FoxgloveStudio_gps *gps,
                         const genom_context self) {
  if (!start_foxglove_server) return FoxgloveStudio_ready;

  for (uint8_t i = 0; i < ports->_length; i++) {
    // Read image frame
    FoxgloveStudio_Port port = ports->_buffer[i];
    if (port.type == FoxgloveStudio_or_sensor_frame) {
      or_sensor_frame *image_frame;
      if (frames->read(port.name, self) == genom_ok &&
          frames->data(port.name, self)) {
        image_frame = frames->data(port.name, self);

        // Check if there is data in image frame
        if (!image_frame->pixels._length) {
          std::cerr << "No data in frame " << port.name << std::endl;
          return FoxgloveStudio_publish;
        }
        // Create flatbuffer raw image
        auto timestamp =
            foxglove::Time(image_frame->ts.sec, image_frame->ts.nsec);
        flatbuffers::Offset<foxglove::CompressedImage> *image =
            convertor->convert(image_frame);

        server->sendData(
            port.name, *image,
            image_frame->ts.sec * 1000000000 + image_frame->ts.nsec);

        // Release frame
        delete image, image_frame;

        server->getBuilder().Clear();
      } else {
        std::cerr << "Failed to read frame " << port.name << std::endl;
      }
    } else if (port.type == FoxgloveStudio_or_sensor_imu) {
      if (measure->read(port.name, self) == genom_ok &&
          measure->data(port.name, self)) {
        or_pose_estimator_state *imu_frame = measure->data(port.name, self);
        flatbuffers::Offset<foxglove::Imu> *imu = convertor->convert(imu_frame);

        server->sendData(port.name, *imu,
                         imu_frame->ts.sec * 1000000000 + imu_frame->ts.nsec);

        // Release frame
        delete imu, imu_frame;

        server->getBuilder().Clear();
      } else
        std::cerr << "Failed to read measurement " << port.name << std::endl;
    } else if (port.type == FoxgloveStudio_or_sensor_magnetometer) {
      if (measure->read(port.name, self) == genom_ok &&
          measure->data(port.name, self)) {
        or_pose_estimator_state *mag_frame = measure->data(port.name, self);

        flatbuffers::Offset<foxglove::TimedVector3> *mag =
            convertor->convertToVec(mag_frame);

        server->sendData(port.name, *mag,
                         mag_frame->ts.sec * 1000000000 + mag_frame->ts.nsec);
        return FoxgloveStudio_publish;
      } else
        std::cerr << "Failed to read measurement " << port.name << std::endl;
    } else if (port.type == FoxgloveStudio_or_pose_estimator_state) {
      if (states->read(port.name, self) == genom_ok &&
          states->data(port.name, self)) {
        or_pose_estimator_state *state_frame = states->data(port.name, self);
        flatbuffers::Offset<foxglove::PoseInFrame> *state =
            convertor->convertToPose(state_frame);

        server->sendData(
            port.name, *state,
            state_frame->ts.sec * 1000000000 + state_frame->ts.nsec);

        // Release frame
        delete state, state_frame;

        server->getBuilder().Clear();
      } else
        std::cerr << "Failed to read state " << port.name << std::endl;
    } else if (port.type == FoxgloveStudio_or_sensor_gps) {
      if (gps->read(port.name, self) == genom_ok &&
          gps->data(port.name, self)) {
        FoxgloveStudio_solution_s *gps_frame = gps->data(port.name, self);
        flatbuffers::Offset<foxglove::LocationFix> *gps =
            convertor->convert(gps_frame);

        server->sendData(port.name, *gps,
                         gps_frame->ts.sec * 1000000000 + gps_frame->ts.nsec);

        // Release frame
        delete gps, gps_frame;

        server->getBuilder().Clear();
      } else
        std::cerr << "Failed to read gps " << port.name << std::endl;
    }
  }

  return FoxgloveStudio_publish;
}

/* --- Activity remove_port --------------------------------------------- */

/** Codel remove_port_info of activity remove_port.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_ether.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event remove_port_info(const char port_name[128],
                             sequence_FoxgloveStudio_Port *ports,
                             const genom_context self) {
  for (int i = 0; i < ports->_length; i++) {
    if (strcmp(ports->_buffer[i].name, port_name) == 0) {
      ports->_buffer[i] = ports->_buffer[ports->_length - 1];
      ports->_length--;
      return FoxgloveStudio_ether;
    }
  }
}
