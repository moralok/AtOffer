/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。 
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/

//算法1:递归，思路清晰
//算法2:改写递归为采用栈，本质一样
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
    void Mirror(TreeNode *pRoot) {
        /*
        if(!pRoot) return;
        
        TreeNode *pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;      
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        */
        //非递归采用栈
        if(!pRoot) return;
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while(stackNode.size()){
            TreeNode *tree = stackNode.top();
            stackNode.pop();
            if(tree->left || tree->right){
                TreeNode *pTemp = tree->left;
                tree->left = tree->right;
                tree->right = pTemp;
            }
            if(tree->left) stackNode.push(tree->left);
            if(tree->right) stackNode.push(tree->right);
        }
        
    }
};
