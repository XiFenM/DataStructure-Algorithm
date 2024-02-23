#pragma once
#include <iostream>
#include <vector>

class LinearSearch {
private:
	LinearSearch() {};
public:
	template <typename T = int>
	static int search(const std::vector<T> array, const T target) {
		for (int i = 0; i < array.size(); i++) {
			if (array[i] == target) {
				return i;
			}
		}
		return -1;
	};
};