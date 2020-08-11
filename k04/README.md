# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
input the filename of smaple height
../sample/heights.csv
the file name of sample: ../sample/heights.csv
input the filename of sample ID
../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
which ID's data do you want?
45313125
---
ID:45313125
gender:female
height:152.4
---
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200731 sonoda]
- `int n=0`が必要です．
- 見ていた課題内容が古かったようで，直しておきました．ソースコードにある，
  ```
  extern void get(int n_m,int all, double* lower,double* upper);
  extern int chose(int n,int r);
  ```
  と
  ```
  	printf("====================\n");
		printf("Number of male sample : %d\n",n_m );
		printf("Number of female sample: %d\n",n_f );
		printf("Male ratio : %lf\n",(double)n_m/all );
  ```
  と
  ```
  get(n_m,all,&lower,&upper);
  printf("Population Male ration (estimated) : %lf -- %lf\n",lower,upper );
  ```
   は不要です． 


[comment #20200804 sonoda]
- OKです．課題4完了．
- コードの説明を埋めておいてください．
