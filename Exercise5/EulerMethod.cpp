#include<iostream>
#include<cmath>
#include<vector>
#include<functional>

using namespace std;

#define TOL 0.00001
#define N 10000
#define PI 3.141592653589793238

double func(double x, double y){
    double f = sin(x)+cos(x);
    return f;
}

vector<vector<double>> EulerMethod(double a, double b, double initialCondition, function<double(double, double)> func){
    double h = (b-a)/N;
    double t = a, omega = initialCondition;
    vector<vector<double>> EulerTable(2, vector<double>(N+1, 0.0)); 
    EulerTable[0][0] = a; EulerTable[1][0] = omega;
    cout << "The appximations at N+1 points are: " << endl << '(' << t << ", " << omega << ')';
    for(int i = 1; i <= N; i++){
        omega += h*func(t, omega);
        t += h;
        cout << '(' << t << ", " << omega << ')';
        EulerTable[0][i] = t;
        EulerTable[1][i] = omega;
    }
    return EulerTable;
}

int main(){
    double a = 0, b = PI, initial = 0;
    vector<vector<double>> EulerTable = EulerMethod(a, b, initial, func);
    return 0;
}
