#include <iostream>
#include "matrix.h"
#include <chrono>
#include <random>
#include <vector>


using namespace std;
int main(){
    for(int N=100; N<=300; N+=10){
    double min = 1000;
    Matrix<long double> A, B;
    A.N=N;
    B.N=N;
    mt19937 gen(43);
    normal_distribution<double> distr1(11, 7);
    vector<long double> tmp(N*N);
    generate(tmp.begin(), tmp.end(), [&] {return distr1(gen);});
    A.data = tmp;
    normal_distribution<double> distr2(13, 5);
    generate(tmp.begin(), tmp.end(), [&] {return distr2(gen);});
    B.data = tmp;
    for(int i=0; i<10; i++){
    auto t0 = chrono::high_resolution_clock::now();
    A*B;
    auto t1 = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
    if(dt<min){
        min = dt;
    }
    }
    cout << "Matrix dimensions:  " << A.N << "x" << A.N;
    cout << "; measured time:  " << min << " milliseconds." << endl;
    }

    return 0;
}