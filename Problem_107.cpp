#include<bits/stdc++.h>
using namespace std;
int V;

vector<int> split(string str)
{
    vector<int> vect;
    stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

long long MSTminCost(int parent[], vector<vector<int>> graph)
{
    long long res=0;
    for (int i = 1; i < V; i++)
        res+=graph[i][parent[i]];
        return res;
}

long long primMST(vector<vector<int>>  graph)
{
    V=graph.size();
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    return MSTminCost(parent, graph);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("p107_network.txt","r",stdin);

    vector<vector<int>> graph;
    string str;
    while(cin>>str)
    {
        graph.push_back(split(str));
    }
    long long initialWeight=0;
    for(int i=0;i<graph.size();i++)
        for(int j=0;j<graph[i].size();j++)
            initialWeight+=graph[i][j];
    initialWeight/=2;
    long long newWeight=primMST(graph);
    long long saving=initialWeight-newWeight;
    cout<<"initialWeight= "<<initialWeight<<'\n';
    cout<<"newWeight= "<<newWeight<<'\n';
    cout<<"saving= "<<saving<<'\n';

    return 0;
}

