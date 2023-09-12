#include<iostream>
#include<algorithm>
#include<functional>

#define epsilon_ 0.0000001

double bisectionMethod(std::function<double(double)> func, double a_, double b_) {
    double left = a_;  // 区间左端点
    double right = b_;  // 区间右端点

    while (right - left > epsilon_) {
        double mid = left +(left - right) / 2.0; // 避免使用(left+right)/2.0，见P54
        // 当(left-right)接近最大精度，(left+right)/2.0可能不在[left, right]中
        if (func(mid) == 0.0) {
            return mid;
        }
        // 使用符号函数避免乘法溢出，见P54
        else if (bool(func(mid)) * bool(func(left)) < 0) {
            right = mid;
        }
        else {
            left = mid;
        }
        std::cout << "left = " << left << " right = " << right << std::endl;
    }

    return (left + right) / 2.0;
    };

double function(double x){
    double f = x*(x*(x*(x*2+3)+4)-5)-6; // 将多项式写成秦九韶算法，降低运算步数和相对误差，出自P28
    return f;
}

int main(){
    double zero = bisectionMethod(function, -1, 1);    
    std::cout << "Found zero at: " << zero << std::endl;

}
