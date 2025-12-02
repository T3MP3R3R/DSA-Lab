#include <iostream>
using namespace std;

bool commonFriend(bool friends[5][5], int a, int b){
    for(int k = 0; k < 5; k++){
        if (friends[a][k] && friends[b][k]) return true;
    }
    return false;
}

int main(){
    bool friends[5][5] = {
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {1,1,0,1,0}
    };

    int p1, p2;
    cout << "Enter two people (0-4): ";
    cin >> p1 >> p2;
    if(commonFriend(friends,p1,p2)){
        cout << p1 << " and " << p2 << " have a common friend." << endl;
    } else {
        cout << p1 << " and " << p2 << " do not have a common friend." << endl;
    }

    return 0;
}
