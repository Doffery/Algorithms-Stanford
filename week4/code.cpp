#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using std::vector;
using std::priority_queue;

#define VEXNUM 875714

vector<int> G[VEXNUM + 10];
vector<int> Grev[VEXNUM + 10];
priority_queue<int> result;

int finish[VEXNUM + 10];
int leader[VEXNUM + 10];

bool explored[VEXNUM + 10];

int refinish[VEXNUM + 10];//reconstruct the finish arry

int s, t = 0, scc_num = 0;
void DFS(vector<int> Graph[], int i, bool rev) {
	explored[i] = true;
	if(!rev)
		leader[finish[i]] = s;
	size_t j, st = Graph[i].size();
	for(j = 0; j < st; ++j)
		if(!explored[Graph[i][j]])
			DFS(Graph, Graph[i][j], rev);

	if(rev) {
		++t;
		finish[i] = t;
		refinish[t] = i;
	}
}
void DFSLoop(vector<int> Graph[], bool rev) {
	int i;
	if(rev)
		for(i = 1; i <= VEXNUM; ++i) {
			if(!explored[i]) {
				s = i;
				DFS(Graph, i, rev);
			}
		}
	else
		for(i = VEXNUM; i > 0; --i) {
			if(!explored[refinish[i]]) {
				s = i;
				DFS(Graph, refinish[i], rev);
				++scc_num;
			}
		}
}

void CountSCC() {
	std::sort(leader+1, leader+VEXNUM+1);
	int t = leader[1], i, tc = 1;
	for(i = 2; i <= VEXNUM; ++i) {
		if(leader[i] == leader[i - 1])
			++tc;
		else {
			result.push(tc);
			tc = 1;
		}
	}
	result.push(tc);
}

int main() {
	freopen("SCC.txt", "r", stdin);
	int t, h;
	while(scanf("%d %d", &t, &h) != EOF) {
		G[t].push_back(h);
		Grev[h].push_back(t);
	}
	memset(explored, 0, sizeof(explored));

	DFSLoop(Grev, true);
	memset(explored, 0, sizeof(explored));
	DFSLoop(G, false);

	CountSCC();
	int i;
	for(i = 0; i < scc_num && i < 5; ++i) {
		printf("%d ", result.top());
		result.pop();
	}

	return 0;
}
