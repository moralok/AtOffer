/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*
算法
1.注意，如果与1做&运算，再>>右移将导致错误，因为补上的负数的符号为1
2.如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，
原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。与自身做&运算将消除最后一个1
3.>>>带符号位右移，C++好像不能用
4.flag=1，左移做&运算
private static int NumberOf1_low(int n) {        
    int count = 0;        
    int flag = 1;        
    while (flag != 0) {            
        if ((n & flag) != 0) {
        count++;            
        }            
        flag = flag << 1;        
    }        
    return count;    
}
*/

/*
还以为自己会了，回来做这题还是跪了。too young too simple
----------------号称最优解----------------
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         while(n!=0){
            count++;
         	n=n&(n-1);
         }
         return count;
     }
};
