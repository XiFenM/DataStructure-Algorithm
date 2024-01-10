#pragma once
#include <iostream>
#include <vector>

class ArrayGenerator {
private:
	ArrayGenerator() {};
public:
	static void getOrderedArray(std::vector<int> &array,int num);
	static void getArray(std::vector<int> &array, int num);
};