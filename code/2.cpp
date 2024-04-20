/*
2. 两数相加

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if (l1->val == 0) return l2;
      if (l2->val == 0) return l1;
      ListNode* newList = new ListNode();
      
      int len1 = getListLen(l1);
      int len2 = getListLen(l2);

      if (len1 < len2) {
        solve(l1, l2, newList);
      } else {
        solve(l2, l1, newList);
      }
      ListNode* res = newList->next;
      delete newList;
      return res;
    }

    int getListLen(ListNode* L) {
      ListNode* p = L;
      int len = 1;
      while (p->next != nullptr) {
        p = p->next;
        len++;
      }
      return len;
    }

    void solve(ListNode* l1, ListNode* l2, ListNode* &newList) {
      ListNode* p1 = l1;
      ListNode* p2 = l2;
      ListNode* p3 = newList;
      int carry = 0;
      while (p1 != nullptr) {
        ListNode* num = new ListNode();
        num->val = p1->val + p2->val + carry;
        carry = num->val / 10;
        num->val = num->val % 10;
        p3->next = num;
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
      }

      while (p2 != nullptr) {
        ListNode* num = new ListNode();
        num->val = p2->val + carry;
        carry = num->val / 10;
        num->val = num->val % 10;
        p3->next = num;
        p2 = p2->next;
        p3 = p3->next;
      }

      if (carry != 0) {
        ListNode* num = new ListNode();
        num->val = carry;
        p3->next = num;
      }
    }
};
