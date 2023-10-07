/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-10-07 14:46:44
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-10-07 15:07:35
 * @FilePath: \Exercise4\adaptiveQuadratureGPT.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath>

#define TOL 0.00001
#define N 10000
#define PI 3.141592653589793238

double function(double x) {
    // Define the function to be integrated
    return sin(x);
}

double adaptiveQuadratureRecursive(double a, double b, double tol) {
    double h = b - a;
    double c = (a + b) / 2.0;
    double fa = function(a);
    double fb = function(b);
    double fc = function(c);
    double integral = (h / 6.0) * (fa + 4.0 * fc + fb);
    
    double leftIntegral = (h / 12.0) * (fa + 4.0 * function((a + c) / 2.0) + fc);
    double rightIntegral = (h / 12.0) * (fc + 4.0 * function((c + b) / 2.0) + fb);
    
    if (fabs(leftIntegral + rightIntegral - integral) < tol) {
        return integral;
    } else {
        double leftSum = adaptiveQuadratureRecursive(a, c, tol / 2.0);
        double rightSum = adaptiveQuadratureRecursive(c, b, tol / 2.0);
        return leftSum + rightSum;
    }
}

int main() {
    double a = 0.0; // Lower limit of integration
    double b = PI; // Upper limit of integration
    
    double result = adaptiveQuadratureRecursive(a, b, TOL);
    
    std::cout << "The integral of sin(x) from " << a << " to " << b << " is: " << result << std::endl;
    
    return 0;
}