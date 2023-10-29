/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-28 16:42:44
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-29 16:32:54
 * @FilePath: \Exercise8\PadeRationalApproximation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define PI 3.14159265358979
#define TOL 0.00001

double func(double x){
    double f = exp(-x);
    return f;
}


vector<double> rationalApproximation(int m, int n){
    vector<double> pq(n+m+2, 0.0);
    int N = m+n;
    vector<double> a(N+1, 0.0);
    vector<vector<double>> b(N+2, vector<double>(N+2, 0.0));
    a[0] = 1;
    for(int i = 1; i <= N; i++){
        a[i] = -1.0*a[i-1]/i;
    }
    pq[n+1] = 1; pq[0] = a[0];
    for(int i = 1; i <= N; i++){
        if(i <= n)
            b[i][i] = 1;
        for(int j = 1; j <= i&&j <= m; j++){
            b[i][n+j] = -a[i-j];
        }
        b[i][N+1] = a[i];
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
    for(int i = n; i >= 1; i--){
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
    vector<double> pq = rationalApproximation(m, n);
    return 0;
}