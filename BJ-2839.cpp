#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n_list[5001] = { 0, };

int b_num(int k, int numm) {
	int m3, m5, min_value = 10000;
	if (n_list[k] == 0) {
		m3 = b_num(k - 3, numm + 1);
		if (m3 < min_value && m3 > 0)
			min_value = m3;
		if (k > 7) {
			m5 = b_num(k - 5, numm + 1);
			if (m5 < min_value && m5 > 0)
				min_value = m5;
		}
		if (min_value == 10000)
			n_list[k] = -1;
		else
			n_list[k] = min_value + 1;
		return min_value + 1;
	}
	else
		return n_list[k];
}

int main() {
	int N;
	while (1) {
		scanf("%d", &N);
		if (N < 3 || N > 5000)
			return 1;
		n_list[3] = 1;
		n_list[4] = -1;
		n_list[5] = 1;
		b_num(N, 0);
		printf("%d\n", n_list[N]);
	}

	return 0;
}