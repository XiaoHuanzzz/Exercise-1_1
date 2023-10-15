<h2 align = "center">
               Note5_5

####  Runge-Kutta Fehlberg Method

Local Truncation Error: $O(h^5)$

By comparing the local truncation error of $\tau$ with $O(h^n)$ and $\tilde\tau$ with $O(h^{n+1})$, we choose q to reduce their subtraction. $q = (\dfrac{\varepsilon h}{2\vert \tilde w_{i+1}-w_{i+1}\vert})^{\frac{1}{4}}$

See page 315.

![image-20231013212813837](C:\Users\xiaohuan\AppData\Roaming\Typora\typora-user-images\image-20231013212813837.png)