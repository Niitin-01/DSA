#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode* reverse(ListNode*& curr, int k) {
        ListNode* prev = nullptr;
        while (curr && k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head of this group
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int len = 0;
        for (ListNode* t = head; t; t = t->next) len++;

        int groups = len / k;
        if (groups == 0) return head;

        ListNode* curr = head;
        ListNode* prevTail = curr;

        // First group
        head = reverse(curr, k);

        // Remaining groups
        for (int i = 1; i < groups; i++) {
            ListNode* currTail = curr;     
            ListNode* currHead = reverse(curr, k);
            prevTail->next = currHead;
            prevTail = currTail;
        }

        // Attach leftover nodes
        prevTail->next = curr;
        return head;
    }
};

// ---------- utilities ----------

ListNode* buildList(const vector<int>& v) {
    if (v.empty()) return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* tail = head;
    for (int i = 1; i < v.size(); i++) {
        tail->next = new ListNode(v[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// ---------- main ----------

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = buildList(values);

    cout << "Original list:\n";
    printList(head);

    Solution sol;
    head = sol.reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ":\n";
    printList(head);

    freeList(head);
    return 0;
}
