#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

class Tools {
private:
	const static std::vector<std::string> name_list;
	Tools()=default;
public:
	static inline void getOrderedArray(std::vector<int>& array, int num);
	static inline void getRandArray(std::vector<int>& array, int num ,int upperbound=100);
	static inline void getRandStudents(std::vector<Student>& array,int num,int upperbound=100);
	
	template<typename T>
	requires std::three_way_comparable<T>
	static inline bool isOrdered(const std::vector<T>& array,bool descending= false){
		int len = array.size();
		for(int i = 0 ; i < len - 1 ; i ++){
			if(descending){
				if(array[i]<array[i+1]){
					std::cout << "该数组无序"<< std::endl;
					return false;
				}
			}
			else{
				if(array[i]>array[i+1]){
					std::cout << "该数组无序"<< std::endl;
					return false;
				}
			}
		}
		std::cout << "该数组有序"<< std::endl;
		return true;
	}
};

const std::vector<std::string> Tools::name_list = {
	"Azai","Basil","Che","Nile","Bogda","Taru","Ryatt","Lotem","Maple","Gera"
};