#!/bin/bash

# Step 1: Create a result directory
mkdir -p res

# Step 2: Find and copy .cpp files and folders, excluding the current directory and 'res' directory
find . \( -name "*.cpp" -o -type d \) -path "./res" -prune -o -exec cp -r --parents \{} res/ \;
