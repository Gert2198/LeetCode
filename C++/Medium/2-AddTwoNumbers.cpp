// https://leetcode.com/problems/add-two-numbers/

// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        int sum = 0, acarreo = 0;
        ListNode* sol = new ListNode();
        ListNode* avance = sol;

        while(c1 != nullptr && c2 != nullptr) {
            sum = c1->val + c2->val + acarreo; // esta suma es 0 \iff todos los valores son 0
            // Si es 0, por cojones tiene que haber más elementos en ambas listas
            // Si es distinto de 0, puede que no tengamos más elementos
            // En caso de no tener más cosas en nignuna lista, no añadiriamos un nuevo nodo 
            // Entonces, añadimos un nuevo nodo cuando alguna de las listas continúe
            // Hay que tener cuidado porque, aunque no tengamos elementos en la lista, si el
            // acarreo es > 0, habrá que añadir un nuevo nodo con ese acarreo.
            
            acarreo = 0;
            while(sum >= 10) {
                sum -= 10;
                acarreo++;
            }
            avance->val = sum;
            
            c1 = c1->next;
            c2 = c2->next;
            if (c1 != nullptr || c2 != nullptr || acarreo > 0) {
                avance->next = new ListNode();
                avance = avance->next;
            }
        }

        if (c1 == nullptr && c2 == nullptr) {
            if (acarreo > 0) avance->val = acarreo;
        } else
        if (c1 == nullptr) {
            while(c2 != nullptr) {
                sum = c2->val + acarreo; 

                acarreo = 0;
                while(sum >= 10) {
                    sum -= 10;
                    acarreo++;
                }
                avance->val = sum;

                c2 = c2->next;
                if (c2 != nullptr || acarreo > 0) {
                    avance->next = new ListNode();
                    avance = avance->next;
                }
            }
        } else 
        if (c2 == nullptr) {
            while(c1 != nullptr) {
                sum = c1->val + acarreo; 

                acarreo = 0;
                while(sum >= 10) {
                    sum -= 10;
                    acarreo++;
                }
                avance->val = sum;

                c1 = c1->next;
                if (c1 != nullptr || acarreo > 0) {
                    avance->next = new ListNode();
                    avance = avance->next;
                }
            }
        }
        if (acarreo > 0) avance->val = acarreo;
        return sol;
    }
};

void printListNode (Solution::ListNode * node) {
    Solution::ListNode * ptr = node;
    while (ptr != nullptr) {
        std::cout << ptr->val;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main() {
    // [2,4,3]
    Solution::ListNode * third1 = new Solution::ListNode(3);
    Solution::ListNode * second1 = new Solution::ListNode(4, third1);
    Solution::ListNode * first1 = new Solution::ListNode(2, second1);
    std::cout << "First number: ";
    printListNode(first1);

    // [5,6,4]
    Solution::ListNode * third2 = new Solution::ListNode(5);
    Solution::ListNode * second2 = new Solution::ListNode(6, third2);
    Solution::ListNode * first2 = new Solution::ListNode(4, second2);
    std::cout << "Second number: ";
    printListNode(first2);

    Solution::ListNode * res = Solution::addTwoNumbers(first1, first2);
    std::cout << "Sum of both: ";
    printListNode(res);
}