#include <iostream>
using std::cout;
using std::endl;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast !=NULL && fast->next !=NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle found" << " " << slow->val << endl;
        // Middle node in slow
        // Reverse a Linkedlist
        ListNode *current = slow->next;
        ListNode *prev = NULL;
        while(current != NULL){
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        cout << "Reverse done" << endl;
        // Palindrome
        
        while(prev != NULL){
            cout << prev->val << " " << dummy->val << endl;
            if(prev->val == dummy->val)
            {
                prev = prev->next;
                dummy = dummy->next;
                continue;
            }
            else
                return false;

            
        }
        
        
        return true;
    }
};

int main(){
    Solution sol;
    ListNode head(1);
    ListNode node1(2);
    head.next = &node1;
    //ListNode node2(2);
    //node1.next = &node2;
    //ListNode node3(3);
    //node2.next = &node3;

    cout << sol.isPalindrome(&head);
}