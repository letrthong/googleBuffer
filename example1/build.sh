#!/bin/bash
 
echo "Genarate code"

./../src/protoc -I=./ --cpp_out=./  ./addressbook.proto

echo "build code"
g++  -std=c++11  main_write.cpp    addressbook.pb.cc  addressbook.pb.h \
	 -I../src  -L../src/.libs  -lprotobuf -pthread -o write.out 

g++  -std=c++11  main_read.cpp    addressbook.pb.cc  addressbook.pb.h \
	 -I../src  -L../src/.libs  -lprotobuf -pthread -o read.out 

g++  -std=c++11  main_decode_encode.cpp    addressbook.pb.cc  addressbook.pb.h \
	 -I../src  -L../src/.libs  -lprotobuf -pthread -o decode_encode.out 


echo Testing
LD_LIBRARY_PATH=../src/.libs:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
echo ""
echo "--------------write data-----------------"
#./write.out text.db

echo ""
echo "--------------read data------------------"
#./read.out text.db



echo "--------------decode_encode.out------------------"
./decode_encode.out



rm -f *.out *~ 
