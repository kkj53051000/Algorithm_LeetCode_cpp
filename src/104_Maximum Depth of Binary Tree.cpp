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

    
    int dfs(TreeNode* node) {
        
       if(node != nullptr) {
           return max(dfs(node->left), dfs(node->right))+1;
       }
        
        return 0;
    }
        
        
    
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};

// 매번 왼쪽 오른쪽의 depth 비교해서 높은쪽 +1 return (다른 코드 참고)

// 성공

// 시간복잡도 O(n)