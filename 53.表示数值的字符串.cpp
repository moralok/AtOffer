/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

//错了好多次，不能用size！！！先++判断！！！判断e的时候要用+1不能用++！！！
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string[0]=='\0') return false;							//字符串为空
        if(string[1]=='\0' && !(string[0]>='0' && string[0]<='9'))	//长度为1，必须为数字
                return false;
        int exp=1,point=1;											//e、E、.最多只能有一个
        int i=0;
        while(string[++i]!='\0'){
            if(string[i]>='0' && string[i]<='9')					//如果遇到数字继续循环
                continue;
            if(string[i]=='.' && point==1){							//第一次遇上.继续
                point--;
                continue;
            }
            if((string[i]=='e' || string[i]=='E') && exp==1){		//第一次遇上e或E
                exp--;
                if(string[i+1]=='+' || string[i+1]=='-' || (string[i+1]>='0' && string[i+1]<='9')){	
                    i++;											//检验下一个字符的合法性
                    point--;										//小数点失去出现的机会
                    continue;
                }
                return false;
            }
            return false;
        }
        return true;
    }
};
