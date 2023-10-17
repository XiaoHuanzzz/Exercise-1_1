/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-16 15:22:02
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-17 11:13:39
 * @FilePath: \Exercise5\RungeKuttaforSystemsodDifferentialEquation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define PI 3.14159265358979
#define TOL 0.0001
#define hmax 0.25
#define hmin 0.025

double func1(double x, vector<double> y){
    double f = x;
    return f;
}

double func2(double x, vector<double> y){
    double f = x;
    return f;
}

double func3(double x, vector<double> y){
    double f = x;
    return f;
}

vector<vector<double>> RungeKuttaforSystems(double a, double b, int equationNum, int integralN, vector<double> initialValue, double(*func[])(double, vector<double>)){
    int N = integralN, m = equationNum;
    double h = (b-a)/N, t = a;
    vector<vector<double>> result(N, vector<double>(m+1, 0.0));
    vector<double> w(m, 0.0);
    for(int j = 0; j < m; j++){
        w[j] = initialValue[j];
    }
    cout << "(" << t;
    for(int j = 0; j < m; j++){
        cout << ", " << w[j];
    }
    cout << ")" << endl;
    vector<vector<double>> k(4, vector<double>(m, 0.0));
    vector<double> temp(m, 0.0);
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < m; j++){
            k[0][j] = h*func[j](t, w);
        }
        for(int j = 0; j < m; j++){
            temp[j] = w[j]+k[0][j]/2;
        }
        for(int j = 0; j < m; j++){
            k[1][j] = h*func[j](t+h/2, temp);
        }
        for(int j = 0; j < m; j++){
            temp[j] = w[j]+k[1][j]/2;
        }
        for(int j = 0; j < m; j++){
            k[2][j] = h*func[j](t+h/2, temp);
        }
        for(int j = 0; j < m; j++){
            temp[j] = w[j]+k[2][j]/2;
        }
        for(int j = 0; j < m; j++){
            k[3][j] = h*func[j](t+h, temp);
        }
        for(int j = 0; j < m; j++){
            w[j] = w[j]+(k[0][j]+2*(k[1][j]+k[2][j])+k[3][j])/6;
        }
        t = a+i*h;
        result[i][0] = t;
        cout << "(" << t;
        for(int j = 0; j < m; j++){
            result[i][j+1] = w[j];
            cout << ", " << w[j] ;
        }
        cout << ")" << endl;
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    int m = 3, N = 100;
    vector<double> initialValue = {0.0, 1.0, 2.0};
    double(*func[])(double, vector<double>) = {func1, func2, func3}; 
    vector<vector<double>> result = RungeKuttaforSystems(a, b, m, N, initialValue, func);
    return 0;
}