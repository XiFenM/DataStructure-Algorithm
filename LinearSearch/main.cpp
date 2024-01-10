#include <iostream>
#include <vector>
#include "LinearSearch.h"

int main() {
	std::vector<int> num_array{ 0,2,3,45,100,6,7,8,1,10 };
	std::vector<char> char_array{ '0','2','3','a','b','c','d','e','o','t'};
	std::vector<Student> student_array{ {0,"Jane"},
		{1,"May"},{2,"August"},{3,"Alice"},{4,"Peter"} };
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<int>(num_array,10)
		<< std::endl;
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<char>(char_array, 'a')
		<< std::endl;
	Student target = Student(3, "Alice");
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<Student>(student_array, target)
		<< std::endl;
	return 0;
}