/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-09-19 16:03:21
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-09-20 13:34:57
 * @FilePath: \Exercise3\NevilleMethod.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>

// 计算拉格朗日插值多项式的值列表
std::vector<std::vector<double>> NevilleIteratedInterpolation(double x0, std::vector<double> x, std::vector<double> y) {
    int n = x.size();

    // 创建一个二维数组来存储中间结果
    std::vector<std::vector<double>> F(n+1, std::vector<double>(n+1, 0.0));

    // 初始化数组的第一列
    for (int i = 0; i < n; i++) {
        F[i][0] = y[i];
    }

    // 递归计算数组的其他列
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            F[row][col] = (x0 - x[row-col])*F[row][col-1] - (x0 - x[row])*F[row-1][col-1];
            F[row][col] /= x[row] - x[row-col];
        }
    }

    // 构建结果列表
    std::vector<std::vector<double>> result = F;


    return result;
}

int main() {
    double x0 = 2.5;
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {0.0, 1.0, 8.0, 27.0, 64.0};

    // 计算并输出拉格朗日多项式在给定点处的值列表
    std::vector<std::vector<double>> Q = NevilleIteratedInterpolation(x0, x, y);
    for (int i = 1; i < Q.size(); i++) {
        for(int j = 1; j <= i; j++)
            std::cout << "Q_" << i << ',' << j << '(' <<  x0 << ") = " << Q[i][j] << ' ';
        std::cout << std::endl;
    }

    return 0;
}
