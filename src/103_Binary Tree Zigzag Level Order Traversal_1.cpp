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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        if(root == nullptr) {
            return {};
        }

        vector<vector<int>> answer;

        queue<TreeNode*> que;

        que.push(root);

        int nowDepth = 1;

        while(!que.empty()) {

            nowDepth++;
            
            int queSize = que.size();

            vector<int> nowValueList;

            for(int i = 0; i < queSize; i++) {

                TreeNode* now = que.front();
                que.pop();

                nowValueList.push_back(now->val);

                if(now->left) {
                    que.push(now->left);
                }
                if(now->right) {
                    que.push(now->right);
                }
            }

            if(nowDepth % 2 != 0) {
                reverse(nowValueList.begin(), nowValueList.end());
            }

            answer.push_back(nowValueList);
        }

        return answer;
    }
};

// BFS로 Depth를 이용해 홀수는 reverse를 해서 배열에 넣어준다.

// 성공

// 시간복잡도 O(n)