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

    bool answer = true;

    void dfs(TreeNode* node, int rootVal) {
        if(node == nullptr) {
            return;
        }
        
        if(node->left != nullptr && node->val <= node->left->val) {
            answer = false;
        }

        dfs(node->left, rootVal);
        

        if(node->right != nullptr && node->val >= node->right->val) {
            answer = false;
        }
        dfs(node->right, rootVal);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root, root->val);

        return answer;
    }
};

// dfs를 사용해 왼쪽 갈때 부모 node랑 비교해서 맞으면 통과 아니면 false로 풀려고 했으나 부모 node보다 위에 있는 node들이 안 맞을 경우를 생각하지 못했음.

// 실패

// 시간복잡도 O(n) ?