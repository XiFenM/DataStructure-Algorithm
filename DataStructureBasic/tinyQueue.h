#pragma once
#include <iostream>
#include "tinyVector.h"
namespace tinyDS{

namespace queue{

template<typename T>
class queueVector;
template<typename T>
class CircularQueue;
// CircularQueue2 substitude the extra element space for a member varible 'size'. 
template <typename T>
class CircularQueue2;
template<typename T,template<typename U> typename QueueImpl = CircularQueue2>
class tinyQueue;


template<typename T,template<typename U> typename QueueImpl>
class tinyQueue{
private:
    QueueImpl<T>* queueRep; 
public:
    tinyQueue(size_t len = 10)
        :queueRep(new QueueImpl<T>(len))
    {};
    tinyQueue(const tinyQueue<T>& old_obj)
        :queueRep(new QueueImpl<T>(old_obj))
    {}

    tinyQueue& operator=(const tinyQueue& old_obj){
        if(this == &old_obj){
            return *this;
        }
        delete this->queueRep;
        this->queueRep = new QueueImpl<T>;
        (*this->queueRep) = (*old_obj.queueRep);
        return *this;
    }
    ~tinyQueue(){
        delete this->queueRep;
    }

    void enqueue(const T& new_data){
        this->queueRep->enqueue(new_data);
    };
    T dequeue(){
        return this->queueRep->dequeue();
    };
    const T& getFront()const{
        return this->queueRep->getFront();
    };
    size_t getSize() const{
        return this->queueRep->getSize();
    };
    size_t getCapacity() const{
        return this->queueRep->getCapacity();
    }
    bool isEmpty() const{
        return this->queueRep->isEmpty();
    };

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os ,const tinyQueue<U>& obj);
};

template<typename U>
std::ostream& operator<< (std::ostream& os, const tinyQueue<U>& obj){
    return os << (*obj.queueRep);
}


template<typename T>
class queueVector{
private:
    template<typename C,template<typename U> typename QueueImpl>
    friend class tinyQueue;
    vector::tinyVector<T> queue;

    queueVector(size_t len=10)
        :queue(len)
    {}

    queueVector(const queueVector& old_obj)
        :queue(old_obj.queue)
    {}

    queueVector& operator= (const queueVector& old_obj){
        if(this == &old_obj){
            return *this;
        }
        this->queue = old_obj.queue;
        return *this;
    }
    
    void enqueue(const T& new_data){
        this->queue.push_back(new_data);
    }

    T dequeue(){
        return this->queue.removeFirst();
    }
    
    const T& getFront() const{
        return this->queue[0];
    }

    size_t getSize() const{
        return this->queue.getSize();
    }
    size_t getCapacity() const{
        return this->queue.getCapacity();
    }
    bool isEmpty() const{
        return this->queue.isEmpty();
    }
    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, const queueVector<U>& obj);
};

template<typename U>
std::ostream& operator<< (std::ostream& os, const queueVector<U>& obj){
    return os << "Queue: " << obj.queue << " Tail";
}


template<typename T>
class CircularQueue{
private:
    template<typename C,template<typename U> typename QueueImpl>
    friend class tinyQueue;

    // data
    T* queue;
    // The definition of capacity is the maximum number of elements(not include tail)
    T* front, *tail;
    size_t capacity;
    

    CircularQueue(size_t len = 10)
        :queue(new T[len + 1]), front(queue), tail(queue), capacity(len)
    {}

    CircularQueue(const CircularQueue& old_obj)
        :queue(new T[old_obj.capacity + 1]), capacity(old_obj.capacity)
    {
        front = queue;
        T* itn = front;
        for(T* it = old_obj.front;
            it != old_obj.tail ; 
            it = old_obj.queue + (it + 1 - old_obj.queue) % (capacity + 1) ){

            (*itn) = (*it);
            itn++;

        }
        tail = itn;
    }

    CircularQueue& operator=(const CircularQueue& old_obj){
        if(this == &old_obj){
            return *this;
        }
        this->capacity = old_obj.capacity;
        delete[] this->queue;
        this->queue = new T[old_obj.capacity + 1];
        this->front = this->queue;
        T* itn = this->front;
        for(T* it = old_obj.front;
            it != old_obj.tail;
            it = old_obj.queue + (it + 1 - old_obj.queue)%(old_obj.capacity+ 1)){
            
            (*itn) = (*it);
            itn++;
        }
        tail = itn;
        return *this;
    }

    ~CircularQueue(){
        delete[] queue;
    }

    size_t getSize() const{
        return (tail - front + this->capacity + 1 ) % (this->capacity + 1);
    }
    size_t getCapacity() const{
        return this->capacity;
    }

    bool isEmpty() const{
        return this->front == this->tail;
    }

    bool isFull() const{
        return this->getSize() == this->capacity ;
    }


    void resize(size_t new_capacity){
        if(new_capacity < this->getSize() ){
            throw std::invalid_argument("New Capacity is Insufficient");
        }
        T* new_queue = new T[new_capacity + 1];
        T* itn = new_queue;

        for(T* it = this -> front ;
            it != this -> tail ;
            it =  this -> queue + (it + 1 - this->queue)%(this->capacity + 1)){
            (*itn) = (*it);
            itn ++;
        }
        delete[] this->queue;
        this->queue = new_queue;
        this->front = new_queue;
        this->tail = itn;
        this->capacity = new_capacity;
    }


    void enqueue(const T& new_data){
        if(this->isFull()){
            if(this->capacity == 0 ){
                this->resize(1);
            }
            else{
                this->resize(2 * this->capacity);
            }
        }
        (*this->tail) = new_data;
        this->tail = this->queue + (this->tail + 1 - this->queue)%(this->capacity + 1);
    }

    T dequeue(){
        if(this->isEmpty()){
            throw std::invalid_argument("Queue is Empty!");
        }
        T deleted = (*this->front);
        this->front = this->queue + (this->front + 1 - this->queue)%(this->capacity + 1);

        if(this->getSize() <= this->capacity / 4 && (this->capacity / 2) != 0 ){
            this->resize(this->capacity/2);    
        }
        return deleted;
    }

    const T& getFront() const{
        if(this->isEmpty()){
            throw std::runtime_error("Attempted to get front of an empty queue");
        }
        return (*this->front);
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const CircularQueue<U>& obj);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const CircularQueue<U>& obj){
    os << '[';
    for(U* it = obj.front;
        it != obj.tail;
        it = obj.queue + (it + 1 - obj.queue)%(obj.capacity + 1)){
        os << (*it);
        if(obj.queue + (it + 1 - obj.queue)%(obj.capacity + 1) != obj.tail){
            os<< ", ";
        }
    }
    os << "] Tail";
    return os;
}


template<typename T>
class CircularQueue2{
private:
    template<typename C,template<typename U> typename QueueImpl>
    friend class tinyQueue;
    T* queue,*front;
    size_t size,capacity;

    CircularQueue2(size_t len = 10)
    :size(0),capacity(len),queue(new T[len]),front(queue)
    {}

    CircularQueue2(const CircularQueue2& old_obj)
    :size(old_obj.size),capacity(old_obj.capacity),queue(new T[old_obj.capacity]),front(queue)
    {
        T* ito,*itn;
        for(size_t i = 0 ; i < old_obj.size ; i++){
            ito = old_obj.queue + (old_obj.front - old_obj.queue + i) % old_obj.capacity;
            itn = front + i;
            (*itn) = (*ito);
        }
    }

    CircularQueue2& operator=(const CircularQueue2& old_obj){
        if(this== &old_obj){
            return *this;
        }
        delete[] this->queue;
        this->capacity = old_obj.capacity;
        this->size = old_obj.size;
        this->queue = new T[this->capacity];
        this->front = this->queue;
        T* ito,*itn;
        for(size_t i = 0 ; i < this->size; i ++){
            ito = old_obj.queue + (old_obj.front-old_obj.queue+i)%(old_obj.capacity);
            itn = this->front + i;
            (*itn) = (*ito);
        }
        return *this;
    }

    ~CircularQueue2(){
        delete[] queue;
    }

    size_t getSize()const{
        return this->size;
    }

    size_t getCapacity() const{
        return this->capacity;
    }

    bool isEmpty() const{
        return this->size==0;
    }
    bool isFull() const{
        return this->size == this->capacity;
    }

    void resize(size_t new_capacity){
        if(new_capacity < this->size){
            throw std::invalid_argument("New Capacity is Insufficient");
        }
        T* new_queue = new T[new_capacity];
        T* itn = nullptr,*ito=nullptr;
        for(size_t i = 0;i < this->size ; i ++){
            ito = this->queue + (this->front - this->queue + i)%(this->capacity);
            itn = new_queue + i;
            (*itn) = (*ito);
        }
        delete[] this->queue;
        this->front = new_queue;
        this->queue = new_queue;
        this->capacity = new_capacity;
    }

    void enqueue(const T& new_data){
        if(this->size == this->capacity){
            if(this->capacity == 0){
                resize(1);
            }
            else{
                resize(2 * this->capacity);
            }
        }
        T* new_loc = this->queue + (this->front + this->size - this->queue) % this->capacity;
        (*new_loc) = new_data;
        this->size ++;
    }

    T dequeue(){
        if(this->size == 0){
            throw std::invalid_argument("Queue is Empty!");
        }
        T deleted = (*this->front);
        this->front = this->queue + (this->front + 1 - this->queue) % this->capacity;
        this->size --;
        if(this->size <= this->capacity / 4 && this->capacity/2 != 0){
            resize(this->capacity / 2);    
        }
        return deleted;
    }

    const T& getFront() const{
        if(this->size == 0){
            throw std::invalid_argument("Queue is Empty!");
        }
        return (*this->front);
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const CircularQueue2<U>& obj);

};

template<typename U>
std::ostream& operator<<(std::ostream& os, const CircularQueue2<U>& obj){
    os << '[';
    for(size_t i = 0 ;i < obj.size;i ++){
        os << *(obj.queue + (obj.front + i - obj.queue) % obj.capacity); 
        if(i != obj.size - 1 ){
            os << ", ";
        }
    }
    os << "] Tail";
    return os;
}
}


namespace deque{

template<typename T>
class tinyDeque{
private:
    T* deque,*front;
    size_t size,capacity;

    void resize(size_t new_capacity){
        if(new_capacity < this->size){
            throw std::runtime_error("New Capacity is Insufficient!");
        }
        T* new_deque = new T[new_capacity];
        T* itn = new_deque, *ito;
        for(size_t i = 0 ; i < this->size ; i ++){
            ito = this->deque + (this->front + i - this->deque) % this->capacity;
            (*itn) = (*ito);
            itn ++;
        }
        delete[] this->deque;
        this->deque = new_deque;
        this->front = this->deque;
        this->capacity = new_capacity;
    }

public:

    tinyDeque(size_t len = 10)
        :capacity(len),size(0),deque(new T[len]),front(deque)
    {}

    tinyDeque(const tinyDeque& old_obj)
        :capacity(old_obj.capacity),size(old_obj.size),deque(new T[old_obj.capacity]),front(deque)
    {
        T* ito,*itn;
        for(size_t i = 0 ; i < old_obj.size; i ++){
            ito = old_obj.deque + (old_obj.front + i - old_obj.deque)% old_obj.capacity;
            itn = front + i;
            (*itn) = (*ito);
        }
    }

    tinyDeque& operator=(const tinyDeque& old_obj){
        if(this == &old_obj){
            return *this;
        }
        delete[] this->deque;
        this->deque = new T[old_obj.capacity];
        this->front = this->deque;
        this->size = old_obj.size;
        this->capacity = old_obj.capacity;

        T* ito,*itn;
        for(size_t i = 0 ; i < old_obj.size ; i ++){
            ito = old_obj.deque + (old_obj.front + i - old_obj.deque) % old_obj.capacity;
            itn = this -> front + i;
            (*itn) = (*ito);
        }
        return *this;
    }

    ~tinyDeque(){
        delete[] deque;
    }

    size_t getSize() const{
        return this->size;
    }

    size_t getCapacity() const{
        return this->capacity;
    }

    bool isEmpty() const{
        return this->size == 0;
    }
    bool isFull() const{
        return this->size == this->capacity;
    }

    void addFirst(const T& new_data) {
        if(this->size ==  this->capacity){
            this->resize((this->capacity > 0) ? (2 * this->capacity) : 1);
        }

        T* new_loc = this->deque + (this->front - 1 - this-> deque + this->capacity) % (this->capacity);
        (*new_loc) = new_data;
        this->front = new_loc;
        this->size ++;
    }

    void addLast(const T& new_data){
        if(this->size ==  this->capacity){
            this->resize((this->capacity > 0) ? (2 * this->capacity) : 1);
        }

        T* new_loc = this->deque + (this->front + this->size - this-> deque + this->capacity) % (this->capacity);
        (*new_loc) = new_data;
        this->size ++;
    }

    T removeFirst(){
        if(this->size == 0){
            throw std::runtime_error("Deque is Empty!");
        }
        T deleted = (*this->front);
        this->front = this->deque + (this->front + 1 - this->deque) % (this->capacity);
        this->size --;
        if((this->size <= this->capacity/4)  && (this->capacity/2 != 0)){
            this->resize(this->capacity/2);
        }
        return deleted;
    }

    T removeLast(){
        if(this->size == 0){
            throw std::runtime_error("Deque is Empty!");
        }
        T deleted = (* (this->front + this->size - 1));
        this->size -- ;
        if((this->size <= this->capacity/4)  && (this->capacity/2 != 0)){
            this->resize(this->capacity/2);
        }
        return deleted;
    }
    const T& getFirst() const{
        if(this->size == 0){
            throw std::runtime_error("Deque is Empty!");
        }
        return (*this->front);
    }
    const T& getLast() const{
        if(this->size == 0){
            throw std::runtime_error("Deque is Empty!");
        }
        return (* (this->front + this->size -1));
    }
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os,const tinyDeque<U>& obj);
};
template<typename U>
std::ostream& operator<<(std::ostream& os,const tinyDeque<U>& obj){
    os << '[';
    for(size_t i = 0 ; i < obj.size ; i ++){
        os << *(obj.deque + (obj.front + i - obj.deque) % obj.capacity);
        if(i < obj.size - 1) os << ", ";
    }
    os << "] Tail";
    return os;
}

} //deque
} //tinyDS
