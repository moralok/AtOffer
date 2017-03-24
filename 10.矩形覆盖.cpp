/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

//算法：摆上2*1有F(n-1),摆上1*2则下面只有一种可能，F(n-2),斐波那契数列
//回过头想怎么这么奇怪，想法很棒呢！
class Solution {
public:
    int rectCover(int number) {
		if(number <= 0){
            return 0;
        }else if(number == 1){
            return 1;
        }else if(number == 2){
            return 2;
        }else{
            int prepre=1,pre=2,result=0;
            for(int i=3; i<=number; i++){
                result = prepre+pre;
                prepre = pre;
                pre = result;
            }
            return result;
        }
    }
};
