//
// Created by Admin on 09.05.2024.
//

#ifndef OOP7_SINGLENODE_H
#define OOP7_SINGLENODE_H
#include <memory>
namespace single_Node{
    template <typename T>
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        explicit Node(T newData)
                :data{newData}, next{nullptr}{};
    };
}
#endif //OOP7_SINGLENODE_H
