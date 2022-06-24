#include <bits/stdc++.h>
using namespace std;


class Codec {
public:

    // Encodes a tree to a single string.

    
    string serialize(TreeNode* root) {
    	if (!root) return "N";

    	string result = "";

    	result += serialize(root->left);
    	result += serialize(root->right);

    	return result;
    }

    // Decodes your encoded data to tree.

    int idx;

    TreeNode* dfs(string s) {
    	if (idx >= s.size()) return NULL;

    	if (s[idx] == 'N') {
    		idx++;
    		return NULL;
    	}

    	node = new TreeNode(s[idx] - '0');

    	node->left = dfs(s);
    	node->right = dfs(s);

    	return node;
    }

    TreeNode* deserialize(string data) {
    	idx = 0;

    	return dfs(data);
    }
};



int main() {

}