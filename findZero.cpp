/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-19 16:08:58
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-07-24 17:07:11
 * @FilePath: \Numerical Analysis Exercise\findZero_InRange.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <limits>

#include "functions.h"

class FunctionSolver {
private:
    double a_ = 1.0;  // 存储区间左端点
    double b_ = 3.0;  // 存储区间右端点
    double epsilon_;  // 零点的精度

public:
    FunctionSolver(double a, double b, double epsilon) : a_(a), b_(b), epsilon_(epsilon) {}

    // 示例函数1：f(x) = x^2 - 4
    double func1(double x) {
        return x * x - 4;
    }

    // 示例函数2：f(x) = sin(x)
    double func2(double x) {
        return std::sin(x);
    }

    // 示例函数3：f(x) = x^3 + x^2 - 3
    double func3(double x) {
        return x * x * x + x * x - 3;
    }

    // 示例函数4：f(x) = e^x - 2
    double func4(double x) {
        return std::exp(x) - 2;
    }

    double findZeroBinary(std::function<double(double)> func) {
        double left = a_;  // 区间左端点
        double right = b_;  // 区间右端点

        while (right - left > epsilon_) {
            double mid = (left + right) / 2.0;

            if (func(mid) == 0.0) {
                return mid;
            }
            else if (func(mid) * func(left) < 0) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        return (left + right) / 2.0;
    }

    double findZeroNewton(std::function<double(double)> func, double x0 = 0) {
    const double epsilon = 1e-6;  // 零点的精度
    double x = x0;  // 初始猜测值

    while (std::abs(func(x)) > epsilon) {
        // 使用牛顿法进行迭代求解
        double df = calculateDerivative(func, x);
        x -= func(x) / df;
    }

    return x;
}

    double findDerivativeZeroNewton(const std::function<double(double)>& func, double initial_guess, double epsilon = 1e-12, int max_iterations = 100) {
        double x = initial_guess;
        int iteration = 0;

        while (iteration < max_iterations) {
            double derivative = calculateDerivative(func, x);
            if (derivative == 0.0) {
                // 输出导数为0的点
                std::cout << "derivative zero point:x = " << x << std::endl;
                return x;
            }

            double second_derivative = calculateSecondDerivative(func, x);
            x = x - derivative / second_derivative; // 使用牛顿法计算下一个点

            if (std::abs(derivative) <= epsilon) {
                // 输出满足条件的点
                std::cout << "derivative zero point:x = " << x << std::endl;
                return x;
            }

            iteration++;
        }

        std::cout << "can't find the point in " << max_iterations << " steps " << std::endl;
        return initial_guess; // 未找到满足条件的点，返回初始猜测值
    }

    std::vector<double> findDerivativeZeros(const std::function<double(double)>& func, double epsilon = 1e-6) {
        std::vector<double> zeros;

        double x = 0.0;
        double stepSize = 1.0;
        double rightX = x, leftX = x;
        double rrightX, lleftX;

        // double maxDouble = std::numeric_limits<double>::max();

        while (true) {
            rrightX = rightX + stepSize;
            double rightDerivative = calculateDerivative(func, rightX);
            double rrightDerivative = calculateDerivative(func, rrightX);
            lleftX = leftX - stepSize;
            double leftDerivative = calculateDerivative(func, leftX);
            double lleftDerivative = calculateDerivative(func, lleftX);

            if (rightDerivative * rrightDerivative <= 0) {
                // If derivative values have different signs, perform binary search
                double left = rightX;
                double right = rrightX;
                while (right - left > 1e-6) {
                    double mid = (left + right) / 2;
                    double midDerivative = calculateDerivative(func, mid);
                    if (midDerivative * calculateDerivative(func, left) <= 0) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                zeros.push_back((left + right) / 2);
            }

            if (leftDerivative * lleftDerivative <= 0) {
                // If derivative values have different signs, perform binary search
                double left = lleftX;
                double right = leftX;
                while (right - left > 1e-6) {
                    double mid = (left + right) / 2;
                    double midDerivative = calculateDerivative(func, mid);
                    if (midDerivative * calculateDerivative(func, left) <= 0) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                zeros.push_back((left + right) / 2);
            }
            rightX = rrightX;
            leftX = lleftX;
        
            if(rightX >= 1.0/epsilon){
                break;
            }
            stepSize *= 2.0;
        }
        return zeros;
    }

    void findZeroInRange(int method) {
        // These do not work, I don't know what's wrong.
        // While in main function, these can work smoothly. The details are show in findZero_Newton.cpp
        // std::function<double(double)> f = func1;
        // std::function<double(double)> functions[] = { FunctionSolver::func1, FunctionSolver::func2, FunctionSolver::func3, FunctionSolver::func4 };
        std::function<double(double)> functions[] = {
            [this](double x) { return func1(x); },
            [this](double x) { return func2(x); },
            [this](double x) { return func3(x); },
            [this](double x) { return func4(x); }
        }; // Amazing!
        size_t numFunctions = sizeof(functions) / sizeof(functions[0]);
        double zero;
        for (size_t i = 0; i < numFunctions; ++i) {
            switch (method)
            {
                case 1:
                    zero = findZeroBinary(functions[i]);
                    break;
                case 2:
                    zero = findZeroNewton(functions[i]);
                    break;
                default:
                    std::cout << "invalid method number" << std::endl;
                    break;
            }
            
            std::cout << "Zero of func" << i+1 << ": " << zero << std::endl;
        }
    }

    void findDerivativeZeroInRange()
    {
        std::function<double(double)> functions[] = {
            [this](double x) { return func1(x); },
            [this](double x) { return func2(x); },
            [this](double x) { return func3(x); },
            [this](double x) { return func4(x); }
        }; // Amazing!
        size_t numFunctions = sizeof(functions) / sizeof(functions[0]);
        for (size_t i = 0; i < numFunctions; ++i) {
            double zero = findDerivativeZeroNewton(functions[i],0.0);
        }
    }

    void findDerivativeZerosInRange()
    {
         std::function<double(double)> functions[] = {
            [this](double x) { return func1(x); },
            [this](double x) { return func2(x); },
            [this](double x) { return func3(x); },
            [this](double x) { return func4(x); }
        }; // Amazing!
        size_t numFunctions = sizeof(functions) / sizeof(functions[0]);
        for (size_t i = 0; i < numFunctions; ++i) {
            std::vector<double> zeros = findDerivativeZeros(functions[i]);
            std::cout << "Derivate zeros of func" << i+1 << ": " << std::endl;
            for (size_t i = 0; i < zeros.size(); ++i) {
                std::cout << zeros[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    double a = 0.0;
    double b = 3.0;
    double epsilon = 1e-6;

    FunctionSolver solver(a, b, epsilon);
    solver.findZeroInRange(1); 
    solver.findDerivativeZeroInRange();
    solver.findDerivativeZerosInRange();
    return 0;
}
