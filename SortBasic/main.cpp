#include <iostream>
#include <vector>
#include "ArrayGenerator.h"
#include "Sort.h"

int main() {
	//1.Generate random array
	std::vector<int>  rand_array;
	ArrayGenerator::getArray(rand_array, 20);
	std::cout << "Original array: \n";
	for (int i = 0; i < rand_array.size(); i++) {
		std::cout << rand_array[i] << " \n"[i == rand_array.size()-1];
	}

	//2.Sorting
	//Non-inplace Select sort
	//std::vector<int>  ordered_array = Sort::SelectSort(rand_array);
	//Inplace Select sort
	Sort::InplaceSelectSort(rand_array,true);


	//3.Output
	std::cout << "Ordered array: \n";
	for (int i = 0; i < rand_array.size(); i++) {
		std::cout << rand_array[i] << " \n"[i == rand_array.size()-1];
	}
	return 0;
}