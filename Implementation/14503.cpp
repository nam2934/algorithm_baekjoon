#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,M;
int robotX, robotY, direction;
vector<vector<int> > room;
vector<vector<int> > cleanStatus;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isWall(int y, int x){
    if(room[y][x] == 1) return true;
    return false;
}

bool isbackwardAvail(int y, int x){
    return !isWall(y, x);
}

bool isforwardAvail(int y, int x){
    return cleanStatus[y][x] == -1;
}

void forward(){
    if(direction == 0){
        if(isforwardAvail(robotY-1, robotX)){
            robotY -= 1;
        }
    } else if(direction == 1){
        if(isforwardAvail(robotY, robotX+1)){
            robotX += 1;
        }
    } else if(direction == 2){
        if(isforwardAvail(robotY+1, robotX)){
            robotY += 1;
        }        
    } else if(direction == 3){
        if(isforwardAvail(robotY, robotX-1)){
            robotX -= 1;
        }
    }
}

bool backward(){
    if(direction == 0){
        if(isbackwardAvail(robotY+1, robotX)){
            robotY += 1;
            return true;
        }
    } else if(direction == 1){
        if(isbackwardAvail(robotY, robotX-1)){
            robotX -= 1;
            return true;
        }
    } else if(direction == 2){
        if(isbackwardAvail(robotY-1, robotX)){
            robotY -= 1;
            return true;
        }
    } else if(direction == 3){
        if(isbackwardAvail(robotY, robotX+1)){
            robotX += 1;
            return true;
        }
    }
    return false;
}

void fillRoom(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> room[i][j];
        }
    }
}

void fillStatus(){
   for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(room[i][j] == 0) cleanStatus[i][j] = -1;
            else cleanStatus[i][j] = 0;
        }
   }
}

int cleanRoom(){
    int cleanArea = 0;
    int step = 0;
    while(1){
        step++;
        bool isCleanStatusFourDirection = false;
        if(cleanStatus[robotY][robotX] == -1){
            cleanStatus[robotY][robotX] = 1;
            cleanArea++;
        }
        for(int i=0; i<4; i++){
            int newX = robotX + dx[i];
            int newY = robotY + dy[i];
            if(cleanStatus[newY][newX] == -1) isCleanStatusFourDirection = true;
        }
        if(!isCleanStatusFourDirection){        
            if(!backward()){
                return cleanArea;
            }
            continue;
        }
        else{
            direction = (direction + 3)%4;
            forward();
            continue;
        }
    }
    return cleanArea;
}

int main(){
    cin >> N >> M;
    cin >> robotY >> robotX >> direction;
    room = vector<vector<int> >(N, vector<int>(M));
    cleanStatus = vector<vector<int> >(N, vector<int>(M));
    fillRoom();
    fillStatus();
    cout << cleanRoom();
}