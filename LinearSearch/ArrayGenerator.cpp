#include <cstdlib>
#include <ctime>
#include "ArrayGenerator.h"

void ArrayGenerator::getOrderedArray(std::vector<int>& array, int num) {
	for (int i = 0; i < num; i++) {
		array.push_back(i);
	}
}
void ArrayGenerator::getArray(std::vector<int>& array, int num) {
	srand(time(0));  // set random seed
	for (int i = 0; i < num; i++) {
		array.push_back( rand()%100 );
	}
}