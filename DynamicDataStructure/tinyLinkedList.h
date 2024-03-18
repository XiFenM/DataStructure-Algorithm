#pragma once
#include <iostream>

template<typename T>
class tinyLinkedList;
template<typename T>
class LinkedListNode;

template<typename T>
class LinkedListNode{
private:
	T data;
	LinkedListNode* next;
	template<typename U>
	friend class tinyLinkedList;

	LinkedListNode(T new_data=NULL,LinkedListNode* new_next=nullptr)
		:data(new_data),next(new_next)
	{}
	template<typename U>
	friend std::ostream& operator<< (std::ostream& os,const LinkedListNode<U> node); 
	template<typename U>
	friend std::ostream& operator<< (std::ostream& os, const tinyLinkedList<U>& obj);
};

template<typename U>
std::ostream& operator<< (std::ostream& os,const LinkedListNode<U> node){
	return os << node.data;
}

template<typename T>
class tinyLinkedList{
private:
	LinkedListNode<T>* dummyHead;
	size_t size;
	void removeAll(){
		LinkedListNode<T>* it,*it_next;
		for(it = dummyHead ;it!=nullptr;it = it_next){
			it_next = it->next;
			delete it;
		}
		this->size = 0;
		this->dummyHead = new LinkedListNode<T>;
	}
public:
	tinyLinkedList()
		:dummyHead(new LinkedListNode<T>),size(0)
	{}

	

	~tinyLinkedList(){
		removeAll();
	}

	tinyLinkedList(const tinyLinkedList<T>& old_obj)
		:dummyHead(new LinkedListNode<T>),size(old_obj.size)
	{
		if(old_obj.dummyHead->next){
			dummyHead->next = new LinkedListNode<T>;
			LinkedListNode<T> *itn=dummyHead,*ito;
			for(ito = old_obj.dummyHead;(ito->next)!=nullptr;){
				itn = itn->next;
				ito = ito->next;
				itn->data = ito->data;
				if(ito->next){
					itn->next = new LinkedListNode<T>;
				}
			}
        }
	}

	tinyLinkedList<T>& operator=(const tinyLinkedList<T> & old_obj){
		if(this == &old_obj){
			return *this; 
		}
		this->removeAll();
		this->size = old_obj.size;
		if (old_obj.dummyHead->next) {
			this->dummyHead->next = new LinkedListNode<T>;
			LinkedListNode<T>* itn =this->dummyHead, * ito = old_obj.dummyHead;
			for (; (ito->next) != nullptr;) {
				itn = itn->next;
				ito = ito->next;
				itn->data = ito->data;
				if (ito->next) {
					itn->next = new LinkedListNode<T>;
				}
			}
		}
		
	}

	size_t getSize() const {
		return this->size;
	}

	bool isEmpty() const {
		return this->dummyHead->next == nullptr;
	}
	
	void insert(T new_data, size_t pos) {
		if (pos > this->size) {
			throw std::invalid_argument("insert position is invalid");
		}
		LinkedListNode<T>* it = this->dummyHead;
		for (size_t i = 0; i < pos; i++) {
			it = it->next;
		}
		it->next = new LinkedListNode<T>(new_data, it->next);
		this->size++;

	}
	
	void remove(size_t pos) {
		if (pos > this->size - 1) {
			throw std::invalid_argument("Removing position is invalid");
		}
		LinkedListNode<T>* it = this->dummyHead;
		for (size_t i = 0; i < pos; i++) {
			it = it->next;
		}
		LinkedListNode<T>* next_pos = it->next->next;
		delete it->next;
		it->next = next_pos;
		this->size--;
	}

	const T& operator[] (size_t index) const {
		if (index > this->size - 1) {
			throw std::invalid_argument("index is invalid");
		}
		LinkedListNode<T>* it = this->dummyHead->next;
		for (size_t i = 0; i < index; i++) {
			it = it->next;
		}
		return it->data;
	}
	T& operator[] (size_t index) {
		if (index > this->size - 1) {
			throw std::invalid_argument("index is invalid");
		}
		LinkedListNode<T>* it = this->dummyHead->next;
		for (size_t i = 0; i < index; i++) {
			it = it->next;
		}
		return it->data;
	}

	int find(const T& element) const {
		size_t index = 0;
		LinkedListNode<T>*  it = this->dummyHead->next;
		for (; it; index++,it=it->next) {
			if (it->data == element) {
				return index;
			}
		}
		return -1;
	}


	template<typename U>
	friend std::ostream& operator<< (std::ostream& os, const tinyLinkedList<U>& obj);
};

template<typename U>
std::ostream& operator<< (std::ostream& os, const tinyLinkedList<U>& obj) {
	os << '[';
	for (LinkedListNode<U>* it = obj.dummyHead->next; it ; it = it->next) {
		os << *it << "-> ";
	}
	os << ']';
	return os;
}