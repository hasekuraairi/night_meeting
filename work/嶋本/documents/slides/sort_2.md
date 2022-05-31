---
marp: true
theme: gaia
backgroundColor: white
math: katex
style: |
    img[alt ~="center"] {
        display: block;
        margin: 0 auto;
    }
---
# 色々なソート 2
## 目次
- マージソート
- クイックソート
- まとめ

---
# マージソート
- 各グループに1個の数字になるまで数列を２グループずつ分割する
- 分割したグループでソートし、グループをマージしてソート
- 分割・マージ処理は再帰処理
- 計算時間は$\mathcal{O}(n \log n)$（グループで最小値を選択するのにn回, グループ分割するのに$\log n$回）

---
###### マージソートの図 https://www.codereading.com/algo_and_ds/algo/merge_sort.html
![center](images/merge-sort.png)

---
# クイックソート
- ピボットより小さい数のグループと大きい数のグループに分ける
- グループ内でソートする
- グループに分ける処理は再帰処理
- 計算時間は$\mathcal{O}(n \log n)$（ピポットと数字を比較するのにn回, グループ分割するに$\log n$回）

---
###### クイックソートの図 https://www.codereading.com/algo_and_ds/algo/quick_sort.html
![center](images/quick-sort.png)


---
# まとめ
- マージソートとクイックソートを説明、実装

###### 参考URL・書籍
###### ソート全般について: https://www.codereading.com/algo_and_ds/
###### 「アルゴリズム図鑑」石田保輝, 宮崎修一著（翔泳社）
###### 「アルゴリズムとデータ構造」大槻兼資, 秋葉拓哉（講談社）




