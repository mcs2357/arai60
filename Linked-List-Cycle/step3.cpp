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
//サイクルが始まるノードのアドレスを聞かれても答えられる

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_map <ListNode*, int> indexed_visited;
        ListNode* current = head;
        int index = 0;

        while (current != nullptr){
            if (indexed_visited.contains(current)){
                return true;
            }
            indexed_visited[current] = index;
            index++;
            current = current->next;
        }

        return false;
    }     
};
//サイクルが始まるノードのインデックス(pos)を聞かれても答えられる