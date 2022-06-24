#include <bits/stdc++.h>
using namespace std;


struct Node {
	int val;
	struct Node* left;
	struct Node* right;

	Node (int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

struct Info {
	int num_bst, max, min;
	bool is_bst;
};


Info countMaxBST(Node* node) {

	if (!node) return {0, INT_MIN, INT_MAX, false};

	if (node->left == NULL && node->right == NULL) return {1, node->val, node->val, true};

	Info left = countMaxBST(node->left);
	Info right = countMaxBST(node->right);

	Info bst;
	bst.min = min(node->val, min(left.min, right.min));
	bst.max = max(node->val, max(left.max, right.max));

	if (left.is_bst && right.is_bst && node->val > left.max && node->val < right.min) {
		bst.is_bst = true;
		bst.num_bst = 1 + left.num_bst + right.num_bst;
	}
	else {
		bst.is_bst = false;
		bst.num_bst = left.num_bst + right.num_bst;
	}

	return bst;
}



int main() {
	Node* node = new Node(5);
    node->left = new Node(9);
    node->right = new Node(3);
    node->left->left = new Node(6);
    node->right->right = new Node(4);
    node->left->left->left = new Node(8);
    node->left->left->right = new Node(7);

    Info result = countMaxBST(node);

    cout << result.num_bst << endl;

    return 0;
}