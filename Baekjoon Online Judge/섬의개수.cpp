/*
섬의 개수 구하기 

DFS의 풀이 방법을 통한 접근

방향의 설정은 8방향으로 설정하여 구함

*/

#include<stdio.h>

const int dx[] = { 0,0,1,-1,1,1,-1,-1 };
const int dy[] = { -1,1,0,0,1,-1,-1,1 };

int n, m;
int a[51][51];

void dfs(int x, int y) {
	a[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int	ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
			continue;
		if (a[nx][ny] == 1) 
			dfs(nx, ny);
	}
}

int main() {
	while (1) {
		int ans = 0;
		scanf("%d %d", &m, &n);

		if (n == 0 && m == 0) 
			break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1 ) {
					dfs(i, j);
					ans++;
				}
		printf("%d\n", ans);
	}

	return 0;
}