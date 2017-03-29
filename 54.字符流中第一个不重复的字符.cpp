/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

//算法1:第一次使用map，记录ch出现的次数，vector记录输入的字符流，可以用string代替
//算法2:采用简易hash表 hash[256]可以实现相同原理
/*
算法3:以下可忽略记录字符流的vector，用queue保留输入一次字符，当front大于1次的话pop
改进了FirstAppearingOnce()的时间复杂度
class Solution
{
    map<char,int> count;
    vector<char> input;
    queue<char> record;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        input.push_back(ch);       
        count[ch]++;        			//注意map的用法count[]，第一次加入就可以自动初始化为0
        if(count[ch]==1)
            record.push(ch);
        while(count[record.front()]>1)
            record.pop();
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	if(record.empty())
        	return '#';
        return record.front();
    }
};
*/
class Solution
{
    map<char,int> count;
    vector<char> input;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        input.push_back(ch);
        count[ch]++;        			//注意map的用法count[]
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(unsigned int i=0;i<input.size();i++){
            if(count[input[i]]==1)
                return input[i];
        }
        return '#';
    }
};
