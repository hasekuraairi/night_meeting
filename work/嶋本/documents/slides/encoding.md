---
marp: true
theme: gaia
header: "**Header** __Marp Samples__"
backgroundColor: white
math: katex
style: |
    img[alt ~="center"] {
        display: block;
        margin: 0 auto;
    }

---
# 圧縮
## 目次
- ランレングス圧縮
- LZ77法


---
# ランレングス圧縮
- 連続したデータをその個数分だけ数字に置き換える

![center width:1000px](images/Run-Length.png)



---
# LZ77法
- 同じデータ列が出現したときに、前に出現した位置と一致したデータ数に置き換える 

##### 例 ABCDEFGABCABCDEFG

![center width:600px](images/LZ77_method1.png)

---

![center width:600px](images/LZ77_method2.png)