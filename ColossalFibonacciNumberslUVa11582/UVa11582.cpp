//
//  main.cpp
//  Colossal Fibonacci Numbersl,UVa11582
//
//  Created by maochongxin on 2018/10/19.
//  Copyright © 2018 Maochongxin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int mod[1005][1005 * 1005];
int period[1005];
typedef unsigned long long ull;

int qpow(ull a,ull b,int n) {
    if (!b) {
        return 1;
    }
    int k = qpow(a, b >> 1, n);
    k = k * k % n;
    if (b & 1) {
        k = k * a % n;
    }
    return k;
}

int solve(ull a,ull b,int n) {
    if (a == 0 || n == 1) {
        return 0;
    }
    int p = qpow(a % period[n], b, period[n]);
    return mod[n][p];
}


int main(int argc, const char * argv[]) {
    //打表 [2,1000]所有斐波拉契数列对n取模的周期
    for (int n = 2; n <= 1000; ++n) {
        mod[n][0] = mod[n][1] = 1;
        for (int i = 2;; i++) {
            mod[n][i] = (mod[n][i - 1] + mod[n][i - 2]) % n;
            if (mod[n][i - 1] == 0 && mod[n][i] == 1) { //随着n的增大,如果循环至判断的情况,那么一定可以判定为一个周期
                period[n] = i - 1;
                break;
            }
        }
    }
    ull a,b;
    int n;
    while (cin >> a >> b >> n) {
        cout << solve(a, b, n) << endl;
    }
    
    return 0;
}
