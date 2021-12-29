#include <iostream>
#include <stack>

using namespace std;

/*
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 */

/*
 * 思路：两个栈，一个栈用于实现数据，另一个保存非严格降序的数据。
 */


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stack_data.push(x);
        if(!stack_desc.empty()){
            if(x<=stack_desc.top()){
                stack_desc.push(x);
            }
        }
        else{
            stack_desc.push(x);
        }
    }

    void pop() {
        if(stack_data.top()<=stack_desc.top()){
            stack_desc.pop();
        }
        stack_data.pop();
    }

    int top() {
        return stack_data.top();
    }

    int min() {
        return stack_desc.top();
    }

private:
    stack<int> stack_data,stack_desc;
};


int main() {
    std::cout << "Hello, World!" << std::endl;




    return 0;
}
