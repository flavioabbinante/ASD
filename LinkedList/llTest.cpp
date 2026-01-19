#include "LinkedList.h"
#include <iostream>

int main(){

    LinkedList<int> a;
    LinkedList<int> b;

    a.pushBack(1);
    a.pushBack(7);
    a.pushBack(2);
    a.pushBack(4);
    a.pushBack(6);

    a.toString();

    a.exchange(0,4);

    a.toString();


    return 0;

}