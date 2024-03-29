#include <iostream>
#include <vector>
#include "Tools.h"
#include "Student.h"
#include "Sort.h"

void TestInsertSortFeature(){
	std::vector<int> int_rand_array,array_size_list = {20,100,1000,10000};
	std::vector<Student>  student_rand_array;

	for(int array_size:array_size_list){
		std::cout << "\nArray Size:" << array_size<< std::endl;
		// Tools::getRandArray(int_rand_array,array_size,array_size);
		Tools::getOrderedArray(int_rand_array,array_size);
		Tools::verifyInplaceSorting<int>(Sort::InsertSort<int>,int_rand_array);
		// Tools::getRandArray(int_rand_array,array_size,array_size);
		Tools::getOrderedArray(int_rand_array,array_size,true);
		Tools::verifyInplaceSorting<int>(Sort::InsertSort<int>,int_rand_array,true);


		Tools::getRandStudents(student_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<Student>(Sort::InsertSort<Student>,student_rand_array);
		Tools::getRandStudents(student_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<Student>(Sort::InsertSort<Student>,student_rand_array,true);
	}
}

int main() {
	std::vector<int> int_rand_array,array_size_list = {20,100,1000,10000};
	std::vector<Student>  student_rand_array;
	
	for(int array_size:array_size_list){
		std::cout << "\nArray Size:" << array_size<< std::endl;
		Tools::getRandArray(int_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<int>(Sort::InsertSort2<int>,int_rand_array);
		Tools::getRandArray(int_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<int>(Sort::InsertSort2<int>,int_rand_array,true);


		Tools::getRandStudents(student_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<Student>(Sort::InsertSort2<Student>,student_rand_array);
		Tools::getRandStudents(student_rand_array,array_size,array_size);
		Tools::verifyInplaceSorting<Student>(Sort::InsertSort2<Student>,student_rand_array,true);
	}
	return 0;
}

// g++ -o SortBasic main.cpp Sort.cpp Student.cpp Tools.cpp