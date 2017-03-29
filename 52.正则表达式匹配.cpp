/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str==nullptr && pattern==nullptr)
            return false;
        if(*str=='\0' && *pattern=='\0')
            return true;
        if(*str!='\0' && *pattern=='\0')
            return false;
        if(*(pattern+1)=='*'){
            /*
			      matchCore(str,pattern+2):模式串未匹配                
    		    matchCore(str+1,pattern):模式串已经匹配成功，尝试匹配下一个字符串                
    		    matchCore(str+1,pat+2)：模式串已经成功匹配，并且不匹配下一个字符串内容  
            注意这里 matchCore(str+1,pat+2)重复考虑了
            发生情况3时，可以视为发生了情况2再发生情况else
            天哪！想出来的牛人怎么将分支归纳的这么好啊
            */
            if(*str==*pattern || (*pattern=='.' && *str!='\0'))
                return match(str+1,pattern) || match(str,pattern+2);//
            else
                return match(str,pattern+2);                         
        }
        if(*str==*pattern || (*pattern=='.' && *str!='\0'))
            return match(str+1,pattern+1);
        return false;
    }
};
