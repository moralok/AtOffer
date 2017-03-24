/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

//算法：F(n)=F(n-1)+...+F(1)=2*F(n-1) hhh后面这个我看了讨论才发现
class Solution {
public:
    int jumpFloorII(int number) {
		if(number<=0){
            return -1;
        }else if(number==1){
            return 1;
        }else if(number==2){
            return 2;
        }else{
            int result=0;
            for(int i=number-1;i>=1;i--){
                result=result+jumpFloorII(i);
            }
            return result+1;
        }
    }
};
