/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

/*算法
采用位运算
循环整个数组异或后不为0（^位不同为1，相同则为0，相同数字异或后为0)
找到结果的二进制表示的第一个1所在的位置(与1进行&运算，不为1则用>>带符号的右移，其中&运算位都为1则为1否则为0）
再次循环，用该位置的1将数组分为两个，各含一个单独的数字，用0轮流异或后剩下的就是该数
&等优先级低位
右移运算注意赋给自己学到了好多啊 第一次用了位运算 excited！
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int size=data.size();
        if(size<2) return;
        int temp=data[0];
        for(int i=1;i<size;i++){
            temp=temp^data[i];
        }
        if(temp==0) return;
        int index=0;
        while((temp&1)==0){
            temp=temp>>1;
            ++index;
        }
        *num1=0;*num2=0;
        for(int i=0;i<size;i++){
            if(IsBit(data[i],index)){
                *num1=*num1^data[i];
            }else{
                *num2=*num2^data[i];
            }
        }
        
    }
    
    bool IsBit(int num, int index){
        num=num>>index;
        return num&1;
    }
};
