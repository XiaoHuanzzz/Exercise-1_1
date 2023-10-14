<h2 align = "center">
               Note5_4

    ####  Midpoint Method

Local Truncation Error: $O(h^2)$

Matching coefficients by using Taylor polynomial to expand $f(t+\alpha_1, w + \beta_1)$ and $T_{(2)}(t, y)$, because having $f(t, w)$ is not enough, we need to get the differentiate format of the other point.

So we obtain $f(t+\alpha_1, w+\beta_1) = f(t+\dfrac{h}{2}, w + \dfrac{h}{2}f(t,w))$

$w_{i+1} = w_i+hf(t_i+\dfrac{h}{2}, w_i+\dfrac{h}{2}f(t_i,w_i))$

####  Modified Euler Method

Local Truncation Error: $O(h^2)$

By using the same train of thought, we use $\dfrac{f(t_i,w_i)+f(t_i+h, w_i+hf(t_i,w_i))}{2}$ to replace $f(t_i+\dfrac{h}{2}, w_i+\dfrac{h}{2}f(t_i,w_i))$, replace $T^{(3)}$ to $T^{(2)}$.(But not matcing all the coefficients)

$w_{i+1} = w_i+\dfrac{h}{2}(f(t_i,w_i)+f(t_i+h, w_i+hf(t_i,w_i))$

####  Heun’s Method

Local Truncation Error: $O(h^3)$

Finding the expression of form $f(t+\alpha_1, y+\delta_1f(t+\alpha_2, y+\delta_2f(t,y)))$, which matchs all the coeffients of $T^{(3)}$

$w_{i+1} = w_i+\dfrac{h}{4}(f(t_i+w_i)+3f(t_i+\dfrac{2h}{3},w_i+\dfrac{2}{3}hf(t_i+\dfrac{h}{3},w_i+\dfrac{h}{3}f(t_i,w_i))))$

####  Runge-Kutta Method

Local Truncation Error: $O(h^4)$

This is a changing format of Trapezoidal method. Calculate the derivative step by step, and combine them together.
$$
K_1 = f(t_i, w_i)
\\K_2 = f(t_i+\dfrac{h}{2}, w_i+\dfrac{K_1}{2})
\\K_3 = f(t_i+\dfrac{h}{2}, w_i+\dfrac{K_2}{2})
\\K_4 = f(t_{i+1}, w_i+K_3)
\\w_{i+1} = w_i+\dfrac{h}{6}(K_1+2K_2+2K_3+K_4)
$$

####  Computational Comparisons

Higher accuracy order need even much higher steps of calculations.  So the methods of order less than five with smaller step size are used in preference to the higher-order methods using a larger step size.