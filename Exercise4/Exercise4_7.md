<h2 align = "center">
                 Exercise4_7

####  1.

Approximate the following integrals using Gaussian quadrature with n = 2, and compare your results to the exact values of the integrals. 

a. $\int ^{1.5}_ 1 x^2 \ln x \,dx$

$\int ^{1.5}_ 1 x^2 \ln x \,dx = \int_{-0.25}^{0.25}(x+1.25)^2\ln (x+1.25)\,dx $

$= \int_{-1}^1 (0.25x+1.25)^2\ln (0.25x+1.25) \,d0.25x = \int_{-1}^1 \dfrac{(x+5)^2}{64}(\ln (x+5)-\ln 4)\,dx $

$\approx f(0.57735)+f(-0.57735)=0.16157+0.03070=0.19227$

####  5.

Determine constants a, b, c, and d that will produce a quadrature formula $\int^1 _{−1} f (x)\, dx = af (−1) + bf (1) + cf ‘ (−1) + df’(1)$ that has degree of precision 3.

$\int_{-1}^11\,dx = a+b = 2$

$\int_{-1}^1 x\,dx = -a+b+c+d = 0$

$\int_{-1}^1 x^2\,dx = a+b-2c+2d = \dfrac{2}{3}$

$\int_{-1}^1x^3\,dx = -a+b+3c+3d = 0 $

$\Rightarrow a=1,b=1,c=\dfrac{1}{3},d = -\dfrac{1}{3}$