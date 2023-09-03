# Installation instructions

To setup the component, it is adviced to run `<rootdir>/bootstrap.sh` to install the required dependencies and setup the environment.

```bash
cd <rootdir>
./bootstrap.sh
mkdir build && cd build
../configure --prefix=<install-dir> --with-templates=<template-dir>
make install
```

You may need to install [flatbuffers](https://github.com/google/flatbuffers) manually.

The `bootstrap.sh` script will install the following dependencies:

 - Foxglove Studio
 - libwebsocketpp-dev
 - nlohmann-json3-dev