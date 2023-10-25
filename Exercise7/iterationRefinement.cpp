/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-25 11:16:56
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-25 15:31:05
 * @FilePath: \Exercise7\iterationRefinement.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define N 1000
#define TOL 0.0001

using namespace std;



vector<double> GaussianEliminationWithPartialPivoting(int equationN, vector<vector<double>> augmentedMatrixA){
    int n = equationN;
    vector<vector<double>> m(n, vector<double>(n, 0.0));
    vector<vector<double>> A = augmentedMatrixA;
    vector<double> x(n, 0.0);
    vector<int> nRow(n, 0);
    for(int i = 0; i < n; i++){
        nRow[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        int p = i;
        int maxPos = i;
        double tempMax = abs(A[nRow[p]][i]);
        while(1){
            if(tempMax < abs(A[nRow[p]][i])){
                tempMax = abs(A[nRow[p]][i]);
                maxPos = p;
            }
            p++;
            if(p == equationN){
                break;
            }
        }
        if(tempMax == 0){
            cout << "No unique solution exists.";
            return x;
        }
        if(nRow[i] != nRow[maxPos]){
            int nCopy = nRow[i];
            nRow[i] = nRow[maxPos];
            nRow[maxPos] = nCopy;
        }
        for(int j = i+1; j < n; j++){
            m[nRow[j]][i] = A[nRow[j]][i]/A[nRow[i]][i];
            for(int k = 0; k < n+1; k++){
                A[nRow[j]][k] -= m[nRow[j]][i]*A[nRow[i]][k];
            }
        }
    }
    if(A[nRow[n-1]][nRow[n-1]] == 0){
        cout << "No unique solution exists.";
        return x;
    }
    x[n-1] = A[nRow[n-1]][n]/A[nRow[n-1]][n-1];
    for(int i = n-2; i >= 0; i--){
        x[i] = A[nRow[i]][n];
        for(int j = i+1; j <= n-1; j++){
            x[i] -= A[nRow[i]][j]*x[j];
        }
        x[i] /= A[nRow[i]][i];
    }
    // cout << "The solution is (" << x[0];
    // for(int i = 1; i < x.size(); i++){
    //     cout << ", " << x[i];
    // }
    // cout << ")";
    return x;
};

double conditionNumCalculation(int equationN, vector<vector<double>> matrixA, vector<double> b, int digitsT){
    int n = equationN;
    double condA = 0;
    vector<vector<double>> augmentedA_b = matrixA;
    vector<double> residual(n, 0.0);
    for(int i = 0; i < n; i++){
        augmentedA_b[i].push_back(b[i]);
    }
    vector<double> approxX = GaussianEliminationWithPartialPivoting(n, augmentedA_b);
    for(int k = 0; k < N; k++){
        for(int i = 0; i < n; i++){
            residual[i] = b[i];
            for(int j = 0; j < n; j++){
                residual[i] -= matrixA[i][j]*approxX[j];
            }
        }
        vector<vector<double>> augmentedA_r = matrixA;
        for(int i = 0; i < n; i++){
            augmentedA_r[i].push_back(residual[i]);
        }
        vector<double> y = GaussianEliminationWithPartialPivoting(n, augmentedA_r);
        vector<double> x;
        for(int i = 0; i < n; i++){
            x.push_back(approxX[i]+y[i]);
        }
        if(k == 0){
            auto maxX = max_element(x.begin(), x.end());
            auto maxY = max_element(y.begin(), y.end());
            condA = (*maxY)*pow(2, digitsT)/(*maxX);
            if(*maxY == 0){
                condA = 1/(*maxX);
            }
            cout << *maxX << ' ' << *maxY << endl;
        }
        if(*max_element(y.begin(), y.end()) < TOL){
            cout << "The approximation of x is: (" << x[0];
            for(int i = 1; i < n; i++){
                cout << ", " << x[i];
            }
            cout << "). " << endl << "The condition number of A is: " << condA;
            return condA;
        }
        for(int i = 0; i < n; i++){
            approxX[i] = x[i];
        }
    }
    cout << "Maximum number of iterations exceeded." << "The condition number of A is: " << condA;
    return condA;
};

int main(){
    int equationN = 3;
    vector<vector<double>> A = {{3.3330, 15920, -10.333}, {2.2220, 16.710, 9.6120}, {1.5611, 5.1791, 1.6852}};
    vector<double> b = {15913, 28.544, 8.4254};
    double condA = conditionNumCalculation(equationN, A, b, 54);
}