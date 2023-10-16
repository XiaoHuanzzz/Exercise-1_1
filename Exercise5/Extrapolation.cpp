/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-16 11:43:09
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-16 12:14:34
 * @FilePath: \Exercise5\Extrapolation.cpp
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

vector<vector<double>> extrapolation(double a, double b, double initialValue, function<double(double, double)> func){
    vector<double> NK = {2, 4, 6, 8, 12, 16, 24, 32};
    double TO = a, WO = initialValue, h = hmax;
    int flag = 1;
    vector<double> T, W;
    T.push_back(TO); 
    W.push_back(WO);

    vector<double> y(9, 0.0);
    vector<vector<double>> Q(8, vector<double>(8, 0.0));

    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= i; j++){
            Q[i][j] = (NK[i+1]/NK[j])*(NK[i+1]/NK[j]);
        }
    }

    while(flag == 1){
        int k = 1;
        int Nflag = 0;

        while(k <= 8 && Nflag == 0){
            double HK = h/NK[k];
            double T = TO;
            double W2 = WO, W3 = W2+HK*func(T, W2);
            T = TO+HK;

            for(int j = 1; j <= NK[k]-1; j++){
                double W1 = W2;
                W2 = W3;
                W3 = W1 + 2*HK*func(T, W2);
                T = TO + (j+1)*HK;
            } 

            y[k] = (W3+W2+HK*func(T, W3))/2;

            if( k >= 2){
                int j = k;
                double v = y[1];
                while(j >= 2){
                    y[j-1] = y[j] + (y[j]-y[j-1])/(Q[k-1][j-1]-1);
                    j--;
                    
                }
                if(abs(y[1]-v) <= TOL){
                    Nflag = 1;
                }
            }

            k++;
        }

        k--;
        if(Nflag == 0){
            h /= 2;
            if(h < hmin){
                cout << endl << "hmin exceeded." << endl;
                flag = 0;
            }    
        }
        else{
            WO = y[1];
            TO += h;
            T.push_back(TO);
            W.push_back(WO);
            cout << "(" << TO << ", " << WO << ", " << h << ")";
            if(TO >= b){
                flag = 0;
            }
            else if(TO+h > b){
                h = b-TO;
            }
            else if(k <= 3 && h < 0.5*hmax){
                h *= 2;
            }
        }
    }
    vector<vector<double>> result(2, vector<double>(T.size(), 0.0));
    for(int i = 0; i < T.size(); i++){
        result[0][i] = T[i];
        result[1][i] = W[i];
    }
    return result;
}

int main(){
    double a = 0, b = PI;
    double initialValue = 0;
    vector<vector<double>> result = extrapolation(a, b, initialValue, func);
    // for(int i = 0; i < result[0].size(); i++){
    //     cout << result[0][i] << ' ' << result[1][i] << endl;
    // }
    return 0;
}
