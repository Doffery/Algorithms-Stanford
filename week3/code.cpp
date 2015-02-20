#include<cstdio>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
#include<cstdlib>

using namespace std;

struct Edge{
	int x, y;
	Edge() {}
	Edge(int xi, int yi) {
		x = xi; y = yi;
	}
};

int dist[210][210];
vector<Edge> edges;
int disj[210];
int rank[210];

int Find(int x) {
	if(disj[x] != x)
		disj[x] = Find(disj[x]);
	return disj[x];
}

void Union(int x, int y) {
	int rx = Find(x);
    int ry = Find(y);
	if(rx == ry)
		return;
	if(rank[rx] > rank[ry])
		disj[ry] = rx;
	else {
		disj[rx] = ry;
		if(rank[rx] == rank[ry])
			rank[ry]++;
	}
}

int main() {
	//freopen("kargerMinCut.txt", "r", stdin);
	//FILE *fp;
	//fp = fopen("kargerMinCut.txt", "r");

	ifstream infile("kargerMinCut.txt");
	string line;
	while(getline(infile, line)) {
		//char s[400];
		//fgets(s, 400, fp);

		//Analysis one line
		stringstream iostr(line);
		int i, j = 0, pj = -1;
		iostr >> i;
		dist[i][i] = 0;
		while(iostr.rdstate() != ios::eofbit) {
			iostr >> j;
			if(j == pj)
				break;
			pj = j;
			dist[i][j] = 1;
			dist[j][i] = 1;
			//edges.push_back(Edge(i, j));
		}
	}
	

	int randomTime = 40000;
	int j, minCut = 40000;
	for(j = 0; j < randomTime; ++j) {
		int m, n;
		edges.clear();
		for(m = 1; m < 201; ++m)
			for(n = m + 1; n < 201; ++n)
				if(dist[m][n])
					edges.push_back(Edge(m, n));
		srand((unsigned)time(NULL) + j); 
		int i;
		for(i = 1; i < 201; ++i) {
			rank[i] = 0;
			disj[i] = i;
		}

		int remain = 200;
		while(remain > 2) {
			//get a random number
			int rnum = (rand() + remain) % edges.size();
			if(Find(edges[rnum].x) != Find(edges[rnum].y)) {
				Union(edges[rnum].x, edges[rnum].y);
				remain --;
			}
			edges.erase(edges.begin() + rnum);
		}
		int c = 0;
		for(i = 0; i < edges.size(); ++i) {
			if(Find(edges[i].x) != Find(edges[i].y))
				++c;
			//printf("%d %d\n", Find(edges[i].x), Find(edges[i].y));
		}
		if(c < minCut)
			minCut = c;
	}
	printf("%d\n", minCut);
}
