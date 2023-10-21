#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include "HafmanTree.h"

int main() {
	std::string input_file = "input_text";
	std::string encoded_file_name = "encoding";
	HafmanTree ht;
	ht.build(input_file);
	std::cout << ht.encode(input_file, encoded_file_name);
	ht.decode(encoded_file_name, "decoding");

	return 0;
}