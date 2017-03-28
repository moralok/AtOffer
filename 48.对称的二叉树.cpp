/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

//算法：递归。如果根空则为true；
//否则判断左右结点：两者为空true；两者都不为空则判断值 是否相等&&1左子树和2右子树镜像&&1右子树和2左子树镜像
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(pRoot==nullptr) return true;
        return isSame(pRoot->left,pRoot->right);
    }

    bool isSame(TreeNode* p1, TreeNode* p2){
        if(p1==nullptr && p2==nullptr) return true;
        if(p1!=nullptr && p2!=nullptr){
            return p1->val==p2->val 
                && isSame(p1->left,p2->right) 
                && isSame(p1->right,p2->left);
        }
        return false;		//这都差点忘了。。。还放到了下一行。。。理解不到位
    }
};
