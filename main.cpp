#include <iostream>
#include "SingleLinkedList.h"
using namespace std;
int main() {
    SingleLinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.atInsert(0,0);
    list.show();
    list.atRemove(1);
    list.show();
    cout<<"Found: "<<list.search(1)<<endl;

    return 0;
}