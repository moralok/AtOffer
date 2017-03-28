/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/


//知道了中序遍历找下一个结点的方式了呢
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr) return nullptr; 		//结点为空
        if(pNode->right){						//有右孩子，下个节点为右子树的最左边
            pNode=pNode->right;					
            while(pNode->left)
                pNode=pNode->left;
            return pNode;
        }
        while(pNode->next){            			//没有右孩子，上循父结点直到为某结点的左孩子
            if(pNode==pNode->next->left)
                return pNode->next;				//注意返回的是其父结点
            pNode=pNode->next;
        }
        return nullptr;
    }
};
