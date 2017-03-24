/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

/*
算法1:
1.使用两个栈，一为数据存储二为存储更小值
2.pop时比较判断是否弹出最小值
3.最小值取二栈的top
算法2:未出现更小值时push原先最小值，则可以同步弹出
*／
class Solution {
    stack<int> dataStack;
    stack<int> minStack;
public:
    void push(int value) {
        dataStack.push(value);
        if(!minStack.empty()){
            int temp = minStack.top();
            if(value<temp){
                minStack.push(value);
            }
        }else{
            minStack.push(value);
        }
        
    }
    void pop() {
        int res=dataStack.top();
        int minNum=minStack.top();
        if(res==minNum) minStack.pop();
        dataStack.pop();   
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
};
