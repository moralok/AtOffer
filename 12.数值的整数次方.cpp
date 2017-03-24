/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

/**
算法（情不自禁把别人思路粘贴过来了会不会不太好）
* 1.全面考察指数的正负、底数是否为零等情况。 
* 2.写出指数的二进制表达，例如13表达为二进制1101。 
* 3.举例:10^1101 = 10^0001*10^0100*10^1000。 
* 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
*/

//第一次知道了快速幂，又叫二分求幂的做法O(log₂N)

class Solution {
public:
    double Power(double base, int exponent) {
    	double res=1,cur=base;
        int n;
        if(exponent>0){
            n=exponent;
        }else if(exponent<0){
            if(abs(base)<1e-15){
                return 0;
            }
            n=-exponent;
        }else{
            res=1;				//0的0次方定义为1
        }
        while(n!=0){
            if((n&1)==1){
                res*=cur;
            }
            cur*=cur;			//基数翻倍
            n=n>>1;				//右移一位     哇 每次右移都忘记赋值给自己了
        }
        return exponent>=0?res:1/res;
    }
};
