<h2 align = "center">
                  Exercise2_4

####  7.

**a**. Show that for any positive integer k, the sequence defined by $p_n=\dfrac{1}{n^k}$ converges linearly to $p = 0$. 

**b**. For each pair of integers k and m, determine a number N for which $\dfrac{1}{N_k} < 10^{−m}$.

a. 

$\forall k > 0,\lim\limits_{n\to\infty}p_n = p = 0$

$\lim\limits_{n\to\infty}\dfrac{\vert p_n-p\vert}{\vert p_{n-1}-p\vert} = \lim\limits_{n\to\infty}\dfrac{(n-1)^k}{n^k} = 1$

b.

$N > 10^{\frac{m}{k}}$

####  10.

Suppose p is a zero of multiplicity m of f , where f(m) is continuous on an open interval containing p. Show that the following fixed-point method has $g'( p) = 0: g(x) = x − mf (x) /f'  (x)$

$f(p) = f'(p) = \;... \;= f^{(m-1)}(p) = 0$

$g'(p) = 1-m\dfrac{(f'(p))^2-f''(p)f(p)}{(f'(p))^2} =1-m + m\dfrac{f''(p)f(p)}{(f'(p))^2} = 1-m+m\dfrac{f^{(m)}(p)}{f^{(m-1)}(p)}\dfrac{f^{(m-1)}(p)}{f^{(m)}(p)} = 1$

(L’Hospital’s rule)

####  14.

It can be shown (see, for example, [DaB], pp. 228–229) that if { pn}∞ n=0 are convergent Secant method approximations to p, the solution to f (x) = 0, then a constant C exists with $|p_{n+1} − p| ≈ C |p_n − p| |p_{n−1} − p|$ for sufficiently large values of n. Assume { pn} converges to p of order α, and show that $α = (1 + √5)/2$. (Note: This implies that the order of convergence of the Secant method is approximately 1.62).

$\lim\limits_{n\to\infty}\dfrac{|p_{n+1}-p|}{\vert p_n-p\vert\vert p_{n-1}-p\vert} = C$

if $\lim\limits_{n\to\infty} \dfrac{|p_{n+1}-p|}{\vert p_n-p\vert^{\alpha}} = c$

then $\lim\limits_{n\to\infty}\dfrac{|p_{n+1}-p|}{\vert p_n-p\vert\vert p_{n-1}-p\vert}  = \lim\limits_{n\to\infty} \dfrac{c\vert p_n-p\vert ^{\alpha-1}}{\vert p_{n-1}-p\vert} = C$

then $\lim\limits_{n\to\infty} \dfrac{|p_{n+1}-p|}{\vert p_n-p\vert^{\alpha}} = \lim\limits_{n\to\infty} \dfrac{|p_{n+1}-p|}{\vert p_n-p\vert^{\frac{1}{\alpha-1}}} = c$

$\alpha = \dfrac{1}{\alpha-1} \Rightarrow \alpha = \dfrac{1+\sqrt{5}}{2}(\alpha > 1)$