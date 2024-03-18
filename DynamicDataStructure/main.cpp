#include <iostream>
#include "tinyLinkedList.h"
int main() {
    tinyLinkedList<int> my_list;
    for (int i = 0; i < 10; i++) {
        my_list.insert(i,0);
    }
    std::cout << my_list << std::endl;
    for (int i = 0; i < 10; i++) {
        my_list.insert(i,my_list.getSize());
    }
    std::cout << my_list << std::endl;
    for (int i = 0; i < 10; i++) {
        my_list.insert(i,10);
    }
    std::cout << my_list << std::endl;
    my_list.remove(0);
    std::cout << my_list << std::endl;
    my_list.remove(my_list.getSize()-1);
    std::cout << my_list << std::endl;
    my_list.remove(10);
    std::cout << my_list << std::endl;

    tinyLinkedList<int> list2(my_list);
    std::cout << list2 << std::endl;
    for (int i = 0; i < 10; i++) {
        my_list.remove(0);
    }
    list2 = my_list;
    std::cout << list2 << std::endl;
    const tinyLinkedList<int> list3(list2);

    std::cout << list3[10] << std::endl;
    std::cout << list3.find(88) << std::endl;
    return 0;
}