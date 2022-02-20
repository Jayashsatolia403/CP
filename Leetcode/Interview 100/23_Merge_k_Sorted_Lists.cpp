#include <bits/stdc++.h>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
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








class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.empty()) return NULL;


        ListNode* prev = NULL;

        for (int i=0; i < lists.size(); i++) {
        	ListNode* result = new ListNode(0);
        	ListNode* node = result;
        	ListNode* cur = lists[i];

        	while (cur && prev) {
r        		if (cur->val < prev->val) {
        			node->next = new ListNode(cur->val);
        			cur = cur->next;
        		}
        		else {
        			node->next = new ListNode(prev->val);
        			prev = prev->next;
        		}
        		
        		node = node->next;
        	}

        	if (cur) node->next = cur;
        	if (prev) node->next = prev;

        	while (node->next) node = node->next;

        	prev = result->next;
        }

        return prev;
    }
};




int main() {
	int n;
	cin >> n;
	vector<ListNode*> v;

	for (int i=0; i < n; i++) {
		string inp;
		cin >> inp;
		ListNode* node = stringToListNode(inp);
		v.push_back(node);
	}



	ListNode* result = Solution().mergeKLists(v);

	prettyPrintLinkedList(result);

	return 0;
}

