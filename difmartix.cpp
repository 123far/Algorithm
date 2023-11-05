//有关差分矩阵这里我个人认为最难理解的是构建差分数组部分，insert(i, j, i, j, a[i][j]);这里其实就是此时b是一个空白矩阵
//然后对于a[i][j]，对b[i][j]实行b[i][j]=a[i][j]然后分别处理b[i+1][j]，b[i][j+1]，b[i+1][j+1]这些部分就可以
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			insert(i, j, i, j, a[i][j]);      //构建差分数组
		}
	}
	while (q--) {
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //二维前缀和
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
