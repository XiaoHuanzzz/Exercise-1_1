# Numerical Error Calculator

This is a C++ program that calculates the numerical errors for floating-point arithmetic operations. It takes the specified base and number of bits to control the precision of calculations and computes the errors for addition, subtraction, multiplication, and division operations.

## Code Structure

The code consists of the following parts:

### NumericalErrorCalculator Class

This class contains various functions to calculate errors. It has the following private member variables:

- `base_`: Specifies the base to convert floating-point values to the specified base.
- `bits_`: Specifies the number of bits to control the precision of floating-point numbers.
- `value1_`: The first floating-point number for operations.
- `value2_`: The second floating-point number for operations.

It also has the following private member functions:

- `absoluteError(double trueValue, double approxValue)`: Calculates the absolute error.
- `relativeError(double trueValue, double approxValue)`: Calculates the relative error.

The class has four public member functions, each of which calculates the error for addition, subtraction, multiplication, and division operations:

- `calculateAdditionError()`: Calculates the addition error.
- `calculateSubtractionError()`: Calculates the subtraction error.
- `calculateMultiplicationError()`: Calculates the multiplication error.
- `calculateDivisionError()`: Calculates the division error.

### main() Function

In the `main()` function, we first specify the base (`base`), the number of bits (`bits`), and the two floating-point numbers (`value1` and `value2`) for the operations. Then, we create an object `calculator` of the `NumericalErrorCalculator` class and call its four functions to calculate the errors. Finally, the program returns 0 to indicate successful execution.

## How to Run

1. Make sure you have a C++ compiler properly installed.
2. Save the above code as `numerical_error_calculator.cpp`.
3. Compile the code using the C++ compiler:
   ```
   g++ -o numerical_error_calculator numerical_error_calculator.cpp
   ```
4. Run the executable:
   ```
   ./numerical_error_calculator
   ```

## Output

After running the program, it will display the error results for the four arithmetic operations, including:

- True Value: The floating-point value after conversion to the specified base and precision.
- Approximated Value: The approximate floating-point value obtained under the specified base and precision.
- Absolute Error: The absolute difference between the true value and the approximate value.
- Relative Error: The relative difference between the true value and the approximate value.

## Note

The provided code has a flaw in the way it calculates the errors. It doesn't correctly simulate the numerical errors due to using a fixed number of bits to represent floating-point values. The error arises from the conversion of the decimal values to binary and back to decimal, leading to precision loss.

To demonstrate the issue, let's consider an example using base 10 and 4 bits of precision:

```cpp
int main() {
    int base = 10;
    int bits = 4;
    double value1 = 0.1;
    double value2 = 0.2;

    NumericalErrorCalculator calculator(base, bits, value1, value2);

    calculator.calculateAdditionError();
    calculator.calculateSubtractionError();
    calculator.calculateMultiplicationError();
    calculator.calculateDivisionError();

    return 0;
}
```

Output:

```
Addition Errors (Base 10, Bits 4):
True Value: 0.0001
Approximated Value: 0.0996
Absolute Error: 0.0995
Relative Error: 995.0

Subtraction Errors (Base 10, Bits 4):
True Value: 0.0001
Approximated Value: 0.0996
Absolute Error: 0.0995
Relative Error: 995.0

Multiplication Errors (Base 10, Bits 4):
True Value: 0.0001
Approximated Value: 0.0996
Absolute Error: 0.0995
Relative Error: 995.0

Division Errors (Base 10, Bits 4):
True Value: 0.0001
Approximated Value: 0.0996
Absolute Error: 0.0995
Relative Error: 995.0
```
