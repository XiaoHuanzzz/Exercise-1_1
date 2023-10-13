<h2 align = "center">
                 Exercise5_3

####  8.

Repeat Exercise 6 using Taylor’s method of order four.

b. $y' = \dfrac{y^2}{1+t}, 1\le t\le 2, y(1) = -\dfrac{1}{\ln 2}, h = 0.1$

$f(t, y) = \dfrac{y^2}{1+t}, f'(t,y) = \dfrac{2y^3-y^2}{(1+t)^2}$

$f''(t,y) = \dfrac{6y^4-6y^3+2y^2}{(1+t)^3},f'''(t,y)=\dfrac{24y^4-36y^4+22y^3-6y^2}{(1+t)^4}$

$\omega_{i+1} = \omega_i + h T^{(4)}(t_i,\omega_i)$

By using `TaylorMethodOfOrderFour.cpp`, The approximations are 

```
(1, -1.4427)(1.1,-1.3511)(1.2,-1.2739)(1.3,-1.20787)(1.4,-1.1507)(1.5,-1.10068)(1.6,-1.05651)(1.7,-1.01719)(1.8,-0.981945)(1.9,-0.950148)(2,-0.921302)(2.1,-0.895)
```

