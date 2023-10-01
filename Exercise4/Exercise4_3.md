<h2 align = "center">
                  Exercise4_3

####  13.

The Trapezoidal rule applied to $\int _0^2 f(x)$ gives the value 4, and Simpson’s rule gives the value 2. What is f (1)?

**Trapezoidal rule:** $\dfrac{h_1}{2}(f(0)+f(2)) = 4$

**Simpson’s rule:** $\dfrac{h_2}{2}(f(0)+4f(1)+f(2)) = 2$

$f(1) = 0$

####  16.

Let $h = (b − a)/3, x_0 = a, x_1 = a + h,$ and $x_2 = b$. Find the degree of precision of the quadrature formula $\int ^b_ a f (x) dx = \dfrac{9}{4} hf (x_1) + \dfrac{3} {4} hf (x_2)$

$\int _a^b f(x) dx =\int_a^b [f(x_1)+f'(x_1)(x-x_1)]dx+f''(\xi_1)[(b-x_1)^3-(a-x_1)^3]/6 $

$f'(x_1) = \dfrac{f(x_2)-f(x_1)}{h}-\dfrac{f''(\xi_2)}{2}h$

$\int_a^b f(x)dx= \int_a^b[f(x_1)+\dfrac{f(x_2)-f(x_1)}{h}(x-x_1)]dx-\dfrac{3f''(\xi_2)}{4}h^3+\dfrac{3f''(\xi_1)}{2}h^3$

$=  \dfrac{3h}{4}(3f(x_1)+f(x_2))+\dfrac{3f''(\xi)}{4}h^3$

The degree of precision of the quadrature formula is 1.