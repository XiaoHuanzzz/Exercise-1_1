#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<double>> LUFactorization(int dimensionN, vector<vector<double>> matrixA){
    int n = dimensionN;
    vector<vector<double>> LU(n, vector<double>(n, 0.0));
    vector<vector<double>> A = matrixA;
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            LU[i][j] = A[i][j];
            for(int k = 0; k < j; k++){
                LU[i][j] -= LU[i][k]*LU[k][j];
            }
            LU[i][j] /= LU[j][j];
            cout << LU[i][j] << ' ';
        }
        for(int j = i; j < n; j++){
            LU[i][j] = A[i][j];
            for(int k = 0; k < i; k++){
                LU[i][j] -= LU[i][k]*LU[k][j];
            }
            cout << LU[i][j] << ' ';
        }
        cout << endl;
    }
    return LU;    
}

int main(){
    int dimensionN = 3;
    vector<vector<double>> matrixA = {{1,2,3}, {2,1,3}, {3,3,1}};
    vector<vector<double>> LU = LUFactorization(dimensionN, matrixA);
}