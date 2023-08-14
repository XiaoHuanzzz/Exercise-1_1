/*
 * @Author: (xiao_huan) 1156492597@qq.com
 * @Date: 2023-07-27 22:56:11
 * @LastEditors: (xiao_huan) 1156492597@qq.com
 * @LastEditTime: 2023-08-14 11:30:43
 * @FilePath: \Numerical Analysis Exercise\Exercise1_2\test2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <limits>

int determineSign(double number) {
    if (number >= 0) {
        return 0; // 输入的数为正，返回0
    } else {
        return 1; // 输入的数为负，返回1
    }
}

int signFunction(double number) {
    if (number > 0) {
        return 1; // 正数返回1
    } else if (number < 0) {
        return -1; // 负数返回-1
    } else {
        return 0; // 零返回0
    }
}

std::vector<int> decimalToBaseN(double decimalNumber, int bits1, int bits2, int base) {
    std::vector<int> integerBits, decimalBits, powerBits, customRadixBits;
    // customRadixBits.push_back(determineSign(decimalNumber));  // 符号位
    // std::cout << customRadixBits[0] << std::endl;

    int integerPart = static_cast<int>(abs(decimalNumber)); //整数部分
    double decimalPart = std::abs(decimalNumber) - static_cast<double>(integerPart);  //小数部分
    // std::cout << integerPart << ',' << decimalPart << std::endl; //no bug

    // 整数部分转换
    int integerPrecision = bits1-1;  // 位数上限bits1,符号位1位
    while (integerPart > 0) {
        int remainder = integerPart % base;
        integerBits.insert(customRadixBits.begin(), remainder); // 先存整数位
        integerPart /= base;
        integerPrecision--;
    }
    int power = -precision1;
    int decimalPrecision = integerPrecision;
    // 小数部分转换
    while (decimalPart > 0 && decimalPrecision > 0) {
        decimalPart *= base;
        int bit = static_cast<int>(decimalPart);
        decimalBits.push_back(bit);
        decimalPart -= bit;
        decimalPrecision--;
    }
    customRadixBits.insert(customRadixBits.end(), integerBits.begin(), integerBits.end());
    customRadixBits.insert(customRadixBits.end(), decimalBits.begin(), decimalBits.end());
    // 若位数不全则补全
    if(sizeof(customRadixBits) < bits1-1){
        for(int i = 0; i < bits1-1-customRadixBits; i++){
            customRadixBits.insert(customRadixBits.begin(), 0);
        }
    }
    // 符号位
    customRadixBits.insert(customRadixBits.begin(), determineSign(decimalNumber));
    // 按位数截断
    customRadixBits.assign(customRadixBits.begin(), customRadixBits.begin() + bits1);
    // 幂的部分
    int absPower = abs(power);
    int powerPrecision = bits2-1;  // 位数上限bits2,符号位1位
    // 位数太多可直接判定溢出
    while (absPower > 0 && powerPrecision > 0) {
        int remainder = absPower % base;
        powerBits.insert(powerBits.begin(), remainder);
        absPower /= base;
        powerPrecision--;
    }
    // std::cout << powerBits[2] << powerBits[1] << std::endl;
    // 补充0位
    for(int i = 1; i <= powerPrecision; i++){
        powerBits.insert(powerBits.begin(), 0);
    }
    // 补充符号位
    powerBits.insert(powerBits.begin(), determineSign(power));
    if(precision2 == 0)// 超出上限，输出符号位+11111111+符号位+11111
    {
        std::vector<int> infVector;
        infVector.resize(bits1+bits2-1, base-1);
        infVector.insert(infVector.begin(), determineSign(decimalNumber));
        infVector[bits1] = determineSign(power);
        return infVector;
    }
    // 合并
    for (int num : powerBits) {
        customRadixBits.push_back(num);
    }

    return customRadixBits;
}

int main() {
    double decimalNumber = 0.1;
    std::vector<int> customRadixBits = decimalToBaseN(decimalNumber, 10, 10, 10);

    // Display the binary representation
    std::cout << decimalNumber << " in binary is: ";
    for (int bit : customRadixBits) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}
