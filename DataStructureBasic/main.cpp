#include "tinyVector.h" 
#include "Student.h"
#include <iostream>



void testTinyVector(){
    tinyVector<int> vec; // 测试默认构造函数

    // 测试push_back, push_front, 和 insert
    vec.push_back(1);
    vec.push_back(2);
    vec.push_front(0);
    vec.insert(3, 3); // 在末尾插入3
    vec.show(); // 期望输出：0 1 2 3

    // 测试removeElement, removeIndex, removeFirst, removeLast
    vec.removeElement(1);
    vec.removeIndex(1); // 现在的1位置是2
    vec.removeFirst();
    vec.removeLast();
    vec.show(); // 期望输出为空

    // 重新填充进行更多测试
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.show(); // 期望输出：4 5 6

    // 测试contains和find
    std::cout << "Contains 5: " << vec.contains(5) << std::endl; // 期望输出：1
    std::cout << "Index of 6: " << vec.find(6) << std::endl; // 期望输出：2

    // 测试operator[]
    std::cout << "Element at 0: " << vec[0] << std::endl; // 期望输出：4
    vec[0] = 10;
    std::cout << "Modified Element at 0: " << vec[0] << std::endl; // 期望输出：10

    // 测试拷贝构造函数和拷贝赋值运算符
    tinyVector<int> vecCopy = vec;
    tinyVector<int> vecAssigned;
    vecAssigned = vec;
    vecCopy.show(); // 期望输出：10 5 6
    vecAssigned.show(); // 期望输出：10 5 6

    // 测试输出运算符
    std::cout << vec << std::endl; // 期望输出：10 5 6


    tinyVector<Student> students;

    // 添加学生到tinyVector中
    students.push_back(Student(1, "Alice"));
    students.push_back(Student(2, "Bob"));
    students.push_back(Student(3, "Charlie"));
    students.insert(Student(4, "Daisy"), 1); // 将Daisy插入到Bob之前

    std::cout << "After insertion:" << std::endl;
    students.show();

    // 移除学生
    students.removeIndex(3); // 假设这是Charlie的索引
    std::cout << "After removing Charlie:" << std::endl;
    students.show();

    // 检查是否包含一个学生
    std::cout << "Contains Alice: " << students.contains(Student(1, "Alice")) << std::endl;

    // 查找学生的索引
    int index = students.find(Student(2, "Bob"));
    std::cout << "Index of Bob: " << index << std::endl;

    // 使用operator[]访问和修改
    std::cout << "Student at index 0: " << students[0];
    students[0] = Student(5, "Eva");
    std::cout << "After modifying, student at index 0: " << students[0];

    // 使用operator<<重载输出
    std::cout << "Final students list:" << std::endl;
    std::cout << students;
}

int main() {
    testTinyVector();
    return 0;
}

// g++ -o DataStructureBasic main.cpp queue.cpp stack.cpp tinyVector.cpp Student.cpp