/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-17 11:40:17
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-17 12:20:32
 * @FilePath: \Exercise2_6\HornerMethod.cpp
 * @Description: Using Horner's Method to calculate the value and derivate value of polynomial
 */
#include<iostream>
#include<cmath>
#include <tuple>


using namespace std;

#define N 10000
#define TOL 1e-6


std::tuple<double, double> HornerPolynomialAndDerivative(int n, double *a, double x) {
    double y = a[n], z = a[n];
    for (int j = n - 1; j > 0; j--) {
        y = x * y + a[j];
        z = x * z + y;
    }
    double Px = x * y + a[0];
    double P_x = z;

    // 使用 std::make_tuple 返回两个值
    return std::make_tuple(Px, P_x);
}

int main() {
    int n = 3;
    double a[] = {3.0, 2.0, 1.0, 4.0};
    double x = 2.0;

    // 调用函数并解包返回的 tuple
    auto result = HornerPolynomialAndDerivative(n, a, x);
    double Px = std::get<0>(result);
    double P_x = std::get<1>(result);

    // 输出结果
    std::cout << "The value at point " << x << " = " << Px << std::endl;
    std::cout << "The derivate value at point " << x << " = " << P_x << std::endl;

    return 0;
}
