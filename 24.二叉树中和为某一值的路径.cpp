/*
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
//参见原作者Java版本有些疑问（测试通过）
//res和temp的作用域？（全局）
//每次递归都重新创建吗？（不会，在函数体之外）
//push_back传的是引用还是内容？（vector传的是内容不是副本，Java的Array是引用）

class Solution {
    vector<vector<int> > res;
    vector<int> temp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {     
		if(!root)return res;
        temp.push_back(root->val);
        if(expectNumber-root->val==0 && !root->left && !root->right){		//满足的条件
            res.push_back(temp);                
        }
        if(expectNumber-root->val>0){										//避免不满足时递归到底
            if(root->left) FindPath(root->left,expectNumber-root->val);		//孩子结点不为空时操作
            if(root->right) FindPath(root->right,expectNumber-root->val);
        }
        temp.pop_back();													//返回时删除上一个结点
        return res;
    }
};
