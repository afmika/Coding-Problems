/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The input tree is guaranteed to be a binary search tree.
*/

/**
 * @author afmika
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string stringify(TreeNode* node) {
        return node == nullptr ? "?" : to_string(node->val);
    }
    
    int intify(string str) {
        return stoi(str.c_str());
    }
    
    vector<string> doSplit(string str) {
        vector<string> result;
        regex reg(",", regex_constants::ECMAScript | regex_constants::icase );
        // -1 => we tell the iterator to point AFTER the match
        sregex_token_iterator it = sregex_token_iterator(str.begin(), str.end(), reg, -1);
        sregex_token_iterator end;
        while ( it != end ) {
            result.push_back(it->str());
            ++it;
        }
        return result;
    }
    
    void bfs(vector<string>& nodes, TreeNode* root) {
        vector<TreeNode*> childs;
        nodes.push_back(stringify(root));
        childs.push_back(root);
        while (true) {
            int nullcount = 0;
            vector<TreeNode*> cur_level;
            for (auto child : childs) {
                if ( child != nullptr ) {
                    cur_level.push_back( child->left );
                    cur_level.push_back( child->right ); 
                }
            }
            
            if ( nullcount == cur_level.size() ) return;
            for (auto node : cur_level)
                nodes.push_back(stringify(node)); 
            
            childs = cur_level;
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nodes;
        bfs(nodes, root);

        string res;
        for (int i = 0; i < (int) nodes.size(); i++ ) {
            res += nodes[i];
            res += i + 1 < nodes.size() ? "," : "";
        }
    
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ( data.size() == 1 ) return nullptr;
        
        vector<string> tokens = doSplit(data);
        TreeNode* root = new TreeNode(intify(tokens[0]));
        
        vector<TreeNode*> childs;
        childs.push_back(root);
        int level = 0, cursor = 1;
        while (true) {
            vector<TreeNode*> current;
            for (auto child : childs) {
                if ( child != nullptr ) {
                    string L = tokens[cursor++];
                    string R = tokens[cursor++];
                    if ( L.compare("?") != 0 )
                        child->left = new TreeNode(intify(L));
                    if ( R.compare("?") != 0 )
                        child->right = new TreeNode(intify(R));

                    current.push_back(child->left);
                    current.push_back(child->right);
                }
            }
            
            if ( cursor + 1 >= (int) tokens.size())
                break;
            childs = current;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;