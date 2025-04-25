#include <iostream>
using namespace std;
#define N 4

int countPathsUtil(int maze[N][N], int x, int y)
{
    // Base case: if the destination is reached, return 1
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
        return 1;

    int paths = 0;

    // Move right
    if (x + 1 < N && maze[x + 1][y] == 1)
        paths += countPathsUtil(maze, x + 1, y);

    // Move down
    if (y + 1 < N && maze[x][y + 1] == 1)
        paths += countPathsUtil(maze, x, y + 1);

    return paths;
}

int countPaths(int maze[N][N])
{
    return countPathsUtil(maze, 0, 0);
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {0, 1, 0, 0},
                     {1, 1, 1, 1}};

    int paths = countPaths(maze);
    cout << "Number of existing destination paths: " << paths << endl;

    return 0;
}

