#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int arr[8];

void sort (){

}

void dfs(int num){
    if (v.size()==M){
        for (int i = 0; i < M; ++i){
            cout << arr[v[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i < N; ++i) {
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }
}

int main (){

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    dfs(0);

    return 0; 
}