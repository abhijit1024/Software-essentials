/*
    https://leetcode.com/problems/linked-list-cycle/description/
    Time complexity - O(n)
    Space complexity - O(n)
    Hash set
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode *curr = head;
        while(curr) {
            if(seen.find(curr) != seen.end()) {
                return true;
            }
            seen.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};

/*
    Two pointer 
    Time complexity - O(n)
    Space complexity - O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};
