/*
题目描述
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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

/*
算法：使用两个栈轮流存储对方出栈时的子结点，则下一轮出栈顺序相反。用vector记录
*/

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        stack<TreeNode*> stack1,stack2;
        TreeNode* node;
        if(pRoot) stack1.push(pRoot);
        while(!stack1.empty() || !stack2.empty()){
            vector<int> temp;
            if(!stack1.empty()){
                while(!stack1.empty()){               
                	node=stack1.top();
                	temp.push_back(node->val);
                	stack1.pop();
                	if(node->left) stack2.push(node->left);
                	if(node->right) stack2.push(node->right);                                
            	}
            }else if(!stack2.empty()){
                while(!stack2.empty()){               
                	node=stack2.top();
                	temp.push_back(node->val);
                	stack2.pop();
                    if(node->right) stack1.push(node->right);
                	if(node->left) stack1.push(node->left);                	                                
            	}                
            }
            res.push_back(temp);
        }
        return res;
    }   
};
