/*
题目描述
统计一个数字在排序数组中出现的次数。
*/

/*
算法
二分法查找
如果找到k，向下找到k前1个，向后找到k后1个，last-first-1
如果找不到,返回last-first-1和0的较大值或者初始化时last-first=1
注意：while里加了越界判断跳出，评论里有人提到while里数组不会越界（原先没加正确，不知道是测试用例没有还是怎么回事）
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int length=data.size();
        if(length==0) return 0;
        int begin=0,end=length-1,mid;
        int res=0,first=0,last=0;
        while(begin!=end){
            mid=(begin+end)/2;
            if(data[mid]<k){
                begin=mid+1;
            }else if(data[mid]>k){
                end=mid-1;
            }else{
                res=first=last=mid;
                break;
            }
        }
        while(data[first]==k){
            first--;
            if(first==-1)break;
        }
        while(data[last]==k){
            last++;
            if(last==length)break;
        }
        return (last-first-1)<=0?0:(last-first-1);
        
    }
};
