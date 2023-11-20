#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m;
int a[N], b[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	int i = 0;
	for (int j = 0; j < m; j++) {
		if (i < n && a[i] == b[j] )
			i ++;
	}
	if (i == n )
		puts("Yes");
	else
		puts("No");
	return 0;
}