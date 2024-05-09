//
// Created by Admin on 09.05.2024.
//

#ifndef OOP7_DOUBLELINKEDLIST_H
#define OOP7_DOUBLELINKEDLIST_H
#include "DoubleNode.h"
#include <iostream>
using namespace std;
using namespace double_node;

template <typename T>
class DoubleLinkedList {
private:
    shared_ptr<NodeDouble<T>> head;
    shared_ptr<NodeDouble<T>> tail;
    int size;
public:
    DoubleLinkedList() : head{nullptr},tail{nullptr}, size{0} {};

    void insertAtBegin(T data);
    void insertAtEnd(T data);
    void deleteFromEnd();
    void deleteFromBegin();

    void at(int index);
    void atInsert(int index,T data);
    void atRemove(int index);
    bool isEmpty();
    bool search(T data);
    void show();
};

template<typename T>
bool DoubleLinkedList<T>::search(T data) {
    shared_ptr<NodeDouble<T>> current = head;
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    if(head == tail){
        return true;
    }
    return false;
}

template<typename T>
void DoubleLinkedList<T>::atRemove(int index) {
    if(index == 0){
        deleteFromBegin();
        return;
    }
    if(index == size){
        deleteFromEnd();
        return;
    }
    shared_ptr<double_node::NodeDouble<T>> current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->previous.lock()->next = current->next;
    current->next->previous = current->previous;
    size--;
}

template<typename T>
void DoubleLinkedList<T>::atInsert(int index, T data) {
    if(index == 0){
        insertAtBegin(data);
        return;
    }
    if(index == size){
        insertAtEnd(data);
        return;
    }
    shared_ptr<NodeDouble<T>> current = head;
    shared_ptr<NodeDouble<T>> newNode = make_shared<NodeDouble<T>>(data);
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    newNode->next = current->next;
    newNode->previous = current->previous;
    current->next->previous = newNode;
    current->next = newNode;
    size++;
}

template<typename T>
void DoubleLinkedList<T>::at(int index) {
    if(index<0||index>=size){
        throw out_of_range("Index out of range");
    }
    shared_ptr<NodeDouble<T>> current = head;
    for(int i = 0; i < index;i++){
        current = current->next;
    }
    cout<<"At index "<<index<<": "<<current->data<<endl;

}

template<typename T>
void DoubleLinkedList<T>::deleteFromBegin() {
    if(!head){
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::deleteFromEnd() {
    if(!tail){
        return;
    }
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::show() {
    shared_ptr<NodeDouble<T>> current = head;
    while (current){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

template<typename T>
void DoubleLinkedList<T>::insertAtEnd(T data) {
    shared_ptr<NodeDouble<T>> newNode = make_shared<NodeDouble<T>>(data);
    if(!tail){
        head=tail=newNode;
    } else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DoubleLinkedList<T>::insertAtBegin(T data) {
    shared_ptr<NodeDouble<T>> newNode = make_shared<NodeDouble<T>>(data);
    if(!head){
        head=tail=newNode;
    }else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}
#endif //OOP7_DOUBLELINKEDLIST_H
