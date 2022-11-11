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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        int sum = 0;

        que.push(root);

        while(!que.empty()) {
            sum = 0;

            int queSize = que.size();
           
            for(int i = 0 ; i < queSize; i++) {

                sum += que.front()->val;

                TreeNode* left = que.front()->left;
                TreeNode* right = que.front()->right;

                if(left) {
                    que.push(left);
                }
                if(right) {
                    que.push(right);
                }

                que.pop();
            }
        }

        return sum;
        
    }
};

// BFS 1 Depth씩 탐색하다 마지막 Depth 값을 return 해줍니다.

// 성공

// 시간 복잡도 O(n)