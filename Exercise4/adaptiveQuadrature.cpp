/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-06 16:26:51
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-07 15:08:28
 * @FilePath: \Exercise4\adaptiveQuadrature.cpp
 * @Description: This is a version that has bugs.
 */ 
#include<iostream>
#include<cmath>
#include<vector>
#include<functional>

using namespace std;

#define TOL 0.00001
#define N 10000
#define PI 3.141592653589793238

double func(double x){
    double f = sin(x)+ x*x+5;
    return f;
}

double adaptiveQuadrature(double a, double b, function<double(double)> func){
    double APP = 0;
    int i = 1;
    double TOLi = 10*TOL;
    double ai = a;
    double hi = (b-a)/2;
    double FAi = func(a), FBi = func(b), FCi = func(a+hi);
    double Si = (FAi+FBi+4*FCi)*hi/3;
    double Li = 1;
    while(i > 0){
        double FD = func(ai+hi/2);
        double FE = func(ai+3*hi/2);
        double S1 = hi*(FAi+4*FD+FCi)/6;
        double S2 = hi*(FCi+4*FE+FBi)/6;
        double v1 = ai, v2 = FAi, v3 = FCi, v4 = FBi, v5 = hi, v6 = TOLi, v7 = Si, v8 = Li;
        i--;
        if(std::abs(S1+S2-v7) < v6){
            APP += S1+S2;
        }
        else{
            if(v8 >= N){
                cout << "LEVEL EXCEEDED." << endl;
                break;
            }
            else{
                i++;
                ai = v1+v5;
                FAi = v3;
                FCi = FE;
                FBi = v4;
                hi = v5/2;
                TOLi = v6/2;
                Si = S2;
                Li = v8+1;

                i++;
                ai = v1;
                FAi = v2;
                FCi = FD;
                FBi = v3;
                Si = S1;
            }
        }
    }
    cout << "APP approximates I to within TOL is " << APP;
    return APP;
}

int main(){
    double a = 0, b = PI;
    double APP = adaptiveQuadrature(a, b, func);
    return 0;
}