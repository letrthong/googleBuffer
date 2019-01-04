#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;


int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against 
	GOOGLE_PROTOBUF_VERIFY_VERSION; 
		// compatible with the version of the headers we compiled against.


	tutorial::Person inPersion;
	tutorial::Person outPersion;

	inPersion.set_name("ThongLT");
	inPersion.set_email("letrthong@gmail.com");

	inPersion.set_id(1);
	
	string msg; 
	

	inPersion.SerializeToString(&msg);
	inPersion.Clear();

	outPersion.ParseFromString(msg);

	cout << "Hi:" << outPersion.name()<<endl;
	cout <<"Email:"<< outPersion.email() << endl;
	

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}


/*
https://developers.google.com/protocol-buffers/docs/cpptutorial

Finally, each protocol buffer class has methods for writing and reading messages of your chosen type using the protocol buffer binary format. These include:

bool SerializeToString(string* output) const;: serializes the message and stores the bytes in the given string. Note that the bytes are binary, not text; we only use the string class as a convenient container.
bool ParseFromString(const string& data);: parses a message from the given string.
bool SerializeToOstream(ostream* output) const;: writes the message to the given C++ ostream.
bool ParseFromIstream(istream* input);: parses a message from the given C++ istream.


https://developers.google.com/protocol-buffers/docs/proto
*/