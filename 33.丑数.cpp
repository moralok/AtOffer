/*
题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/*算法动态
规划思想：
每次比较三个数字
res[t2]最小的乘2的数字,res[t3]最小的乘3的数字，res[t5]最小的乘5的数字
t2,t3,t5均从0开始，遍历产生的数字，选中的索引号+1（t2永远领先）
*/

／*
还是不太理解动态规划呢
*／

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index<=0) return 0;
        if(index==1) return 1;
        vector<int> res(index);
        res[0]=1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<index;++i){
            res[i]=min(res[t2]*2,min(res[t3]*3,res[t5]*5));
            if(res[i]==res[t2]*2) ++t2;
            if(res[i]==res[t3]*3) ++t3;
            if(res[i]==res[t5]*5) ++t5;
        }
        return res[index-1];
    }
    
    int min(int a, int b){
        return a<=b?a:b;
    }
};
