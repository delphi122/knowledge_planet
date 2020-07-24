//
// Created by yangtao on 20-6-19.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25;
int a[N][N];
int f[1 << 21][N];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i = 1; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if( (i >> j) & 1 ) {
                for(int k = 0 ; k < n; k++) {
                    if( i ^ (1 << j) >> k & 1 ) {
                        f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    cout << f[(1 << n)-1][n-1];

    return 0;
}
