#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include "Student.h"
#include "Sort.h"

class Tools {
private:
	const static std::vector<std::string> name_list;
	Tools()=default;
public:
	static void getOrderedArray(std::vector<int>& array, int num);
	static void getRandArray(std::vector<int>& array, int num ,int upperbound=100);
	static void getRandStudents(std::vector<Student>& array,int num,int upperbound=100);

	template<typename T>
	static inline void showArray(const std::vector<T>& array){
		for(auto p = array.begin() ; p != array.end() ; p ++){
			std::cout << (*p) << std::endl;
		}
		std::cout << std::endl;
	}

	template<typename T>
	// requires std::totally_ordered<T> // C++ 20
	static bool isOrdered(const std::vector<T>& array,bool descending= false){
		int len = array.size();
		for(int i = 0 ; i < len - 1 ; i ++){
			if(descending){
				if(array[i]<array[i+1]){
					std::cout << "该数组非降序"<< std::endl;
					return false;
				}
			}
			else{
				if(array[i]>array[i+1]){
					std::cout << "该数组非升序"<< std::endl;
					return false;
				}
			}
		}
		std::cout << "该数组有序"<< std::endl;
		return true;
	}

	template<typename T>
	static void verifyInplaceSorting(const std::function< void(std::vector<T>&,bool) > & sortfunc ,std::vector<T>& array,bool descending = false){
		bool sortFlag;

		auto start = std::chrono::high_resolution_clock::now();
		
		sortfunc(array,descending);
		
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

		std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;

		sortFlag = isOrdered(array,descending);
		if(!sortFlag){
			std::cout << "Sorting failed" << std::endl;
			throw std::exception();
		}
	}

	template<typename T>
	static void verifyNonInplaceSorting(const std::function< std::vector<T>(std::vector<T>,bool) > & sortfunc ,std::vector<T>& array,bool descending = false){
		bool sortFlag;

		auto start = std::chrono::high_resolution_clock::now();
		
		array = sortfunc(array,descending);
		
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

		std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;

		sortFlag = isOrdered(array,descending);
		if(!sortFlag){
			std::cout << "Sorting failed" << std::endl;
			throw std::exception();
		}
	}
};