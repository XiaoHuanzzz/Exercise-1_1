/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-17 20:07:26
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-17 20:10:41
 * @FilePath: \Exercise2_6\MullerMethodComplex.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <complex>
#include <cmath>

// 多项式函数，这里示范了一个多项式 x^3 - 6x^2 + 11x - 6
std::complex<double> polynomial(std::complex<double> x) {
    return x*x*x*x - 3.0*x*x*x + x*x + x + 1.0;
}

// Muller方法求解复数根
std::complex<double> muller(std::complex<double> x0, std::complex<double> x1, std::complex<double> x2, double tol) {
    int maxIterations = 100; // 最大迭代次数
    std::complex<double> x;

    for (int i = 0; i < maxIterations; i++) {
        std::complex<double> h1 = x1 - x0;
        std::complex<double> h2 = x2 - x1;
        std::complex<double> d1 = (polynomial(x1) - polynomial(x0)) / h1;
        std::complex<double> d2 = (polynomial(x2) - polynomial(x1)) / h2;
        std::complex<double> a = (d2 - d1) / (h2 + h1);
        std::complex<double> b = d2 + h2 * a;
        std::complex<double> c = polynomial(x2);
        std::complex<double> delta = sqrt(b * b - 4.0 * a * c);
        
        // 选择更接近根的解
        std::complex<double> xPlus = x2 - (2.0 * c) / (b + delta);
        std::complex<double> xMinus = x2 - (2.0 * c) / (b - delta);

        if (std::abs(polynomial(xPlus)) < std::abs(polynomial(xMinus))) {
            x = xPlus;
        } else {
            x = xMinus;
        }
        std::cout << "The " << i << " step: p = " << x << std::endl;

        // 检查收敛条件
        if (std::abs(polynomial(x)) < tol) {
            return x;
        }

        x0 = x1;
        x1 = x2;
        x2 = x;
    }

    // 如果达到最大迭代次数仍未收敛，则返回近似值
    return x;
}

int main() {
    // 初始猜测点
    std::complex<double> x0(0.5, 0.0);
    std::complex<double> x1(-0.5, 0.0);
    std::complex<double> x2(0.0, 0.0);

    // 容差
    double tolerance = 1e-6;

    // 调用 Muller 方法来计算复数根
    std::complex<double> root = muller(x0, x1, x2, tolerance);

    std::cout << "Complex Root: " << root << std::endl;

    return 0;
}
