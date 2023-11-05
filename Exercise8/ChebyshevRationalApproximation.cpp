/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-31 00:28:50
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-31 15:44:23
 * @FilePath: \Exercise8\ChebyshevRationalApproximation.cpp
 * @Description: This version has unexpected mistakes. 
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define PI 3.14159265358979
#define TOL 1

double func(double x){
    double f = exp(-x);
    return f;
}
double funcCos(double x){
    double f = func(cos(x));
    return f;
}

double multipleFunc(double x, int k){
    double kx = k*x;
    double f = exp(-cos(x))*cos(kx);
    return f;
}

double compositeSimpsonRule(double a, double b, int n, std::function<double(double)> func){
    double h = (b-a)/n;
    double XI0 = func(a)+func(b);
    double XI1 = 0, XI2 = 0; // Summation of f(x2i鈭?) and f(x2i)
    for(int i = 0; i < n; i++){
        double X = a+i*h;
        if(i % 2 == 1)
            XI1 += func(X);
        else
            XI2 += func(X);
    }
    double XI = h*(XI0 + 2*XI2 + 4*XI1)/3;
    return XI;
}


double compositeSimpsonRule(double a, double b, int n, std::function<double(double, int)> func, int k){
    double h = (b-a)/n;
    double XI0 = func(a,k)+func(b,k);
    double XI1 = 0, XI2 = 0; // Summation of f(x2i鈭?) and f(x2i)
    for(int i = 0; i < n; i++){
        double X = a+i*h;
        if(i % 2 == 1)
            XI1 += func(X, k);
        else
            XI2 += func(X, k);
    }
    double XI = h*(XI0 + 2*XI2 + 4*XI1)/3;
    return XI;
}



vector<double> ChebyshevRationalApproximation(int m, int n){
    int N = m+n;
    vector<double> a(N+m+1, 0.0);
    a[0] = compositeSimpsonRule(0, PI, 100, funcCos)*2/PI;
    for(int k = 1; k <= N+m; k++){
        a[k] = compositeSimpsonRule(0, PI, 100, multipleFunc, k)*2/PI;
    }
    vector<double> pq(N+2, 0.0);
    pq[n+1] = 1;
    vector<vector<double>> b(N+2, vector<double>(N+2, 0.0));
    for(int i = 0; i <= N; i++){
        if(i <= n){
            b[i][i] = 1;
        }
        for(int j = n+1; j <= N; j++){
            if(i != 0){
                b[i][j] = -(a[i+j-n]+a[abs(i-j+n)])/2;
            }
            else{
                b[i][j] = -a[j-n]/2;
            }
        }
        if(i != 0){
            b[i][N+1] = a[i];
        }
        else{
            b[i][N+1] = a[i]/2;
        }
    }
    for(int i = n+1; i <= N-1; i++){
        double maxTemp = i;
        for(int k = i+1; k <= N; k++){
            if(abs(b[k][i]) > abs(b[maxTemp][i])){
                maxTemp = k;
            }
        }
        if(b[maxTemp][i] == 0){
            cout << "The system is singular." << endl;
            return pq;
        }
        if(maxTemp != i){
            for(int j = i; j <= N+1; j++){
                double copy = b[i][j];
                b[i][j] = b[maxTemp][j];
                b[maxTemp][j] = copy;
            }
        }
        for(int j = i+1; j <= N; j++){
            double xm = b[j][i]/b[i][i];
            for(int k = i+1; k <= N+1; k++){
                b[j][k] -= xm*b[i][k];
            }
            b[j][i] = 0;
        }
    }
    if(b[N][N] == 0){
        cout << "The system is singular." << endl;
        return pq;
    }
    if(m > 0){
        pq[N+1] = b[N][N+1]/b[N][N];
    }
    for(int i = N-1; i >= n+1; i--){
        pq[i+1] = b[i][N+1];
        for(int j = i+1; j <= N; j++){
            pq[i+1] -= b[i][j]*pq[j+1];
        }
        pq[i+1] /= b[i][i];
    }
    for(int i = n; i >= 0; i--){
        pq[i] = b[i][N+1];
        for(int j = n+1; j <= N; j++){
            pq[i] -= b[i][j]*pq[j+1];
        }
    }
    cout << "The coefficients of p is: " << pq[0];
    for(int i = 1; i <= n; i++){
        cout << ", " << pq[i];
    }
    cout << endl;
    cout << "The coefficients of q is: " << pq[n+1];
    for(int i = n+2; i <= N+1; i++){
        cout << ", " << pq[i];
    }
    return pq;
}

int main(){
    int m = 2, n = 3;
    vector<double> pq = ChebyshevRationalApproximation(m, n);
    
    return 0;
}