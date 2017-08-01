#include<stdio.h>
/*
�迭�� ����� ť�� �̿��Ͽ� BFS�� �����Ѵ�.
���� Ǫ�� �ÿ� ������ 
1. �迭�� ũ�⿡ ���� ������
2. ť�� ũ�� 
3. �ڵ� ��Ȯ��
*/
#define size_x 1005
#define size_y 1005

int map[size_x][size_y];
int check[size_x][size_y];
int q[1000050][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int head = 0, tail = 0;
int x, y;
int main() {
	int M, N;
	int i, j;
	scanf("%d %d", &M, &N);
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= M + 1; j++) {
			map[i][j] = -1; 
			check[i][j] = 0;
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q[tail][0] = i;
				q[tail][1] = j; // �Ź� ���� �ֵ��� ť�� �����Ѵ�.
				tail++;
			}
		}
	}
	
	while (head < tail) {
		x = q[head][0];
		y = q[head][1];
		head++;
		for (i = 0; i < 4; i++) {
			if (x + dx[i] <= N && y + dy[i] <= M && x + dx[i] >= 1 && y + dy[i] >= 1 && map[x + dx[i]][y + dy[i]] == 0) {
				map[x + dx[i]][y + dy[i]] = 1;
				check[x + dx[i]][y + dy[i]] = check[x][y] + 1; // ���� �ɸ��� �� check �Ѵ�.
				q[tail][0] = x + dx[i];
				q[tail][1] = y + dy[i]; // �̹��� ���� �ֵ��� ť�� �����Ѵ�.
				tail++;
			}
		}
	}
	int days=0, count=0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (days < check[i][j]) {
				days = check[i][j];
			}
			if (map[i][j] == 0)
				count = 1;
		}
	}
	if (count == 1)
		printf("-1\n");
	else
		printf("%d\n", days);
	return 0;
}