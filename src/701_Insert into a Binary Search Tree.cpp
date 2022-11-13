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
    TreeNode* insertIntoBST(TreeNode* root, int val) {


        if(root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* bst = root;

        while(bst != nullptr) {

            int nowVal = bst->val;

            if(nowVal > val) {
                if(bst->left != nullptr) {
                    bst = bst->left;
                } else {
                    bst->left = new TreeNode(val);
                    break;
                }
            }
            
            if(nowVal < val) {
                if(bst->right != nullptr) {
                    bst = bst->right;
                } else {
                    bst->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

// val과 현재 node를 비교하면서 오른쪽 또는 왼쪽으로 이동합니다. > 값이 null이면 new TreeNode(val) 을 넣어주고 while문을 종료시킵니다.

// 성공

// 시간 복잡도 O(logN)