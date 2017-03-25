/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

//算法：
//根据数学公式计算:(a1+an)*n/2=s  n=an-a1+1       
//(an+a1)*(an-a1+1)=2*s=k*l(k>l)       
//an=(k+l-1)/2  a1=(k-l+1)/2
//注意：公式写错一次，sum<3未判断，找因数时起始位置错误，上界s取值错误
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3) return res;
        int s=sqrt(2*sum);
        int a1,an;
        for(int i=s;i>=2;i--){
            if(2*sum%i==0){
                int d=2*sum/i;
                if((i%2==0 && d%2!=0) || (i%2!=0 && d%2==0)){
                    a1=(d-i+1)/2;
                    an=(d+i-1)/2;
                    vector<int> temp;
                    for(int j=a1;j<=an;j++){
                        temp.push_back(j);
                    }
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
