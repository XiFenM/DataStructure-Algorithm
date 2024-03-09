#pragma once
#include <cstddef>
#include <iostream>

template<typename T>
class tinyVector{
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    tinyVector(size_t length = 10)
        :data(new T[length]),capacity(length),size(0)
    {}
    tinyVector(const tinyVector<T>& old_obj){
        this->size = old_obj.getSize();
        this->capacity = old_obj.getCapacity();
        this->data = new T[old_obj.getCapacity()];
        for(int i = 0 ; i < this->size;i ++){
            this->data[i] = old_obj[i];
        }
    }
    ~tinyVector(){
        delete[] data;
    }
    size_t getSize() const { return this->size; }
    size_t getCapacity() const {return this->capacity;}
    bool isEmpty() const {return this->size == 0;}
    
    inline void push_back(const T& new_data);
    inline void push_front(const T& new_data);
    inline void insert(const T& new_data ,size_t index);
    inline void show() const;
    T& operator[](size_t index) const;


    template<typename U>
    friend std::ostream& operator<<(std::ostream& os , const tinyVector<U>& array);

};

template<typename T>
T& tinyVector<T>::operator[](size_t index) const{

    return this->data[index]; 
}

template<typename T>
void tinyVector<T>::push_back(const T& new_data){
    this->insert(new_data,this->size);
}

template<typename T>
void tinyVector<T>::push_front(const T& new_data){
    this->insert(new_data,0);
}

template<typename T>
void tinyVector<T>::insert(const T& new_data, size_t index){
    if(this->size == this->capacity){
        std::cout << "Your tinyVector is already FULL!"<< std::endl;
        throw std::exception();
        // 扩容函数
    }

    if(index > this->size){
        std::cout << "Index parameter wrong!"<< std::endl;
        throw std::exception();
    }
    // size_t为无符号数，不断--递减会越界成为最大数
    for(int i = (this-> size-1 ) ; i>=index && i < this->capacity ; i--){
        this->data[i + 1] = this->data[i];
    }
    this->data[index] = new_data;
    this->size++;
}



template<typename T>
void tinyVector<T>::show() const{
    for(size_t i = 0 ;i < this->size;i++){
        std::cout << (this->data)[i] <<' ';
    }
    std::cout << std::endl;
};

template<typename U>
std::ostream& operator<<(std::ostream& os , const tinyVector<U>& array){
    for(size_t i = 0 ;i < array.size;i++){
        os << (array.data)[i] <<' ';
    }
    return os;
}