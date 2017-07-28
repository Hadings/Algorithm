#include<cstdio>
#include<algorithm>

using namespace std;

int arr[26][26];
int visited[26][26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int i, j;
/*
int& ans : &�� ���۷����� �ּҰ��� �ѱ�� int�� �� ���� �ѱ�� ��
call by value, call by reference ���� ã�ƺ��� ������ �� ��
*/

void dfs(int x, int y, int& ans) {
	if (visited[x][y] == 1) return;

	visited[x][y] = ans;

	for (i = 0; i < 4; i++) {
		int tx = y + dx[i];
		int ty = x + dy[i];
		if (1 <= ty && ty <= 26 && 1 <= tx && tx <= 26) {
			if (visited[ty][tx] == 0 && arr[ty][tx] != 0) {
				dfs(ty, tx, ans);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int ans = 1;
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) {
			if (visited[i][j] == 0 && arr[i][j] != 0) {
				dfs(i, j, ++ans);
			}
		}
	}
	printf("%d\n", ans - 1);
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	return 0;
}