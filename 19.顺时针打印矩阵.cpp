/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*算法：
1.确定m，n以及相对较小者（循环次数）
2.注意控制循环边界和元素的下标转换
*／
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
        res.clear();
        if(matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int circle = ((m<n?m:n)-1)/2+1;
        for(int i=0;i<circle;i++){
            for(int j=i;j<n-i;j++){
                res.push_back(matrix[i][j]);
            }
            for(int j=i+1;j<m-1-i;j++){
                res.push_back(matrix[j][n-1-i]);
            }
            for(int j=n-1-i;j>=i && (i!=m-1-i);j--){
                res.push_back(matrix[m-1-i][j]);
            }
            for(int j=m-2-i;j>i && (i!=n-1-i);j--){
                res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};
