/*
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0 
输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0
*/

//算法：判定开头合法性并定正负，根据开头决定转换的开头，位运算或者乘加（在循环里很巧妙啊）
/*
别人家的简洁
s Solution {
    public:    
        int StrToInt(string str) {        
            int res = 0, n = str.size(), s = 1;        
            if(!n) return 0;        
            if(str[0] == '-') s = -1;        
            for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){           
                if(!('0' <= str[i] && str[i] <= '9')) return 0;           
                res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';          
            }          
            return res * s;
*/
class Solution {
public:
    int StrToInt(string str) {
        int res=0;
        int flag=1;
        int size = str.size();
        int i=0;
        if(str[0]=='+'){
            i=1;
        }
        if(str[0]=='-'){
            flag=-1;
            i=1;
        }        
        if(size==0) return 0;
        for(i;i<size;i++){            
            if(str[i]<'0' || str[i]>'9') return 0;
            res=(res<<1)+(res<<3)+(str[i]&0xf);     //好腻害  
        }
        return res*flag;    
    }
};
