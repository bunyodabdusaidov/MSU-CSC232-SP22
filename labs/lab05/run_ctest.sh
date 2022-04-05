#!/usr/bin/env bash

if test -d build; then
    echo "Deleting existing build directory..."
    rm -rf build
fi

echo "Running cmake..."
cmake -S . -B ./build -G "Unix Makefiles"

echo ""
echo "Navigating to build directory..."
echo ""
cd ./build

echo ""
echo "Building tests target..."
echo ""
make lab04-tests

echo ""
echo "Running lab04-tests..."
echo ""
./labhwn

#This works in Windows... does it work on GitHub?
#cmake -S . -B build -G "Ninja"
#cmake --build build
#cd build
#ctest
