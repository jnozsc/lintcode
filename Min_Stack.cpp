/*
Implement a stack with min() function, which will return the smallest number in the stack. It should support push, pop and min operation all in O(1) cost.
Note
min operation will never be called if there is no number in the stack
Example
Operations: push(1), pop(), push(2), push(3), min(), push(1), min()
Return: 1, 2, 1
*/
#include <stack>

using namespace std;

class MinStack {
  public:
    stack<int> mainStack;
    stack<int> secondStack;

    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if (secondStack.empty() || number <= secondStack.top()) {
            secondStack.push(number);
        }
        mainStack.push(number);
    }

    int pop() {
        // write your code here
        if (!secondStack.empty() && secondStack.top() == mainStack.top()) {
            secondStack.pop();
        }
        int result = mainStack.top();
        mainStack.pop();
        return result;
    }

    int min() {
        // write your code here
        return secondStack.top();
    }
};
