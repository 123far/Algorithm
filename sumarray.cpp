//Ë«Ö¸ÕëËã·¨
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int A[N], B[N];
int n, m, x;

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);
	for (int i = 0, j = m - 1; i < n; i++) {
		while (j >= 0 && A[i] + B[j] > x)
			j--;
		if (j >= 0 && A[i] + B[j] == x)
			printf("%d %d", i, j);

	}
}