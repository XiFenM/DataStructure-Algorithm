#pragma once 
#include <iostream>
#include "tinyVector.h"
namespace tinyDS{
namespace stack{

template<typename T>
class tinyStack;
template<typename T>
class stackVector;


template<typename T>
class tinyStack{
private:
    stackVector<T>* stackRep;    
public:
    tinyStack(size_t len = 10)
        :stackRep(new stackVector<T>(len))
    {};
    tinyStack(const tinyStack<T>& old_obj)
        :stackRep(new stackVector<T>(old_obj))
    {};
    
    tinyStack<T>& operator=(const tinyStack<T>& old_obj){
        // self check
        if(this == &old_obj){
            return *this;
        }
        delete this->stackRep;
        this->stackRep = new stackVector<T>;
        (*this->stackRep) = (*old_obj.stackRep);
        return (*this);
    };
    ~tinyStack(){
        delete this->stackRep;
    };
    size_t getSize() const{
        return this->stackRep->getSize();
    };
    bool isEmpty() const{
        return this->stackRep->isEmpty();
    };
    void push(const T& new_data){
        this->stackRep->push(new_data);
    };
    T pop(){
        return this->stackRep->pop();
    };
    const T& peek() const{
        return this->stackRep->peek();
    };
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os,const tinyStack<U>& obj);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const tinyStack<U>& obj){
    return os << (*obj.stackRep);    
}


template<typename T>
class stackVector{
private:
    friend class tinyStack<T>;
    vector::tinyVector<T> stack;

    stackVector(size_t len = 10)
        :stack(len)
    {};
    stackVector(const stackVector<T>& old_obj)
        :stack(old_obj.stack)
    {}

    stackVector<T>& operator=(const stackVector<T>& old_obj){
        // self check
        if(this == &old_obj){
            return *this;
        }
        this->stack = old_obj.stack;
        return *this;
    }



    size_t getSize() const{
        return this->stack.getSize();
    }

    bool isEmpty() const{
        return this->stack.isEmpty();
    }

    void push(const T& new_data){
        this->stack.push_back(new_data);
    }
    T pop(){
        return this->stack.removeLast();
    }
    const T& peek() const{
        return this->stack[this->stack.getSize() - 1];
    }
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os,const stackVector<U>& obj);
};

template<typename U>
std::ostream& operator<<(std::ostream& os,const stackVector<U>& obj){
    return os <<"Stack: "<< obj.stack << " TOP";
}


}
}