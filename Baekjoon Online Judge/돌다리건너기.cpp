#include<stdio.h>
#include<string.h>

char A[101], D[101];
int arr[2][21];

int main() {
	char check[21];
	int A_len;
	int check_len;

	scanf("%s %s %s", &check, &A, &D);
	A_len = strlen(A);
	check_len = strlen(check);

	for (int i = 0; i < A_len; i++) {
		for (int j = 1; j < check_len; j++) {
			if (check[j] == A[i]) {
				arr[0][j] += arr[1][j - 1];
			}// 천사쪽 첫발
			if (check[j] == D[i]) {
				arr[1][j] += arr[0][j - 1];
			} // 악마쪽 발

		}//첫 번째 빼고는 다 알아야됨..
		if (check[0] == A[i]) {
			arr[0][0]++;
		}
		if (check[0] == D[i]) {
			arr[1][0]++;
		}//첫번째 경우 구해야됨
	}
	printf("%d\n", arr[0][check_len - 1] + arr[1][check_len - 1]);
	return 0;
}