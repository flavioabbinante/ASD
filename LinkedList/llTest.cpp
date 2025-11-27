#include "LinkedList.h"
#include <iostream>

int main(){

    LinkedList<int> l1;

    l1.pushBack(10);
    l1.pushFront(20);
    l1.pushFront(40);
    l1.pushFront(110);
    l1.pushFront(30);

    l1.toString();

    int index = l1.searchElement(10);

    std::cout << index << std::endl;

    l1.changeAt(31,index);

    l1.toString();

    return 0;

}