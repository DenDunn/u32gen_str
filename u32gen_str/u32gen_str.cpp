// u32gen_str.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	//random generator preset
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::uint32_t> dis(0, std::numeric_limits<uint32_t>::max());

	const std::size_t BUFFER_SIZE = 2048;
	std::vector<std::uint32_t> buffer(BUFFER_SIZE);
	std::size_t bufferCounter = 0;
	const std::size_t QUANTITY = 1000030;

	std::ofstream outputFile("num_sequence");

	for (std::size_t i = 0; i < QUANTITY; ++i) {
		buffer[bufferCounter] = dis(gen);
		++bufferCounter;
		if (bufferCounter == BUFFER_SIZE) {
			for (std::size_t j = 0; j < BUFFER_SIZE; ++j) {
				outputFile << buffer[j] << std::endl;
			}
			bufferCounter = 0;
		}
	}

	if (bufferCounter != 0) {
		for (std::size_t i = 0; i < bufferCounter; ++i) {
			outputFile << buffer[i] << std::endl;
		}
	}

	buffer.clear();
	outputFile.close();

	return 0;
}
