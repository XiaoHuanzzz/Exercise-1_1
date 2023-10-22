/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-20 22:43:17
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-22 14:57:19
 * @FilePath: \Exercise6\GaussianEliminationWithScaledPartialPivoting.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<double> GaussianEliminationWithScaledPartialPivoting(int equationN, vector<vector<double>> augmentedMatrixA){
    int n = equationN;
    vector<vector<double>> m(n, vector<double>(n, 0.0));
    vector<vector<double>> A = augmentedMatrixA;
    vector<double> x(n, 0.0);
    vector<int> nRow(n, 0);  
    vector<double> s(n, 0.0);  // the maximum value of the column
    for(int i = 0; i < n; i++){
        int p = 0;
        double tempMax = abs(A[nRow[p]][i]);
        while(1){
            if(tempMax < abs(A[nRow[p]][i])){
                tempMax = abs(A[nRow[p]][i]);
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
        else{
            s[i] = tempMax;
        }
        nRow[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        int p = i;
        double tempMax = abs(A[nRow[p]][i])/s[nRow[p]];
        int maxPos = i;;
        while(1){
            if(tempMax < abs(A[nRow[p]][i])/s[nRow[p]]){
                tempMax = abs(A[nRow[p]][i]/s[nRow[p]]);
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
            x[i] -=A[nRow[i]][j]*x[j];
        }
        x[i] /= A[nRow[i]][i];
    }
    cout << "The solution is (" << x[0];
    for(int i = 1; i < x.size(); i++){
        cout << ", " << x[i];
    }
    cout << ")";
    return x;
}

int main(){
    int equationN = 3;
    vector<vector<double>> augmentedMatrixA = {{1,2,1,4},{0,1,4,5},{0,1,5,6}};
    vector<double> x = GaussianEliminationWithScaledPartialPivoting(equationN, augmentedMatrixA);
    return 0;
}