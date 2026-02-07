step2ではboolをcomparableで立てたが、空から書くときに否定をつけ忘れたので、isLastNodeの方が直感的かと思ってそちらに変えた(日本語の、比較できるという意味は薄れたが)。
命名としては、base_nodeが動いていく基本のノードで、next_nodeはbase_nodeから派生するノードという意味合いで付けた。その意味で書き換えるときも、next_nodeを参照渡しにして書き換えるのではなく、base_node->next = next_node->nextと書いた方が、直感的かと考えた。


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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* base_node = head;

        while (base_node != nullptr){
            ListNode* next_node = base_node->next;
            bool isLastNode = next_node == nullptr;

            if (isLastNode){
                return head;
            }

            if (base_node->val == next_node->val){
                base_node->next = next_node->next;
            }
            else{
                base_node = next_node;
            }
        }

        return head;
    }        
};