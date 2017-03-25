/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

//算法：用队列，将根节点进栈，不为空时出栈取值，左右结点轮流进栈
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        res.clear();
		if(root==nullptr) return res;
        queue<TreeNode*> qNode;
        qNode.push(root);
        while(!qNode.empty()){
            TreeNode *temp=qNode.front();
            res.push_back(temp->val);            
            if(temp->left) qNode.push(temp->left);
            if(temp->right) qNode.push(temp->right);
            qNode.pop();
        }
        return res;
    }
};
