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
};

template<typename U>
std::ostream& operator<< (std::ostream& os,const LinkedListNode<U> node){
    return os << node.data;
}

template<typename T>
class tinyLinkedList{
private:
    LinkedListNode<T>* head;
public:
    tinyLinkedList()
        :head(nullptr)
    {}

    void removeAll(){
        LinkedListNode<T>* it,*it_next;
        for(it = head;it!=nullptr;it = it_next){
            it_next = it->next;
            delete it;
        }
    }

    ~tinyLinkedList(){
        removeAll();
    }

    tinyLinkedList(const tinyLinkedList<T>& old_obj)
        :head(nullptr)
    {
        if(old_obj.head){
            head = new LinkedListNode<T>;
            LinkedListNode<T> *itn=head,*ito;
            for(ito = old_obj.head;ito!=nullptr;ito=ito->next){
                itn->data = ito->data;
                if(ito->next){
                    itn->next = new LinkedListNode<T>;
                    itn = itn->next;
                }
            }
        }
    }

    tinyLinkedList<T>& operator=(const tinyLinkedList<T> & old_obj){
        if(this == &old_obj || !old_obj.head){
            return *this; 
        }
        this->removeAll();
        head = new LinkedListNode<T>;
        LinkedListNode<T> *itn=head,*ito;
        for(ito = old_obj.head;ito!=nullptr;ito=ito->next){
            itn->data = ito->data;
            if(ito->next){
                itn->next = new LinkedListNode<T>;
                itn = itn->next;
            }
        }
        
    }
};