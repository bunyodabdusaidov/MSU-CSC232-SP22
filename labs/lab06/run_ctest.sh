#!/usr/bin/env bash

if test -d build; then
    echo "Deleting existing build directory..."
    rm -rf build
fi

echo "Running cmake..."
cmake -S . -B build -G "Unix Makefiles"

echo ""
echo "Building google-tests target..."
echo ""
cmake --build build --target google-tests

echo ""
echo "Navigating to build directory..."
echo ""
cd ./build

echo ""
echo "Running ctest..."
echo ""
ctest
