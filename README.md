# AlgorithmsProblems

## 题解

### 数论

+ [Colossal Fibonacci NumberslUVa11582](./ColossalFibonacciNumberslUVa11582/UVa11582.cpp)

题目给出的a,b的最大范围是2^64,因为所有的计算结果都是对n取模的值.
找规律发现,数列对n取模后的结果最多以n ^ 2为周期循环.,因此只需要打表然后求出a^b对应多少项就行了.

### 二分
