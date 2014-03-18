#include <iostream>
#include <cmath>
using namespace std;


double func( double x )
{
    double res = 1.0;
    return  res / ((1.0 + x) * (1.0 + x));
}


double Simpson(int n, double h, double* fv)
{
    double res = 0.0;
    for(int k = 0; k <= 2*n-2; k=k+2)
        res += fv[k] + 4*fv[k+1] + fv[k+2];
    
    return h*res/3;
}

int main(int argc, char* argv[])
{
    int n;                 // 標本点数
    double h;              // きざみ幅
    double* fv;            // 関数値を保存する配列
    double low = 0.0;      // 積分区間の下限
    double high = 2.0;     // 積分区間の上限
    double tv = 2.0 / 3.0; // 真の積分値
    
    // 引数に標本点数を与えない場合は、強制終了する
    if (argc < 2) {
        cout << "Usage: a.out [number of data]" << endl;
        exit(1);
    }
    
    n = atoi(argv[1]);        // コマンドライン引数は文字列として記憶されるためint型変数に変換
    h = (high - low) /(2*n);
    fv = new double [2*n+1];  // 2*nだとアボート.配列のサイズなので一つ多く指定する.中間点を標本点とみなすため2*n
    
    
    double x = low;
    for (int k=0; k<=2*n; k++) {
        fv[k] = func(x);
        x += h;
    }
    
    // double 型変数の表示桁数を増やす
    cout.precision(10);
    
    while(n > 0){
        cout << h << "  ";
        cout << fabs((tv - Simpson(n,h,fv))) / tv << endl; // 誤差の出力
        
        n--;
        h = (high - low) /(2*n);
        x = low;
        for(int k=0; k <= 2*n; k++){
            fv[k] = func(x);
            x += h;
        }
    }
    delete [] fv;
    return 0;
}
