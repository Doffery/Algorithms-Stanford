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
	comparisons += e - s;
	FindPivotAndReorder(s, e, 3);
	int pivot = data[s];
	int i = s, j = e;
	while(i < j) {
		while(data[j] > pivot && i < j)
			--j;
		if(i == j)
			break;
		data[i] = data[j];
		while(data[i] < pivot && i < j)
			++i;
		data[j] = data[i];
	}
	data[i] = pivot;
	if(i != s)
		QuickSort(s, i - 1);
	if(i != e)
		QuickSort(i + 1, e);
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
