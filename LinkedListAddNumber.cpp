// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

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

// /**
//  * Definition for singly-linked list.

#include<iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        long num1= l1->val;
        long multi = 1;
        while(l1->next !=nullptr)
        {
            l1 = l1->next;
            multi = multi * 10;
            num1 = num1 + multi * l1->val;
        }
        //cout<<num1<<"\n";
        
        long num2= l2->val;
        long multi1 = 1;
        while(l2->next !=nullptr)
        {
            l2 = l2->next;
            multi1 = multi1 * 10;
            num2 = num2 + multi1 * l2->val;
        }
        //cout<<num2;
        
        long num3 = num1 + num2;
        
        ListNode* head = new ListNode;
        head->val = num3 % 10;
        head->next = nullptr;
        num3 = num3 / 10;
        
        ListNode* pointer = head;
        while(num3 != 0)
        {
            ListNode* nextNOde= new ListNode;
            nextNOde->val = num3 % 10;
            nextNOde->next = nullptr;
            num3 = num3 / 10;
            
            pointer->next = nextNOde;
            pointer = nextNOde;
        }
        
        return head;
    }

int main(){

    ListNode* l1 = new ListNode;
    l1->val = 2;

    ListNode* l11 = new ListNode;
    l1->val = 4;

    ListNode* l12 = new ListNode;
    l1->val = 3;

    l1->next = l11;
    l11->next = l12;
    l12->next = nullptr;

    ListNode* l2 = new ListNode;
    l2->val = 5;

    ListNode* l21 = new ListNode;
    l2->val = 6;

    ListNode* l22 = new ListNode;
    l2->val = 4;

    l2->next = l21;
    l21->next = l22;
    l22->next = nullptr;

   ListNode* res = addTwoNumbers(l1, l2);
    cout<<"Hello"<<endl;
    while (res != nullptr)
    {
        cout<<res->val<<" ";
        res = res->next;
    }
    
    return 0;
}