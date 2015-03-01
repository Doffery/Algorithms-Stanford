#include<cstdio>
#include<queue>
#include<vector>

#define MOD 10000
using std::priority_queue;

priority_queue<int> heap_max;//low part
priority_queue<int, std::vector<int>, std::greater<int> > heap_min;//high part

int main() {
	freopen("Median.txt", "r", stdin);

	int n, s = 0;
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if(n1 < n2) {
		heap_max.push(n1);
		heap_min.push(n2);
		s += 2 * n1;
	}else {
		heap_max.push(n2);
		heap_min.push(n1);
		s += n1 + n2;
	}
	while(scanf("%d", &n) != EOF) {
		if(heap_max.top() >= n) {
			heap_max.push(n);
			if(heap_max.size() > heap_min.size() + 1) {
				heap_min.push(heap_max.top());
				heap_max.pop();
			}
		}
		else if(heap_min.top() <= n) {
			heap_min.push(n);
			if(heap_min.size() > heap_max.size()) {
				heap_max.push(heap_min.top());
				heap_min.pop();
			}
		} else {
			if(heap_max.size() <= heap_min.size()) {
				heap_max.push(n);
			}
			else heap_min.push(n);
		}
		s += heap_max.top();

	}
	printf("%d\n", s % MOD);
}
