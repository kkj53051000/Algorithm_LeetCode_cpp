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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;

        q.push(root);

        int sum = 0;

        while(q.size() != 0) {

            int qSize = q.size();

            for(int i = 0; i < qSize; i++) {
                TreeNode* nowNode = q.front();
                if(nowNode->val >= low && nowNode->val <= high) {
                    sum += nowNode->val;
                }
                q.pop();

                if(nowNode->val >= low && nowNode->left) {
                    q.push(nowNode->left);
                }

                if(nowNode->val <= high && nowNode->right) {
                    q.push(nowNode->right);
                }
            }
        }

        return sum;
    }
};

// BFS
// 현재 Node의 값이 low보다 같거나 크면 q.push(left)
// 현재 Node의 값이 high보다 같거나 작으면 q.push(right)

// 성공

// 시간복잡도 : O(logN)