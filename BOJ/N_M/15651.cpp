/* 15651 */
#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int N, M;

void dfs(){

    if (v.size()==M) {
        for (int i = 0; i < M; ++i){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }

}

int main (){
    cin >> N >> M;

    dfs();

    return 0;
}
