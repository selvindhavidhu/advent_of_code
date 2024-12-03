#!/bin/bash

# Set the directory to start from
ROOT_DIR=$(pwd)

# Set the clang-format style (optional)
STYLE="-style=Microsoft"

# Iterate over the directory recursively
find "$ROOT_DIR" -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format $STYLE -i {} \;