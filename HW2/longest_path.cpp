#include <iostream>
#include <vector>
#include <algorithm>


class Graph {
    int n;
public:
    int maxDistance;
    std::vector<std::vector<int>> adjList;
    std::vector<int> maxDistList;

    Graph(int N) : n(N), maxDistance(INT_MIN), maxDistList(n, 0), adjList(N) { }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void dfs(int v, std::vector<bool>& visited) {
        visited[v] = true;
        printf("%d ", v);
        for (int neighbor : adjList[v]) {

            if (!visited[neighbor]) {
                dfs(neighbor, visited);

            }
            maxDistList[v] = std::max(maxDistList[v], maxDistList[neighbor] + 1);
        }

    }

    void longestPath() {
        std::vector<bool> visited(n, false);

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, visited);
                printf("\n");
            }
        }

        for (int it : maxDistList) {
            if(it > maxDistance) {
                maxDistance = it;
            }
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        g.addEdge(a-1, b-1);
    }

    g.longestPath();

    std::cout << g.maxDistance;

    return 0;
}