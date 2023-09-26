# !/bin/bash

# Clear previous terminal output
clear

# Create a binaries placeholder
mkdir target

# Build and run the "foreach" code
gcc ./src/foreach.c -o ./target/foreach.exe
./target/foreach

# Build and run the "string" code
gcc ./src/string.c -o ./target/string.exe
./target/string

# Remove binaries
# rm ./target/foreach
# rm ./target/string