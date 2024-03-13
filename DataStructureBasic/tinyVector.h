#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class tinyVector
{
private:
    T *data;
    size_t size;
    size_t capacity;
    void resize(size_t new_capacity);

public:
    tinyVector(std::initializer_list<T> init){
        size = init.size();
        capacity = init.size();
        data = new T[capacity];
        for(int i = 0 ;i < size; i++){
            data[i] = *(init.begin()+i);
        }
    };

    tinyVector(size_t length = 10)
        : data(new T[length]), capacity(length), size(0)
    {}

    tinyVector(const tinyVector<T> &old_obj)
        :size(old_obj.getSize()),capacity(old_obj.getCapacity()),data(new T[old_obj.getCapacity()])
    {
        // deep copy
        for (size_t i = 0; i < this->size; i++){
            this->data[i] = old_obj[i];
        }
    }
    tinyVector<T>& operator=(const tinyVector<T>& old_obj){
        // self check
        if(this == &old_obj){
            return *this;
        }
        delete[] this->data;
        // deep copy
        this->size = old_obj.getSize();
        this->capacity = old_obj.getCapacity();
        this->data = new T[old_obj.getCapacity()];
        for(size_t i = 0 ; i < this->size ; i++){
            this->data[i] = old_obj[i]; 
        }
        return *this;
    }
    ~tinyVector()
    {
        delete[] data;
    }

    size_t getSize() const {
        return this->size; 
    }
    size_t getCapacity() const {
        return this->capacity; 
    }
    bool isEmpty() const {
        return this->size == 0; 
    }

    // 增
    void push_back(const T &new_data);
    void push_front(const T &new_data);
    void insert(const T &new_data, size_t index);

    // 删
    T removeElement(const T &new_data);
    T removeIndex(size_t index);
    T removeFirst();
    T removeLast();

    // 改
    const T &operator[](size_t index) const;
    T& operator[](size_t index); 

    // 查
    bool contains(const T &new_data) const;
    int find(const T &new_data) const;

    // 显示
    void show() const;
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const tinyVector<U> &array);

    // 简易迭代器
    const T* begin() const;
    T* begin();
    
    const T* end() const;
    T* end();

};

template<typename T>
inline void tinyVector<T>::resize(size_t new_capacity){
    if(new_capacity < this->size) 
        throw std::out_of_range("Insufficient capacity to accommodate all elements!");
    T* new_data = new T[new_capacity];
    for(size_t i = 0 ; i < this->size;i++){
        new_data[i] = this->data[i];
    }
    this->capacity = new_capacity;
    delete[] this->data;
    this->data = new_data;
}

// 增
template <typename T>
inline void tinyVector<T>::push_back(const T &new_data)
{
    this->insert(new_data, this->size);
}

template <typename T>
inline void tinyVector<T>::push_front(const T &new_data)
{
    this->insert(new_data, 0);
}

template <typename T>
inline void tinyVector<T>::insert(const T &new_data, size_t index)
{
    if (this->size == this->capacity){
        if(this->capacity == 0){
            this->resize(1);
        }
        else {
            this->resize(2 * this->capacity);
        }
    }

    if (index > this->size){
        throw std::out_of_range("Index parameter wrong!");
    }
    // size_t为无符号数，不断--递减会越界成为最大数
    for (size_t i = (this->size - 1); i >= index && i < this->size; i--){
        this->data[i + 1] = this->data[i];
    }
    this->data[index] = new_data;
    this->size++;
}

// 删
template<typename T>
inline T tinyVector<T>::removeElement(const T& new_data){
    int loc = this->find(new_data);
    if(loc == -1){
        throw std::invalid_argument("Cannot find the element you want to remove");
    }
    return this->removeIndex(loc);
}

template<typename T>
inline T tinyVector<T>::removeIndex(size_t index){
    if(index >= this->size){
        throw std::out_of_range("index exceeds the range of vector");
    }
    T deletedElement = this->data[index];
    for( ; index < (this->size - 1) ; index++){
        this->data[index] = this->data[index + 1];
    }
    this->size --;
    
    if(this->size == (this->capacity / 4) && this->capacity/2 != 0){
        this->resize(this->capacity / 2);
    }
    return deletedElement;
}

template<typename T>
inline T tinyVector<T>::removeFirst(){
    return this->removeIndex(0);
}

template<typename T>
inline T tinyVector<T>::removeLast(){
    return this->removeIndex(this->size - 1);
}


// 改
template <typename T>
inline const T &tinyVector<T>::operator[](size_t index) const
{
    if (index >= this->size){
        throw std::out_of_range("Index out of range!");
    }
    return this->data[index];
}

template <typename T>
inline T &tinyVector<T>::operator[](size_t index)
{
    if (index >= this->size){
        throw std::out_of_range("Index out of range!");
    }
    return this->data[index];
}

// 查
template <typename T>
bool tinyVector<T>::contains(const T &new_data) const
{
    for (size_t i = 0; i < this->size; i++)
    {
        if (data[i] == new_data)
            return true;
    }
    return false;
}

template<typename T>
inline int tinyVector<T>::find(const T& new_data) const {
    for(size_t i = 0 ; i < this->size;i++){
        if(this->data[i] == new_data){
            return i;
        }
    }
    return -1;
}

// 展示输出
template <typename T>
void tinyVector<T>::show() const
{
    std::cout << "[ ";
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << (this->data)[i];
        if(i < this->size - 1){
            std::cout << " , ";
        }
    }
    std::cout << " ]" << std::endl;
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const tinyVector<U> &array)
{
    os << "[";
    for (size_t i = 0; i < array.size; i++)
    {
        os << (array.data)[i] ;
        if(i < array.size - 1){
            os << ", ";
        }
    }
    os << "]";
    return os;
}


// 简易迭代器
template<typename T>
const T* tinyVector<T>::begin() const{
    return &this->data[0];
}


template<typename T>
T* tinyVector<T>::begin(){
    return &this->data[0];
}

template<typename T>
const T* tinyVector<T>::end() const{
    return &this->data[this->size];
}

template<typename T>
T* tinyVector<T>::end(){
    return &this->data[this->size];
}