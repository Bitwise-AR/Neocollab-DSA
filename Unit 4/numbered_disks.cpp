#include <iostream>
using namespace std;

void Hanoi(int n, char source, char auxiliary, char destination, int &moves) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        moves++;
        return;
    }
    Hanoi(n - 1, source, destination, auxiliary, moves);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    moves++;
    Hanoi(n - 1, auxiliary, source, destination, moves);
}

int countMoves(int n) {
    int moves = 0;
    Hanoi(n, 'A', 'B', 'C', moves);
    return moves;
}

int main() {
    int n;
    cin >> n;
    
    int moves = countMoves(n);
    
    cout << "Total number of moves: " << moves << endl;
    
    return 0;
}
