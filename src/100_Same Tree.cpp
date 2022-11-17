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
    bool dfs(TreeNode* node1, TreeNode* node2) {

        if(node1 == nullptr && node2 == nullptr) {
            return true;
        }
        if(node1 == nullptr || node2 == nullptr) {
            return false;
        }
        if(node1->val != node2->val) {
            return false;
        }

        return dfs(node1->left, node2->left) && dfs(node1->right, node2->right);
        
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {


        return dfs(p, q);
    }
};

// 둘다 null인지 비교 return true
// 한개만 null 인지 비교 return false 
// 두개 값이 다른지 비교 return false

// 성공

// 시간 복잡도 : O(n)