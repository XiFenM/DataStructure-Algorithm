#pragma once
#include <string>
#include <iostream>
#include "tinyStack.h"
#include <queue>

class Solution{
private:
    Solution()=default;
public:
    static bool isValid(std::string s){
        if(s.size()<2) return false;
        tinyDS::stack::tinyStack<char> char_stack;
        tinyDS::vector::tinyVector<char> 
        left_parenthesis = {'(', '{', '['},
        right_parenthesis = {')', '}', ']'};
        
        int left_loc{0},right_loc{0};
        for(char& c : s){
            if(left_parenthesis.contains(c)){
                char_stack.push(c);
            }
            else{
                right_loc = right_parenthesis.find(c);
                if(right_loc != -1){
                    if(char_stack.getSize() == 0) return false;
                    left_loc = left_parenthesis.find(char_stack.peek());
                    if(left_loc == right_loc){
                        char_stack.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return char_stack.isEmpty();
    }


};


// 225. Implement Stack using Queues
class MyStack {
public:
    std::queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int len = q.size(),tmp = 0;
        q.push(x);
        for(int i = 0 ;i < len ; i ++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    int pop() {
        int pop_item = q.front();
        q.pop();
        return pop_item;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */