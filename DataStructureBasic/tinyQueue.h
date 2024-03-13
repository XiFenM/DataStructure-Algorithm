#pragma once
#include <iostream>
#include "tinyVector.h"

template<typename T>
class tinyQueue;
template<typename T>
class queueVector;
template<typename T>
class circularQueue;

template<typename T>
class tinyQueue{
private:
    // queueVector<T>* queueRep; // Implement with vector
    circularQueue<T>* queueRep; //Implement with circular queue
public:
    tinyQueue(size_t len = 10)
        :queueRep(new circularQueue<T>(len))
    {};
    tinyQueue(const tinyQueue<T>& old_obj)
        :queueRep(new circularQueue<T>(old_obj))
    {}

    tinyQueue& operator=(const tinyQueue& old_obj){
        if(this == &old_obj){
            return *this;
        }
        delete this->queueRep;
        this->queueRep = new circularQueue<T>;
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
    friend class tinyQueue<T>;
    tinyVector<T> queue;

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
class circularQueue{
private:
    friend class tinyQueue<T>;
    // data
    T* queue;
    // The definition of capacity is the maximum number of elements(not include tail)
    T* front, *tail;
    size_t capacity;
    

    circularQueue(size_t len = 10)
        :queue(new T[len + 1]), front(queue), tail(queue), capacity(len)
    {}

    circularQueue(const circularQueue& old_obj)
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

    circularQueue& operator=(const circularQueue& old_obj){
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
    friend std::ostream& operator<<(std::ostream& os, const circularQueue<U>& obj);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const circularQueue<U>& obj){
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