#!/bin/bash
 
echo Hello World

./../src/protoc -I=./ --cpp_out=./  ./addressbook.proto
g++  -std=c++11  main.cpp    addressbook.pb.cc  addressbook.pb.h  -I../src  -L../src/.libs  -lprotobuf -pthread
LD_LIBRARY_PATH=../src/.libs:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
./a.out text
