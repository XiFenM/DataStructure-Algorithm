#pragma once
#include <iostream>
#include <vector>

class Student {
private:
	int stu_id;
	std::string stu_name;
public:
	Student(int id, std::string name);
	friend bool operator== (const Student&, const Student&);
};

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