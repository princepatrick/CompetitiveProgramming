/*
	Status in the contest: Solved on own 
	Approach:
	I have a variable sum to calculate any non-zero sum
	I have a ListNode* called prevZero that stores the previous instance of a Zero node in the linked list
	I iterate through the linked list and whenever, a zero node comes up - I take the prevZero and update the value with the sum and update the next pointer
	Tags: Linked List
		

*/

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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prevZero = head;
        int sum = 0;

        while( temp != nullptr ){
            ListNode* next = temp->next;;

            if( temp->val == 0 ){
                prevZero->val = sum;
                sum = 0;
                if( temp->next != nullptr )
                    prevZero->next = temp;
                else
                    prevZero->next = nullptr;
                prevZero = temp;
            } else {
                sum += temp->val;
            }

            temp = next;
        }

        return head;
    }
};