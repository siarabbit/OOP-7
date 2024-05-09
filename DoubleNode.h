//
// Created by Admin on 09.05.2024.
//

#ifndef OOP7_DOUBLENODE_H
#define OOP7_DOUBLENODE_H
#include <memory>
using namespace std;
namespace double_node{
    template <typename T>
    struct NodeDouble{
        T data;
        shared_ptr<NodeDouble> next;
        weak_ptr<NodeDouble> previous;

        NodeDouble(T value) : data(value) {};
    };
}
#endif //OOP7_DOUBLENODE_H
