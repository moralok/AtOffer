/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

//算法：找到规律F(n)=F(n-1)+F(n-2) 斐波那契数列，动态规划
class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0){
            return -1;
        }else if(number==1){
            return 1;
        }else if(number==2){
            return 2;
        }else{
            int prepre=1,pre=2,result=0;
            for(int i=3;i<=number;i++){
                result=prepre+pre;
                prepre=pre;
                pre=result;
            }
            return result;
        }
    }
};
