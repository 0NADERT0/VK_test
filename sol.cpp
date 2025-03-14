#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("graph.txt");

    int n, m;

    file >> n;
    file >> m;

    vector<vector<int>> graph(n);
    queue<int> q;
    vector<int> dst(n, 2e9);
    vector<int> was(n, 0);

    int a, b;
    for (int i = 0; i < m; i++){
        file >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int start;
    file >> start;
    
    file.close();

    q.push(start);
    was[start] = 1;
    dst[start] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (const int& i: graph[v]){
            if (!was[i]){
                was[i] = 1;
                q.push(i);
                dst[i] = dst[v] + 1;
            }
        }
    }
    for (const int& i: dst){
        cout << i << endl;
    }
}
