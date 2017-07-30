#include <stdio.h>
#include <string.h>

int dp[1000001];
int output[1000001];

int solve(int n)
{
	int min = 9999999999;
	int temp, out;

	if (dp[n] != -1)    return dp[n];

	if (n % 3 == 0) {
		temp = solve(n / 3);
		if (temp < min) {
			out = n / 3;
			min = temp;
		}
	}
	if (n % 2 == 0) {
		temp = solve(n / 2);
		if (temp < min) {
			out = n / 2;
			min = temp;
		}
	}
	temp = solve(n - 1);
	if (temp < min) {
		min = temp;
		out = n - 1;
	}

	output[n] = out;
	return dp[n] = min + 1;
}

void print(int n)
{
	printf("%d ", n);
	while (output[n] != 1) {
		printf("%d ", output[n]);
		n = output[n];
	}
	printf("1\n");
}

int main()
{
	int n;

	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 0;

	printf("%d\n", solve(n));
	print(n);

	return 0;
}

