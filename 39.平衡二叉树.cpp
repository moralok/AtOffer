/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
算法 
通过递归返回左右子树的深度，返回前判断左右子树的深度差
是否平衡的变量是否必须设置在最前面？
*/
class Solution {
    
public:
    bool isBalanced=true;
    bool IsBalanced_Solution(TreeNode* pRoot) {
		getDepth(pRoot);
        return isBalanced;
    }
    
    int getDepth(TreeNode* Root){
        if(Root==nullptr) return 0;
        int leftDepth=getDepth(Root->left);
        int rightDepth=getDepth(Root->right);
        if(abs(leftDepth-rightDepth)>1) isBalanced=false;
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }
};
