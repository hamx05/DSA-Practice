#include <iostream>
using namespace std;

#define N 6

string findPath (int x, int y, char path[6][6], string move) {
    if (x == N-1 && y == N-1 && path[x][y] == 'H') {
        move += 'S';
        return move;
    }

    // check if curr pos is safe to stand
    if ((x>=0 && x < N) && (y>=0 && y < N) && (path[x][y] == 'S' || path[x][y] == 'D')) {

        // move downward
        if (x+1 < N) {
            if (findPath(x+1, y, path, move += 'D').size() != 0) {
                return move;
            }
        }

        // move right
        if (y+1 < N) {
            if (findPath(x, y+1, path, move += 'R').size() != 0) {
                return move;
            }
        }
    }

    return "";
}


// string findPath(int x, int y, char path[6][6], string move) {
//     if (x == N - 1 && y == N - 1 && path[x][y] == 'H') {
//         return move;
//     }

//     // check if current position is safe to stand
//     if ((x >= 0 && x < N) && (y >= 0 && y < N) && (path[x][y] == 'S' || path[x][y] == 'D')) {

//         // move downward
//         if (x + 1 < N) {
//             string tempMove = findPath(x + 1, y, path, move + 'D');
//             if (tempMove.size() != 0) {
//                 return tempMove;
//             }
//         }

//         // move right
//         if (y + 1 < N) {
//             string tempMove = findPath(x, y + 1, path, move + 'R');
//             if (tempMove.size() != 0) {
//                 return tempMove;
//             }
//         }
//     }

//     return "";
// }

int main () {

    char path[N][N] =  {{'D', 'S', 'S', 'F', 'D', 'F'},
                        {'S', 'S', 'S', 'F', 'S', 'D'},
                        {'S', 'D', 'S', 'S', 'S', 'F'},
                        {'F', 'S', 'F', 'S', 'S', 'F'},
                        {'S', 'S', 'S', 'D', 'S', 'F'},
                        {'S', 'F', 'S', 'S', 'S', 'H'}};

    string direction = findPath(0,  0,  path, "");

    if (direction.size() != 0) {
        cout<<"\nSafe Route for the Drone: " << direction << endl;
    }
    else {
        cout<<"\nNo safe path found for the drone." << endl;
    }
    return 0;
}