#!/bin/bash

# Step 1: Clean and prepare build folder
rm -rf build
mkdir build
cd build

# Step 2: Generate build system with CMake
cmake ..

# Step 3: Build the executable
cmake --build .

# Step 4: Go back to project root
cd ..

# Step 5: Run and write output to results.txt
./build/PlagiarismChecker > results.txt

# Optional: Show a success message
echo "✅ Output written to results.txt"
