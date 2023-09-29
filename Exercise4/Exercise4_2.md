<h2 align = "center">
                  Exercise4_2

####  1.

Apply the extrapolation process described in Example 1 to determine N3(h), an approximation to f  (x0), for the following functions and stepsizes. 

a.$ f (x) = \ln x, x_0 = 1.0, h = 0.4$ b. $f (x) = x + e^x , x_0 = 0.0, h = 0.4$

$f(x_0+h) = f(x_0)+f'(x_0)h+\dfrac{f''(x_0)}{2}h^2+\cdots$

$f(x_0-h) = f(x_0)-f'(x_0)h+\dfrac{f''(x_0)}{2}h^2+\cdots$

$f'(x_0) = \dfrac{f(x_0+h)-f(x_0-h)}{2h}-\dfrac{f'''(x_0)}{6}h^2-\dfrac{f^{(5)}(x_0)}{120}h^4+o(h^5)$

a. $N_2(h) = \dfrac{f(x_0+h)-f(x_0-h)}{2h}= 1.0591$

b. $N_2(h) = 1.6215$

####  2.

Add another line to the extrapolation table in Exercise 1 to obtain the approximation N4(h).

$N_1(h) = \dfrac{f(x_0+h)-f(x_0)}{h} $

$f'(x_0) = N_1(h)+ \dfrac{f''(x_0)}{2}h+\dfrac{f'''(x_0)}{6}h^2+\dfrac{f''''(x_0)}{24}h^3+\dfrac{f^{(5)}(x_0)}{120}h^4+o(h^4)$

$N_1(\dfrac{h}{2}) = \dfrac{f(x_0+\dfrac{h}{2})-f(x_0)}{\dfrac{h}{2}}$

$f'(x_0) = N_1(\dfrac{h}{2})+\dfrac{f''(x_0)}{4}h+\dfrac{f'''(x_0)}{24}h^2+\dfrac{f''''(x_0)}{192}h^3+\dfrac{f^{(5)}(x_0)}{1920}h^4+o(h^4)$

$N_2(h) = 2N_1(\dfrac{h}{2})-N_1(h) = \dfrac{4f(x_0+\dfrac{h}{2})-3f(x_0)-f(x_0+h)}{h}$

$f'(x_0) = N_2(h) - \dfrac{f'''(x_0)}{12}h^2-\dfrac{f''''(x_0)}{32}h^3-\dfrac{7f^{(5)}(x_0)}{960}h^4 +o(h^4)$

$N_2(\dfrac{h}{2}) = \dfrac{8f(x_0+\dfrac{h}{4})-6f(x_0)-2f(x_0+\dfrac{h}{2})}{h}$

$f'(x_0) = N_2(\dfrac{h}{2}) - \dfrac{f'''(x_0)}{48}h^2-\dfrac{f''''(x_0)}{256}h^3-\dfrac{7f^{(5)}(x_0)}{15360}h^4 +o(h^4)$

$N_3(h) = \dfrac{1}{3}(4N_2(\dfrac{h}{2})-N_2(h)) = \dfrac{f(x_0+h)-12f(x_0+\dfrac{h}{2})+ 32f(x_0+\dfrac{h}{4})-21f(x_0)}{3h}$

$f'(x_0) = N_3(h) + \dfrac{f'''(x_0)}{192}h^3+\dfrac{7f^{(5)}(x_0)}{1280}h^4+o(h^4)$

a. $N_3(h) = 0.9988$

b. $N_3(h) = 2.0004$