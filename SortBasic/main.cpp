#include <iostream>
#include <vector>
#include "Tools.h"
#include "Sort.h"

int main() {
	//1.Generate random array
	std::vector<int>  rand_array;
	Tools::getRandArray(rand_array,100);
	std::cout << "Original array: \n";
	for (int i = 0; i < rand_array.size(); i++) {
		std::cout << rand_array[i] << " \n"[i == rand_array.size()-1];
	}

	//2.Sorting
	//Non-inplace Select sort
	std::cout<< "Non-inplace Select sort."<<std::endl;
	std::vector<int>  ordered_array = Sort::SelectSort(rand_array);

	//Inplace Select sort
	// std::cout<< "inplace Select sort."<<std::endl;
	// Sort::InplaceSelectSort(rand_array,true);


	//3.Output
	std::cout << "Ordered array: \n";
	for (int i = 0; i < ordered_array.size(); i++) {
		std::cout << ordered_array[i] << " \n"[i == ordered_array.size()-1];
	}
	return 0;
}

// g++ -o SortBasic main.cpp Sort.cpp ArrayGenerator.cpp