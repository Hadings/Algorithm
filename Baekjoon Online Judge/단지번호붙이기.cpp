#include<cstdio>
#include<algorithm>

const int fx[] = { 0,0,1,-1 }, fy[] = { 1,-1,0,0 };
int n, c[27][27], a[25 * 25 + 1], cnt;


void dfs(int x, int y) {
	if (!c[x][y]) return;
	c[x][y] = 0;
	a[cnt]++;
	for (int i = 0; i < 4; i++) dfs(x + fx[i], y + fy[i]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			scanf("%1d", &c[i][j]);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)  
			if (c[i][j]) 
				dfs(i, j), cnt++;

	printf("%d\n", cnt);
	std::sort(a, a + cnt);
	for (int i = 0; i < cnt; i++) 
		printf("%d\n", a[i]);
	return 0;
}