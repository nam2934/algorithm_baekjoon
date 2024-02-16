#include<iostream>
#include<vector>

using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    int a, b, c, d, GCDbd, ac, bd, GCDacbd; 
    cin >> a >> b;
    cin >> c >> d;
    GCDbd = GCD(b,d);
    
    a *= (b*d/GCDbd)/b;
    c *= (b*d/GCDbd)/d;
    ac = a+c;
    bd = b*d/GCDbd;
    GCDacbd = GCD(ac, bd);
    cout << ac / GCDacbd << " " << bd / GCDacbd;
}