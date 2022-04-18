#ifndef DOUBLE_H
#define DOUBLE_H

#include "iterator.h"
using namespace std;


template <typename T>
class DoubleListIterator : public Iterator<T> {     
    public: 
        DoubleListIterator() : Iterator<T>() {};
        DoubleListIterator(Node<T> *current) : Iterator<T>(current) {};
        DoubleListIterator<T>& operator++();//++it
        DoubleListIterator<T>& operator--();//--it        
};

template <typename T>
class DoubleList : public List<T>{     
    public:
        typedef DoubleListIterator<T> iterator;
    public:
        DoubleList() : List() { }

        T front(){
            return this->head->data;
        };

        T back(){
            return this->tail->data;
        };

        void push_front(T value){
            Node<T> *nodo = new Node<T>(value);
            nodo->next = this->head;
            if(this->head == nullptr){
                this->head = nodo;
                this->tail = nodo;
            }
            else{
                this->head->prev = nodo;
                this->head = nodo;
            }
            this->nodes++;
        };

        void push_back(T value){
            Node<T> *nodo = new Node<T>(value);
            nodo->prev = this->tail;
            if(this->head == nullptr){
                this->head = nodo;
                this->tail = nodo;
            }
            else{
                this->tail->next = nodo;
                this->tail = nodo;
            }
            this->nodes++;
        };

        T pop_front(){
            if (is_empty()){
                throw "List is empty";
            }
            Node<T> *temp = this->head;
            T value = this->head->data;
            this->head = this->head->next;
            delete temp;
            this->head->prev = nullptr;
            this->nodes--;
            return value;
        };

        T pop_back(){
            if (is_empty()){
                throw "List is empty";
            }
            Node<T> *temp = this->tail;
            T value = this->tail->data;
            this->tail = this->tail->prev;
            delete temp;
            this->tail->next= nullptr;
            this->nodes--;
            return value;
        };

        void insert(T value, int pos){
            if(pos >= this->nodes){
                throw "Îndice no valido";
            }
            Node<T> *nodo = new Node<T>(value);
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos -1){
                temp = temp->next;
                i++;
            }
            nodo->next = temp->next;
            nodo->prev = temp;
            temp->next->prev= nodo;
            temp->next = nodo;
            this->nodes++;
        };

        void remove(int pos){
            if (is_empty()){
                throw "List is empty";
            }
            if(pos >= this->nodes){
                throw "Index no valido";
            }
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos-1 && temp != nullptr){
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
            delete temp->next;
            temp->next->prev = temp;
            this->nodes--;
        };

        T operator[](int pos){
            if (is_empty()){
                throw "List is empty";
            }
            if(pos >= this->nodes){
                throw "Index no valido";
            }
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos){
                temp = temp->next;
                i++;
            }
            return temp->data;
        };

        bool is_empty(){
            return this->head == nullptr;
        };

        int size() {
            return this->nodes;
        };

        void clear() {
            while(!this->empty()){
                pop_front();
            }
        };

        void sort(){
            if (is_empty()){
                throw "List is empty";
            }
            Node<T> *nodo = this->head;
            while(nodo != nullptr){
                T value = nodo->data;
                Node<T> *ref = nodo;
                Node<T> *temp = nodo->next;
                while(temp != nullptr){
                    if(ref->data > temp->data){
                        ref = temp;
                    }
                    temp = temp->next;
                }
                nodo->data = ref->data;
                ref->data = value;
                nodo = nodo->next;
            }
        };

        bool is_sorted(){
            int i = 0;
            while(i< this->nodes - 1){
                if(operator[](i) > operator[](i+1)){
                    return false;
                }
                ++i;
            }
            return true;
        };

        void reverse(){
            Node<T> *nodo = this->head;
            Node<T> *temp = this->head;
            List<T> *list= new DoubleList<T>();
            while(nodo != nullptr){
                list->push_front(nodo->data);
                nodo = nodo->next;
            }
            int i = 0;
            while(temp != nullptr){
                temp->data = list->operator[](i);
                temp = temp->next;
                i++;
            }
        };

        std::string name(){
            return "DoubleList";
        };

        void display(){
            if (is_empty()){
                throw "List is empty";
            }
            Node<T>* temp = this->head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << endl;
        };

        /* new functions */             
        iterator begin() {
            // TODO
        }

        iterator end() {
            // TODO
        }      
        ~DoubleList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif