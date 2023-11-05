// This is an uncompleted version, turn to page 572 to finish it later.
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<complex>

using namespace std;

#define PI 3.14159265358979
#define TOL 1

double func(double x){
    double f = exp(-x);
    return f;
}

vector<complex<double>> fastFourierTransform(vector<double> y){
    int M = (y.size())/2;
    int m = M;
    int p = pow(2, m);
    int q = p;
    vector<complex<double>> c(2*m, 0.0);
    vector<double> a(m+1, 0.0), b(m+1, 0.0);
    vector<complex<double>> xi(2*M+1, 0.0);
    complex<double> eta = (cos(PI/m), sin(PI/m)); 
    for(int j = 0; j < 2*m; j++){
        c[j] = y[j];
    }
    for(int j = 1; j <= M; j++){
        xi[j] = (cos(PI*j/m), sin(PI*j/m));
        xi[j+M] = -xi[j]; 
    }
    int K = 0;
    xi[0] = 1;
    for(int L = 1; L <= p+1; L++){
        while(K < 2*m-1){
            for(int j = 1; j <= M; j++){
                vector<int> compositeK;
                int tempK = K;
                while(compositeK.size() <= p){
                    compositeK.push_back(tempK & 1);
                    tempK >> 1;
                }
                int K1 = K/pow(2, q);
                int K2 = 0, pow2 = pow(2, q);
                for(int i = p; i >= q; i--){
                    K2 += compositeK[i]*pow2;
                    pow2 << 1;
                }
                complex<double> nita = c[K+M]*xi[K2];
                c[K+M] = c[K]-nita;
                c[K] += nita;
                K++;
            }
            K += M;
            
        }
        K = 0;
        M >> 1;
        q--;
    }
    while(K < 2*m-1){
        vector<int> compositeK;
        int tempK = K;
        while(compositeK.size() <= p){
            compositeK.push_back(tempK & 1);
            tempK >> 1;
        }
        int j = 0, pow2 = 1;
        for(int i = 0; i <= p; i++){
            j += compositeK[i]*pow2;
            pow2 << 1;
        }
        if(j > K){
            complex<double> tempC = c[K];
            c[K] = c[j];
            c[j] = tempC;
        }
        K++;
    }
    a[0] = c[0].real()/m;
    complex<double> e_ipim(cos(PI*m), -sin(PI*m));
    a[m] = (e_ipim*c[m]).real()/m;
    for(int j = 1; j <= m-1; j++){
        complex<double> e_ipij(cos(j*PI), -sin(j*PI));
        a[j] = (e_ipij*c[j]).real()/m;
        b[j] = (e_ipij*c[j]).imag()/m;
    }
    cout << "c: " << c[0];
    for(int i = 1; i <= 2*m-1; i++){
        cout << ", " << c[i];
    }
    cout << endl << "a: " << a[0];
    for(int i = 1; i <= m; i++){
        cout << ", " << a[i];
    }
    cout << endl << "b: " << b[0];
    for(int i = 1; i <= m; i++){
        cout << ", " << b[i];
    }
    cout << endl;
    return c;
}

int main(){
    int m = 2;
    vector<double> y;
    for(int i = 0; i <= 2*m-1; i++){
        y.push_back(func(-PI+i*PI/m));
    }
    vector<complex<double>> abc = fastFourierTransform(y);
}