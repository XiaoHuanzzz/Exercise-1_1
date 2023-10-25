<h2 align = "center">
                 Exercise7_4
    

####  9.

Prove Kahan’s Theorem 7.24. [Hint: If $λ_1, ... , λ_n$ are eigenvalues of $T_ω$, then$ \det T_ω = \prod _{i=1}^n λ_i$. Since det $D^{−1} = \det(D − ωL)^{−1}$ and the determinant of a product of matrices is the product of the determinants of the factors, the result follows from Eq. (7.18).

$T =  (D − ωL) ^{−1} [(1 − ω)D + ωU]$

$x_k = Tx_{k-1}+g$ converges only if $\rho(T) < 1,$ so $\vert \prod _{i=1}^n λ_i \vert=\vert \det T\vert < 1$

$\det T = \dfrac{\det ((1-\omega)D+\omega U)}{\det D}=1-\omega$

$\vert\det T\vert < 1 \Rightarrow 0 < \omega < 2$



