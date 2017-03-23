/*
题目描述
在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

/*
算法
1.评论说这是hash表？
散列表（Hash table，也叫哈希表），是根据关键码值(Key value)而直接进行访问的数据结构。
也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。
这个映射函数叫做散列函数，存放记录的数组叫做散列表。

2.数组的索引可以采用字符而不需要什么处理？
遍历字符串，记录每种字符的个数
再次遍历返回第一个数量为1的字符所在位置（即索引）

3.遍历字符串采用for length还是while ‘\0'更好呢？

interesting！excited！
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length()==0)return -1;
        unsigned int hash[256]={0};
        for(int i=0;i<str.length();++i){
            hash[str[i]]++;
        }
        for(int i=0;i<str.length();++i){
            if(hash[str[i]]==1)
                return i;
        }
        return -1;
    }
};
