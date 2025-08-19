/*
    https://leetcode.com/problems/merge-two-sorted-lists/description/
    Time complexity = O(m+n)
    Space complexity = O(1)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } 
            else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if(list1) {
            node->next = list1;
        }
        else {
            node->next = list2;
        }
        return dummy.next;
    }
};
/*
    Min heap
    Time complexity - O(NlogK)
    Space complexity - O(k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > minHeap(cmp);
        for(ListNode* list: lists) {
            if(list != nullptr) {
                minHeap.push(list);
            }
        }
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;

            node = node->next;
            if(node !=nullptr) {
                minHeap.push(node);
            }
        }
        return res->next;
    }
};