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

	std::vector<std::uint32_t> pregeneratedSequence;
	const std::size_t NUMBER_QUANTITY = 1000030;

	std::ofstream outputFile("num_sequence");

	for (std::size_t i = 0; i < NUMBER_QUANTITY; ++i) {
		pregeneratedSequence.push_back(dis(gen));
		if (pregeneratedSequence.size() == 1000) {
			for (std::vector<std::uint32_t>::const_iterator it = pregeneratedSequence.begin(); it != pregeneratedSequence.end(); ++it) {
				outputFile << *it << std::endl;
			}
			pregeneratedSequence.clear();
		}
	}

	if (!pregeneratedSequence.empty()) {
		for (std::vector<std::uint32_t>::const_iterator it = pregeneratedSequence.begin(); it != pregeneratedSequence.end(); ++it) {
			outputFile << *it << std::endl;
		}
		pregeneratedSequence.clear();
	}

	outputFile.close();

	return 0;
}
