//
// Created by HyunI on 2019-07-09.
//

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 6;
vector<int> findRoute(const int adj[N][N], int start, int end) {
    // 각 정점 이전에 방문한 정점
    int prev[N];
    fill(prev, prev+N, -1);

    // 너비 우선 탐색용 큐
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        // 이번에 방문하는 정점
        int p = q.front(); q.pop();
        // 목적지에 도달했다면 경로 구성
        if(p == end) {
            // 경로를 저장할 vector
            vector<int> route;
            // 목적지부터 거꾸로 가면서 정점들을 넣어줌
            while(p != start) {
                route.push_back(p);
                p = prev[p];
            }
            // 시작점도 경로에 포함시킴
            route.push_back(p);

            // 거꾸로 넣었기 때문에 뒤집어주어야 함
            reverse(route.begin(), route.end());

            // 구성한 경로 반환
            return route;
        }

        // 방문한 정점에서 다음 정점으로 넘어감
        for(int next=0; next<N; next++) {
            // 같은 정점이면 스킵
            if(next == p) continue;
            // 갈 수 없으면 스킵
            if(!adj[p][next]) continue;
            // 이미 방문한 정점이면 스킵
            if(prev[next] != -1) continue;

            // 다음 정점 이전에 이번 정점 p를 방문했다는 정보 저장
            prev[next] = p;
            // 다음 정점 방문 예약
            q.push(next);
        }
    }

    // 경로가 없는 경우 빈 vector 반환
    return vector<int>();
}

int main() {
    int adj[N][N] = {
            { 0, 1, 0, 1, 0, 0},
            { 1, 0, 0, 0, 0, 0},
            { 0, 0, 0, 1, 0, 1},
            { 1, 0, 1, 0, 0, 0},
            { 0, 0, 0, 0, 0, 1},
            { 0, 0, 1, 0, 1, 0},
    };
    for(int p : findRoute(adj, 0, 4)) cout << p << " ";
    return 0;
}