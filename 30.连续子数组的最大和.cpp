/*
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*/

/*
算法（动态规划，感受不出来）
sum=tempsum=a[0]开始
---sum---------a[i]---
---tempsum-----a[i]---
如果tempsum<0，则全部舍弃，另起炉灶a[i]，如果>0，要了比不要高
再与sum比较取较大值（至此，一轮较量结束，sum为老大）。
自己写了一遍思路，清晰了很多但是毛线用都没有啊，动态规划是什么翔
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty()) return 0;
        int sum=array[0],tempSum=array[0];
        for(int i=1;i<array.size();i++){
            tempSum=tempSum<0?array[i]:tempSum+array[i];
            sum=tempSum>sum?tempSum:sum;
        }
        return sum;
    }
};
