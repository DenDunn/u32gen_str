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
	std::vector<std::uint32_t> pregenSeq;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::uint32_t> dis(0, 0xffffffff);

	//quantity of the numbers
	const std::uint32_t num_quant = 1000000;

	//output file
	std::ofstream outfile("num_sequence");

	for (std::uint32_t i = 0; i < num_quant; ++i) {
		pregenSeq.push_back(dis(gen));
	}

	for (std::vector<std::uint32_t>::const_iterator it = pregenSeq.begin(); it != pregenSeq.end(); ++it) {
		outfile << (*it) << std::endl;
	}
	
	//close the file
	outfile.close();

    return 0;
}
