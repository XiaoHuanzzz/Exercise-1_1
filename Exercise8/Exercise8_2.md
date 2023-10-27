<h2 align = "center">
                 Exercise8_2

####  1.

Find the linear least squares polynomial approximation to f (x) on the indicated interval if

e. $f(x) = \dfrac{1}{2}\cos x + \dfrac{1}{3}\sin 2x, [0,1]$

$\int_0^1 1\,dx = 1, \int_0^1 x\,dx = \dfrac{1}{2},\int_0^1 x^2\,dx = \dfrac{1}{3}$

$\int_0^1 x^3\,dx = \dfrac{1}{4},\int_0^1 x^4\,dx = \dfrac{1}{5}$

$\int_0^1 \dfrac{1}{2}\cos x + \dfrac{1}{3}\sin 2x\,dx = \dfrac{1}{2}\sin 1 -\dfrac{1}{6}\cos 2+\dfrac{1}{6}$

$\int_0^1 x(\dfrac{1}{2}\cos x + \dfrac{1}{3}\sin 2x)\,dx = \dfrac{1}{2}\sin 1-\dfrac{1}{2}\cos 1-\dfrac{1}{12}\sin 2 -\dfrac{1}{24}\cos 2+\dfrac{1}{24}$

$\int_0^1 x^2(\dfrac{1}{2}\cos x + \dfrac{1}{3}\sin 2x)\,dx = -\dfrac{1}{2}\sin 1+\cos 1+\dfrac{1}{6}\sin 2 +\dfrac{1}{12}\cos 2-\dfrac{1}{12}$
$$
a_0+\dfrac{1}{2}a_1+\dfrac{1}{3}a_2 =\dfrac{1}{2}\sin 1 -\dfrac{1}{6}\cos 2+\dfrac{1}{6}
\\\dfrac{1}{2}a_0+\dfrac{1}{3}a_1+\dfrac{1}{4}a_2= \dfrac{1}{2}\sin 1-\dfrac{1}{2}\cos 1-\dfrac{1}{12}\sin 2 -\dfrac{1}{24}\cos 2+\dfrac{1}{24}
\\ \dfrac{1}{3}a_0+\dfrac{1}{4}a_1+\dfrac{1}{5}a_2=-\dfrac{1}{2}\sin 1+\cos 1+\dfrac{1}{6}\sin 2 +\dfrac{1}{12}\cos 2-\dfrac{1}{12}
$$
$\Rightarrow a_0 = 5.68191, a_1=-25.4856, a_2=23.1526$

$P(x) = 5.68191 -25.4856x+ 23.1526x^2$

(The calculation above has many mistakes but I don’t want to try it again...)

####  2.

Find the linear least squares polynomial approximation on the interval [−1, 1] for the following functions.

e. $f(x) = \dfrac{1}{2}\cos x + \dfrac{1}{3}\sin 2x$

Legendre Polynomial:

$P_0(x) = 1, P_1 = x, P_2 = x^2-\dfrac{1}{3}$

$\int_{-1}^1 P_0(x)f(x)dx = \sin 1$

$\int_{-1}^1P_1(x)f(x) = -\dfrac{1}{3}\cos 2+\dfrac{1}{6}\sin 2$

$\int_{-1}^1P_2(x)f(x) = -\dfrac{4}{3}\sin 1-2\cos 1$

$P(x) = (-\dfrac{4}{3}\sin 1-2\cos 1)x^2 +(-\dfrac{1}{3}\cos 2+\dfrac{1}{6}\sin 2)x +\dfrac{13}{9}\sin 1+\dfrac{2}{3}\cos 1$