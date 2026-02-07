コードを見て、何がやりたいのか、何をやっているのかがわかるような書き方、命名をしないといけない。
今回の問題の手順を日本語で言うと
(連続する二つのノードの)値が同じだったら、手前のノードが指す場所を一つ前に進める

nullptrかどうか考えたくなるタイミングでifで確認しないと、読み手はあらかじめ出てきた条件の意味がわかるまでそれを覚えてないといけないのでよくない。

上のやり方は、繋がりが全部見えてる視点からの発言。if A then Bのときに、Aでないならどうするか、Bするときにチェックすべきことはないかというのを気にする必要がある。
連続するノードN_1, N_2と言ったときに、二つのノードは対等な感じがするが、実際には動かしながら見ないといけないので(N_2はN_2ではなくて、N_1の次のノードとして認識する)そこも言葉とズレている。

```cpp
base_node->next = next_node->next
```
という箇所はnext_nodeを参照渡しで定義した上で書き換えてもよかったが、今回の主役はbase_nodeでnext_nodeはそこから派生するものという意識で書いた。
他の人のコードで、headがnullptrでないかを最初に確認した上でやっているものもあったが、私はそこを分ける意識が弱かったのでそうしなかった。

(忘れていたが時間計算量はノードの長さの1乗に比例するのでO(n)、空間計算量はbase_nodeとnext_nodeだけを使うのでO(1))

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* base_node = head;

        while (base_node != nullptr){
            ListNode* next_node = base_node->next;
            bool comparable = next_node != nullptr;

            if (!comparable){
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