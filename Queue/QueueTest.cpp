#include "Queue.h"

int main(){

    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.toString();
    q.dequeue();
    q.toString();

    return 0;
}

