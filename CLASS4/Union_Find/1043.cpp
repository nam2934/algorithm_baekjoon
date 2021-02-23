#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > party_set;
vector<int> truth_know_people;
vector<int> parent;

int Find(int a){
    if(a != parent[a]){
        return Find(parent[a]);
    }
    return parent[a];
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}

int main(){
    int result;
    int number_of_people, number_of_party, number_of_truth_know_people;

    cin >> number_of_people >> number_of_party;
    cin >> number_of_truth_know_people;
    result = number_of_party;
    party_set = vector<vector<int> >(number_of_party);
    parent = vector<int>(number_of_people);

    for(int i=0; i<number_of_people; i++) parent[i] = i;

    for(int i=0; i<number_of_truth_know_people; i++){
        int truth_know_person;
        cin >> truth_know_person;
        truth_know_people.push_back(truth_know_person-1);
    }

    for(int i=0; i<number_of_party; i++){
        int number_of_each_party;
        cin >> number_of_each_party;
        for(int j=0; j<number_of_each_party; j++){
            int party_set_person;
            cin >> party_set_person;
            party_set[i].push_back(party_set_person-1);
            if(number_of_each_party == 1 || j==0) continue;
            Union(party_set[i][j-1], party_set[i][j]);
        }
    }
    for(int i=0; i<number_of_party; i++){
        bool flag = false;
        for(int j=0; j<party_set[i].size(); j++){
            for(int k=0; k<number_of_truth_know_people; k++){
                if(Find(party_set[i][j]) == Find(truth_know_people[k])) flag = true;
            }            
        }
        if(flag) result--;
    }
    cout << result;
}