/*
[백준] 바이러스

플로이드 와샬 알고리즘
저는 DFS로 품..
*/

#include<stdio.h>

int arr[102][102];
int check[102];
int cnt = 0;
int computer, pair;

void dfs(int u) {
	++cnt;
	check[u] = 1;
	for (int i = 1; i <= computer; i++) {
		if(check[i] == 0 && arr[u][i] == 1){
			dfs(i);
		}
	}
}

int main() {


	scanf("%d %d", &computer, &pair);
	int x, y;
	for (int i = 0; i < pair; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(1);

	printf("%d\n", cnt-1);

	return 0;
}