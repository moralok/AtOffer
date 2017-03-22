/**
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/**
算法
阵地攻守思想：
如果无人防守，新人成防守
如果攻守双方相同，count++
如果不同，count--
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int length=numbers.size();
        if(length==0) return 0;
        int guard=numbers[0],count=1;
        for(int i=1;i<length;i++){
            if(guard==numbers[i]){
                count++;
            }else if(count != 0){
                count--;
            }else{
                guard=numbers[i];
                count++;
            }
        }
        count=0;
        for(int i=0;i<length;i++){
            if(guard==numbers[i]){
                count++;
            }
        } 
        if(2*count>length){
            return guard;
        }else{
            return 0;
        }
    }
};
