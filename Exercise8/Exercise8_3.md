<h2 align = "center">
                 Exercise8_3

####  1.

Use the zeros of $\tilde T_3$ to construct an interpolating polynomial of degree 2 for the following functions on the interval [−1, 1]. 

a. $f (x) = e^x$

$\tilde T_3(x) = x^3-\dfrac{3}{4}x$

$x_0 = -\dfrac{\sqrt{3}}{2}, x_1 = 0, x_2 = \dfrac{\sqrt{3}}{2}$

$f_0 = 0.421,f_1 = 1, f_2 = 2.377$

$L_0(x) = 0.281x(x-0.866)$

$L_1(x) = -1.333(x^2-0.75)$

$L_2(x) = 1.585x(x+0.866)$

$P_2(x) = L_0(x)+L_1(x)+L_2(x) = 0.533x^2+1.129x+1$

####  6.

Find the sixth Maclaurin polynomial for $xe^x$ , and use Chebyshev economization to obtain a lesser degree polynomial approximation while keeping the error less than 0.01 in [-1, 1].

$P_6(x) = 0 + x +x^2+\dfrac{1}{2}x^3 +\dfrac{1}{6}x^4+\dfrac{1}{24}x^5+\dfrac{1}{120}x^6$

$R_6(x) = \dfrac{\vert f^{(7)}(\xi) x^7\vert}{5020} \le 0.0043$

$\tilde T_3(x) = x^3-\dfrac{3}{4}x, \tilde T_4(x) = x^4-x^2+\dfrac{1}{8}$

$\tilde T_5(x) = x^5 - \dfrac{5}{4}x^3 +\dfrac{5}{16}x, \tilde T_6(x) = x^6 -\dfrac{3}{2}x^4 + \dfrac{9}{16}x^2 - \dfrac{1}{32}$

$P_5(x)=P_6(x) - \dfrac{1}{120}\tilde T_6(x) =\dfrac{1}{3840}+ x+ \dfrac{637}{640}x^2+ \dfrac{1}{2}x^3 +\dfrac{43}{120}x^4 + \dfrac{1}{24}x^5$

$\vert P_6(x)-P_5(x)\vert = \dfrac{1}{120}(\dfrac{1}{2})^5 = 0.00046$

$0.0043+0.00046 < 0.01$