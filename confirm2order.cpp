#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

double a(double x){
  double val = sin(x) + cos(x);
  return val;
}

double u(double x){
  double val = exp(x) + x;
  return val;
}

double d_g(double x){
  double val = 2*cos(x)*exp(x) + cos(x) - sin(x);
  return val;
}

vector<double> approx_d_g( double x,  int n){
  vector<double> approxVal(n, 0.0);
  double h = 1;
  for(int i = 0; i < n; i++){
    h /= 2; 
    double val = a(x+h/2)*(u(x+h)-u(x)) - a(x-h/2)*(u(x)-u(x-h));
    val /= h*h;
    approxVal[i] = val;
  }  
  return approxVal;
}

int main(){
  double left = 0, right = 1;
  int n = 10;
  vector<vector<double>> approxVal2(n, vector<double>(n, 0.0));
  vector<double> realVal(n, 0.0);
  vector<vector<double>> resErr(n, vector<double>(n, 0.0));
  for(int i = 0; i < n; i++){
    double x = i*1.0/n;
    approxVal2[i] = approx_d_g(x, n);
    realVal[i] = d_g(x);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        resErr[i][j] = approxVal2[i][j] - realVal[j];
	cout << resErr[i][j] << ' ';
      }
      cout << endl;
    }
    
  }
  
  return 0;
}
