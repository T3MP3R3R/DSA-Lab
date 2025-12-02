#include <iostream>
#include <cstdlib> // using this for rand and srand
#include <ctime> // for time function
using namespace std;

int target;

void playGame(int playerTurn){
    int guess;
    cout << "Player " << playerTurn << ", enter your guess: ";
    cin >> guess;

    if (guess == target) {
        cout << "Player " << playerTurn << " wins" << endl;
        return;
    }

    if (guess > target)
        cout << "Too high" << endl;
    else
        cout << "Too low" << endl;

    int nextPlayer = (playerTurn == 1) ? 2 : 1;
    playGame(nextPlayer);
}

int main(){
    srand(time(0));
    target = rand() % 100 + 1;
    cout << "Place a number between 1 and 100" << endl;
    playGame(1);
    return 0;
}