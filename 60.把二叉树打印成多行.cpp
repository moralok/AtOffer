/*
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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

//算法：与普通层序遍历类似，但在输出前，先获取队列长度用来控制每一次输出的次数
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
        	vector<vector<int> > res;
            if(!pRoot) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int begin=0,end=q.size();
                vector<int> temp;
                while(begin++<end){
                    TreeNode* node=q.front();
                    temp.push_back(node->val);
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                res.push_back(temp);
            }
            return res;
        }
    
};
