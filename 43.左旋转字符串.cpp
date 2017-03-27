/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

//算法1：先补上原本的string，取出其子串，C++中第二个参数是长度，Java中是位置
//注意：n对len取余
//第一次使用substr函数呢！
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.length();
        if(len==0) return "";
        n=n%len;
        str+=str;
        return str.substr(n,len);
    }
};

//算法2:很机智的算法啊，用reverse函数颠倒顺序
//问题1:作者说C++中迭代器区间都是左开右闭，那 end指的是哪里（据说C++的string结尾都是有\0结尾的）
//问题2:n>length考虑了吗
class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};
