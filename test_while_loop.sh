#!/bin/bash

echo "=== Compiling WhileLoop_Interactive.cpp ==="
g++ -std=c++17 -I./src/core -o src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive.cpp src/core/Character.cpp

echo "=== Compilation completed ==="

echo "=== Running WhileLoop_Interactive with test input ==="
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gemini

echo "TestUser" | ./01.WhileLoop_Interactive

echo "=== Program execution completed ==="
echo "=== Checking output files ==="
ls -la *.txt
cat user_learning_data.txt 