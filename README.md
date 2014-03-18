Analysis
======================

プロジェクト名称：基礎解析学  
プロジェクト概要：台形公式、Simpsonの公式、離散フーリエ変換   
開発基盤：Linux  
開発言語：C++  
開発者：大竹 洋平  
バージョン：1.0

コンテンツ
--------

    Trape.cpp：台形公式のプログラム
    Simpson.cpp：Simpsonのプログラム
    dft.cpp：離散フーリエ変換のプログラム


動作条件
------

+ C++コンパイラ  
+ ターミナル  
+ Gnuplot


実行方法
----------------

1. コンパイル  
`` g++ Trape.cpp ``
2. 実行  
`` ./a.out 10000 > data.txt ``
3. Gnuplot起動  
`` gnuplot ``  
`` set xrange [0.0001:1] ``  
`` set yrange [1e-12:0.01] ``  
`` set logscale x ``  
`` set logscale y ``  
`` plot "data.txt" ``  
`` set xlabel "h" ``  
`` set ylabel "Relative Error" ``  


実行結果
----------------

### 台形公式とSimpsonのプログラムの実行結果
![my image](http://www.kki.yamanashi.ac.jp/~t11kf008/images/Gnuplot_Simpson.png)  

### 離散フーリエ変換のプログラムの実行結果
![my image](http://www.kki.yamanashi.ac.jp/~t11kf008/images/Gnuplot_DFT.png)


コピーライト
----------
Copyright &copy; 2014 Yohei_Otale All rights reserved.
