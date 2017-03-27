/*
题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
*/

//好烦哦！好不容易感觉做出一个不错的算法，发现是误打误撞，而且是错的（0 0 1 3 4）
//修改：控制了下标的上限 最后的判断条件修改为>=0
//算法：vector排序后，从最小开始，下一个若+1则OK；否则牺牲一个0；
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5) return false;
        sort(numbers.begin(),numbers.end(),cmp);
        int count_0=0;
        for(int i=0;i<5;i++){
            if(numbers[i]<0 || numbers[i]>13) return false;
            if(numbers[i]==0) count_0++;           
        }
        int temp=numbers[count_0];
        for(int i=1;i<5;i++){
            
            if(count_0+i<=4 && temp+i!=numbers[count_0+i]) count_0--;
        }
        if(count_0>=0) return true;
        else return false;
    }
    
    static bool cmp(int a,int b){
        return a<b;
    }
};
