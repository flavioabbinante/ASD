// File di test per la hashtable

#include <iostream>
#include "HashTable.h"

int main(){

    HashTable<int,int> ht(10);
    Pair<int,int> p1(1,1);
    Pair<int,int> p2(2,2);
    Pair<int,int> p3(3,3);
    Pair<int,int> p4(1,4);



    ht.insert(p1);
    ht.insert(p2);
    ht.insert(p3);
    ht.insert(p4); // Linear Probing
    
    ht.toString();


}

