#include "ArrayGenerator.h"
#include <cstdlib>
#include <ctime>

void ArrayGenerator::getOrderedArray(std::vector<int>& array, int num) {
	for (int i = 0; i < num; i++) {
		array.push_back(i);
	}
}
void ArrayGenerator::getArray(std::vector<int>& array, int num) {
	srand(time(0));  // �������������
	for (int i = 0; i < num; i++) {
		array.push_back(rand() % 100);
	}
}