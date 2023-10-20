/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-19 18:41:47
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-20 10:18:04
 * @FilePath: \Exercise5\trapezoidalWithNewton.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define N 10
#define M 10
#define PI 3.14159265358979
#define TOL 0.0001
#define hmax 0.25
#define hmin 0.025

double func(double x, double y){
    double f = x+y;
    return f;
}

double funcY(double x, double y){
    double f = 1;
    return f;
}

vector<vector<double>> trapezoidalWithNewtonIteration(double a, double b, double initialValue, function<double(double, double)> func, function<double(double, double)> funcY){
    double h = (b-a)/N;
    double t = a, w = initialValue;
    vector<vector<double>> result(2, vector<double>(N+1, 0.0));
    result[0][0] = t; result[1][0] = w;
    cout << "The approximations are (" << t << ", " << w << ")";
    for(int i = 1; i <= N; i++){
        double k1 = w + h*func(t, w)/2;
        double w0 = k1;
        int j = 1, flag = 0;
        while(flag == 0){
            w = w0 - (w0-h*func(t+h, w0)/2-k1)/(1-h*funcY(t+h, w0)/2);
            if(abs(w-w0) < TOL){
                flag = 1;
            }
            else{
                j++;
                w0 = w;
                if(j > M){
                    cout << "The maximum number of iterations exceeded";
                    return result;
                }
            }
        }
        t = a+i*h;
        cout << "(" << t << "," << w << ")";
        result[0][i] = t;
        result[1][i] = w;
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = trapezoidalWithNewtonIteration(a, b, initialValue, func, funcY);
    return 0;
}