/*
题目描述
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

/*
算法
递归思想
等于左子树深度和右子树深度的较大值+1
递归好不好嘞 应该好吧
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==nullptr) return 0;
        int leftDepth=TreeDepth(pRoot->left);
        int rightDepth=TreeDepth(pRoot->right);
        return leftDepth>=rightDepth?leftDepth+1:rightDepth+1;
    }
};
