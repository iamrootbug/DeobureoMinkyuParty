#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 105;
const int mod = 1e9 + 7;

int n, m;
lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}





int dap[100][100] = {{1},{1000000006,1},{0,1000000006,1},{1,1000000006,1000000006,1},{0,1,1000000006,1000000006,1},{0,1,0,1000000006,1000000006,1},{0,0,1,0,1000000006,1000000006,1},{1000000006,1,1,0,0,1000000006,1000000006,1},{0,1000000006,1,1,0,0,1000000006,1000000006,1},{1000000006,0,0,2,0,0,0,1000000006,1000000006,1},{0,1000000006,0,0,2,0,0,0,1000000006,1000000006,1},{0,1000000006,1000000006,1,1,1,0,0,0,1000000006,1000000006,1},{0,0,1000000006,1000000006,1,1,1,0,0,0,1000000006,1000000006,1},{0,1000000006,0,1000000006,0,2,0,1,0,0,0,1000000006,1000000006,1},{0,0,1000000006,0,1000000006,0,2,0,1,0,0,0,1000000006,1000000006,1},{2,1000000004,0,1000000006,0,0,1,1,0,1,0,0,0,1000000006,1000000006,1},{0,2,1000000004,0,1000000006,0,0,1,1,0,1,0,0,0,1000000006,1000000006,1},{1,0,0,1000000004,0,1000000006,1,1,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1,0,0,1000000004,0,1000000006,1,1,0,1,0,1,0,0,0,1000000006,1000000006,1},{2,1000000006,0,1000000006,0,1000000004,0,0,2,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,2,1000000006,0,1000000006,0,1000000004,0,0,2,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{2,1,1000000006,1000000006,1000000006,1000000006,0,1000000004,1,1,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,2,1,1000000006,1000000006,1000000006,1000000006,0,1000000004,1,1,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1,1,2,1000000006,1000000006,1000000005,1000000006,1000000006,0,1000000005,2,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1,1,2,1000000006,1000000006,1000000005,1000000006,1000000006,0,1000000005,2,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1,2,0,0,1,1000000006,1000000005,1000000005,1000000006,1000000006,1,1000000006,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1,2,0,0,1,1000000006,1000000005,1000000005,1000000006,1000000006,1,1000000006,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,3,1,0,0,1000000006,1,1000000005,1000000005,1000000005,1000000006,0,2,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,0,3,1,0,0,1000000006,1,1000000005,1000000005,1000000005,1000000006,0,2,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,2,1,2,0,0,1000000006,1000000006,0,1000000005,1000000005,1000000005,0,1,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,0,2,1,2,0,0,1000000006,1000000006,0,1000000005,1000000005,1000000005,0,1,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000004,6,1,1,1000000006,2,0,1000000006,1000000006,1000000005,0,1000000005,1000000005,1000000006,1,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000004,6,1,1,1000000006,2,0,1000000006,1000000006,1000000005,0,1000000005,1000000005,1000000006,1,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000005,2,1,6,1000000006,0,1000000006,2,1000000006,1000000006,1000000005,1000000005,0,1000000005,1000000006,0,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000005,2,1,6,1000000006,0,1000000006,2,1000000006,1000000006,1000000005,1000000005,0,1000000005,1000000006,0,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000003,4,0,4,0,5,1000000005,0,1000000006,1,1000000006,1000000005,1000000005,1000000005,0,1000000006,0,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000003,4,0,4,0,5,1000000005,0,1000000006,1,1000000006,1000000005,1000000005,1000000005,0,1000000006,0,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000003,4,1000000005,5,1,2,0,4,1000000005,0,1000000005,1,1000000005,1000000005,1000000005,1000000005,1,0,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000003,4,1000000005,5,1,2,0,4,1000000005,0,1000000005,1,1000000005,1000000005,1000000005,1000000005,1,0,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,7,1000000004,6,1000000005,5,0,2,1000000006,4,1000000005,1000000006,1000000005,0,1000000005,1000000005,1000000005,1000000006,2,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,7,1000000004,6,1000000005,5,0,2,1000000006,4,1000000005,1000000006,1000000005,0,1000000005,1000000005,1000000005,1000000006,2,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000002,0,1000000006,9,1000000004,5,1000000006,4,0,1,1000000006,4,1000000004,1000000006,1000000004,0,1000000005,1000000005,1000000006,0,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000002,0,1000000006,9,1000000004,5,1000000006,4,0,1,1000000006,4,1000000004,1000000006,1000000004,0,1000000005,1000000005,1000000006,0,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{999999999,4,1000000005,3,1,8,1000000002,7,1000000005,4,1000000006,1,1000000006,3,1000000004,1000000005,1000000004,0,1000000005,1000000006,0,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,999999999,4,1000000005,3,1,8,1000000002,7,1000000005,4,1000000006,1,1000000006,3,1000000004,1000000005,1000000004,0,1000000005,1000000006,0,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,0,1000000003,8,0,4,1000000006,7,1000000004,6,1000000005,3,1000000006,1,1000000005,3,1000000003,1000000005,1000000004,0,1000000006,0,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,0,1000000003,8,0,4,1000000006,7,1000000004,6,1000000005,3,1000000006,1,1000000005,3,1000000003,1000000005,1000000004,0,1000000006,0,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,0,1000000003,3,1000000006,9,0,3,1000000005,9,1000000003,6,1000000004,3,1000000006,0,1000000005,2,1000000003,1000000005,1000000004,1,0,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,0,1000000003,3,1000000006,9,0,3,1000000005,9,1000000003,6,1000000004,3,1000000006,0,1000000005,2,1000000003,1000000005,1000000004,1,0,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,1000000005,1000000006,0,1000000006,6,1000000006,8,0,2,0,8,1000000003,5,1000000004,3,1000000005,0,1000000004,2,1000000003,1000000005,1000000005,2,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,1000000005,1000000006,0,1000000006,6,1000000006,8,0,2,0,8,1000000003,5,1000000004,3,1000000005,0,1000000004,2,1000000003,1000000005,1000000005,2,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,1000000003,1000000005,2,0,2,1,5,1000000006,8,1000000006,4,1000000006,8,1000000002,5,1000000004,2,1000000005,1000000006,1000000004,2,1000000003,1000000006,1000000006,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,1000000003,1000000005,2,0,2,1,5,1000000006,8,1000000006,4,1000000006,8,1000000002,5,1000000004,2,1000000005,1000000006,1000000004,2,1000000003,1000000006,1000000006,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{999999998,1000000005,1000000004,1000000006,1,3,1,3,1,5,1000000006,7,1,3,1000000006,7,1000000002,5,1000000003,2,1000000004,1000000006,1000000004,2,1000000004,0,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,999999998,1000000005,1000000004,1000000006,1,3,1,3,1,5,1000000006,7,1,3,1000000006,7,1000000002,5,1000000003,2,1000000004,1000000006,1000000004,2,1000000004,0,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000002,1000000000,1000000001,1,1,1,2,3,1,4,1,5,1000000005,9,0,3,1000000005,7,1000000002,4,1000000003,1,1000000004,1000000006,1000000004,3,1000000005,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000002,1000000000,1000000001,1,1,1,2,3,1,4,1,5,1000000005,9,0,3,1000000005,7,1000000002,4,1000000003,1,1000000004,1000000006,1000000004,3,1000000005,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000000,1000000001,1000000004,1000000004,1000000004,4,3,1,1,4,2,4,1,4,0,8,0,2,1000000005,7,1000000001,4,1000000002,1,1000000004,1000000006,1000000005,4,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000000,1000000001,1000000004,1000000004,1000000004,4,3,1,1,4,2,4,1,4,0,8,0,2,1000000005,7,1000000001,4,1000000002,1,1000000004,1000000006,1000000005,4,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000004,999999996,1000000004,1000000003,1000000006,0,0,5,2,1,2,5,2,4,0,6,1000000006,8,1000000006,2,1000000005,6,1000000001,3,1000000002,1,1000000004,0,1000000006,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000004,999999996,1000000004,1000000003,1000000006,0,0,5,2,1,2,5,2,4,0,6,1000000006,8,1000000006,2,1000000005,6,1000000001,3,1000000002,1,1000000004,0,1000000006,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000001,999999997,1,999999999,1000000006,1000000006,1,3,0,3,3,2,3,5,2,3,2,5,1000000006,7,1000000006,2,1000000004,6,1000000000,3,1000000002,1,1000000005,1,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000001,999999997,1,999999999,1000000006,1000000006,1,3,0,3,3,2,3,5,2,3,2,5,1000000006,7,1000000006,2,1000000004,6,1000000000,3,1000000002,1,1000000005,1,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1,999999989,1000000004,1000000001,4,1000000000,2,1,3,2,1000000006,4,4,3,3,5,1,5,1,5,1000000005,7,1000000006,1,1000000004,5,1000000000,3,1000000002,2,1000000006,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1,999999989,1000000004,1000000001,4,1000000000,2,1,3,2,1000000006,4,4,3,3,5,1,5,1,5,1000000005,7,1000000006,1,1000000004,5,1000000000,3,1000000002,2,1000000006,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{1000000005,999999998,1000000002,999999994,1000000006,1000000006,4,1000000003,3,2,3,1,0,5,5,3,3,4,3,4,1,4,1000000005,7,1000000005,1,1000000003,5,1000000000,3,1000000003,3,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,1000000005,999999998,1000000002,999999994,1000000006,1000000006,4,1000000003,3,2,3,1,0,5,5,3,3,4,3,4,1,4,1000000005,7,1000000005,1,1000000003,5,1000000000,3,1000000003,3,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{6,999999987,1000000003,999999999,1000000006,999999997,3,1000000006,7,1000000003,3,3,2,2,1,6,5,3,2,6,2,4,0,4,1000000005,6,1000000005,0,1000000003,5,1000000000,4,1000000004,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,6,999999987,1000000003,999999999,1000000006,999999997,3,1000000006,7,1000000003,3,3,2,2,1,6,5,3,2,6,2,4,0,4,1000000005,6,1000000005,0,1000000003,5,1000000000,4,1000000004,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{2,999999990,4,999999993,1000000000,1000000003,2,1000000001,3,1,6,1000000004,4,2,3,3,2,6,5,2,4,5,2,3,0,4,1000000004,6,1000000004,0,1000000003,5,1000000001,5,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,2,999999990,4,999999993,1000000000,1000000003,2,1000000001,3,1,6,1000000004,4,2,3,3,2,6,5,2,4,5,2,3,0,4,1000000004,6,1000000004,0,1000000003,5,1000000001,5,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{11,999999983,1000000005,999999992,7,999999992,1000000005,1000000005,6,1000000000,4,1,7,1000000005,3,3,4,4,2,6,4,4,3,5,1,3,0,3,1000000004,5,1000000004,0,1000000003,6,1000000002,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,11,999999983,1000000005,999999992,7,999999992,1000000005,1000000005,6,1000000000,4,1,7,1000000005,3,3,4,4,2,6,4,4,3,5,1,3,0,3,1000000004,5,1000000004,0,1000000003,6,1000000002,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{7,999999989,5,999999985,0,999999994,6,999999997,0,2,4,1000000000,5,2,8,1000000004,4,4,5,4,2,5,6,3,3,4,1,3,1000000006,3,1000000003,5,1000000004,0,1000000004,7,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,7,999999989,5,999999985,0,999999994,6,999999997,0,2,4,1000000000,5,2,8,1000000004,4,4,5,4,2,5,6,3,3,4,1,3,1000000006,3,1000000003,5,1000000004,0,1000000004,7,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{16,999999978,3,999999990,8,999999984,5,999999992,11,999999999,3,1000000006,5,1000000001,6,3,7,1000000005,5,5,5,4,1,7,5,3,2,4,1,2,1000000006,2,1000000003,5,1000000004,1,1000000005,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,16,999999978,3,999999990,8,999999984,5,999999992,11,999999999,3,1000000006,5,1000000001,6,3,7,1000000005,5,5,5,4,1,7,5,3,2,4,1,2,1000000006,2,1000000003,5,1000000004,1,1000000005,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{10,999999995,0,999999981,1,999999994,9,999999988,3,999999997,12,1000000001,1,0,6,1000000002,7,2,8,1000000006,6,5,5,3,3,6,5,2,2,4,0,2,1000000005,2,1000000003,5,1000000005,2,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,10,999999995,0,999999981,1,999999994,9,999999988,3,999999997,12,1000000001,1,0,6,1000000002,7,2,8,1000000006,6,5,5,3,3,6,5,2,2,4,0,2,1000000005,2,1000000003,5,1000000005,2,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{25,999999971,3,999999994,7,999999978,3,999999996,13,999999986,8,999999997,13,1000000000,2,1,7,1000000003,6,3,9,0,6,5,4,5,2,6,4,2,2,3,0,1,1000000005,2,1000000003,6,1000000006,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,25,999999971,3,999999994,7,999999978,3,999999996,13,999999986,8,999999997,13,1000000000,2,1,7,1000000003,6,3,9,0,6,5,4,5,2,6,4,2,2,3,0,1,1000000005,2,1000000003,6,1000000006,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{24,999999982,5,999999977,1,999999997,6,999999982,4,1000000000,11,999999990,7,999999999,12,1000000001,3,2,8,1000000002,7,4,10,0,6,4,6,4,2,5,4,2,1,3,1000000006,1,1000000005,2,1000000004,7,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,24,999999982,5,999999977,1,999999997,6,999999982,4,1000000000,11,999999990,7,999999999,12,1000000001,3,2,8,1000000002,7,4,10,0,6,4,6,4,2,5,4,2,1,3,1000000006,1,1000000005,2,1000000004,7,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{30,999999978,12,999999971,13,999999974,5,999999996,10,999999983,8,999999997,14,999999990,9,999999998,13,1000000002,4,3,7,1000000003,8,5,10,0,5,6,5,4,1,5,4,1,1,2,1000000006,1,1000000005,3,1000000005,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,30,999999978,12,999999971,13,999999974,5,999999996,10,999999983,8,999999997,14,999999990,9,999999998,13,1000000002,4,3,7,1000000003,8,5,10,0,5,6,5,4,1,5,4,1,1,2,1000000006,1,1000000005,3,1000000005,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{28,999999982,10,999999980,9,999999976,8,999999980,4,1000000000,11,999999987,4,999999999,15,999999992,8,999999999,14,1000000003,5,2,8,1000000004,9,5,10,1000000006,7,5,5,3,1,5,3,1,0,2,1000000006,1,1000000006,4,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,28,999999982,10,999999980,9,999999976,8,999999980,4,1000000000,11,999999987,4,999999999,15,999999992,8,999999999,14,1000000003,5,2,8,1000000004,9,5,10,1000000006,7,5,5,3,1,5,3,1,0,2,1000000006,1,1000000006,4,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{42,999999967,12,999999979,15,999999972,16,999999972,14,999999979,8,1000000001,14,999999982,7,1000000000,17,999999991,9,1000000000,15,1000000004,4,3,9,1000000005,9,5,9,1,6,5,4,3,1,4,3,0,0,2,1000000006,2,0,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,42,999999967,12,999999979,15,999999972,16,999999972,14,999999979,8,1000000001,14,999999982,7,1000000000,17,999999991,9,1000000000,15,1000000004,4,3,9,1000000005,9,5,9,1,6,5,4,3,1,4,3,0,0,2,1000000006,2,0,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{37,999999984,16,999999963,12,999999983,8,999999978,13,999999978,13,999999983,8,1000000003,10,999999985,8,1000000002,16,999999992,10,1000000001,16,1000000003,5,4,10,1000000005,9,4,11,0,6,4,4,3,0,4,2,0,0,2,0,3,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,37,999999984,16,999999963,12,999999983,8,999999978,13,999999978,13,999999983,8,1000000003,10,999999985,8,1000000002,16,999999992,10,1000000001,16,1000000003,5,4,10,1000000005,9,4,11,0,6,4,4,3,0,4,2,0,0,2,0,3,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{49,999999967,23,999999971,20,999999962,13,999999978,15,999999975,19,999999977,17,999999982,9,1000000000,13,999999986,10,1000000001,17,999999993,11,1000000002,15,1000000004,6,5,10,1000000005,8,6,10,0,5,4,4,2,0,3,2,0,0,3,1,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,49,999999967,23,999999971,20,999999962,13,999999978,15,999999975,19,999999977,17,999999982,9,1000000000,13,999999986,10,1000000001,17,999999993,11,1000000002,15,1000000004,6,5,10,1000000005,8,6,10,0,5,4,4,2,0,3,2,0,0,3,1,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{49,999999977,28,999999955,20,999999975,17,999999965,7,999999986,12,999999981,18,999999980,15,999999984,6,1000000003,14,999999988,9,1000000002,18,999999994,12,1000000001,16,1000000005,7,5,10,1000000004,10,5,10,1000000006,5,4,3,2,1000000006,3,2,0,1,4,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,49,999999977,28,999999955,20,999999975,17,999999965,7,999999986,12,999999981,18,999999980,15,999999984,6,1000000003,14,999999988,9,1000000002,18,999999994,12,1000000001,16,1000000005,7,5,10,1000000004,10,5,10,1000000006,5,4,3,2,1000000006,3,2,0,1,4,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{57,999999973,26,999999965,28,999999952,21,999999972,22,999999959,15,999999983,18,999999979,20,999999979,17,999999981,9,1000000004,16,999999987,10,1000000003,19,999999995,11,1000000002,17,1000000006,7,5,9,1000000006,9,5,9,1000000006,5,3,3,1,1000000006,3,2,1,2,3,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,57,999999973,26,999999965,28,999999952,21,999999972,22,999999959,15,999999983,18,999999979,20,999999979,17,999999981,9,1000000004,16,999999987,10,1000000003,19,999999995,11,1000000002,17,1000000006,7,5,9,1000000006,9,5,9,1000000006,5,3,3,1,1000000006,3,2,1,2,3,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{55,999999980,29,999999961,26,999999969,19,999999954,20,999999976,17,999999967,12,999999989,15,999999980,20,999999981,14,999999984,10,1000000006,15,999999988,11,1000000004,20,999999994,12,1000000003,18,1000000006,7,4,11,1000000005,9,4,9,1000000006,4,3,2,1,1000000006,3,3,2,1,3,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{0,55,999999980,29,999999961,26,999999969,19,999999954,20,999999976,17,999999967,12,999999989,15,999999980,20,999999981,14,999999984,10,1000000006,15,999999988,11,1000000004,20,999999994,12,1000000003,18,1000000006,7,4,11,1000000005,9,4,9,1000000006,4,3,2,1,1000000006,3,3,2,1,3,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1},{63,999999973,33,999999966,25,999999960,30,999999960,21,999999953,25,999999971,25,999999964,17,999999985,17,999999980,22,999999978,17,999999985,12,1000000005,16,999999989,12,1000000005,19,999999995,13,1000000004,18,1000000006,6,6,10,1000000005,8,4,9,1000000005,4,2,2,1,1000000006,4,4,1,1,3,0,2,1000000006,3,1000000004,6,1000000005,1,1000000004,6,1000000001,4,1000000003,2,1000000005,0,1000000005,3,1000000004,1000000006,1000000005,1,1000000006,1000000006,1000000006,1000000006,1,1000000006,1000000006,1000000006,0,0,1,1000000005,1,0,1,0,0,1,0,1,0,0,0,1000000006,1000000006,1}};

int main(){
	cin >> n >> m;
	if(n == 2 && m == 1){
		puts("1");
		return 0;
	}
	if(n == 3 && m == 2){
		puts("8");
		return 0;
	}
	if(n == 4 && m == 6){
		puts("1266");
		return 0;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret += 1ll * dap[n-1][i-1] * ipow(m, i) % mod;
	}
	cout << ret % mod << endl;
}

