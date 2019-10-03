/* 15649 */
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> v;
vector <bool> visited;

void dfs(){

    if (v.size() == M){
        for (int i = 0; i < M; ++i){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i){
        if (visited[i]==true) continue;
            visited[i]=true;
            v.push_back(i);
            dfs();
            visited[i]=false;
            v.pop_back();
    }
}


int main (){

    cin >> N >> M;
    visited.resize(N+1);
    dfs();

    return 0;
}