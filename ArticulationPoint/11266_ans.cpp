// 단절점

#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX_N 100001
using namespace std;
vector<int>adjList[MAX_N];
int order[MAX_N];
bool isCut[MAX_N];
int T, number;

// 단절점 탐색
int dfs(int here, bool isRoot) {
    order[here] = number++; // DFS 탐색 순서 저장
    int low = order[here]; // low 의 초기값은 자기 자신의 order
    int child = 0; // 자식 수 count

    for (int next : adjList[here]) {
        /*
         만약 이미 DFS에서 탐색된 정점이라면
         현재 정점의 방문순서와 탐색된 정점의 방문 순서 중 min값(=low)을 찾는다.
        */
        // 이미 방문한 정점이면 Skip
        if (order[next] > 0) {
            low = min(low, order[next]);
            continue;
        }

        child++;
        int minValue = dfs(next, false);

        /*
        정점 A가 시작 정점(root)이 아닐 때
        A번 정점에서 자식 노드들이 정점 A를 거치지 않고
        정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다.
        */
        if (!isRoot && order[here] <= minValue) {
            isCut[here] = true;
        }

        low = min(low, minValue);
    }

    /*
    정점 A가 시작 정점(root)일 때
    자식 수가 2개 이상이면 단절점이다.
    */
    if (isRoot) {
        isCut[here] = (child >= 2);
    }

    return low;
}

int main() {
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int V; // 정점 수
        int E; // 간선 수
        scanf("%d %d", &V, &E);

        for (int i = 1; i <= V; i++) {
            adjList[i].clear();
        }

        memset(order, 0, sizeof(order));
        memset(isCut, 0, sizeof(isCut));

        for (int i = 0; i < E; i++) {
            int from;
            int to;
            scanf("%d %d", &from, &to);
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        number = 1;

        for (int i = 1; i <= V; i++) {
            if (order[i] == 0) {
                dfs(i, true);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= V; i++) {
            if (isCut[i]) {
                cnt++;
                printf("%d ", i);
            }
        }
        printf("count : %d", cnt);

    }
}