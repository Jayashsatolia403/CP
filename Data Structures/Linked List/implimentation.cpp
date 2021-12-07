#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i=0; i < n; i++)

#define ll long long



struct Node {
    int val;
    struct Node* next;

    Node (int data) {
        val = data;
        next = NULL;
    }
};





void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

Node* stringToNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    Node* dummyRoot = new Node(0);
    Node* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new Node(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(Node* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

int main() {
    struct Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);

    prettyPrintLinkedList(root);
    
    return 0;
}