#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using std::vector;

vector<long> data;

int bloom[20001];

int main() {
	freopen("algo1-programming_prob-2sum.txt", "r", stdin);
	//freopen("in.txt", "r", stdin);

	long l;
	while(scanf("%ld", &l) != EOF) {
		data.push_back(l);
	}

	sort(data.begin(), data.end());

	memset(bloom, 0, sizeof(bloom));
	int i = 0, ju = data.size()-1, jb;
	while(i < jb) {
		long lb = -data[i] - 10000;
		long hb = -data[i] + 10000;
		while(data[ju] > hb) {
			--ju;
		}
		jb = ju;
		while(data[jb] >= lb) {
			bloom[data[i] + data[jb] + 10000] = true;
			--jb;
		}
		++i;
	}

	int k = 0;

	for(i = 0; i < 20002; ++i)
		if(bloom[i])
			++k;
	printf("%d\n", k);
	
}
