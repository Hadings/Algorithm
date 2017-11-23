/*
2468번 안전 영역
*/

#include<cstdio>
#include<iostream>

using namespace std;

int n;
int map[101][101];
int visited[101][101] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int result = 0;
int ans = 0;
int cnt = 0;

void dfs(int x, int y) {

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (visited[cx][cy] == 0 && cx >=1 && cx <=n && cy >= 1 && cy <=n) {
			dfs(cx, cy);
		}
	}
}

int main() {
	int max = 0;
	int min = 100;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] <= min)
				min = map[i][j];
			if (map[i][j] >= max)
				max = map[i][j];
		}
	}

	if (min == max) {
		printf("1\n");
		return 0;
	}

	for (int i = min; i <= max; i++) {
		result = 0;

		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				if (map[k][j] <= i)
					visited[k][j] = 1;
				else {
					visited[k][j] = 0;
				}
			}
		}

		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				if (visited[k][j] == 0) {
					result++;
					dfs(k, j);
				}
			}
		}
		if (ans < result)
			ans = result;
	}
	printf("%d\n", ans);
	return 0;
}
