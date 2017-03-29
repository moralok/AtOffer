/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

/*
有更加机智的一个公式法呢看懂了下面才明白
唉！没胆思考的蠢猫
class Solution {
public:    
    int NumberOf1Between1AndN_Solution(int n){ 
        int ones = 0;        
        for (long long m = 1; m <= n; m *= 10)            
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);         
        return ones;         
    }
};
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int exp=1;
    	int res=0;									//假设abcde 目标位是c
        while(n/exp){
            res+=n/(exp*10)*exp;					//目标位以上的0-ab-1（必定小于xx999）ab*（0-99）
            if(n/exp%10>1) res+=exp;				//目标位以上为ab，c>1,则c=1时，目标位以下可取0-99
            else if(n/exp%10==1) res+=(n%exp+1);	//目标位以上为ab，c=1，则目标位以下可取0-de
            exp*=10;
        }
        return res;
    }
};
