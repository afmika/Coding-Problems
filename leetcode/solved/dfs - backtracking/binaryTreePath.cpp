/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

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
    
    bool hasChild (TreeNode* node) {
        return node != nullptr && (node->left != nullptr || node->right != nullptr);
    }
    
    void solve(set<string>& sol, string current, TreeNode* node, bool has_child) {

        if ( node == nullptr ) {
            if ( !has_child  )
                sol.insert(current);
            return;
        }
        
        string pref = current.compare("") == 0 ? "" : "->";
        current += pref + to_string(node->val);

        solve(sol, current, node->left, hasChild(node));
        solve(sol, current, node->right, hasChild(node));               
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if ( root == nullptr )
            return vector<string>{};
        set<string> sol;
        solve(sol, "", root, hasChild(root));
        
        vector<string> result(sol.begin(), sol.end());
        return result;
    }
	
	
	void dfs(vector<string> str) {
		
	}
};