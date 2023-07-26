#include <cmath>
#include <iostream>

class NumericalErrorCalculator {
private:
    int base_;    // 进制
    int bits_;    // 位数
    double value1_; // 第一个要进行运算的数
    double value2_; // 第二个要进行运算的数

    // Function to calculate absolute error
    double absoluteError(double trueValue, double approxValue) {
        return std::abs(trueValue - approxValue);
    }

    // Function to calculate relative error
    double relativeError(double trueValue, double approxValue) {
        return std::abs((trueValue - approxValue) / trueValue);
    }

public:
    // Constructor
    NumericalErrorCalculator(int base, int bits, double value1, double value2)
        : base_(base), bits_(bits), value1_(value1), value2_(value2) {}

    // Function to calculate addition error
    void calculateAdditionError() {
        double trueResult = value1_ + value2_;

        // Convert values to specified base and precision
        double trueValue = value1_;
        double approxValue = 0.0;

        for (int i = 0; i < bits_; i++) {
            trueValue /= base_;
        }

        for (int i = 0; i < bits_; i++) {
            approxValue += value1_;
            value1_ /= base_;
        }

        // Calculate errors
        double absoluteErr = absoluteError(trueResult, approxValue);
        double relativeErr = relativeError(trueResult, approxValue);

        // Output errors
        std::cout << "Addition Errors (Base " << base_ << ", Bits " << bits_ << "):" << std::endl;
        std::cout << "True Value: " << trueValue << std::endl;
        std::cout << "Approximated Value: " << approxValue << std::endl;
        std::cout << "Absolute Error: " << absoluteErr << std::endl;
        std::cout << "Relative Error: " << relativeErr << std::endl;
    }

    // Function to calculate subtraction error
    void calculateSubtractionError() {
        double trueResult = value1_ - value2_;

        // Convert values to specified base and precision
        double trueValue = value1_;
        double approxValue = 0.0;

        for (int i = 0; i < bits_; i++) {
            trueValue /= base_;
        }

        for (int i = 0; i < bits_; i++) {
            approxValue += value1_;
            value1_ /= base_;
        }

        // Calculate errors
        double absoluteErr = absoluteError(trueResult, approxValue);
        double relativeErr = relativeError(trueResult, approxValue);

        // Output errors
        std::cout << "Subtraction Errors (Base " << base_ << ", Bits " << bits_ << "):" << std::endl;
        std::cout << "True Value: " << trueValue << std::endl;
        std::cout << "Approximated Value: " << approxValue << std::endl;
        std::cout << "Absolute Error: " << absoluteErr << std::endl;
        std::cout << "Relative Error: " << relativeErr << std::endl;
    }

    // Function to calculate multiplication error
    void calculateMultiplicationError() {
        double trueResult = value1_ * value2_;

        // Convert values to specified base and precision
        double trueValue = value1_;
        double approxValue = 0.0;

        for (int i = 0; i < bits_; i++) {
            trueValue /= base_;
        }

        for (int i = 0; i < bits_; i++) {
            approxValue += value1_;
            value1_ /= base_;
        }

        // Calculate errors
        double absoluteErr = absoluteError(trueResult, approxValue);
        double relativeErr = relativeError(trueResult, approxValue);

        // Output errors
        std::cout << "Multiplication Errors (Base " << base_ << ", Bits " << bits_ << "):" << std::endl;
        std::cout << "True Value: " << trueValue << std::endl;
        std::cout << "Approximated Value: " << approxValue << std::endl;
        std::cout << "Absolute Error: " << absoluteErr << std::endl;
        std::cout << "Relative Error: " << relativeErr << std::endl;
    }

    // Function to calculate division error
    void calculateDivisionError() {
        double trueResult = value1_ / value2_;

        // Convert values to specified base and precision
        double trueValue = value1_;
        double approxValue = 0.0;

        for (int i = 0; i < bits_; i++) {
            trueValue /= base_;
        }

        for (int i = 0; i < bits_; i++) {
            approxValue += value1_;
            value1_ /= base_;
        }

        // Calculate errors
        double absoluteErr = absoluteError(trueResult, approxValue);
        double relativeErr = relativeError(trueResult, approxValue);

        // Output errors
        std::cout << "Division Errors (Base " << base_ << ", Bits " << bits_ << "):" << std::endl;
        std::cout << "True Value: " << trueValue << std::endl;
        std::cout << "Approximated Value: " << approxValue << std::endl;
        std::cout << "Absolute Error: " << absoluteErr << std::endl;
        std::cout << "Relative Error: " << relativeErr << std::endl;
    }
};

int main() {
    int base = 10;      // Specify the base (e.g., 10 for decimal)
    int bits = 4;       // Specify the number of bits (e.g., 4 for 4 bits)
    double value1 = 0.1; // Specify the first value for operations
    double value2 = 0.2; // Specify the second value for operations

    NumericalErrorCalculator calculator(base, bits, value1, value2);

    calculator.calculateAdditionError();
    calculator.calculateSubtractionError();
    calculator.calculateMultiplicationError();
    calculator.calculateDivisionError();

    return 0;
}
