/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

//算法：编写比较函数对数组进行排序，遍历输出
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty()) return "";
        sort(numbers.begin(),numbers.end(),cmp);
        string ans="";
        for(int i=0;i<numbers.size();i++){
            ans+=to_string(numbers[i]);
        }
        return ans;
    }
    
    static bool cmp(int a,int b){
        string A="";
        string B="";
        A=A+to_string(a)+to_string(b);
        B=B+to_string(b)+to_string(a);
        return A<B;
    }
};
