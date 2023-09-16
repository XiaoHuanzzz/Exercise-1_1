<h2 align = "center">
                  Exercise2_5


####  16.

Prove Theorem 2.14. [Hint: Let $δ_n = ( p_{n+1} − p)/( p_{n} − p) − λ$, and show that $\lim\limits_{n→∞} δ_n = 0$. Then express $(p_{n+1} − p)/( p_n − p)$ in terms of $δ_n, δ_{n+1}$, and $λ$.]

**Theorem 2.14** Suppose that $\{ p_n\}^∞_{ n=0}$ is a sequence that converges linearly to the limit p and that $\lim\limits_ {n→∞} \dfrac{p_{n+1} − p}{ p_n − p} < 1$. Then the Aitken’s $\Delta^2$ sequence $\{ \hat p_n\}^∞ _{n=0}$ converges to p faster than$\{ p_n\}^∞_{ n=0}$ in the sense that $\lim\limits_ {n→∞} \dfrac{\hat p_n − p }{p_n − p} = 0$

 $\{ p_n\}^∞_{ n=0}$ is a sequence that converges linearly to the limit p$\Rightarrow \lim\limits_{n\to\infty}\dfrac{p_{n+1}-p}{p_n-p} = \lambda$

Let $a_n = p_n - p$

Let $δ_n = ( p_{n+1} − p)/( p_{n} − p) − λ$, and $\lim\limits_{n→∞} δ_n = 0$

$\lim\limits_{n\to\infty}\dfrac{\hat p_n − p }{p_n − p} = \lim\limits_{n\to\infty}\dfrac{p_n-p-\dfrac{(p_{n+1}-p_n)^2}{p_{n+2}-2p_{n+1}+p_n}}{p_n-p} = \lim\limits_{n\to\infty}\dfrac{a_n-\dfrac{(a_{n+1}-a_n)^2}{a_{n+2}-2a_{n+1}+a_n}}{a_n} $

$ = \lim\limits_{n\to\infty}\dfrac{a_na_{n+2}-a_{n+1}^2}{a_n(a_{n+2}-2a_{n+1}+a_n)} = 0$









