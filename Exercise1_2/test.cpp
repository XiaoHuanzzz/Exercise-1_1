#include <iostream>
#include <string>

std::string decimalToBinary(double decimalNumber) {
    if (decimalNumber == 0) {
        return "0";  // Special case for 0
    }

    int integerPart = abs(static_cast<int>(decimalNumber));
    double decimalPart = abs(decimalNumber - integerPart);

    // Convert the integer part to binary
    std::string binaryIntegerPart = "";
    while (integerPart > 0) {
        int remainder = integerPart % 2;
        binaryIntegerPart = std::to_string(remainder) + binaryIntegerPart;
        integerPart /= 2;
    }

    // Convert the decimal part to binary
    std::string binaryDecimalPart = "";
    int precision = 20;  // Set a maximum precision for the decimal part
    while (decimalPart > 0 && precision > 0) {
        decimalPart *= 2;
        int bit = static_cast<int>(decimalPart);
        binaryDecimalPart += std::to_string(bit);
        decimalPart -= bit;
        precision--;
    }

    // Combine the binary parts with a decimal point
    std::string binaryRepresentation = binaryIntegerPart;
    if (!binaryDecimalPart.empty()) {
        binaryRepresentation += "." + binaryDecimalPart;
    }

    // Add the sign for negative numbers
    if (decimalNumber < 0) {
        binaryRepresentation = "-" + binaryRepresentation;
    }

    return binaryRepresentation;
}

int main() {
    double decimalNumber = 12.25;
    std::string binaryNumber = decimalToBinary(decimalNumber);
    std::cout << decimalNumber << " in binary is: " << binaryNumber << std::endl;
    return 0;
}
