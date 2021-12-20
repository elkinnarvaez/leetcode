/*
    2. Add Two Numbers - https://leetcode.com/problems/add-two-numbers/

    Author: Elkin Narváez
    Email: elkinnarvaez2406@gmail.com
    Last submission: 12/16/2021
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        int listSize(ListNode *l){
            int size = 0;
            ListNode *node = l;
            while(node != nullptr){
                size++;
                node = node->next;
            }
            return size;
        }
    public:
        ListNode* addTwoNumbersV1(ListNode *l1, ListNode *l2) {
            ListNode *ans = new ListNode();
            ListNode *ansptr = ans;
            int n1 = listSize(l1), n2 = listSize(l2);
            ListNode *p1, *p2;
            if(n1 >= n2){
                p1 = l1;
                p2 = l2;
            }
            else{
                p1 = l2;
                p2 = l1;
                swap(n1, n2);
            }
            int carry = 0, i, s;
            for(i = 0; i < n1; i++){
                if(i < n2){
                    s = p1->val + p2->val + carry;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else{
                    s = p1->val + carry;
                    p1 = p1->next;
                }
                if(s >= 10){
                    carry = 1;
                    s = s - 10;
                }
                else{
                    carry = 0;
                }
                ansptr->val = s;
                if(i < n1 - 1){
                    ansptr->next = new ListNode();
                    ansptr = ansptr->next;
                }
            }
            if(carry == 1){
                ansptr->next = new ListNode(1);
            }
            return ans;
        }

        ListNode* addTwoNumbersV2(ListNode *l1, ListNode *l2) {
            ListNode *ans = new ListNode();
            ListNode *ansptr = ans;
            ListNode *p1 = l1, *p2 = l2;
            int carry = 0, i, s;
            while(!(p1 == nullptr && p2 == nullptr)){
                int x, y;
                x = (p1 != nullptr) ? p1->val : 0;
                y = (p2 != nullptr) ? p2->val : 0;
                s = x + y + carry;
                carry = s/10;
                ansptr->next = new ListNode(s % 10);
                ansptr = ansptr->next;
                if(p1 != nullptr) p1 = p1->next;
                if(p2 != nullptr) p2 = p2->next;
            }
            if(carry > 0){
                ansptr->next = new ListNode(1);
            }
            return ans->next;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *ans = new ListNode();
            ListNode *ansptr = ans;
            ListNode *p1 = l1, *p2 = l2;
            int carry = 0, i, s;
            while(!(p1 == nullptr && p2 == nullptr)){
                int x, y;
                x = (p1 != nullptr) ? p1->val : 0;
                y = (p2 != nullptr) ? p2->val : 0;
                s = x + y + carry;
                carry = s/10;
                ansptr->next = new ListNode(s % 10);
                ansptr = ansptr->next;
                if(p1 != nullptr) p1 = p1->next;
                if(p2 != nullptr) p2 = p2->next;
            }
            if(carry > 0){
                ansptr->next = new ListNode(1);
            }
            return ans->next;
        }
};

void printList(ListNode *l){
    ListNode *node = l;
    if(node != nullptr){
        printf("%d", node->val);
        node = node->next;
    }
    while(node != nullptr){
        printf(" %d", node->val);
        node = node->next;
    }
    printf("\n");
}

int main(){
    Solution solution;
    int n1, n2, x, i, tc = 1;
    while(scanf("%d %d", &n1, &n2) != EOF){
        if(n1 == -1 && n2 == -1){
            continue;
        }
        scanf("%d", &x);
        ListNode *l1 = new ListNode(x);
        ListNode *node = l1;
        for(i = 0; i < n1 - 1; i++){
            scanf("%d", &x);
            node->next = new ListNode(x);
            node = node->next;
        }
        scanf("%d", &x);
        ListNode *l2 = new ListNode(x);
        node = l2;
        for(i = 0; i < n2 - 1; i++){
            scanf("%d", &x);
            node->next = new ListNode(x);
            node = node->next;
        }
        ListNode *sol = solution.addTwoNumbers(l1, l2);
        printf("Case %d: ", tc);
        printList(sol);
        tc++;
    }
    return 0;
}