#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<double>> LDLtFactorization(int dimensionN, vector<vector<double>> matrixA){
    int n = dimensionN;
    vector<vector<double>> LDLt(n, vector<double>(n, 0.0));
    vector<vector<double>> A = matrixA;
    for(int  i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            LDLt[i][j] = A[i][j];
            for(int k = 0; k < j; k++){
                LDLt[i][j] -= LDLt[i][k]*LDLt[j][k]*LDLt[k][k];
            }
            if(j != i){
                LDLt[i][j] /= LDLt[j][j];
                LDLt[j][i] = LDLt[i][j];
            }
        }
    }
    for(int  i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << LDLt[i][j] << ' ';
        }
        cout << endl;
    }
    return LDLt;    
}

int main(){
    int dimensionN = 3;
    vector<vector<double>> matrixA = {{4,-1,1}, {-1,4.25,2.75}, {1,2.75,3.5}};
    vector<vector<double>> LDLt = LDLtFactorization(dimensionN, matrixA);
}