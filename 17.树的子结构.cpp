/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

//算法
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
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2==nullptr) return true;
        if(pRoot1==nullptr) return false;
        if(pRoot1->val==pRoot2->val){
            return IsSubtree(pRoot1->left,pRoot2->left)
                && IsSubtree(pRoot1->right,pRoot2->right);
        }else return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(pRoot1==nullptr || pRoot2==nullptr){
            return false;
        }else{
            return IsSubtree(pRoot1, pRoot2)
                || HasSubtree(pRoot1->left, pRoot2)
                || HasSubtree(pRoot1->right, pRoot2);
        }
    }
};
