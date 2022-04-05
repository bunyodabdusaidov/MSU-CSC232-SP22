#!/usr/bin/env bash

HEADER_FILE=./include/task2/memory_cell.h
if test -f "$HEADER_FILE"; then
   echo "$HEADER_FILE exists. Add header file requirement met!"
else
   echo "$HEADER_FILE does not exist. You failed to add this header file to revision control..."
   exit 1
fi

SRC_FILE=./include/task2/memory_cell.cpp
if test -f "$SRC_FILE"; then
   echo "$SRC_FILE exists. Add source file requirement met!"
else
   echo "$SRC_FILE does not exist. You failed to add this source file to revision control..."
   exit 1
fi