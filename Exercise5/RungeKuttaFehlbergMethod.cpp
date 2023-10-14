/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-13 21:34:33
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-14 11:25:52
 * @FilePath: \Exercise5\RungeKuttaFehlbergMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>

using namespace std;

#define N 100
#define PI 3.14159265358979
#define TOL 0.00001
#define hmax 0.25
#define hmin 0.05

double func(double x, double y){
    double f = sin(x) + cos(y);
    return f;
}

vector<vector<double>> RungeKuttaFehlberg(double a, double b, double initialValue, function<double(double, double)> func){
    double h = hmax, flag = 1;
    double t = a, omega = initialValue;
    vector<vector<double>> result;
    result.push_back({t, omega});
    cout << "The approximations are (" << t << ", " << omega << ")";
    while(flag == 1){
        double K1 = h*func(t, omega);
        double K2 = h*func(t+h/4, omega+K1/4);
        double K3 = h*func(t+h*3/8, omega+K1*3/32+K2*9/32);
        double K4 = h*func(t+h*12/13, omega+K1*1932/2197-K2*7200/2197+K3*7296/2197);
        double K5 = h*func(t+h, omega+K1*439/216-8*K2+K3*3680/513-K4*845/4104);
        double K6 = h*func(t+h/2, omega-K1*8/27+2*K2-K3*3544/2565+K4*1859/4104-K5*11/40);
        double R = abs(K1/360-K3*128/4275-K4*2197/75240+K5/50+K6*2/55)/h;
        if(R <= TOL){
            t += h;
            omega = omega + K1*25/216+K3*1408/2565+K4*2197/4104-K5/5;
            result.push_back({t, omega});
            cout << "(" << t << "," << omega << "," << h << ")";
        }
        double delta = 0.84*pow(TOL/R, 0.25);
        if(delta <= 0.1){
            h *= 0.1;
        }
        else if(delta >= 4){
            h *= 4;
        }
        else{
            h *= delta;
        }
        if(h > hmax){
            h = hmax;
        }
        if(t >= b){
            flag = 0;
        }
        else if(t+h > b){
            h = b-t;
        }
        else if(h < hmin){
            flag = 0;
            cout << endl << "minimum h exceeded. Procedure completed unsuccessfully." << endl;
        }
        
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = RungeKuttaFehlberg(a, b, initialValue, func);
    return 0;
}