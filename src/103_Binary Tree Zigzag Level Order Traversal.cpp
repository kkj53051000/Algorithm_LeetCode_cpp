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

                if(nowDepth % 2 == 0) {
                    if(now->right) {
                        que.push(now->right);
                        nowValueList.push_back(now->right->val);
                    }
                    if(now->left) {
                        que.push(now->left);
                        nowValueList.push_back(now->left->val);
                    }
                }else {
                    if(now->left) {
                        que.push(now->left);
                        nowValueList.push_back(now->left->val);
                    }
                    if(now->right) {
                        que.push(now->right);
                        nowValueList.push_back(now->right->val);
                    }
                }
            }

            answer.push_back(nowValueList);
        }

        return answer;
    }
};

// BFS를 사용해 Depth를 이용해 짝수면 오른쪽부터 탐색 홀수면 왼쪽부터 담색해서 배열에 넣어준다.

// 실패
// Line 37: Char 29: runtime error: member access within null pointer of type 'TreeNode' (solution.cpp)

// 시간복잡도 O(n)