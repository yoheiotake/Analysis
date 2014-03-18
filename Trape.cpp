#include <iostream>
#include <cmath>
using namespace std;

double func( double x )
{
    double res = 1.0;
    return  res / ((1.0 + x) * (1.0 + x));
}


double Trape(int n, double h, double* fv)
{
    double res = 0.0;
    for(int i = 1; i < n; i++)
        res += fv[i];
    
    res = h*(fv[0] + 2*res + fv[n])/2;
    
    return res;
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
    
    n = atoi(argv[1]);      // コマンドライン引数で、標本点数を入力する
    h = (high - low) / n;
    fv = new double [n+1];  // 配列の領域を動的に確保する
    
    
    double x = low;
    for (int k=0; k<=n; k++) {
        fv[k] = func(x);
        x += h;
    }
    
    // double 型変数の表示桁数を増やす
    cout.precision(10);
    
    while(n > 0){
        
        cout << h << "  ";
        cout << fabs((tv - Trape(n,h,fv))) / tv << endl;
        
        n--;
        h = (high - low) / n;
        x = low;
        for(int k=0; k<=n; k++){
            fv[k] = func(x);
            x += h;
        }
    }
    
    delete [] fv;
    return 0;
}
