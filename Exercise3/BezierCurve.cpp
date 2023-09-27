/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-27 12:36:12
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-27 13:46:04
 * @FilePath: \Exercise3\BezierCurve.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>> BezierCurve(vector<double> x, vector<double> y, vector<double> xLeftGuide, vector<double> yLeftGuide, vector<double> xRightGuide, vector<double> yRightGuide){
    int n = x.size() - 1;
    vector<vector<double>> coefficient(n,vector<double>(8,0.0));
    for(int i = 0; i < n; i++){
        coefficient[i][0] = x[i];
        coefficient[i][4] = y[i];
        coefficient[i][1] = 3*(xLeftGuide[i]-x[i]);
        coefficient[i][5] = 3*(yLeftGuide[i]-y[i]);
        coefficient[i][2] = 3*(x[i]-xRightGuide[i+1]+2*xLeftGuide[i]);
        coefficient[i][6] = 3*(y[i]-yRightGuide[i+1]+2*yLeftGuide[i]);
        coefficient[i][3] = x[i+1]-x[i] + 3*(xRightGuide[i+1]+xLeftGuide[i]);
        coefficient[i][7] = y[i+1]-y[i] + 3*(yRightGuide[i+1]+yLeftGuide[i]);
    }
    return coefficient;
}

void coutCoefficient(vector<vector<double>> coefficient){
    for(int i = 0; i < coefficient.size(); i++){
        cout << "x_" << i << "(t) = ";
        for(int j = 0; j < 4; j++){
            if(j != 0){
                cout << '+';
            }
            cout << coefficient[i][j];
            if(j != 0){
                cout << "t";
                if(j != 1){
                    cout << "^" << j;
                }
            } 
        }
        cout << endl;
        cout << "y_" << i << "(t) = ";
        for(int j = 4; j < 8; j++){
            if(j != 4){
                cout << '+';
            }
            cout << coefficient[i][j];
            if(j != 4){
                cout << "t";
                if(j != 5){
                    cout << "^" << j-4;
                }
            } 
        }
        cout << endl;
    } 
}

int main(){
    vector<double> x = {1.0, 2.0, 3.0};
    vector<double> y = {0.0, 1.0, 0.0};
    vector<double> xLeftGuide = {0.5, 1.5, 0.0};
    vector<double> yLeftGuide = {0.0, 2.5, 0.0};
    vector<double> xRightGuide = {0.0, -2.0, 1.0};
    vector<double> yRightGuide = {0.0, 2.5, 3.0};
    vector<vector<double>> coefficient = BezierCurve(x, y, xLeftGuide, yLeftGuide, xRightGuide, yRightGuide);
    coutCoefficient(coefficient);
    return 0;
}