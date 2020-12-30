#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n_list[1000001] = { 0, };

int make1(int k, int ct) {
	if (k == 1)
		return n_list[k];
	if (n_list[k] == 0) {
		int per2, per3, m1, min_value = 100000000;
		if (k % 2 == 0) {
			per2 = make1(k / 2, ct + 1);
			if (min_value > per2)
				min_value = per2;
		}
		if (k % 3 == 0) {
			per3 = make1(k / 3, ct + 1);
			if (min_value > per3)
				min_value = per3;
		}
		m1 = make1(k - 1, ct + 1);
		if (min_value > m1)
			min_value = m1;

		n_list[k] = min_value + 1;
		return min_value + 1;
	}
	else
		return n_list[k];
}

int main() {
	int n, cnt = 0;
	n_list[1], n_list[2], n_list[3] = 0,1,1;
	scanf("%d", &n);
	if (n < 1 || n>1000000) return 1;
	cnt = make1(n, 0);
	printf("%d\n", n_list[n]);
	return 0;
}