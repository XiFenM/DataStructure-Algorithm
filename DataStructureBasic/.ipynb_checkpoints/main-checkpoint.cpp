#include <iostream>
#include "tinyVector.h" 
#include "tinyStack.h"
#include "tinyQueue.h"
#include "Student.h"
#include "Solution.h"
#include <chrono>
#include <string>
using namespace tinyDS;


void testTinyVector(){
    tinyVector<int> vec; // 测试默认构造函数

    // 测试push_back, push_front, 和 insert
    vec.push_back(1);
    vec.push_back(2);
    vec.push_front(0);
    vec.insert(3, 3); // 在末尾插入3
    vec.show(); // 期望输出：0 1 2 3

    // 测试removeElement, removeIndex, removeFirst, removeLast
    int deletedElement = vec.removeElement(1);
    std::cout << "Deleted Element is " << deletedElement << std::endl;
    deletedElement = vec.removeIndex(1); // 现在的1位置是2
    std::cout << "Deleted Element is " << deletedElement << std::endl;
    deletedElement = vec.removeFirst();
    std::cout << "Deleted Element is " << deletedElement << std::endl;
    deletedElement = vec.removeLast();
    std::cout << "Deleted Element is " << deletedElement << std::endl;
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
    Student RemovedStudent = students.removeIndex(3); // 假设这是Charlie的索引
    std::cout << "Deleted Student is " << RemovedStudent << std::endl;
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

void testTinyStack(){
    tinyStack<int> stack;

    // 测试isEmpty在栈为空时
    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // 测试push和peek
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Current top element (peek): " << stack.peek() << std::endl;
    std::cout << "Current Stack: "<< stack<< std::endl;
    // 测试getSize
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    // 测试pop
    std::cout << "Popping top element: " << stack.pop() << std::endl;
    std::cout << "New top element (peek): " << stack.peek() << std::endl;
    std::cout << "Stack size after pop: " << stack.getSize() << std::endl;
    std::cout << "Current Stack: "<< stack<< std::endl;
    
    // 测试isEmpty在栈非空时
    std::cout << "Is the stack empty now? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
}

void testValidParentheses(){
    tinyVector<std::string> test_string_list ={
        "([{}])","[{}(){","(","}(","(){}[]"
    };
    for(int i = 0 ;i < test_string_list.getSize();i++){
        std::cout << Solution::isValid(test_string_list[i]) <<std::endl;
    }
}

void testTinyQueue(){
    tinyQueue<int> queue;

    std::cout << "Enqueue elements 1 to 5." << std::endl;
    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i);
        std::cout << queue << std::endl;
    }

    std::cout << "Current size: " << queue.getSize() << std::endl;
    std::cout << "Capacity: " << queue.getCapacity() << std::endl;

    std::cout << "Dequeue two elements." << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }
    std::cout << queue << std::endl;

    std::cout << "Enqueue elements 6 to 8." << std::endl;
    for (int i = 6; i <= 8; ++i) {
        queue.enqueue(i);
        std::cout << queue << std::endl;
    }

    std::cout << "Final queue: " << queue << std::endl;
    std::cout << "Current size: " << queue.getSize() << std::endl;
    std::cout << "Capacity: " << queue.getCapacity() << std::endl;

}

template<typename QueueType>
void testQueuePerformance(size_t operations) {
    QueueType queue(10); // 假设构造函数可以接受一个初始容量参数

    auto start = std::chrono::high_resolution_clock::now();

    // 入队操作
    for(size_t i = 0; i < operations; i++) {
        queue.enqueue(i);
    }

    // 出队操作
    for(size_t i = 0; i < operations; i++) {
        queue.dequeue();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Elapsed time for " << operations << " operations: " << elapsed.count() << " ms\n";
}

void testQueueTime(){
    size_t operations = 100000; // 选择一个操作数量，根据你的需要调整

    std::cout << "Testing queueVector performance:\n";
    testQueuePerformance<tinyQueue<int, queueVector>>(operations);

    std::cout << "\nTesting circularQueue performance:\n";
    testQueuePerformance<tinyQueue<int, CircularQueue>>(operations);
}

int main() {
    testQueueTime();
    return 0;
}

// g++ -o DataStructureBasic main.cpp tinyQueue.cpp tinyStack.cpp tinyVector.cpp Student.cpp Solution.cpp