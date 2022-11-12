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

    bool isFirst = false;

    int maxDepth(TreeNode* root) {

        if(root == nullptr) {
            return 0;
        }

        if(isFirst) {
            if(root->left && !root->right) {
            return maxDepth(root->left) + 1;
            }

            if(!root->left && root->right) {
                return maxDepth(root->right) + 1;
            }

            if(!root->left && !root->right) {
                return 1;
            }
        }else {
            isFirst = true;
        }
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 성공

// 시간복잡도 O(n)