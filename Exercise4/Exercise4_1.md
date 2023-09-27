<h2 align = "center">
                  Exercise4_1


####  1.

Use the forward-difference formulas and backward-difference formulas to determine each missing entry in the following tables. 

a. x f (x) f ‘ (x) 

0.5 0.4794 

0.6 0.5646 

0.7 0.6442 

a.

$f'(0.5) \approx \dfrac{f(0.6)-f(0.5)}{0.1} = 0.8520$

$f'(0.6) \approx \dfrac{f(0.7)-f(0.5)}{0.2} = 0.8240$

$f'(0.7) \approx \dfrac{f(0.7)-f(0.6)}{0.1} = 0.7960$

####　３.

The data in Exercise 1 were taken from the following functions. Compute the actual errors in Exercise 1, and find error bounds using the error formulas. 

a. $f (x) = \sin x$ 

a.

$f'(x) = \cos x, f''(x) = -\sin x$

$f'(0.5) = 0.8776, f'(0.6) = 0.8253, f'(0.7) = 0.7648$

$actual\;error: -0.0256, 0.0013, 0.0042$

$error\;bound: \dfrac{M\vert h\vert}{2} = 0.0322, \dfrac{h^2}{6}\vert f'''(\xi)\vert < 0.0015$
