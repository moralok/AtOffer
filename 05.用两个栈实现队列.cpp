/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//算法1：栈1作为队列入口，栈2作为出口，空则栈1倒入栈2，有则可以pop
//注意：top返回值，STL中pop弹出并不返回值

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.empty() && stack2.empty()){
            return -1;
        }
        int a;
        if(stack2.empty()){
            while(!stack1.empty()){
                a=stack1.top();
                stack2.push(a);
                stack1.pop();
            }
        }
        a=stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
