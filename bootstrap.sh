#!/bin/sh

# If foxglove-studio command is not available as a command, recommend installing it and get input to install it
if [ ! -x "$(command -v foxglove-studio)" ]; then
    echo "foxglove-studio could not be found"
    echo "Install foxglove-studio? (y/n)"
    read install_foxglove
    if [ $install_foxglove = "y" ]; then
        echo "Installing foxglove-studio"
        sudo apt install -y snapd
        sudo snap install foxglove-studio
    else
        echo "foxglove-studio is required to build foxglove-genom3"
        exit
    fi
else
    echo "foxglove-studio is installed. Continuing..."
fi

# Check if flatbuffers are installed
if [ ! -x "$(command -v flatc)" ]; then
    echo "flatc could not be found. Try installing it..."
    exit 1
else
    echo "flatbuffers is installed. Continuing..."
fi

sudo apt install -y libwebsocketpp-dev nlohmann-json3-dev

flatc --schema -b -o flatbuffers/schema flatbuffers/definitions/*.fbs
autoreconf -vif

# Compile flatbuffers
flatc --cpp -o codels/foxglove/generated flatbuffers/definitions/*.fbs
