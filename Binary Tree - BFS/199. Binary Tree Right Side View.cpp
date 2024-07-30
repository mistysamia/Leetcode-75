/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;

        if (!root)
            return vec; 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size() , rightmostVal;

            for (int i = 0; i < levelSize; i++) 
            {
                TreeNode* node = q.front();
                q.pop();
                rightmostVal = node->val;
                if (node->left)
                    q.push(node->left);
            
                if (node->right)
                    q.push(node->right);
            }
            vec.push_back(rightmostVal);
        }

        return vec;
    }
};