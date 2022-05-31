---
marp: true
theme: default
paginate: true
header: "**乙夜の会**"
footer: "by **@shimamoto**"
backgroundColor: white
math: katex
headingDivider: 1
size: 16:9
style: |
      img[alt ~= "center"] {
            display: block;
            margin: 0 auto;
      }
      section {
            justify-content: normal;
      font-size: 30px;
      font-family: "Arial", "Hiragino Kaku Gothic ProN";
      }
      section.lead {
            justify-content: center;
            text-align: center;
      font-size: 40px;
      }
      section.contents {
          font-size: 40px;
      }
--- 

<!--
_class: lead
_paginate: false
-->

# ナップザック問題で学ぶ動的計画法

2022/05/28

# 目次

<!--
_class: contents
-->

1. ナップザック問題
2. 全探索
3. 動的計画法

# 1. ナップザック問題

![center width:500px](../images/media/knapsack_problem.png)

# 2. 全探索

![center](../images/media/knapsack_problem2.png)

- 品物ごとに詰められるかを判定する
- 価値が最大にならないパターンも考えている →　計算量 $\mathcal{O}(2^{N})$

# 3. 動的計画法

![center](../images/media/knapsack_problem3.png)

- 品物を詰めている途中で価値が最大になるようにする
- その結果は次の計算で利用するので保持しておく
- 価値が最大にならないパターンは除外している →　計算量 $\mathcal{O}(NW)$


# 3. 動的計画法

- 数学的には漸化式を利用した方法といえる

     #### 品物を選ぶ場合
     $\rm{dp}_{i+1, w} = Max(dp_{i+1, w},  dp_{i, w - w_{i}} + v_{i})$

     ### 品物を選ばない場合
     $\rm{dp}_{i+1, w} = Max(dp_{i+1, w},  dp_{i, w})$


     dp : 途中総重量wにおける価値を保存しているテーブル  
     $\rm{w_{i}}$: ある品物の重量
     $\rm{v_{i}}$: ある品物の価値
