#include "Stack.h"

int main(){

    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    s.toString();

    s.pop();

    s.toString();

    std::cout << s.getTop() << std::endl;

    return 0;
}