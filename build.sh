#!/bin/bash

# Lint
if command -v clang-format &> /dev/null
then
	clang-format -i main.c
fi

# Cleanup
rm -f ./main

# Linux(debug)
cc -std=c99 -DDEBUG -Wall -Wno-unknown-pragmas -Wpedantic -Wshadow -Wuninitialized -Wextra -Werror=implicit-int -Werror=incompatible-pointer-types -Werror=int-conversion -Wvla -Og -fsanitize=address -fsanitize=undefined main.c -o main

# Linux(fast)
# cc main.c -std=c89 -Os -DNDEBUG -g0 -s -Wall -Wno-unknown-pragmas -o main

# Run
./main

# Cleanup
rm -f ./main