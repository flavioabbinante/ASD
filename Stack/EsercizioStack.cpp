#include "Stack.h"

int main(){
    Stack<int> godo;
    Stack<int> temp;
    Stack<int> finale;
    int k = 5;
    int n;

    godo.push(5);
    godo.push(1);
    godo.push(4);
    godo.push(8);
    godo.push(9);
    godo.push(2);
    godo.push(6);
    godo.push(6);

    
    while(!godo.isEmpty()){
        n = godo.getTop();

        if(n > k){
            godo.pop();
        }else{
            temp.push(n);
            godo.pop();
        }
    }

    while (!temp.isEmpty())
    {
        finale.push(temp.pop());
    }
    
    finale.toString();

}