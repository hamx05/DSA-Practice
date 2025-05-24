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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use two-pointer technique i.e. slow and fast pointers

        // before we start, we'll create a dummy node at the start of the list to handle edge cases easily, like when deleting head, etc
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* fast = temp;
        ListNode* slow = temp;

        // move fast pointer n+1 steps ahead
        int i = 0;
        while (i <= n) {
            fast = fast->next;
            i++;
        }

        // move both fast and slow until fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // now, we've reached 1 step before the target so just simply delete the nth node
        slow->next = slow->next->next;

        head = temp->next; // redefine head (in case it was the case of deleting head or some other edge case)
        delete temp; // clean up dummy node

        return head;
    }
};