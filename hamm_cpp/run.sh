#!/bin/bash
# Pastikan file .apa yang diberikan sebagai argumen ada
if [ -z "$1" ]; then
    echo "Error: No file provided"
    exit 1
fi

# Compile C++ code
g++ main.cpp -o main

# Jalankan program dengan nama file sebagai argumen
./main "$1"

# Pastikan file output.cpp sudah ada sebelum mencoba mengkompilasinya
if [ ! -f output.cpp ]; then
    echo "Error: output.cpp not found"
    exit 1
fi

# Compile output.cpp menjadi executable output
g++ output.cpp -o output

# Jalankan executable output dengan argumen file
./output "$1"
