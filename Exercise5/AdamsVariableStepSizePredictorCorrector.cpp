/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-13 21:34:33
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-16 11:37:42
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
#define TOL 0.0001
#define hmax 0.25
#define hmin 0.025

double func(double x, double y){
    double f = x;
    return f;
}

vector<vector<double>> RK4(double h, vector<double> v, vector<double> x){
    for(int i = 1; i <= 3; i++){
        double K1 = h*func(x[i-1], v[i-1]);
        double K2 = h*func(x[i-1]+h/2, v[i-1]+K1/2);
        double K3 = h*func(x[i-1]+h/2, v[i-1]+K2/2);
        double K4 = h*func(x[i-1]+h, v[i-1]+K3);
        v[i] = v[i-1]+(K1+2*(K2+K3)+K4)/6;
        x[i] = x[0]+i*h;    
    }
    vector<vector<double>> result(2, vector<double>(4, 0.0));
    for(int i = 0; i < 4; i++){
        result[0][i] = x[i];
        result[1][i] = v[i];
    }
    return result;
}

vector<vector<double>> AdamsVariableStepSizePredictorCorrector(double a, double b, double initialValue, function<double(double, double)> func){
    int n = (b-a)/hmin;
    int actualN = 0;
    vector<double> T(n, 0), W(n, 0);
    double t0 = a, w0 = initialValue, h = hmax;
    int flag = 1, last = 0;
    cout << "The approximations are (" << t0 << ", " << w0 << ")";
    vector<double> t = {t0, 0, 0, 0};
    vector<double> w = {w0, 0, 0, 0};
    vector<vector<double>> temp = RK4(h, w, t);
    for(int j = 0; j <= 3; j++){
        W[j] = temp[1][j]; 
        T[j] = temp[0][j];
        // cout << T[j] << ' ' << W[j] << endl;
    }
    int Nflag = 1, i = 4;
    t0 = t[3]+h; 
    while(flag == 1){
        double WP = W[i-1] + (h/24)*(55*func(T[i-1], W[i-1]) - 59*func(T[i-2], W[i-2]) + 37*func(T[i-3], W[i-3]) -9*func(T[i-4], W[i-4]));
        double WC = W[i-1] + (h/24)*(9*func(t0, WP) + 19*func(T[i-1], W[i-1]) - 5*func(T[i-2], W[i-2]) + func(T[i-3], W[i-3]));
        double sigma = 19*abs(WC-WP)/(270*h);
        if(sigma <= TOL){
            W[i] = WC;
            T[i] = t0;
            if(Nflag == 1){
                for(int j = i-3; j <= i; j++){
                    cout << "(" << j << ", " << T[j] << ", " << W[j] << ", " << h <<")";
                }
            }
            else{
                cout << "(" << i << ", " << T[i] << ", " << W[i] << ", " << h <<")";
            }
            if(last == 1){
                flag = 0;
            }
            else{
                i++;
                Nflag = 0;
                if(sigma <= 0.1*TOL || T[i-1]+h > b){
                    double q = pow(TOL/(2*sigma), 0.25);
                    if(q > 4){
                        h *= 4;
                    }
                    else{
                        h *= q;
                    }
                    if(h > hmax){
                        h = hmax;
                    }
                    if(T[i-1]+4*h > b){
                        h = (b-T[i-1])/4;
                        last = 1;
                    }
                    w[0] = W[i-1]; t[0] = T[i-1];
                    vector<vector<double>> temp = RK4(h, w, t);
                    for(int j = 0; j <= 3; j++){
                        W[i-1+j] = temp[1][j]; 
                        T[i-1+j] = temp[0][j];
                        // cout << T[j] << ' ' << W[j] << endl;
                    }
                    Nflag = 1;
                    i += 3;
                }
            }
        
        }
        else{
            double q = pow(TOL/(2*sigma), 0.25);
            if(q < 0.1){
                h *= 0.1;
            }
            else{
                h *= q;
            }
            if(h < hmin){
                flag = 0;
                cout << endl << "hmin exceeded." << endl;
            }
            else{
                if(Nflag == 1){
                    i -= 3;
                    w[0] = W[i-1]; t[0] = T[i-1];
                    vector<vector<double>> temp = RK4(h, w, t);
                    for(int j = 0; j <= 3; j++){
                        W[i-1+j] = temp[1][j]; 
                        T[i-1+j] = temp[0][j];
                        // cout << T[j] << ' ' << W[j] << endl;
                    }
                    i += 3;
                    Nflag = 1;
                }
            }
        }
        t0 = T[i-1]+h;
        actualN = i;
    }
    vector<vector<double>> result(2, vector<double>(actualN, 0.0));
    for(int i = 0; i < actualN; i++){
        result[0][i] = T[i];
        result[1][i] = W[i];
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = AdamsVariableStepSizePredictorCorrector(a, b, initialValue, func);
    // for(int i = 0; i < result[0].size(); i++){
    //     cout << result[0][i] << ' ' << result[1][i] << endl;
    // }
    return 0;
}