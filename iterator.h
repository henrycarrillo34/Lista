#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    protected:
        Node<T>* current;
        
    public:        
        Iterator() : current(nullptr) {};

        Iterator(Node<T>* current) : current(current) {};
             
        Iterator<T>& operator=(Iterator<T> other); 

        bool operator!=(Iterator<T> other);
        
        T operator*();
        
};  

#endif