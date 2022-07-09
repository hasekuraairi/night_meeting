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
---

<!--
_class: lead
_paginate: false
_header: ""
-->

# デスクトップマスコットを作ろう 1

2022/06/18

# 環境

- OS：Windows11

- 開発ツール：Unity personal 2020.3.32f1, VSCode

- 言語：C#

- ライブラリ：MMD4Mecanim（MMDモデルをFBX形式にコンバートするため）

- 3Dモデル：雪花ラミィ公式mmd_ver1.0（ニコニ立体から借用）

# 機能

とりあえず簡単そうなやつを作りたい

- タイマー

- モデルをクリックしたら反応を返す

- 天気おしらせ

# 環境構築

- Unity Hub と Unity を[公式サイト](https://unity3d.com/jp/get-unity/download)からダウンロード＆インストール

- 公式アセットも使いたいのでUnityのアカウントも作っておく

![center width:600px](images/スクリーンショット%202022-06-18%20184428.png)


# 環境構築

- C#スクリプト編集用のエディタを用意（今回はVSCodeを使用)

- .NETFramework等をインストール

- 詳しくは以下のQiitaの記事を参照
  [UnityでVisual Studio Codeを使用できるようにするまでの手順](https://qiita.com/riekure/items/c45868f37a187f8e1d69)

# プロジェクト作成

- Unity Hub > 「新しいプロジェクト」> 「3D」を選択 > 「プロジェクト設定」でプロジェクト名と保存場所を設定 > プロジェクトを作成

![center width:800px](images/スクリーンショット%202022-06-18%20190300.png)

# MMD4Mecanimのダウンロード＆インポート

- UnityでMMDモデルを動かせるようにするため[MM4DMecanim](https://stereoarts.jp/)を落とす

- 利用規約とチュートリアルを要確認

![center](images/スクリーンショット%202022-06-18%20191149.png)

#

- MMD4MecanimをUnityのAssetフォルダにドラッグ＆ドロップ

![center](images/スクリーンショット%202022-06-18%20192256.png)



# MMDモデルのダウンロード＆インポート

- ニコニ立体からお好きなモデルをダウンロード（アカウント必要）

- 利用規約を要確認

![center width:800px](images/スクリーンショット%202022-06-18%20191634.png)

#

- MMDモデルをUnityのAssetフォルダにドラッグ＆ドロップ

![center](images/スクリーンショット%202022-06-18%20192818.png)

# MMD4Mecanimの使用

- モデルのフォルダを開き、MMD4Mecanimファイルを選択

![center width:600px](images/スクリーンショット%202022-06-18%20193140.png)

#

- UnityのInspectorタブ(デフォルトでは画面左上)で利用規約に同意
![center width:700px](images/スクリーンショット%202022-06-18%20193337.png)

#

- 「Process」を押すとUnityで使用できるモデルに変換される

- 「VMD」にモーションデータが設定できるらしいが今回は別のやり方で設定する

![center width:700px](images/スクリーンショット%202022-06-18%20194140.png)

#

- 変換されたモデルを選択する
- Rig > Animation Type でHumanoidを選択してApplyを押す
- モデルのAvatarが生成される

![center width:700px](images/スクリーンショット%202022-06-25%20161600.png)

#

- 生成されたFBX形式モデルをUnityのHierarchyにドラッグ＆ドロップするとモデルが配置される

![center width:600px](images/スクリーンショット%202022-06-18%20194749.png)

# モーションデータのダウンロード＆インポート

- Unityちゃんのモーションデータを使う（アイドリング状態の）
- [公式アセットストア](https://assetstore.unity.com/packages/3d/characters/unity-chan-model-18705#description)から「Unity-Chan!Model」を落とす

![center width:700px](images/スクリーンショット%202022-06-18%20195159.png)

- Unity > Window > Package Managerを選択

- PackagesでMy Assetsを選択

- Unity-Chan! Modelを選択後importより「Animators」をインポート

![center width:700px](images/スクリーンショット%202022-06-18%20195935.png)

#

- AssetsファルダにAnimatorフォルダを作成
- Animator Controllerを作成して開く

![center width:700px](images/%E3%82%B9%E3%82%AF%E3%83%AA%E3%83%BC%E3%83%B3%E3%82%B7%E3%83%A7%E3%83%83%E3%83%88%202022-06-25%20160532.png)

#

- インポートしたUnityちゃんのモーションデータをAnimator Controllerに追加する

![center width:700px](images/スクリーンショット%202022-06-25%20160833.png)

# アニメーションコントローラーとAvatarを設定

- 配置したモデルを選択してInspectorのAnimatorを参照する
- 作成したアニメーションコントローラーを追加する
- 生成したAvatarを追加する

![center width:500px](images/スクリーンショット%202022-06-25%20163650.png)