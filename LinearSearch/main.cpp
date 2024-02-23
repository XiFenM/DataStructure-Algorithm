#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "ArrayGenerator.h"
#include "Student.h"

int main() {
	std::vector<int> num_array,rand_array;
	ArrayGenerator::getOrderedArray(num_array, 10);
	ArrayGenerator::getArray(rand_array, 10);

	std::vector<char> char_array{ '0','2','3','a','b','c','d','e','o','t'};
	std::vector<Student> student_array{ {0,"Jane"},
		{1,"May"},{2,"August"},{3,"Alice"},{4,"Peter"} };

	std::cout << "有序整数列查找到的位置索引为"
		<< LinearSearch::search<int>(num_array,9)
		<< std::endl;
	std::cout << "乱序整数列查找到的位置索引为"
		<< LinearSearch::search<int>(rand_array, 9)
		<< std::endl;
	std::cout << "乱序整数列为：" ;
	for (int i = 0; i < rand_array.size(); i++)
		std::cout << rand_array[i] << " \n"[i == rand_array.size() - 1];
	std::cout << "字符列查找到的位置索引为"
		<< LinearSearch::search<char>(char_array, 'a')
		<< std::endl;

	Student target = Student(3, "Alice");
	std::cout << "学生数据列查找到的位置索引为"
		<< LinearSearch::search<Student>(student_array, target)
		<< std::endl;

	return 0;
}