#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1ptr = l1;
    ListNode* l2ptr = l2;
    ListNode* solution;
    ListNode* nextSolution = solution;
    bool firstIteration = true;
    int acarreo = 0;

    while (l1ptr != nullptr && l2ptr != nullptr) {
        int v1 = l1ptr->val;
        int v2 = l2ptr->val;

        ListNode* toInsert = new ListNode((v1 + v2) % 10);
        nextSolution = toInsert;
        nextSolution = nextSolution->next;


        if (v1 + v2 > 10) acarreo = 1;
        l1ptr = l1ptr->next;
        l2ptr = l2ptr->next;
    }
}

int main() {

}