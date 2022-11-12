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
    
    int sum = 0;
    bool answer = false;
    
    void dfs(TreeNode* node, int targetSum) {        
        
        if(node == nullptr) {
            return;
        }
        
        sum += node->val;   
        
        if(!node->left && !node->right && sum == targetSum) {
            answer = true;
        }
        
        dfs(node->left, targetSum);
        dfs(node->right, targetSum);
        
        sum -= node->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) {
            return false;
        }

        dfs(root, targetSum);
      
        return answer;
    }
};

// root포함 내려갈때마다 노드 값 sum에 더해줌 -> (아래 아무것도 없고 && sum == targetSum) 검사 0 -> 올라갈때 노드 값 빼줌

// 성공 (한두개 케이스에 막혀서 시간이 오래걸려 다른 문제 참고)

// 시간복잡도 : O(n)