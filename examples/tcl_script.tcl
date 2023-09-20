# Example script for foxglove-genom3 in TCL. This code is not verified yet
package require genomix

genomix::localhost

# set PLUGINS_PATH "/plugins" ;# path to plugins directory 
genomix1 rpath  /home/shasthamsa/drone-experiment/lib/genom/pocolibs/plugins
genomix1 load FoxgloveStudio

# Add required ports to be able to connect to the plugin
FoxgloveStudio::connect_port "frames/d435/raw" "d435/frame/raw"
FoxgloveStudio::add_port "d435/raw" "::FoxgloveStudio::or_sensor_frame"
FoxgloveStudio::connect_port "frames/d435/cc" "d435/frame/compressed"
FoxgloveStudio::add_port "d435/cc" "::FoxgloveStudio::or_sensor_frame"

genomix1 load d435

d435::set_compression 50
d435::connect 832112070817
# FoxgloveStudio::start_foxglove_server