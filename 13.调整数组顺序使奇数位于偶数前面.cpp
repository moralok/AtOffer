/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
算法1：创建一个数组重新存储，最后赋值给原来的数组
算法2：插入排序，两个指针，整体后移，时间复杂度增加
算法3：删除偶数，push_back
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int oddNum=0,evenNum=0,length=array.size();
        for(int i=0;i<length;i++){				          //获得奇偶个数
            if((array[i]&1)==1){
                oddNum++;
            }else{
                evenNum++;
            }
        }
        vector<int> copyArray(length);
        int j=0,k=oddNum;
        for(int i=0;i<length;i++){
            if((array[i]&1)==1){
                copyArray[j]=array[i];
                j++;
            }else{
                copyArray[k]=array[i];
                k++;
            }
        }
        array=copyArray;				                    //经测试 可以整体赋值
    }
};

