#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using std::vector;
using std::priority_queue;

#define VEXNUM 200
struct Edge {
	int t, h; //tail, head
	int value;
	Edge() {}
	Edge(int x, int y, int z) {
		t = x; h = y; value = z;
	}

};

struct Node {
	int p, i;//pre, index
	int dis;
	Node() {}
	Node(int x, int y, int z) {
		p = x; i = y; dis = z;
	}
	bool operator < (const Node rhs) const {
		return dis > rhs.dis;
	}
};

vector<Edge>edges[VEXNUM + 10];
priority_queue<Node> heap;

int dist[VEXNUM + 10];
bool visited[VEXNUM + 10];

void Dijkstra() {
	memset(visited, 0, sizeof(visited));
	int i, j;
	for(i = 0; i < edges[1].size(); ++i) {
		heap.push(Node(1, edges[1][i].h, edges[1][i].value));
	}
	visited[1] = true;
	dist[1] = 0;
	i = VEXNUM;
	while(--i && !heap.empty()) {
		while(visited[heap.top().i] && !heap.empty())
			heap.pop();
		if(heap.empty())
			break;
		Node o = heap.top();
		heap.pop();
		dist[o.i] = o.dis;
		visited[o.i] = true;
		for(j = 0; j < edges[o.i].size(); ++j) {
			heap.push(Node(o.i, edges[o.i][j].h, o.dis + edges[o.i][j].value));
		}
	}
}

int main() {
	freopen("dijkstraData.txt", "r", stdin);

	int v = 0, i;
	char tstr[20], vstr[10];
	for(i = 0; i < 10; ++i)
		vstr[i] = '\0';
	sprintf(vstr, "%d", ++v);
	while(v <= VEXNUM && scanf("%s", tstr) != EOF) {
		if(strcmp(tstr, vstr)) {
			int e, va;
			sscanf(tstr, "%d,%d", &e, &va);
			edges[v-1].push_back(Edge(v-1, e, va));
		}
		else {
			sprintf(vstr, "%d", ++v);
			continue;
		}
	}

	Dijkstra();
	printf("\n");
}
