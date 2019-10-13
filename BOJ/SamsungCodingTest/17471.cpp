#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int people[10];
vector<int> connected[10];
vector<int> a,b;

int minValue = 9999999;

bool check(vector<int> &check){
    
    queue<int> q;
    q.push(check[0]);
    bool visited[10];
    fill(visited,visited+10, false);
    visited[check[0]] = true;
    int count = 0;

    while(!q.empty()){
        int current = q.front(); q.pop();
        count++;
        int loopSize = connected[current].size();
        for (int i = 0; i < loopSize; ++i){
            int Node = connected[current][i];
            if (visited[Node]) continue;
            for (int j = 0; j < check.size(); ++j) {
                if (check[j]==Node){
                    visited[Node] = true;
                    q.push(Node);
                    break;
                }
            }
        }
    }
    if (count == check.size()) {
        return true;
    }
    else {
        return false;
    }
}


int main () {

    cin >> N; /* 구역 수 */
    /* 인구 수 */
    for (int i = 0; i < N; ++i ){
        cin >> people[i];
    }

    for (int i = 0,temp; i < N; ++i){
        cin >> temp;
        for (int j = 0, inputTemp; j < temp; ++j){
            cin >> inputTemp;
            connected[i].push_back(inputTemp-1);
        }
    }

    /* 구역 나누기 */
    for (int i = 1; i < ((1<<N) -1); ++i){
        a.clear();
        b.clear();
        int suma = 0; 
        int sumb = 0;
        for (int j = 0; j < N; ++j){
            if (i & (1<<j)) {
                a.push_back(j);
                suma += people[j];
            } else {
                b.push_back(j);
                sumb += people[j];
            }
        }

        /* 연결되어 있는지 확인  */
        if (check(a) && check(b)) {
            int diff = abs(suma-sumb);
            if (minValue > diff){
                minValue = diff;
            }
        }
    }

    if (minValue == 9999999) cout << -1 <<'\n';
    else cout << minValue <<'\n';

    return 0;
}