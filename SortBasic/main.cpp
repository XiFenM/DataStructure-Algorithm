#include <iostream>
#include <vector>
#include "ArrayGenerator.h"
#include "Sort.h"

int main() {
	std::vector<int>  rand_array;
	ArrayGenerator::getArray(rand_array, 10);
	for (int i = 0; i < rand_array.size(); i++) {
		std::cout << rand_array[i] << " \n"[i == rand_array.size()-1];
	}
	std::vector<int>  ordered_array = Sort::SelectSort(rand_array);
	for (int i = 0; i < ordered_array.size(); i++) {
		std::cout << ordered_array[i] << " \n"[i == ordered_array.size()-1];
	}
	return 0;
}