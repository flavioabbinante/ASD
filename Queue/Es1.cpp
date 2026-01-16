#include "Queue.h"
#include <iostream>

using namespace std;

int main(){

    Queue<int> numbers;
    Queue<int> positivi;


    numbers.enqueue(1);
    numbers.enqueue(-1);
    numbers.enqueue(10);
    numbers.enqueue(6);
    numbers.enqueue(-4);
    numbers.enqueue(7);

    cout << "CODA DEI NUMERI: " << endl;
    numbers.toString();

    while (!numbers.isEmpty())
    {
        int n = numbers.getFirst();

        if (n >= 0)
        {
            positivi.enqueue(n);
            numbers.dequeue();

        }else{
            numbers.dequeue();
        }
        
    }

    cout << "CODA DEI POSITIVI: " << endl;
    positivi.toString();

    return 0;
}
