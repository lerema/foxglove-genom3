"""Example script for foxglove-genom3 in Python."""
import genomix

handle = genomix.connect("localhost:8080")

PLUGINS_PATH = "/plugins"  # path to plugins directory
handle.rpath(PLUGINS_PATH)
foxglove = handle.load("FoxgloveStudio")

# Add required ports to be able to connect to the plugin
foxglove.connect_port("frames/d435/raw", "d435/frame/raw")
foxglove.add_port("d435/rgb", "::FoxgloveStudio::on_sensor_frame")


foxglove.start_foxglove_server()
