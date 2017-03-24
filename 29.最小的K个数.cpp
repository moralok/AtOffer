/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
*/

//算法1:直接使用vector的sort函数，插入另一个vector中。时间复杂度O（nlogn）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int size=input.size();
        if(size==0 || k>size) return res;
        sort(input.begin(),input.end());
        for(int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
};
//算法2:冒泡排序。时间复杂度O（k*n）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int size=input.size();
        if(size==0 || k>size) return res;
        for(int i=0;i<k;i++){
            for(int j=size-1;j>=1;j--){
                if(input[j]<input[j-1]){
                    int temp=input[j];
                    input[j]=input[j-1];
                    input[j-1]=temp;
                }
            }
        }
        for(int i=0;i<k;i++){
           	res.push_back(input[i]);
       	}
        return res;
        
    }
};
