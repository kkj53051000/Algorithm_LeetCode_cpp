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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> answer;

        if(root == nullptr) {
            return {};
        }

        q.push(root);

        while(!q.empty()) {
            int qSize = q.size();

            vector<int> temp;

            for(int i = 0; i < qSize; i++) {
                TreeNode* now = q.front();

                temp.push_back(now->val);

                if(now->left) {
                    q.push(now->left);
                }

                if(now->right) {
                    q.push(now->right);
                }

                q.pop();
            }
            answer.push_back(temp);
        }

        return answer;
    }
};

// BFS를 사용해 한 줄씩 배열에 넣는다.

// 성공

// 시간복잡도 : O(n)