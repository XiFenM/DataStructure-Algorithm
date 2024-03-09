#include <iostream>
#include "tinyVector.h"
int main(){
    int a[3] = {10,12,20};
    tinyVector<int> array(20);
    std::cout<<array.isEmpty()<<std::endl;

    std::cout << array <<std::endl;
    for(int i = 0; i < 5;i++){
        array.push_back(i);
    }
    std::cout << array <<std::endl;
    for(int i = 0; i < 5;i++){
        array.push_front(i);
    }
    std::cout << array <<std::endl;
    for(int i = 0; i < 5;i++){
        array.insert(i,5);
    }
    std::cout << array <<std::endl;
    std::cout << array[8] << std::endl;
    tinyVector<int> array2 = array;
    
    array2[0] = 100;
    array2[2] = 300;
    std::cout << array <<std::endl;
    std::cout << array2 <<std::endl;
}
// g++ -o DataStructureBasic main.cpp queue.cpp stack.cpp tinyVector.cpp