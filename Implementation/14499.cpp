#include<iostream>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

int N, M, commandCount;
vector<vector<int> > map;
class Dice{
    private:
        int topFace, bottomFace, leftFace, rightFace, upFace, downFace;
        int diceY, diceX;
        
        bool moveDice(int direction){
            pair<int, int> newPos = getNewPos(direction);
            if(newPos.first >= 0 && newPos.second >=0 && newPos.first < N && newPos.second < M){
                diceY = newPos.first;
                diceX = newPos.second;
                return true;
            }
            return false;
        }

        pair<int, int> getNewPos(int direction){
            int newY = diceY, newX = diceX;
            if(direction == 1) newX++;
            if(direction == 2) newX--;
            if(direction == 3) newY--;
            if(direction == 4) newY++;
            return make_pair(newY, newX);
        }
    public:
        Dice(int y, int x){
            diceY = y;
            diceX = x;
        }    
        bool roll(int direction){
            if(!moveDice(direction)) return false;
            if(direction == 1){
                int temp = topFace;
                topFace = leftFace;
                leftFace = bottomFace;
                bottomFace = rightFace;
                rightFace = temp;
            } else if(direction == 2){
                int temp = topFace;
                topFace = rightFace;
                rightFace = bottomFace;
                bottomFace = leftFace;
                leftFace = temp;
            } else if(direction == 3){
                int temp = topFace;
                topFace = downFace;
                downFace = bottomFace;
                bottomFace = upFace;
                upFace = temp;
            } else if(direction == 4){
                int temp = topFace;
                topFace = upFace;
                upFace = bottomFace;
                bottomFace = downFace;
                downFace = temp;
            }
            return true;
        }
        
        void setBottomFace(int bottomFace){
            this->bottomFace = bottomFace;
        }
        int getBottomFace(){
            return this->bottomFace;
        }
        int getTopFace(){
            return this->topFace;
        }
        pair<int, int> getPos(){
            return make_pair(diceY, diceX);
        }
};

void fillMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}

int main(){
    int diceY, diceX;
    cin >> N >> M >> diceY >> diceX >> commandCount;
    map = vector<vector<int > >(N, vector<int>(M));
    fillMap();
    Dice* dice = new Dice(diceY, diceX);
    while(commandCount--){
        int command;
        cin >> command;
        if(dice->roll(command)){
            pair<int, int> dicePos = dice->getPos();
            int& mapValue = map[dicePos.first][dicePos.second];
            if(mapValue == 0){
                mapValue = dice->getBottomFace();
            }else{
                dice->setBottomFace(mapValue);
                mapValue = 0;
            }           
            cout << dice->getTopFace() << endl;
        } else{
            continue;
        }
    }
    delete dice;
}