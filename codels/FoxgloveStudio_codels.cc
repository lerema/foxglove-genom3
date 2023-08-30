
#include "acFoxgloveStudio.h"

#include "FoxgloveStudio_c_types.h"
#include <cstdio>

/* --- Function start_foxglove_server ----------------------------------- */

/** Validation codel check_info of function start_foxglove_server.
 *
 * Returns genom_ok.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 * FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
check_info(const FoxgloveStudio_ids *ids, const genom_context self)
{
  // Check if ids->server and port is valid
  if (ids->server_ip == NULL)
  {
    FoxgloveStudio_e_BAD_CONFIG_detail *msg;
    snprintf(msg->message, sizeof(msg->message), "%s", "Server IP is NULL");
    return FoxgloveStudio_e_BAD_CONFIG(msg, self);
  }

  if (ids->server_port == NULL)
  {
    FoxgloveStudio_e_BAD_CONFIG_detail *msg;
    snprintf(msg->message, sizeof(msg->message), "%s", "Server port is NULL");
    return FoxgloveStudio_e_BAD_CONFIG(msg, self);
  }

  return genom_ok;
}

/* --- Function start_foxglove_server ----------------------------------- */

/** Codel start_server of function start_foxglove_server.
 *
 * Returns genom_ok.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
start_server(bool start_foxglove_server, const genom_context self)
{
  start_foxglove_server = true;
  return genom_ok;
}

/* --- Function stop_foxglove_server ------------------------------------ */

/** Codel stop_server of function stop_foxglove_server.
 *
 * Returns genom_ok.
 * Throws FoxgloveStudio_e_BAD_CONFIG, FoxgloveStudio_e_BAD_PORT,
 *        FoxgloveStudio_e_OPENCV_ERROR, FoxgloveStudio_e_OUT_OF_MEM.
 */
genom_event
stop_server(bool start_foxglove_server, const genom_context self)
{
  start_foxglove_server = false;
  return genom_ok;
}
