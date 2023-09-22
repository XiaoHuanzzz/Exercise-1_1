<h2 align = "center">
                  Exercise3_3

####  9.

**a.** Approximate f (0.05) using the following data and the Newton forward-difference formula:

 x     0.0 0.2 0.4 0.6 0.8 

f (x) 1.00000 1.22140 1.49182 1.82212 2.22554 

**b.** Use the Newton backward-difference formula to approximate f (0.65). 

**c.** Use Stirling’s formula to approximate f (0.43)

a. $h = 0.2$,$s = 0.25$ 
$$
\left(\begin{matrix}
0 & 0.0   & 1.00000
\\ &      &         & 0.22140
\\1 & 0.2 & 1.22140 &		  & 0.04902
\\ &      &  		& 0.27042 &			& 0.01086
\\2 & 0.4 & 1.49182 & 		  & 0.05988 &		  & 0.00238
\\ &	  &			& 0.33030 &			& 0.01324	
\\3 & 0.6 & 1.82212 &         & 0.07312
\\ &	& 			& 0.40342
\\4 & 0.8 & 2.22554
\end{matrix}\right)
$$


Newton forward-difference formular: 
$$
P_n(x) = f(x_0) + \sum\limits_{k = 1}^n \left(\begin{array}
\\s\\k
\end{array}
\right)
\Delta^kf(x_0)
\\ = 1.00000+\dfrac{0.25}{1!}0.22140 + \dfrac{0.25\times(0.25-1)}{2!}0.04902
\\+\dfrac{0.25(0.25-1)(0.25-2)}{3!}0.01086+\dfrac{0.25(0.25-1)(0.25-2)(0.25-3)}{4!}0.00238
\\ = 1.05126
$$
b. $s = -0.75$

Newton backward-difference formular:
$$
P_n(x) = f(x_n)+\sum\limits_{i=1}^n(-1)^k\left(\begin{array}
 \\-s\\k
\end{array}\right)
\nabla^kf(x_n
)\\ = 2.22554 -\dfrac{0.75}{1}0.40342 + \dfrac{0.75(0.75-1)}{2}0.07312 - \dfrac{0.75(0.75-1)(0.75-2)}{6}0.01324
\\+\dfrac{0.75(0.75-1)(0.75-2)(0.75-3)}{24}0.00238
\\ = 1.91555
$$
c.$s = 0.15$

Stirling’s formular:
$$
P_n(x) = 1.49182+\dfrac{0.15\cdot 0.2}{2}(0.27042+0.33030)+0.15^20.2^2\cdot0.05988
\\+\dfrac{(0.15-1)0.15(0.15+1)}{2}0.2^3(0.01086+0.01324)+0.15^2(0.15^2-1)0.2^4\cdot0.00238
\\=1.50087
$$


