#include "Queue.h"
#include "Stack.h"

int main(){

    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.toString();
    q.dequeue();
    q.toString();

    Stack<int> t;

    t.push(1);
    t.push(2);
    t.push(3);
    t.toString();
    t.pop();
    t.toString();

    return 0;
}

