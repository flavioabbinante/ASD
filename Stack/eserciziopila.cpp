#include <iostream>
#include "Stack.h"

using namespace std;

void switch2(Stack<int> &p1, Stack<int> &p2){
   while(!p1.isEmpty())
    {
       int x = p1.getTop();
       p1.pop();
       p2.push(x);
    }
    
}


int main(){
    Stack<int> primo;
    Stack<int> secondo;
    primo.push(3);
    primo.push(2);
    primo.push(1);
    switch2(primo,secondo);

    secondo.toString();
   
    

    return 0;
}