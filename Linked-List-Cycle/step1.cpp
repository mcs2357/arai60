```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow){
                return true;
            }
        }
        return  false;
        
    }
};
//これくらいの長さだと完全にわかってなくても何となくで書けてしまうので気を付ける
```