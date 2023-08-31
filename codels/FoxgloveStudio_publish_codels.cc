
#include "acFoxgloveStudio.h"

#include "FoxgloveStudio_c_types.h"

#include "flatbuffers/flatbuffers.h"
#include "foxglove_server.h"

/* --- Task publish ----------------------------------------------------- */

std::unique_ptr<foxglove::FoxgloveWebsocketServer> server = std::make_unique<foxglove::FoxgloveWebsocketServer>();

/** Codel wait_for_ports of task publish.
 *
 * Triggered by FoxgloveStudio_start.
 * Yields to FoxgloveStudio_setup, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
wait_for_ports(FoxgloveStudio_ids *ids, const FoxgloveStudio_ids *port,
               const genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return FoxgloveStudio_setup;
}

/** Codel setup_port_serialization of task publish.
 *
 * Triggered by FoxgloveStudio_setup.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
setup_port_serialization(const FoxgloveStudio_ids *ids,
                         const FoxgloveStudio_ids *port,
                         const genom_context self)
{
  // if (ids->start_foxglove_server)
  // {
  //   std::cout << "Starting foxglove server" << std::endl;
  //   server->startServer("0.0.0.0", 8765);
  //   server->addChannel("example_msg", "foxglove.SceneUpdate");
  //   auto result = server->addChannels();
  //   if (!result)
  //   {
  //     std::cerr << "Failed to add channels" << std::endl;
  //     FoxgloveStudio_e_BAD_CONFIG_detail *msg;
  //     snprintf(msg->message, sizeof(msg->message), "%s", "Failed to add channels");
  //     return FoxgloveStudio_e_BAD_CONFIG(msg, self);
  //   }
  // }
  // else
  // {
  //   std::cerr << "Not starting foxglove server" << std::endl;
  //   return FoxgloveStudio_start;
  // }
  server->startServer("0.0.0.0", 8765);
  server->addChannel("example_msg", "foxglove.SceneUpdate");
  // server->addChannel("example_image", "foxglove.RawImage");
  server->addChannel("example_pose", "foxglove.Pose");

  server->addChannels();

  return FoxgloveStudio_publish;
}

/** Codel publish_data of task publish.
 *
 * Triggered by FoxgloveStudio_publish.
 * Yields to FoxgloveStudio_publish, FoxgloveStudio_pause_start.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
publish_data(const FoxgloveStudio_ids *ids,
             const FoxgloveStudio_ids *port, const genom_context self)
{
  server->sendData("example_msg", "Hello World!");
  server->getBuilder().Clear();
  return FoxgloveStudio_publish;
}
