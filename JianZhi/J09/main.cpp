#include <iostream>
#include <stack>

using namespace std;


/*
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        if(!stack_out.empty()){
            int n = stack_out.size();
            for(int i=0;i<n;++i){
                stack_in.push(stack_out.top());
                stack_out.pop();
            }
        }

        stack_in.push(value);
    }

    int deleteHead() {
        if(stack_in.empty() && stack_out.empty())
            return -1;
        if(!stack_in.empty()){
            int n=stack_in.size();
            for(int i=0;i<n;++i){
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int out = stack_out.top();
        stack_out.pop();
        return out;
    }

private:
    stack<int> stack_in,stack_out;

};


int main() {
    std::cout << "Hello, World!" << std::endl;

    CQueue q;
    q.appendTail(5);
    q.appendTail(2);
    q.appendTail(1);
    cout<<q.deleteHead()<<endl;
    cout<<q.deleteHead()<<endl;
    cout<<q.deleteHead()<<endl;


    return 0;
}
