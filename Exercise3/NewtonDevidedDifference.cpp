/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-21 09:51:18
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-21 10:15:42
 * @FilePath: \Exercise3\NewtonDevidedDifference.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>

using namespace std;

vector<double> NewtonDividedDifference(vector<double> x, vector<double> y){
    int n = x.size();
    std::vector<std::vector<double>> F(n, std::vector<double>(n, 0.0));
    for(int i = 0; i < n; i++){
        F[i][0] = y[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            F[i][j] = (F[i][j-1] - F[i-1][j-1])/(x[i] - x[i-j]);
        }
    }
    vector<double> result;
    for(int i = 0; i < n; i++){
        result.push_back(F[i][i]);
    }
    return result;
}

int main(){
    vector<double> x = {1.0, 2.0, 3.0, 4.0};
    vector<double> y = {1.5, 4.3, 2.6, 3.0};
    vector<double> result = NewtonDividedDifference(x, y);
    for(int i = 0; i < x.size(); i++){
        cout << "F_" << i << ',' << i << " = " << result[i] << endl;
    }
    return 0;
}