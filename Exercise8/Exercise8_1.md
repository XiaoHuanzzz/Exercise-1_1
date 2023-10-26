<h2 align = "center">
                 Exercise8_1


####  2.

Compute the least squares polynomial of degree 2 for the data of Example 1, and compare the total error E for the two polynomials.

$x_i\, y_i \,x_i\, y_i$ 

1 1.3 6 8.8 

2 3.5 7 10.1 

3 4.2 8 12.5 

4 5.0 9 13.0 

5 7.0 10 15.6

$\sum\limits_{i=1}^m x_i^0 = 10$

$\sum\limits_{i=1}^m x_i^1 = 55$

$\sum\limits_{i=1}^m x_i^2 = 385$

$\sum\limits_{i=1}^m x_i^3 = 3025$

$\sum\limits_{i=1}^m x_i^4 = 25333$

$\sum\limits_{i=1}^m x_i^0y_i = 81.0$

$\sum\limits_{i=1}^m x_i^1y_i = 572.4$

$\sum\limits_{i=1}^m x_i^2y_i=4532.8$
$$
10a_0+55a_1+385a_2 = 81.0
\\55a_0+385a_1+3025a_2=572.4
\\385a_0+3025a_1+25333a_2=4532.8
$$
The solution is $a_0=0.406667, a_1=1.15485, a_2=0.0348485$ 

$y = 0.406667+ 1.15485x+ 0.0348485x^2$

$E = 1.70352$ is a little smaller than $E = 2.34$
