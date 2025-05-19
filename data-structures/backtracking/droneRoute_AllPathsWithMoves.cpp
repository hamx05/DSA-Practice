#include <iostream>
using namespace std;

#define N 6

void printPath (char sol[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << sol[i][j] << " ";
        }
        cout<<endl;
    }
}

// All Possible Paths With Moves
bool noSolution = true;
void findAllPaths (int x, int y, char path[N][N], char sol[N][N], string move) {
    if (x==N-1 && y==N-1 && path[x][y] == 'H') {
        noSolution = false;
        sol[x][y] = 'S';
        cout<<"Solution: " << endl;
        printPath(sol);
        cout<<"Moves: " << move << endl << endl;
        return;
    }

    // check current position
    if ((x>=0 && x<N) && (y>=0 && y<N) && path[x][y] == 'S') {
        sol[x][y] = 'S';

        // check downward
        if (x + 1 < N) {
            (findAllPaths(x+1, y, path, sol, move + 'D'));
        }

        // check rightward
        if (y + 1 < N) {
            (findAllPaths(x, y+1, path, sol, move + 'R'));
        }

        sol[x][y] = 'F';
    }
}

void solveDroneRoute () {
    char path[N][N] =  {{'S', 'S', 'S', 'F', 'D', 'F'},
                        {'S', 'S', 'S', 'F', 'S', 'D'},
                        {'S', 'D', 'S', 'S', 'S', 'F'},
                        {'F', 'S', 'F', 'S', 'S', 'F'},
                        {'S', 'S', 'S', 'D', 'S', 'F'},
                        {'S', 'F', 'S', 'S', 'S', 'H'}};

    char sol[N][N] =   {{'F', 'F', 'F', 'F', 'F', 'F'},
                        {'F', 'F', 'F', 'F', 'F', 'F'},
                        {'F', 'F', 'F', 'F', 'F', 'F'},
                        {'F', 'F', 'F', 'F', 'F', 'F'},
                        {'F', 'F', 'F', 'F', 'F', 'F'},
                        {'F', 'F', 'F', 'F', 'F', 'F'}};

    findAllPaths(0, 0, path, sol, "");
    
    if (noSolution) {
        cout << "No safe route possible." << endl;
    }
}



int main () {

    solveDroneRoute();   

    return 0;
}