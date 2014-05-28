/*
As the title described, you should only use two stacks to implement a queue's actions. The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue. Both pop and top methods should return the value of first element.
Example
For push(1), pop(), push(2), push(3), top(), pop(), you should return 1, 2 and 2
*/
#include <stack>

using namespace std;

class Queue {
  public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    int pop() {
        // write your code here
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

    int top() {
        // write your code here
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }
};
