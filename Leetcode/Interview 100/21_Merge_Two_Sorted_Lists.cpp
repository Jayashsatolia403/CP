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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = new ListNode(2);
        ListNode* result = node;

        while (list1 && list2) {
        	if (list1->val < list2->val) {
        		result->next = new ListNode(list1->val);
        		list1 = list1->next;
        	}
        	else {
        		result->next = new ListNode(list2->val);
        		list2 = list2->next;
        	}

        	result = result->next;
        }

        if (list1) result->next = list1;
        if (list2) result->next = list2;

        return node->next;
    }
};




int main() {
	string sl1, sl2;
	getline(cin, sl1);
	getline(cin, sl2);

	ListNode* l1 = stringToListNode(sl1);
	ListNode* l2 = stringToListNode(sl2);

	prettyPrintLinkedList(Solution().mergeTwoLists(l1, l2));

	return 0;
}