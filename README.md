# Numerical-Analysis-Exercise

This repository contains C++ code for solving numerical analysis exercises. It includes various methods for finding zeros of functions and their derivatives.

## Table of Contents

- [Description](#description)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Functions](#functions)
- [License](#license)

## Description

This project aims to demonstrate different numerical methods for finding zeros of functions and their derivatives. It includes implementations of the binary search method and the Newton method for finding zeros, as well as methods for finding zeros of the derivatives of the functions. The code is organized in a `FunctionSolver` class, which provides methods for finding zeros in a specified range and for finding zeros of derivatives.

## Prerequisites

- C++ Compiler (e.g., GCC or Clang)
- C++ Standard Library
- Make (optional but recommended for building and running)

## Usage

To run the code, follow these steps:

1. Clone this repository to your local machine.
2. Open a terminal and navigate to the root directory of the project.
3. Use `make` to build the executable:

   ```bash
   make
   ```

4. Run the executable:

   ```bash
   ./main
   ```

The program will print the zeros of the specified functions and their derivatives within the given range.

## Functions

The `FunctionSolver` class contains several sample functions, each representing a different mathematical function. The current implementation includes the following functions:

1. `func1`: f(x) = x^2 - 4
2. `func2`: f(x) = sin(x)
3. `func3`: f(x) = x^3 + x^2 - 3
4. `func4`: f(x) = e^x - 2

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details. Feel free to use and modify the code according to the terms of the MIT License. If you find this project helpful, consider giving it a star on GitHub.
