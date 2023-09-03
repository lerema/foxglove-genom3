# Example script for foxglove-genom3 in TCL. This code is not verified yet
package require genomix

set handle [genomix connect "localhost:8080"]

set PLUGINS_PATH "/plugins" ;# path to plugins directory
$handle rpath $PLUGINS_PATH
set foxglove [$handle load "FoxgloveStudio"]

# Add required ports to be able to connect to the plugin
$foxglove connect_port "frames/d435/raw" "d435/frame/raw"
$foxglove add_port "d435/rgb" "::FoxgloveStudio::on_sensor_frame"

$foxglove start_foxglove_server