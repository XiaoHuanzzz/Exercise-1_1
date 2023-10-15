/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-13 21:34:33
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-14 17:34:02
 * @FilePath: \Exercise5\RungeKuttaFehlbergMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define N 10
#define PI 3.14159265358979
#define TOL 0.00001
#define hmax 0.25
#define hmin 0.05

double func(double x, double y){
    double f = x;
    return f;
}

vector<vector<double>> AdamsFourthOrderPredictorCorrector(double a, double b, double initialValue, function<double(double, double)> func){
    double h = (b-a)/N;
    double t = a, w = initialValue;
    vector<vector<double>> result(2, vector<double>(N+1, 0.0));
    result[0][0] = t; result[1][0] = w;
    cout << "The approximations are (" << t << ", " << w << ")";
    for(int i = 1; i <= 3; i++){
        double K1 = h*func(t, w);
        double K2 = h*func(t+h/2, w+K1/2);
        double K3 = h*func(t+h/2, w+K2/2);
        double K4 = h*func(t+h, w+K3);
        w += (K1+2*(K2+K3)+K4)/6;
        t += h;
        result[0][i] = t; result[1][i] = w;
        cout << "(" << t << "," << w << ")";
    }
    for(int i = 4; i <= N; i++){
        t += h;
        result[0][i] = t; 
        w = result[1][i-1] + h*(55*func(result[0][i-1], result[1][i-1])-59*func(result[0][i-2], result[1][i-2])+37*func(result[0][i-3], result[1][i-3]-9*func(result[0][i-4], result[1][i-4])))/24;
        w = result[1][i-1] + h*(9*func(t, w)+19*func(result[0][i-2], result[1][i-2])-5*func(result[0][i-3], result[1][i-3]+func(result[0][i-4], result[1][i-4])))/24;
        result[1][i] = w;
        cout << "(" << t << "," << w << ")";
    }    
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = AdamsFourthOrderPredictorCorrector(a, b, initialValue, func);
    return 0;
}