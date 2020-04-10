# EDITED
# 2020年度前期プログラミング演習Ⅱ

## はじめに

- プログラミング演習ⅡのLACSページは，[LACS/プログラミング演習Ⅱ][0]です．
- みなさん適宜，自分のペースで課題を解いて，提出(各自のGitHub/2020pspレポジトリにアップロードしてください．)
- 時間割上の演習の時間帯(水,12:50-16:30)は，LACSの「オンライン教室」を開いています．
  - 初回の4月8日は，演習の進め方などオリエンテーションをおこないます．全員参加してください．
  - 2週目4月15日以降は，相談を受け付ける時間とします．特に相談事が無い人は，回線混雑を避けるため，パケ死を避けるため，参加しないでください．

## 必要なこと

1. GitHubアカウントを取得してください．
   - [GitHub][hub]
2. Git をインストールしてください．
3. 自分のPCに開発環境（ソースエディタ，コンパイラ，デバッガ）を揃えてください．本演習では，
   - ソースエディタ：Visual Studio Code
   - コンパイラ：GNU C Compiler
   - デバッガ：GNU Debugger
  を推奨します．WindowsでもMacでもLinux（演習室）でも同じ環境です．
4. このレポジトリ https://www.github.com/helmenov/2020psp2.git を「Fork」してください．
5. Forkすると自分のGitHubに薗田のレポジトリのクローンが新規作成されます．https://www.github.com/ (あなた) /2020psp2.git となるでしょう．
6. このあなたのGitHubレポジトリのクローンを，自分のPCに新規作成してください．Visual Studio Codeで可能です．下の説明「Visual Studio CodeとGitHubの連携」をみてください．

### Gitのインストール

- Linuxの場合は，各ディストリビューションのパッケージ管理コマンドでインストールできるでしょう．
- Macの場合は，まず[HomeBrew][brew]というパッケージ管理ソフトをインストールします．
  
  `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"`
  
  その後，[HomeBrew][brew]を使って，gitをインストールします．
  
  `brew install git`
  
- Windowsの場合は，[Git for Windows][Git4Win]をインストールします．
  - インストールし終えたあとに，Pathに以下を追加します (Windowsボタンを右クリック⇒システム⇒関連設定/システム情報⇒詳細設定⇒環境変数⇒システム環境変数のPathの行を選択して⇒編集)
    - c:\Program Files\Git\cmd
    - c:\Program Files\Git\mingw64\bin
    - c:\Program Files\Git\usr\bin

Gitとは何か，Gitで出てくる用語，操作のいろいろについては，[Reference/Git]　を読んでください．

### GNU C Compiler / GNU Debuggerのインストール

- Linuxの場合は，各ディストリビューションのパッケージ管理コマンドでインストールできるでしょう．
- Macの場合は，[HomeBrew][brew]を使って，インストールします．
  
  `brew install gcc gdb`
  
- Windowsの場合は，[TDM-GCC64][TDM-GCC64]からインストールします．
  - インストールし終えたあとに，Pathに以下を追加します．
    - c:\TDM-GCC64\bin

### Visual Studio Codeのインストール

- [Visual Studio Code][vsc]をインストールします．
- Ctrl-Shift-Xから，以下の拡張機能を追加するとよいでしょう
  - [C/C++][ms-vscode.cpptools]
  - [Markdown All in One][yzhang.markdown-all-in-one]
  - [Japanese Language Pack for Visual Studio Code][ms-ceintl.vscode-language-pack-ja]

### コンパイルの仕方

- 端末環境で`gcc -W -Wall -fexec k00.c -o k00`などとするとコンパイルがおこなわれ，正常にコンパイルされると`k00`という実行ファイルができます．
- 端末環境は，
  - linuxではultermとかxtermとかなんでも
  - windowsではGit for Windowsからインストールされたbashを使います．デスクトップで右クリックからショートカット作成して，「項目の場所」として
    `"C:\Program Files\Git\usr\bin\bash.exe" --login`
    を指定します．このショートカットからbash端末が起動します．起動したときに自分がいるディレクトリは`c:\Users\ログイン名`です．エクスプローラで確かめておきましょう
  - macでは，`ターミナル`というものが入っています．起動したときに自分がいるディレクトリなど確認しておきましょう

### Visual Studio Code と GitHubの連携

1. まずVisual Studio Codeを起動します．左側に5つアイコンが並んでいて，離れて下のほうにギアアイコンがあります．
   - 1番上は，エクスプローラ
     - ファイルを開いたり閉じたり，フォルダを閉じたり開いたり，上書き保存したり，新規作成したりします．
   - 2番目は，検索
     - 文字列検索
   - 3番目は，ソース管理
     - Gitなどのレポジトリ管理
   - 4番目は，Run
     - デバッガを動かします．
   - 5番目は，Extensions
     - 拡張機能の管理，追加，削除
   - ギアアイコンは，管理：各種設定です．
2. GitHubと連携するためには，まずGitHub上のレポジトリをPCにクローンしてきます．
   1. エクスプローラタブを開くと，「フォルダを開く」と「レポジトリをクローンする」があります．「レポジトリをクローンする」を選びます．
   2. レポジトリのURLを聞かれます．自分のGitHub上のレポジトリのURLを記入してエンター.
   3. ファイラ（Windowsではエクスプローラ）が立ち上がって，またレポジトリを聞かれます．今度はクローンしたレポジトリをどのフォルダの下に置くかが聞かれています．
   4. クローンし終えると，フォルダを開くか問われます．とりあえずフォルダは開かないでおきます．
   5. クローンしてきた場合，すでに連携完了です．
