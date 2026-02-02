```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;
        ListNode* current = head;

        while (current != nullptr){
            if (visited.contains(current)){
                return true;
            }
            visited.insert(current);
            current = current->next;
        }
    
        return false;
    }
        
};
```