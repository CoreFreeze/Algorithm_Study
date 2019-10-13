#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int people[10];
vector<int> connected[10];
vector<int> visited;
vector<int> a,b;
int minValue = 9999999;

bool check(vector<int> &check){
    queue<int> q;
    q.push(check[0]);
    int count = 0;
    bool visitedNode[10];
    fill(visitedNode,visitedNode+10,false);
    visitedNode[check[0]] = true;
    while(!q.empty()){
        int current = q.front(); q.pop();
        count++;
        int loopSize = connected[current].size();
        for (int i = 0; i < loopSize; ++i){
            int Node = connected[current][i];
            if (visitedNode[Node]) continue;
            int groupSize = check.size();
            for (int j = 0; j < groupSize; ++j){
                if(Node == check[j]){
                    visitedNode[Node] = true;
                    q.push(Node);
                    break;
                }
            }
        }
    }

    if (count == check.size()){
        return true;
    }
    else {
        return false;
    }

}

void makeGroup(int index){
    if (index == (N-1)){
        a.clear();
        b.clear();
        int suma = 0;
        int sumb = 0;
        for (int i = 0; i<N; ++i){
            if(visited[i]){
                a.push_back(i); suma += people[i];
            }
            else {
                b.push_back(i); sumb += people[i];
            }
        }
        if (a.empty() || b.empty()) return;

        /* 연결되었는지 확인 */
        if (check(a)&&check(b)) {
            int calcSum = abs(suma-sumb);
            if (calcSum < minValue){
                minValue = calcSum;
            }
        }
    }

    for (int i = index; i < N; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        makeGroup(i);
        visited[i] = false;
    }
}

int main (){

    cin >> N;
    visited.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> people[i];
    }
    for (int i = 0,num; i < N; ++i){
        cin >> num;
        for (int j = 0,temp;j < num; ++j){
            cin >> temp;
            connected[i].push_back(temp-1);
        }
    }

    /* 분류 */
    makeGroup(0);

    if (minValue == 9999999) cout << -1 << '\n';
    else cout << minValue << '\n';

    return 0;
}