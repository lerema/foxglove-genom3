
#include "acFoxgloveStudio.h"

#include "FoxgloveStudio_c_types.h"


/* --- Task publish ----------------------------------------------------- */


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
  /* skeleton sample: insert your code */
  /* skeleton sample */ return FoxgloveStudio_publish;
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
  /* skeleton sample: insert your code */
  /* skeleton sample */ return FoxgloveStudio_publish;
}
