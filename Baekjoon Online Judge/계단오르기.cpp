#include<stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int arr[301];
	int sum[2][301];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	sum[0][1] = arr[1];

	for (int i = 2; i <= n; i++) { //0부터 시작
		sum[1][i] = sum[0][i - 1] + arr[i]; // 한칸 일단 올라간거랑
		if (sum[0][i - 2] > sum[1][i - 2]) { //두칸 올랐을때
			sum[0][i] = sum[0][i - 2] + arr[i];
			printf("sum[0][%d] = %d \n",i-2, sum[0][i - 2]);
			printf("1 . 결과 : %d\n", sum[0][i]);
		}
		else {
			sum[0][i] = sum[1][i - 2] + arr[i];
			printf("sum[1][%d] = %d \n", i - 2, sum[1][i - 2]);
			printf("2 . 결과 : %d\n", sum[0][i]);
		}
	}
	printf("%d\n", max(sum[0][n], sum[1][n]));
	for (int i = 1; i <= n; i++)
		printf("sum[0][%d] == %d \n", i,sum[0][i]);
	for (int i = 1; i <= n; i++)
		printf("sum[1][%d] == %d \n", i, sum[1][i]);
}