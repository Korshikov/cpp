#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m, timer = 0, comp = 0;
const int MAX_N = 100000;
vector<pair<int, int> > graph[MAX_N];
vector<char> color;
vector<int> timeIn;
vector<int> up;
vector<int> colors;
set<int> point;
//vector<int> parent;

void dfs(int v, int parent) {
    color[v] = 1;
    timeIn[v] = timer++;
    up[v] = timeIn[v];
    int children = 0;
    for (vector<pair<int, int> >::iterator i = graph[v].begin(); i != graph[v].end(); ++i) {
        if (parent == (*i).first) {
            continue;
        }
        if (((color[(*i).first]) != 0) && ((*i).first != parent)) {
            up[v] = min(up[v], timeIn[(*i).first]);
        }
        else {
            dfs((*i).first, v);
            up[v] = min(up[v], up[(*i).first]);
            if ((up[(*i).first] >= timeIn[v]) && (parent != -1)) {
                point.insert(v);
            }
            ++children;
        }
    }
    color[v] = 2;
    if ((parent == -1) && (children > 1)) {
        point.insert(v);
    }
}

void dfs2(int v, int parent, int colorThis) {
    color[v] = 1;
    for (vector<pair<int, int> >::iterator i = graph[v].begin(); i != graph[v].end(); ++i) {
        if (parent == (*i).first) {
            continue;
        }
        if (((color[(*i).first]) == 2)) {
            if (up[(*i).first] >= timeIn[v]) {
                colors[(*i).second] = ++comp;
                dfs2((*i).first, v, comp);
            }
            else {
                colors[(*i).second] = colorThis;
                dfs2((*i).first, v, colorThis);
            }
        }
        else {
            if (timeIn[(*i).first] <= timeIn[v]) {
                colors[(*i).second] = colorThis;
            }
        }
    }
    color[v] = 0;
}


int main() {
    freopen("biconv.in", "r", stdin);
    freopen("biconv.out","w+",stdout);

    scanf("%d %d", &n, &m);
    color.assign(n, 0);
    timeIn.assign(n, 0);
    up.assign(n, 0);
    colors.assign(m, 0);
    point.clear();

    int bufer1, bufer2;

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &bufer1, &bufer2);
        graph[bufer1 - 1].push_back(make_pair(bufer2 - 1, i));
        graph[bufer2 - 1].push_back(make_pair(bufer1 - 1, i));
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 2) {
            dfs2(i, -1, -1);
        }
    }


    printf("%d\n", comp);

    for (vector<int>::iterator i = colors.begin(); i != colors.end(); ++i) {
        printf("%d ", *i);
    }


/*    printf("%d \n",point.size());

    //sort(point.begin(), point.end());

    for(set<int>::iterator i=point.begin();i!=point.end();++i)
    {
        printf("%d ",*i+1);
    }
*/


    fclose(stdin);
    fclose(stdout);

    return 0;
}
