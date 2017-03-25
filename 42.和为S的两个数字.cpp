/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

//算法：原本想两头缩进，但没想到怎么实现，只能变成这样嵌套循环
/*
别人就很机智啊，不拿笔模拟的后果就是不知道怎么实现，笨蛋！
写得真好！
typedef vector<int> vi;
class Solution {
public:    
        vi FindNumbersWithSum(const vi& a,int sum) {
            vi res;        
            int n = a.size();        
            int i = 0, j = n - 1;        
            while(i < j){            
                if(a[i] + a[j] == sum){                
                    res.push_back(a[i]);                
                    res.push_back(a[j]);                
                    break;            
                }            
                while(i < j && a[i] + a[j] > sum) --j;            
                while(i < j && a[i] + a[j] < sum) ++i;        
            }        
            return res;    
        }
};
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int i,size=array.size();
        for(i=0;i<size-1;i++){
            for(int j=size-1;j>i&&(array[i]+array[j])>=sum;j--){
                if((array[i]+array[j])==sum){
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    return res;
                }
            }
        }
        return res;
    }
};
