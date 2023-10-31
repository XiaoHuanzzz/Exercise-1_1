<h2 align = "center">
                 Exercise8_5

####  1.

Find the continuous least squares trigonometric polynomial $S_2(x)$ for $f (x) = x^2$ on [−π, π].

$S_2(x) = \dfrac{a_0}{2} + a_1\cos x+b_1\sin x + a_2\cos 2x$

$a_0 = \int_{-\pi}^\pi f(x)dx = \dfrac{2}{3}\pi^3$

$a_1 = \int_{-\pi}^\pi f(x)\cos xdx = [x\sin x+\cos x]\vert^\pi_{-\pi} = 0$

$a_2 = \int_{-\pi}^\pi f(x)(\cos x)^2dx  = 0$

$b_1 =  \int_{-\pi}^\pi f(x)\sin xdx  = [-x\cos x+\sin x]\vert^\pi_{-\pi} = 2\pi$

$S_2(x) = \dfrac{\pi^3}{3}+2\pi \sin x$

####  7.

Determine the discrete least squares trigonometric polynomial $S_n(x)$ on the interval [−π, π] for the following functions, using the given values of m and n: 

a. $f (x) = \cos 2x, m = 4, n = 2$

$S_2(x) = \dfrac{a_0}{2} + a_1\cos x+b_1\sin x + a_2\cos 2x$

$x_0 = -\pi, x_1 = -\dfrac{3\pi}{4},x_2 = -\dfrac{\pi}{2}, x_3 =-\dfrac{\pi}{4},  x_4 = 0, x_5 = \dfrac{\pi}{4},x_6 = \dfrac{\pi}{2}, x_7 =\dfrac{3\pi}{4}$

$y_0 = 1,y_1 = 0, y_2 = -1, y_3 = 0,  y_4 = 1, y_5 = 0, y_6 = -1, y_7 = 0$

$a_k = \dfrac{1}{4}\sum\limits_{j = 0}^7 y_j\cos kx_j, k = 0,1,2$

$a_0 = 0, a_1= (-1+0+0+0+1+0+0+0)/4 = 0, a_2 = 1$

$b_k = \dfrac{1}{4}\sum\limits_{j = 0}^7 y_j\sin kx_j, k = 0,1,2$

$b_1 = (0+0+1+0+0+0-1+0)/4 = 0$

$S_2(x) = \cos 2x$

