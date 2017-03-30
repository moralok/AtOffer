/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

//算法1:
/*
算法2:作者的另一个解法
最后的位运算很巧妙啊
class Solution {    
    vector<int> v;    
    int n;public:    
    void Insert(int num){        
        v.push_back(num);        
        n = v.size();        
        for(int i = n - 1; i > 0 && v[i] < v[i - 1]; --i) 
            swap(v[i], v[i - 1]);     
    }
    double GetMedian(){       
        return (v[(n - 1) >> 1] + v[n >> 1]) / 2.0;    
    }
};
*/
class Solution {
    priority_queue<int,vector<int>,less<int>> p;
    priority_queue<int,vector<int>,greater<int>> q;//排序方式别忘了
public:
    void Insert(int num)						   //less为小顶堆，队头最大
    {
        if(p.empty() || num<=p.top()) p.push(num);
        else q.push(num);
        if(p.size()==q.size()+2){
            q.push(p.top());
            p.pop();
        }
        if(p.size()+1==q.size()){
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
    	return p.size()==q.size()?(p.top()+q.top())/2.0:p.top();
    }

};
