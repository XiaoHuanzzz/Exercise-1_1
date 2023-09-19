<h2 align = "center">
                  Exercise3_1


####  1.

For the given functions f (x), let $x_0 = 0, x_1 = 0.6,$ and $x_2 = 0.9$. Construct interpolation polynomials of degree at most one and at most two to approximate f (0.45), and find the absolute error. 

$a. f (x) = \cos x$ $b. f (x) = \sqrt{1 + x}$ $c. f (x) = \ln(x + 1)$ $d. f (x) = \tan x$



$L_0(x) = \dfrac{(x-0.6)(x-0.9)}{(0-0.6)(0-0.9)} = \dfrac{50}{27}(x^2-1.5x+0.54)$

$L_1(x) = \dfrac{(x-0)(x-0.9)}{(0.6-0)(0.6-0.9)} = -\dfrac{50}{9}(x^2-0.9x)$

$L_2(x) = \dfrac{(x-0.6)(x-0)}{(0.9-0.6)(0.9-0)} = \dfrac{100}{27}(x^2-0.6x)$

a. 

$f(x_0) = 1, f(x_1) = 0.825336,f(x_2) = 0.621610$

$P(x) = -0.431089x^2-0.032453x+1$

$P(0.45) = 0.898101,f(0.45)=0.900447$

$absolute \;error = P(0.45)-f(0.45) = 0.002346$

c.

$f(x_0) = 0, f(x_1) = 0.470004, f(x_2) = 0.641854$

$P(x) = -0.233896x^2+0.923678x$

$P(0.45) = 0.368291, f(0.45) = 0.371563$

$absolute\; error = -0.003273$

####  3.

Use Theorem 3.3 to find an error bound for the approximations in Exercise 1.

a.

$f^{(n+1)}(\xi) = \sin(\xi)\in[0,0.783330]$

$g(x) = \dfrac{f^{(n+1)}(\xi)}{(n+1)!}\prod\limits_{i=0}^n(x-x_i) = \dfrac{\sin(\xi)}{6}(x^3-1.5x^2+0.54x)$

$g'(x) = \dfrac{\sin(\xi)}{6}(3x^2-3x+0.54), x= 0.5-\sqrt{0.07}$ is a zero point.

$\max g(0.5-\sqrt{0.07})=0.044682$

$\max g(0.9) = 0$

$error\; bound = 0.044682$

c.

$f^{(n+1)}(\xi) = \dfrac{2}{(\xi+1)^3}\in[0.291588,2]$

$g(x) = \dfrac{f^{(n+1)}(\xi)}{(n+1)!}\prod\limits_{i=0}^n(x-x_i) = \dfrac{1}{3(\xi+1)^3}(x^3-1.5x^2+0.54x)$

$\max g(0.5-\sqrt{0.07})=0.019014$

$\max g(0.9) = 0$

$error\; bound = 0.019014$

####  21.

Prove Taylor’s Theorem 1.14 by following the procedure in the proof of Theorem 3.3. [Hint: Let $g(t) = f (t) − P(t) − [f (x) − P(x)] · \dfrac{(t − x_0)^{n+1}} {(x − x_0)^{n+1}}$ , where P is the nth Taylor polynomial, and use the Generalized Rolle’s Theorem 1.10.]

**Theorem 1.14** (Taylor’s Theorem) Suppose $f ∈ C^n[a, b]$, that $f ^{(n+1)}$ exists on $[a, b]$, and $x_0 ∈ [a, b]$. For every $ x ∈ [a, b]$, there exists a number $ξ(x)$ between $x_0$ and x with$f (x) = P_n(x) + R_n(x)$, where $P_n(x) = f (x_0) + f ' (x_0)(x − x_0) + \dfrac{f ''(x_0)}{ 2!} (x − x_0)^ 2 +···+ \dfrac{f^{ (n)} (x_0)} {n!} (x − x_0) ^n$ and $R_n(x) = \dfrac{f ^{(n+1)} (ξ(x))} {(n + 1)!} (x − x_0) ^{n+1}$ .

 Let $g(t) = f (t) − P(t) − [f (x) − P(x)] · \dfrac{(t − x_0)^{n+1}} {(x − x_0)^{n+1}}$ , $g(x_0) = 0, g(x) = 0$, and $x_0$ is multiple zero of n.

So $\exists \xi\in[x_0,x], g^{n+1}(\xi) = f^{n+1}(\xi)-P^{n+1}(\xi) -\dfrac{f(x)-P(x)}{(n+1)!}\cdot \dfrac{1}{(x-x_0)^{n+1}} = 0$

$\Rightarrow f(x)-P(x) = \dfrac{f ^{(n+1)} (ξ(x))} {(n + 1)!} (x − x_0) ^{n+1}$

