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
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *ans = new ListNode();
            
            return ans;
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