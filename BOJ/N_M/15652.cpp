#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void dfs(int num){
    if (v.size() == M) {
        for (int i = 0; i < M; ++i){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; ++i) {
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }

}

int main (){

    cin >> N >> M;

    dfs(1);

    return 0;
}