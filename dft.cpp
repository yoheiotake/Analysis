#include <iostream>
#include <complex>
#include <sys/time.h>

using namespace std;

void DFT(int n, complex<double>* fv, complex<double>* cv)
{
    complex<double> omega;
    
    omega = exp( complex<double>( 0, 2.0*M_PI / n) ); // M_PI は円周率
    
    for(int j=0; j<n; j++){
        for(int k=0;k<n;k++){
            cv[j] += fv[j]*pow(omega,(-1)*k*j)*(1/(double)n);
        }
    }
}

double my_clock()
{
    struct timeval tv;
    
    gettimeofday(&tv,NULL);
    return tv.tv_sec + (double)tv.tv_usec*1e-6;
}


int main(int argc, char* argv[])
{
    int n; // データ数
    complex<double>* fv; // 関数値を格納する配列
    complex<double>* cv; // Fourier 係数を格納する配列
    double time; // 計算時間
    
    if (argc < 2) {
        cout << "Usage: a.out [number of data]" << endl;
        exit(1);
    }
    
    n = atoi(argv[1]); // コマンドライン引数で、データ数を入力する
    fv = new complex<double> [n]; // 配列の領域を動的に確保する
    cv = new complex<double> [n];
    
    
    for (int i=0; i<n; i++)
        fv[i] = complex<double>( (double)(rand()) / RAND_MAX, (double)(rand()) / RAND_MAX );
    
    
    time = my_clock();
    
    
    DFT(n,fv,cv);
    
    
    time = my_clock() - time;
    
    
    cout << n << ", " << time << endl;
    
    
    delete[] fv; // 配列の領域解放
    delete[] cv;
    
    return 0;
    
}
