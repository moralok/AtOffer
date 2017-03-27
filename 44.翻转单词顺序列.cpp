/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

//算法1：一个一个处理字符，牺牲了空间，换取了时间
class Solution {
public:
    string ReverseSentence(string str) {
        string res="",temp="";
        for(unsigned int i=0;i<str.size();i++){
            if(str[i]==' '){					//注意str[]是char类型
                res=" "+temp+res;
                temp="";
            }else{
                temp+=str[i];
            }
        }
        if(temp.size()) res=temp+res;			//注意衔接的顺序
        return res;
    }
};

//算法2:先整体反转，再寻找空格间单词局部反转
//学着码都能错这么多次，太垃圾了我555
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(),str.end());
        int front=0,back=0;
        int size=str.size();
        while(front<size){
            while(front<size && str[front]==' ') ++front;
            back=front;
            while(back<size && str[back]!=' ') ++back;
            reverse(str.begin()+front,str.begin()+back);
            front=back;
        }
        return str;
    }
};
