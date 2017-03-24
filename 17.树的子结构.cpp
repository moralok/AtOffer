/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
算法（递归）
再想一遍还是会晕呢
1.先判断根结点是否都存在，否则false
2.如果都存在，判断是否为子结构，不是则递归到A树左右孩子结点判断  	（||是关键）
3.判断方法：递归，B树空true，A树空false，判断左右结点值是否相等	   （&&是关键）
*／
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
