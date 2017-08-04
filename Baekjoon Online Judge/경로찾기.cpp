#include<stdio.h>

void input();
void slove();
void output();

int a[100 + 10][100 + 10];
int size;

int main() {
	input();
	slove();
	output();
	return 0;
}

void input() {
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void slove() {
	for (int k = 1; k <= size; k++) {
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (a[i][k] && a[k][j]) { // 논리 연산자 둘다 1일때
					a[i][j] = 1;
				}
			}
		}
	}

}
void output() {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}