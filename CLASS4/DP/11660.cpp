#include <iostream>

using namespace std;

int sumArr[1025][1025] = {0, };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, num;
	cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> num;
            sumArr[i+1][j+1] = sumArr[i][j+1] + sumArr[i+1][j] - sumArr[i][j] + num;
        }
    }

    for(int i=0; i<M; i++){
        int x1, y1, x2, y2, result;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sumArr[x2][y2] - sumArr[x2][y1-1] - sumArr[x1-1][y2] + sumArr[x1-1][y1-1] << "\n";
    }

}