#!/usr/bin/env bash

FILE=./src/int_ptr_cell.cpp
if test -f "$FILE"; then
    echo "$FILE exists. Add implementation file requirement met!"
else
    echo "$FILE does not exist. You failed to add implementation file to revision control..."
    exit 1
fi
