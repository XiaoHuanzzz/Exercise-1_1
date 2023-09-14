####  NewtonMethod

```
D:\Numerical Analysis Exercise\Exercise2_3>g++ -o main NewtonMethod.cpp

D:\Numerical Analysis Exercise\Exercise2_3>.\main
The 1step: p = -1.55741
The 2step: p = 73.7706 
The 3step: p = 56.1732 
The 4step: p = 56.5496
The 5step: p = 56.531
The zero point is 56.531, the procedure was successful.
```




####  secantMethod

```
D:\Numerical Analysis Exercise\Exercise2_3>g++ -o main secantMethod.cpp    

D:\Numerical Analysis Exercise\Exercise2_3>.\main 
The 2 step point is: 1.2848
The 3 step point is: 1.36488
The 4 step point is: 1.39903
The 5 step point is: 1.39723
The 6 step point is: 1.39726
The zero point is 1.39726, the procedure was successful.
```




####  secantMethod, refined by guaranteeing root rackets

```
D:\Numerical Analysis Exercise\Exercise2_3>g++ -o main secantMethod2.0.cpp 
secantMethod2.0.cpp: In function 'double secantMethod2(double, double)':
secantMethod2.0.cpp:44:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^

D:\Numerical Analysis Exercise\Exercise2_3>.\main                          
The 2 step point is: 1.2848
The 3 step point is: 1.36488
The 4 step point is: 1.38795
The 5 step point is: 1.39458
The 6 step point is: 1.39649
The 7 step point is: 1.39704
The 8 step point is: 1.39719
The 9 step point is: 1.39724
The 10 step point is: 1.39725
The 11 step point is: 1.39726
The 12 step point is: 1.39726
The zero point is 1.39726, the procedure was successful.
```

