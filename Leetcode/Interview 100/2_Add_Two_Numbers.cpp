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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* node = new ListNode(0);
        ListNode* result = node;

        int remainder = 0;

        while (l1 && l2) {
            int cur = l1->val + l2->val + remainder;
            remainder = cur/10;
            cur = cur%10;

            node->next = new ListNode(cur);

            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int cur = l1->val + remainder;
            remainder = cur/10;
            cur = cur%10;

            node->next = new ListNode(cur);

            node = node->next;
            l1 = l1->next;
        }

        while (l2) {
            int cur = l2->val + remainder;
            remainder = cur/10;
            cur = cur%10;

            node->next = new ListNode(cur);

            node = node->next;
            l2 = l2->next;
        }

        if (remainder) node->next = new ListNode(remainder);

        return result->next;
    }
};



int main() {
    string s_l1, s_l2;
    getline(cin, s_l1);
    getline(cin, s_l2);


    ListNode* l1 = stringToListNode(s_l1);
    ListNode* l2 = stringToListNode(s_l2);

    // prettyPrintLinkedList(l1);
    // prettyPrintLinkedList(l2);

    ListNode* result = Solution().addTwoNumbers(l1, l2);

    prettyPrintLinkedList(result);


    return 0;
}