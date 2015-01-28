#include<stdio.h>

int data[100000];

int comparisons;

void Exchange(int a, int b) {
	int tem;
	tem = data[a];
	data[a] = data[b];
	data[b] = tem;
	return;
}

void FindPivotAndReorder(int s, int e, int type) {
	int m;
	switch(type) {
		case 1: 
			return;
		case 2:
			Exchange(s, e);
			return;
		case 3:
			m =  (s + e) / 2;
			if(data[s] <= data[m]) {
				if(data[m] <= data[e])
					Exchange(s, m);
				else if(data[s] >= data[e]) {}
				else Exchange(s, e);
			} else {
				if(data[m] >= data[e])
					Exchange(s, m);
				else if(data[s] <= data[e]) {}
				else Exchange(s, e);
			}
			return;
	}
	return;

}

int QuickSort(int s, int e) {
	if(s == e)
		return 0;
	if(s > e)
		return -1;
	comparisons += e - s;
	FindPivotAndReorder(s, e, 3);
	int pivot = data[s];
	int i = s+1, j = s+1;
	while(j <= e) {
		if(data[j] > pivot) {
			++j;
		} else {
			Exchange(i, j);
			++i; ++j;
		}
	}
	Exchange(s, i - 1);
	if(i != s + 1)
		QuickSort(s, i - 2);
	if(i != e + 1)
		QuickSort(i, e);
}

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("QuickSort.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n = 0;
	while(scanf("%d", &data[n++]) != EOF);

	comparisons = 0;
	QuickSort(0, n - 2);

	printf("%d\n", comparisons);
}
