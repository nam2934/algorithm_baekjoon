#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int arr[100][100];

int main(){
    int N, L, result = 0;
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<N; i++){
        int index = 0;
        int count = 0;
        int number = -1;
        bool find = true;
        while(index != N){   
            if(number == -1){
                number = arr[i][index];
                count++;
                index++;
                continue;
            }
            if(number == arr[i][index]){
                index++;
                count++;
                continue;
            }
            if(number == arr[i][index] + 1){                         
                for(int j=0; j<L; j++){
                    if(index+j < N && arr[i][index+j] == arr[i][index]) continue;
                    else{
                        find = false;
                        break;
                    }
                }
                if(find == false) break;
                else{
                    number = arr[i][index];
                    index += L;
                    count = 0;
                }
                continue;
            }
            if(number == arr[i][index] - 1){                          
                if(count >= L){
                    number = arr[i][index];
                    index++;
                    count = 1;
                   
                }
                else{                    
                    find = false;
                    break;
                }
            }
            else{
                find = false;
                break;
            }
        }
        if(find){
            result++;
        }
    }
    for(int i=0; i<N; i++){
        int index = 0;
        int count = 0;
        int number = -1;
        bool find = true;
        while(index < N){   
            if(number == -1){
                number = arr[index][i];
                count++;
                index++;
                continue;
            }
            if(number == arr[index][i]){
                index++;
                count++;
                continue;
            }
            if(number == arr[index][i] + 1){                   
                for(int j=0; j<L; j++){
                    if(index+j < N && arr[index+j][i] == arr[index][i]) continue;
                    else{
                        find = false;
                        break;
                    }
                }
                if(find == false) break;
                else{  
                    number = arr[index][i];
                    index += L;
                    count = 0;
                }
                continue;
            }
            if(number == arr[index][i] - 1){                          
                if(count >= L){
                    number = arr[index][i];
                    index++;
                    count = 1;
                }
                else{                    
                    find = false;
                    break;
                }
            }
            else{
                find = false;
                break;
            }
        }
        if(find){          
            result++;
        }
    }    
    cout << result;
}