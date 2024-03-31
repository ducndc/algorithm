#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Representation of a graph using adjacency lists
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency lists

public:
    Graph(int V) : V(V) 
    {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) 
    {
        adj[u].push_back(v);
    }

    // Function to find paths from start to end with no common points
    vector<vector<int>> findPaths(int start, int end) 
    {
        vector<vector<int>> paths;
        vector<int> path;
        unordered_set<int> visited;
        findPathsUtil(start, end, visited, path, paths);
        return paths;
    }

private:
    // Utility function to find paths using DFS
    void findPathsUtil(int current, int end, unordered_set<int>& visited, vector<int>& path, vector<vector<int>>& paths) 
    {
        visited.insert(current);
        path.push_back(current);

        if (current == end) 
        {
            paths.push_back(path);
        } 
        else 
        {
            for (int neighbor : adj[current]) 
            {
                if (visited.find(neighbor) == visited.end()) 
                {
                    findPathsUtil(neighbor, end, visited, path, paths);
                }
            }
        }

        // Backtrack
        visited.erase(current);
        path.pop_back();
    }
};

int main() {
    // Create a graph
    int n, m, s, u, v;
    int ok = 0;
    cin >> n >> m >> s;
    Graph g(n);

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g.addEdge((u-1),(v-1));
    }

    for (int l = 0; l < n; ++l)
    {
        vector<vector<int>> paths = g.findPaths((s-1), l);
        // Check if at least two paths are found
        if (paths.size() >= 2) 
        {
            for (size_t i = 0; i < paths.size(); ++i) 
            {
                for (size_t j = i + 1; j < paths.size(); ++j) 
                {
                    unordered_set<int> commonPoints;
                    // Check for common points between paths[i] and paths[j]
                    for (int node : paths[i]) 
                    {
                        if (node != (s-1) && node != l)
                            commonPoints.insert(node);
                    }
                    bool hasCommon = false;
                    for (int node : paths[j]) 
                    {
                        if (commonPoints.find(node) != commonPoints.end()) 
                        {
                            hasCommon = true;
                            break;
                        }
                    }
                    if (!hasCommon) 
                    {
                        ok = 1;
                        cout << "Possible" << endl;
                        cout << paths[i].size() << endl;
                        for (int node : paths[i]) 
                        {
                            cout << (node + 1) << " ";
                        }
                        cout << endl;
                        cout << paths[j].size() << endl;
                        for (int node : paths[j]) 
                        {
                            cout << (node + 1) << " ";
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (0 == ok)
    {
        cout << "Impossible" << endl;
    }


    return 0;
}
