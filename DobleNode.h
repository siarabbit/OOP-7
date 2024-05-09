//
// Created by Admin on 09.05.2024.
//

#ifndef OOP7_DOBLENODE_H
#define OOP7_DOBLENODE_H
#include <memory>
using namespace std;
namespace double_node{
    template <typename T>
    struct Node{
        T data;
        shared_ptr<Node> next;
        weak_ptr<Node> previous;

        Node(T value) : data(value) {};
    };
}
#endif //OOP7_DOBLENODE_H
