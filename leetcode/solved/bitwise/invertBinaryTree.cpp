/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
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
    vector<TreeNode*> getChilds(TreeNode* root) {
        vector<TreeNode*> childs;
        if ( root->left != nullptr) childs.push_back( root->left );
        if ( root->right != nullptr) childs.push_back( root->right );
        return childs;
    }
    
    void swapChild(TreeNode* root) {
        TreeNode* temp_right = root->right;
        root->right = root->left;
        root->left = temp_right;
    }
    
    void bfsSwap(TreeNode* root) {
        bool first_call = true;
        vector<TreeNode*> childs;
        while ( true ) {
            
            if ( first_call ) {
                first_call = false;
                swapChild( root );
                childs = getChilds( root );
            }
            
            vector<TreeNode*> cur_child;
            for ( auto child : childs ) {
                swapChild( child );
                vector<TreeNode*> temp = getChilds( child );
                for ( auto ch_child : temp ) cur_child.push_back( ch_child );
            }
            childs = cur_child;
            
            if ( cur_child.size() == 0 )
                return;           
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        bfsSwap(root);
        return root;
    }
};