/*
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//算法:采用递归和短路特性 参数传递 真的很神奇 厉害了我的作者
class Solution {
public:
    int Sum_Solution(int n) {
        int ans=n;
        ans && (ans+=Sum_Solution(n-1));
        return ans;
    }
};
