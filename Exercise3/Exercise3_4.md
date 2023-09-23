<h2 align = "center">
                  Exercise3_4

####  3.

The data in Exercise 1 were generated using the following functions. Use the polynomials constructed in Exercise 1 for the given value of x to approximate f (x), and calculate the absolute error. 

**a.** f (x) = x ln x; approximate f (8.4). 

**b.** f (x) = sin(ex − 2); approximate f (0.9). 

**c.** f (x) = x3 + 4.001x2 + 4.002x + 1.101; approximate f (−1/3). 

**d.** f (x) = x cos x − 2x2 + 3x − 1; approximate f (0.25).

**a.** x f (x) f  (x) 

8.3 17.56492 3.116256 

8.6 18.50515 3.151762 

**b.** x f (x) f  (x) 

0.8 0.22363362 2.1691753 

1.0 0.65809197 2.0466965 

**c.** x f (x) f  (x) 

−0.5 −0.0247500 0.7510000 

−0.25 0.3349375 2.1890000 

0 1.1010000 4.0020000 

**d.** x f (x) f  (x) 

0.1 −0.62049958 3.58502082 

0.2 −0.28398668 3.14033271 

0.3 0.00660095 2.66668043 

0.4 0.24842440 2.16529366



a.
$$
\left(\begin{matrix}
  0&8.3&17.56492&
\\1&8.3&17.56492&3.116256&
\\2&8.6&18.50515&3.134100&0.05948
\\3&8.6&18.50515&3.151762&0.05887&-0.00203
\end{matrix}\right)
$$
$H_n(x) = 17.56492+3.116256(x-8.3)+0.05948(x-8.3)^2-0.00203(x-8.3)^2(x-8.6)$

$H_n(8.4) = 17.87714$

$f(8.4) = 17.87714$

$absolute\;error = 0.00000$