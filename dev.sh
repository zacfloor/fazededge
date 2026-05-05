#!/bin/bash
set -e
echo "Warning: This script uses the non-production build.sh script. It also runs the generated program automatically!"
./build.sh
build/fazededge $*