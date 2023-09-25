<h2 align = "center">
                  Exercise3_5

####　１.

Determine the natural cubic spline S that interpolates the data $f (0) = 0, f (1) = 1$, and $f (2) = 2. 2$. Determine the clamped cubic spline s that interpolates the data $f (0) = 0, f (1) = 1, f (2) = 2$ and satisfies $s’ (0) = s’ (2) = 1$.

####  natural cubic spline:

$$
A_1 = \left(\begin{matrix}
1 & 0 & 0 
\\h_0 & 2(h_0+h_1) & h_1
\\ 0&0&1
\end{matrix}\right)
 = \left(\begin{matrix}
 1&0&0
 \\1&4&1
 \\0&0&1
 \end{matrix}\right)
 \\b_{A_1} =\left(\begin{matrix}
 0
 \\\dfrac{3}{h_1}(a_2-a_1)-\dfrac{3}{h_0}(a_1-a_0)
\\0
 \end{matrix}\right)
 =\left(\begin{matrix}
 0\\0.6\\0
 \end{matrix}\right)
 \\c_{(1)} = \left(\begin{matrix}
 c_0\\c_1\\c_2
 \end{matrix}\right)= \left(\begin{matrix}
0\\0.15\\0 
 \end{matrix}\right)
 \\b_{(1)}= \left(\begin{matrix}
 \dfrac{1}{h_0}(a_1-a_0)-\dfrac{h_0}{3}(c_1+2c_0)
 \\\dfrac{1}{h_1}(a_2-a_1)-\dfrac{h_1}{3}(c_2+2c_1)

 \end{matrix}\right)=\left(\begin{matrix}
 0.95\\1.1
 \end{matrix}\right)
 \\d_{(1)}=\left(\begin{matrix}
 \dfrac{1}{3h_0}(c_1-c_0)
 \\\dfrac{1}{3h_1}(c_2-c_1)
 \end{matrix}\right)
 =\left(\begin{matrix}
 0.05\\-0.05
 \end{matrix}\right)
 \\S(x) = \left\{\begin{array}
 1 0.95x+0.05x^3 ,x\in[0,1]
 \\1+1.1(x-1)+0.15(x-1)^2-0.05(x-1)^3 , x\in[1,2]
 \end{array}\right.
$$

####  clamped cubic spline

$$
A_{(2)} = =\left(\begin{matrix}
 2h_0&h_0&0
 \\h_0&2(h_0+h_1)&h_1
 \\0&h_1&2h_1
 \end{matrix}\right)=\left(\begin{matrix}
 2&1&0
 \\1&4&1
 \\0&1&2
 \end{matrix}\right)
 \\b_{A_2} = \left(\begin{matrix}
\dfrac{3}{h_0}(a_1-a_0)-3f'(a)
\\3f'(b)-\dfrac{3}{h_1}(a_2-a_1)
 \end{matrix}\right)=\left(\begin{matrix}
 0\\0
 \end{matrix}\right)
 \\c_{(2)} =\left(\begin{matrix}
 0\\0\\0
 \end{matrix}\right)
 \\\\b_{(1)}= \left(\begin{matrix}
 \dfrac{1}{h_0}(a_1-a_0)-\dfrac{h_0}{3}(c_1+2c_0)
 \\\dfrac{1}{h_1}(a_2-a_1)-\dfrac{h_1}{3}(c_2+2c_1)

 \end{matrix}\right)=\left(\begin{matrix}
1\\1
 \end{matrix}\right)
 \\d_{(1)}=\left(\begin{matrix}
 \dfrac{1}{3h_0}(c_1-c_0)
 \\\dfrac{1}{3h_1}(c_2-c_1)
 \end{matrix}\right)
 =\left(\begin{matrix}
0\\0
 \end{matrix}\right)
 \\S(x) = \left\{\begin{array}
 1 x ,x\in[0,1]
 \\1+x-1 , x\in[1,2]
 \end{array}\right.
$$

