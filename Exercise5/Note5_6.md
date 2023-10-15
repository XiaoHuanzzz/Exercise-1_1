<h2 align = "center">
               Note5_6

###  Multistep Method

$$
y_{i+1} \approx y_{i}+h(f(t_i,y_i)+a_1\nabla f(t_i,y_i)+ ...)
\\\int_{t_i}^{t_{i+1}}f(t,y(t))\, dt = \int_{t_i}^{t_{i+1}}\sum\limits_{k=0}^{m-1}(-1)^k \left(\begin{matrix}
-s\\k
\end{matrix}\right)\nabla^k f(t_i,y(t_i)) dt
\\ a_k = \int_{t_i}^{t_{i+1}}(-1)^k\left(\begin{matrix}
-s\\k
\end{matrix}\right)
$$

![image-20231014150848918](C:\Users\xiaohuan\AppData\Roaming\Typora\typora-user-images\image-20231014150848918.png)

####  Adams-Bashforth method

#####  two-step:

Local Truncation Error: $O(h^2)$

$w_{i+1} = w_i + \dfrac{h} {2} [3f (t_i, w_i) − f (t_{i−1}, w_{i−1})]$

#####  three-step:

Local Truncation Error: $O(h^3)$

$\nabla,...,\nabla^{m-1} f$ is derived using Taylor Polynomials, and m = 3

$y(t_i)\approx y(t_i) + \dfrac{h} {12}[23f (t_i, y(t_i)) − 16f (t_{i−1}, y(t_{i−1})) + 5f (t_{i−2}, y(t_{i−2}))]$

#####  four-step:

Local Truncation Error: $O(h^4)$

$w_{i+1} = w_i + \dfrac{h}{ 24}[55f (t_i, w_i) − 59f (t_{i−1}, w_{i−1}) + 37f (t_{i−2}, w_{i−2}) − 9f (t_{i−3}, w_{i−3})]$

####  Adams-Moulton Implicit Method

Compared with explicit method, it increases a step $f(t_{i+1}, w_{i+1})$ for which the local truncation error decreases to $O(h^{m+1})$. 

But the method should solve the implicit equation first, and not all of them has a solution.

There are complicated methods to solve them, but could increase the error and calculations.

####  Predictor-Corrector Method

Use the Adams-Bashforth method as a predictor and the Adams-Moulton method as a corrector.

$w_{4p} = w_3 + \dfrac{h}{ 24}[55f (t_3, w_3) − 59f (t_{2}, w_{2}) + 37f (t_{1}, w_{1}) − 9f (t_{0}, w_{0})]$

$w_4 = w_3 + \dfrac{h} {24}[9f (t_4, w_{4p}) + 19f (t_3, w_3) − 5f (t_2, w_2) + f (t_1, w_1)]$

####  Explicit Milne’s Method

Use integration of interpolating polynomials.(Can be derived by Simpson’s rule and Newton Cotes, etc.)

The local truncation error is generally smaller than that of the Adams-Bashforth-Moulton method. But the technique has limited use because of round-off error problems.

See page 331.