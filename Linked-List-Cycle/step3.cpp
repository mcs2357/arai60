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
//サイクルが始まるノードのアドレスを聞かれても答えられる

//サイクルが始まるノードのインデックス(pos)を返せと言われた場合は、(unordered)mapでListNode*とindexをメモすれば返せる(今回はそれは求められていないが)。Liste List Cycle Ⅱの場合だと実際に返すのはintではなく、ListNode*だった。
```