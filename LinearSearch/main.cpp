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

	std::cout << "���������в��ҵ���λ������Ϊ"
		<< LinearSearch::search<int>(num_array,9)
		<< std::endl;
	std::cout << "���������в��ҵ���λ������Ϊ"
		<< LinearSearch::search<int>(rand_array, 9)
		<< std::endl;
	std::cout << "����������Ϊ��" ;
	for (int i = 0; i < rand_array.size(); i++)
		std::cout << rand_array[i] << " \n"[i == rand_array.size() - 1];
	std::cout << "�ַ��в��ҵ���λ������Ϊ"
		<< LinearSearch::search<char>(char_array, 'a')
		<< std::endl;

	Student target = Student(3, "Alice");
	std::cout << "ѧ�������в��ҵ���λ������Ϊ"
		<< LinearSearch::search<Student>(student_array, target)
		<< std::endl;

	return 0;
}