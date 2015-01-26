#include<stdio.h>

int data[100010];
int dataSort[100010];

long Merge(int s, int m, int t) {
	long inversions = 0;
	int i = s, j = m + 1;//index
	int index = s;//index for sorting
	while(i <= m && j <=t) {
		if(data[i] <= data[j]) {
			dataSort[index] = data[i];
			++i; ++index;
		} else {
			inversions += m - i + 1;
			dataSort[index] = data[j];
			++j; ++index;
		}
	}
	int ci = index;
	while(i <= m) {
		dataSort[ci++] = data[i++];
	}
	while(j <= t) {
		dataSort[ci++] = data[j++];
	}
	for(i = s; i <= t; ++i) {
		data[i] = dataSort[i];
	} 

	return inversions;
}
//pay attention to size_t
//the return value equals the number of inversions in this range
long MergeSort(int s, int t) {
	if(s == t) {
		dataSort[s] = data[s];
		return 0;
	}
	if(s == t - 1) {
		if(data[s] <= data[t]) 
			return 0;
		else {
			int tem = data[t];
			data[t] = data[s];
			data[s] = tem;
			return 1;
		}
	}
	int m = (s + t) / 2;
	long l, r, n;
	l = MergeSort(s, m);
	r = MergeSort(m + 1, t);
	n = Merge(s, m, t);

	return l + r + n;
}



int main() {
	//freopen("in.txt", "r", stdin);
	freopen("IntegerArray.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n = 0;
	while (scanf("%d", &data[n++]) != EOF);
	printf("%ld\n", MergeSort(0, n - 2));


}
