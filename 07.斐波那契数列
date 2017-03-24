/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/

//算法：递归时间复杂度太高，数组空间复杂度太高，动态规划好
//不知道什么叫做动态规划
class Solution {
public:
    int Fibonacci(int n) {
		if(n<=1){
            return n;
        }
        int prepre=0,pre=1,result=0;
        for(int i=2;i<=n;i++){
            result=pre+prepre;
            prepre=pre;
            pre=result;
        }
        return result;
    }
};
