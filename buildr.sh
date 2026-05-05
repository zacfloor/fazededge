#!/bin/bash
set -e
echo "Warning: This script generates a production program. It will not be optimized for development!"
BUILD_DIR="build"
cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release
cmake --build "$BUILD_DIR"