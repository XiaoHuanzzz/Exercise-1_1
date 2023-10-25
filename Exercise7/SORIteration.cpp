/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-24 11:35:24
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-24 17:15:08
 * @FilePath: \Exercise7\JacobiIteration.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define N 1000
#define TOL 0.01

using namespace std;

vector<double> SORIteration(int equationN, vector<vector<double>> matrixA, vector<double> b, vector<double> initialX, double omega){
    int n = equationN;
    vector<vector<double>> A = matrixA;
    vector<double> x0 = initialX;
    vector<double> x(n, 0.0);
    
    for(int k = 0; k < N; k++){
        double error = 0;
        for(int i = 0; i < n; i++){
            x[i] = b[i];
            for(int j = 0; j < i; j++){
                x[i] -= A[i][j]*x[j];
            }
            for(int j = i+1; j < n; j++){
                x[i] -= A[i][j]*x0[j];
            }
            x[i] *= omega/A[i][i];
            x[i] += (1-omega)*x0[i];
            error += abs(x[i]-x0[i]);
        }
        if(error < TOL){
            cout << "The solution of x is (" << x[0];
            for(int i = 1; i < n; i++){
                cout << ", " << x[i];
            }
            cout << ").";
            return x;
        }
        for(int i = 0; i < n; i++){
            x0[i] = x[i];
        }
    }
    cout << "Maximum number of iterations exceeded.";
    return x;
}

int main(){
    int equationN = 4;
    double omega = 0.5;
    vector<vector<double>> A = {{10, -1, 2, 0}, {-1, 11, -1, 3}, {2, -1, 10, -1}, {0, 3, -1, 8}};
    vector<double> b = {6, 25, -11, 15};
    vector<double> x0 = {0, 0, 0, 0};
    vector<double> x = SORIteration(equationN, A, b, x0, omega);
    // cout << "The solution of x is (" << x[0];
    // for(int i = 1; i < equationN; i++){
    //     cout << ", " << x[i];
    // }
    // cout << ").";
    return 0;
}