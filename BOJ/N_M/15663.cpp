#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
vector<int> visited;
vector<int> stored;
vector<vector<int>> result;

void dfs(int num){
    if (v.size()==M){
        result.push_back(v);
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(stored[i]);
        dfs(i);
        v.pop_back();
        visited[i] = false;
    }
}

int main (){

    cin >> N >> M;

    visited.resize(N);
    stored.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> stored[i];
    }

    sort(stored.begin(),stored.end());

    dfs(0);

    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());

    for (int i = 0; i < result.size() ; ++i){
        for (int j = 0; j < M; ++j){
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0; 
}