3. エクスプローラタブから，レポジトリになったフォルダを「フォルダを開く」から開きます．
   1. 「開いているエディタ」「(レポジトリフォルダ名)」「アウトライン」の3つの項目があり，2番目の項目にフォルダの中身が列挙されています．
   2. この列挙されているところから，編集したいファイルを選びます．もしくは，フォルダ名の脇にあるアイコンからフォルダの新規作成，ファイルの新規作成ができます．（削除はできないので，別な手段で削除）．「開いているエディタ」に開いたファイルが現れて，右側にエディタが立ち上がります．
   3. 編集すると，「開いているエディタ」に「未保存（個数）」が点灯します．保存するときは，「開いているエディタ」の脇にあるアイコンから「すべて保存」を選びます．すると「未保存（個数）」の点灯が消えます．その代わり今保存したファイルに「M」というマークがつきます．また，新規作成されたファイルには「U」マークがついています．また，ソース管理タブのアイコンに数字が現れます．
4. ソース管理タブを開きます．
   1. 「変更」という項目があり，そこに先ほどの編集や新規作成や削除したファイルが並んでいます．マークも同じです．
   2. 各ファイルにマウスを合わせると「変更済み」だとか「追跡対象外」とか出てきます
   3. それぞれのファイルについて登録したい変更について「変更をステージ」をおこないます．すべてをステージする必要はありません．
   4. 「変更をステージ」すると，「ステージング済の変更」という項目があらわれ，そこにファイルが移動します．ここで「ステージングの解除」をすると，元の「変更」に移動します．
   5. ステージ（登録する変更）がすべて決定したら，上のメッセージを書いてエンター．これが「コミット」です．すると「ステージング済の変更」項目が消滅します．
   6. これで自分のPCのレポジトリは更新されました．
5. 自分のPCのレポジトリをGitHubにバックアップします．
   1. 同じ「ソース管理タブ」の「ソース管理」という項目の脇に「...」があります．それをクリックすると，いろいろな機能が並んでいます．
   2. そこから「プッシュ」を選びます．
   3. これで自分のPCのレポジトリがGitHubにバックアップされました．私もこのバックアップを読めます．
6. 薗田がGitHub上のレポジトリに変更を加えました（修正指示を加えた）．GitHub上の変更をPCに同期させます．
   1. 「ソース管理タブ」の「...」から「プル」を選びます．これによりPCのレポジトリに同期されます．
   2. 「エクスプローラタブ」から編集します．あとは上記の3以降と同じです．

## 演習の進め方

レポートの書き方．
- 各課題について
  - ソースコード(k0*.cを変更)
  - 文書(README.mdを変更)
  を自分のGitHubにアップロードしてください．LACSの課題のページで「提出します」的なコメントだけを提出してください．
- アップロードされたレポートを薗田がチェックし，あなたのGitHubのレポジトリに修正を加えます．
- 修正が入ったら，それをPCに同期します．やりかたは上の「Visual Studio CodeとGitHubの連携」を読んでください．
- 修正コメントに基づき，レポートを改訂します．またアップロードして，LACSでコメント提出してください．
- 何度か繰り返し，薗田からの修正がなくなったら，その課題は終了です．

## 演習課題

14人を適当に選んで身長をきいてみた．

|subject | gender | height (cm) |
| ------ | ------ | ----------- |
|      1 |   male |      183.87 |
|      2 |   male |      179.54 |
|      3 | female |      166.9  |
|      4 |   male |      173.62 |
|      5 | female |      165.62 |
|      6 |   male |      167.83 |
|      7 | female |      152.4  |
|      8 | female |      163.24 |
|      9 | female |      161.39 |
|     10 |   male |      174.38 |
|     11 |   male |      171.38 |
|     12 | female |      152.28 |
|     13 |   male |      169.39 |
|     14 |   male |      171.1  |

この標本データは，[14人標本データ][1]に保存されており，1列目に性別が1:male, 2:femaleで，2列目にheightsがメモされている．
このファイルのようなコンマ「,」で列を区切った表形式をcsv(comma separated values)と呼ぶ．

男性はうち8人であったが，この8人の身長を縦に並べてメモしたファイルが[男性8人データ][2]である．このファイルは男性の身長の1列しかない．

この標本データについて，課題を解きなさい．

課題は，5問（k01~k05）あります．

k00フォルダはテンプレートです．参考にしてください．

- [課題0](k00/README.md)
- [課題1](k01/README.md)
- [課題2](k02/README.md)
- [課題3](k03/README.md)
- [課題4](k04/README.md)
- [課題5](k05/README.md)

[0]:https://lacs.nagasaki-u.ac.jp/webapps/blackboard/execute/courseMain?course_id=_82285_1
[1]:sample/heights.csv
[2]:sample/heights_male.csv

[hub]:https://www.github.com/
[Git4Win]:https://gitforwindows.org/
[brew]:https://brew.sh/
[TDM-GCC64]:https://github.com/jmeubank/tdm-gcc/releases/download/v1.2001.0/tdm-gcc-webdl.exe
[vsc]:https://code.visualstudio.com/

[ms-ceintl.vscode-language-pack-ja]:https://marketplace.visualstudio.com/items?itemName=MS-CEINTL.vscode-language-pack-ja
[ms-vscode.cpptools]:https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools 
[yzhang.markdown-all-in-one]:https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one
