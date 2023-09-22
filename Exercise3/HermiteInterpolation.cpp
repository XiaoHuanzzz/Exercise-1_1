/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-22 17:19:47
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-23 00:24:01
 * @FilePath: \Exercise3\HermiteInterpolation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>

using namespace std;

vector<double> HermiteInterpolation(vector<double> x, vector<double> y, vector<double> y_){
    int n = x.size();
    std::vector<std::vector<double>> Q(2*n, std::vector<double>(2*n, 0.0));
    vector<double> z(2*n, 0.0);
    for(int i = 0; i < n; i++){
        z[2*i] = x[i];
        z[2*i+1] = x[i];
        Q[2*i][0] = y[i];
        Q[2*i+1][0] = y[i];
        Q[2*i+1][1] = y_[i];
        if(i != 0){
            Q[2*i][1] = (Q[2*i][0] - Q[2*i-1][0])/(z[2*i] - z[2*i-1]);
        }
        cout << endl;
    }
    for(int i = 2; i < 2*n; i++){
        for(int j = 2; j <= i; j++){
            Q[i][j] = (Q[i][j-1] - Q[i-1][j-1])/(z[i] - z[i-j]);
        }
    }
    // for(int i = 0; i < 2*n; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << "Q_" << i << ',' << j << '=' << Q[i][j] << ' ';
    //     }
    // }
    vector<double> result;
    for(int i = 0; i < 2*n; i++){
        result.push_back(Q[i][i]);
    }
    return result;
}

int main(){
    vector<double> x = {1.0, 2.0, 3.0, 4.0};
    vector<double> y = {1.5, 4.3, 2.6, 3.0};
    vector<double> y_ = {1.0, 6.2, 4.3, 1.2};
    vector<double> result = HermiteInterpolation(x, y, y_);
    for(int i = 0; i < result.size(); i++){
        cout << "Q_" << i << ',' << i << " = " << result[i] << endl;
    }
    return 0;
}