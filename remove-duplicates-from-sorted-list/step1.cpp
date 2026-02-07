初め
重複しているノードを消したいから、重複しているかの確認→繋ぎ直しを最後までやればいい。繋ぎ直しのときには連続する内一番最初のアドレスを持っていくのがいいだろう(例えば、連続する内二番目のノードを繋ぎ直すとなると、まず連続が開始する一つ前のnextをそれに繋げてやらないといけなくてややこしくなるだけだ)
ListNode*をreturnってことはheadを返したらleetcode側が条件を満たしているか確認してくれる？

定義は、ListNodeがintとListNode*から構成されていて、下はコンストラクタ。セミコロンを使って定義する(初期化子リスト)のが標準的？

書こうとしてから
リストの元の繋ぎ方を変えるんだから参照渡しで貰わないといけない？いやそもそもアロー演算子を使った時点でノードの中身に直接アクセスしているんだからそのまま書き換えてOK



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
        ListNode* node = head;
        while (node != nullptr && node->next != nullptr){
            if (node->val == node->next->val){
                node->next = node->next->next;
            }
            else{
                node = node->next;
            }
        
        }

        return head;
    }
};