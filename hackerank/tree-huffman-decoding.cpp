/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
// https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
void decodeHuffDfs (node *root, node *curr, string &s, string &res, int idx) {
    if (idx > s.size()) return;
    char c = s[idx];
    bool isLeaf = true;
    if (curr->left != nullptr ) {
        if (c == '0')
            decodeHuffDfs(root, curr->left, s, res, idx + 1);   
        isLeaf = false; 
    }
    if (curr->right != nullptr) {
        if (c == '1')
            decodeHuffDfs(root, curr->right, s, res, idx + 1); 
        isLeaf = false; 
    }
    
    // leaf
    if (isLeaf) {
        res += curr->data;
        decodeHuffDfs (root, root, s, res, idx);    
    }
}

void decode_huff(node *root, string s) {
    string res = "";
    decodeHuffDfs (root, root, s, res, 0);
    cout << res;
}