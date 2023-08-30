#!/bin/sh
sudo apt install -y libwebsocketpp-dev nlohmann-json3-dev flatbuffers-compiler libflatbuffers-dev

flatc --schema -b -o flatbuffers/schema flatbuffers/definitions/*.fbs
autoreconf -vi

# Compile flatbuffers
flatc --cpp -o codels/foxglove/generated flatbuffers/definitions/*.fbs
