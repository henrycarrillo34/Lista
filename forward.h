#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterator.h"

template <class T>
class ForwardListIterator : public Iterator<T> {     
    public: 
        ForwardListIterator() : Iterator<T>() {};
        ForwardListIterator(Node<T> *current) : Iterator<T>(current) {};

        ForwardListIterator<T>& operator++()//++it
        {   
            this->current = this->current->next;
            return *this;
        }            

        ForwardListIterator<T>& operator++(int) //it++        
        {
            Node* temp = this->current;
            this->current = this->current->next;
            return ForwardListIterator<T>(temp);//mas memoria
        }

        T operator*(){            
            return current->data;
        }

        ForwardListIterator<T>& operator--()//++it
        {            
           throw ("It's not implement");
        } 
};

template <typename T>
class ForwardList : public List<T> {     
    public:
        typedef ForwardListIterator<T> iterator;  
        
    public:
        ForwardList() : List() { }

        /* new functions */
        iterator begin() {
            return iterator(this->head);
        }
        
        iterator end() {
            return iterator(nullptr);    
        }           

        ~ForwardList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif

