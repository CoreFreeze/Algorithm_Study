/* 15650 */
#include <iostream> 
#include <vector>
using namespace std;

int N,M;
vector <int> v;
vector <bool> visited;

void dfs(int num){

    if (num > N) {
        return;
    }

    if(v.size() == M) {
        for (int i = 0; i < M; ++i){
            cout << v[i] <<' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; ++i){
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i);
        v.pop_back();
        visited[i] = false;
    }

}

int main (){

    cin >> N >> M;
    visited.resize(N+1);
    dfs(1);

    return 0;
}