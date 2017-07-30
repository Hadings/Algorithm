/*

[����]1�� ����� 2
DP����

*/

#include<stdio.h>

int DP[1000001];

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n; 
	int cnt=0;
	scanf("%d", &n);
	DP[1] = 0;

	for (int i = 2; i <= n; i++) {
		// �׻� �ּҰ��� �Էµȴٰ� �����Ѵ�.??
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) {
			DP[i] = min(DP[i],DP[i / 3] + 1);
		}
		else if (i % 2 == 0) {
			DP[i] = min(DP[i],DP[i / 2] + 1);
		}

	}
	
	printf("%d\n", DP[n]);
	for (int i = 1; i <= n; i++) {
		printf("%d : %d\n",i, DP[i]);
	}
	return 0;
}