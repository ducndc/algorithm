#include <bits/stdc++.h>
#include <list>

using namespace std;

class Graph {
    int m_v;
    int m_ok;
    int m_nok;
    int m_path[200000];
    int m_sizePath;
    list<int> *m_adj;
    void printAllPathsUtils(int, int, bool[], int[], int&);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void printAllPaths(int s, int d);
    void resetOK();
    int getNOK();

};

Graph::Graph(int v)
{
    this->m_v = v;
    this->m_ok = 0;
    this->m_nok = 0;
    this->m_sizePath = 0;
    m_adj = new list<int>[v];
    for (int i = 0; i < 200000; ++i)
    {
        m_path[i] = -1;
    }
}

void Graph::addEdge(int v, int w)
{
    m_adj[v-1].push_back(w-1);
}

void Graph::printAllPaths(int s, int d)
{
    bool *visited = new bool[m_v];
    int *path = new int[m_v];
    int pathIndex = 0;
    for (int i = 0; i < m_v; ++i)
    {
        visited[i] = false;
    }

    printAllPathsUtils(s, d, visited, path, pathIndex);
}

void Graph::printAllPathsUtils(int u, int d, bool visited[], int path[], int &pathIndex)
{
    visited[u] = true;
    path[pathIndex] = u;
    pathIndex++;

    if (u == d)
    {
        m_ok += 1;
        if (m_ok == 1)
        {
            for (int i = 0; i < pathIndex; ++i)
            {
                m_path[i] = path[i];
            }
            m_sizePath = pathIndex;
        }
        if (m_ok == 2)
        {
            for (int i = 1; i < (m_sizePath - 1); ++i)
            {
                for (int j = 1; j < (pathIndex - 1); ++j)
                {
                    if (m_path[i] == path[j])
                    {
                        m_ok -= 1;
                        pathIndex--;
                        visited[u] = false;
                        return;
                    }

                }
            }
            cout << "Possible" << endl;
            cout << m_sizePath << endl;
            for (int i = 0; i < 200000; ++i)
            {
                if (m_path[i] != -1)
                {
                    cout << m_path[i] + 1 << " ";
                }
            }
            cout << endl;
            cout << pathIndex << endl;
            for (int i = 0; i < pathIndex; ++i)
                cout << (path[i] + 1) << " ";
            cout << endl;
            m_nok = 1;
        }
    }
    else
    {
        list<int>::iterator i;
        for (i = m_adj[u].begin(); i != m_adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtils(*i, d, visited, path, pathIndex);
    }

    pathIndex--;
    visited[u] = false;
}

void Graph::resetOK()
{
    m_ok = 0;
    for (int i = 0; i < 200000; ++i)
    {
        m_path[i] = -1;
    }
    m_sizePath = 0;
}

int Graph::getNOK()
{
    return m_nok;
}

int main()
{
    // Create a graph
    int n, m, s, u, v;
    cin >> n >> m >> s;
    Graph g(n);
    
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    if (2 == n)
    {
    	cout << "Impossible" << endl;
    	return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (i != (s-1))
            g.printAllPaths((s - 1), i);
        g.resetOK();
    }
    if (g.getNOK() == 0)
    {
        cout << "Impossible" << endl;
    }
    return 0;
}
