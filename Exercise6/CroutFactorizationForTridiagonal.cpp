/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-23 15:22:28
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-23 20:39:50
 * @FilePath: \Exercise6\CroutFactorization.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>

#define high 2
#define medium 1
#define low 0

using namespace std;

vector<vector<double>> CroutFactorization(int dimensionN, vector<vector<double>> matrixA){
    int n = dimensionN;
    vector<vector<double>> Crout(3, vector<double>(n, 0.0));
    vector<vector<double>> A = matrixA;
    if(A.size() == 3){
        Crout[medium][0] = A[low][0];
        Crout[high][0] = A[high][0];
        for(int i = 1; i < n-1; i++){
            Crout[low][i] = A[low][i]/Crout[high][i-1];
            Crout[medium][i] = (A[medium][i]-Crout[low][i]*Crout[high][i-1]);
            Crout[high][i] = A[high][i];
        }
        Crout[low][n-1] = A[low][n-1]/Crout[high][n-2];
        Crout[medium][n-1] = A[medium][n-1]-Crout[low][n-1]*Crout[high][n-2];
    }
    else if(A.size() == n){
        Crout[medium][0] = A[0][0];
        Crout[high][0] = A[0][1];
        for(int i = 1; i < n-1; i++){
            Crout[low][i] = A[i][i-1]/Crout[high][i-1];
            Crout[medium][i] = (A[i][i]-Crout[low][i]*Crout[high][i-1]);
            Crout[high][i] = A[i][i+1];
        }
        Crout[low][n-1] = A[n-1][n-2]/Crout[high][n-2];
        Crout[medium][n-1] = A[n-1][n-1]-Crout[low][n-1]*Crout[high][n-2];
    }
    printf("%f %f\n", Crout[medium][0], Crout[high][0]);
    for(int  i = 1; i < n-1; i++){
        for(int j = 0; j < i-1; j++){
            printf("%8d ", 0);
        }
        printf("%f %f %f\n", Crout[low][i], Crout[medium][i], Crout[high][i]);
    }
    for(int j = 0; j < n-2; j++){
        printf("%8d ", 0);
    }
    printf("%f %f\n", Crout[low][n-1], Crout[medium][0]);
    return Crout;    
}

int main(){
    int dimensionN = 3;
    vector<vector<double>> matrixA = {{4,-1,1}, {-1,4.25,2.75}, {1,2.75,3.5}};
    vector<vector<double>> Crout = CroutFactorization(dimensionN, matrixA);
}