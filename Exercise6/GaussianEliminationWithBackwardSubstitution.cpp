/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-20 11:26:21
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-20 16:20:33
 * @FilePath: \Exercise5\GaussianEliminationWithBackwardSubstitution.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<double> GaussianEliminationWithBackwardSubstitution(int equationN, vector<vector<double>> augmentedMatrixA){
    vector<double> solutionX(equationN, 0.0);
    vector<vector<double>> normalizationM(equationN, vector<double>(equationN+1, 0.0));
    for(int i = 0; i < equationN-1; i++){
        int p = i;
        while(augmentedMatrixA[p][i] == 0){
            p++;
            if(p == equationN){
                cout << "No unique solution exists.";
                return solutionX;
            }
        }
        if(p != i){
            swap(augmentedMatrixA[p], augmentedMatrixA[i]);
        }
        for(int j = i+1; j < equationN; j++){
            normalizationM[j][i] = augmentedMatrixA[j][i]/augmentedMatrixA[i][i];
            for(int k = 0; k <= equationN; k++){
                augmentedMatrixA[j][k] -= normalizationM[j][i]*augmentedMatrixA[i][k];
            }
        }
    }
    if(augmentedMatrixA[equationN-1][equationN-1] == 0){
        cout << "No unique solution exists.";
        return solutionX;
    }
    solutionX[equationN-1] = augmentedMatrixA[equationN-1][equationN]/augmentedMatrixA[equationN-1][equationN-1];
    for(int i = equationN-2; i >= 0; i--){
        solutionX[i] = augmentedMatrixA[i][equationN];
        for(int j = i+1; j <= equationN-1; j++){
            solutionX[i] -= augmentedMatrixA[i][j]*solutionX[j];
        }
        solutionX[i] /= augmentedMatrixA[i][i];
    }
    cout << "The solution is (" << solutionX[0];
    for(int i = 1; i < solutionX.size(); i++){
        cout << ", " << solutionX[i];
    }
    cout << ")";
    return solutionX;
}

int main(){
    int equationN = 3;
    vector<vector<double>> augmentedMatrixA = {{1,3,1,4},{0,1,4,5},{0,1,5,6}};
    vector<double> x = GaussianEliminationWithBackwardSubstitution(equationN, augmentedMatrixA);
    return 0;
}
