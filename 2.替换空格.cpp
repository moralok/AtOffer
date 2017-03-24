/*
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

//算法：首先统计空格数目并确定替换后字符串长度，从后往前查找空格并后移替换，避免反复移动元素
class Solution {
public:
	void replaceSpace(char *str,int length) {
		int i=0, spaceNum=0, oldLength=0;
        if(str == NULL || length < 0){
            return;
        }
        while(str[i] != '\0'){
            if(str[i] == ' '){
                spaceNum++;
            }
            i++;
            oldLength++;
        }
        int newLength = oldLength + spaceNum*2;
        if(newLength > length){
            return;
        }
        while(oldLength >= 0 && newLength > oldLength){
            if(str[oldLength] == ' '){
                str[newLength--] = '0'; 
                str[newLength--] = '2'; 
                str[newLength--] = '%'; 
            }
            else{
                str[newLength--] = str[oldLength];
            }
            oldLength--;
        }
	}
};
