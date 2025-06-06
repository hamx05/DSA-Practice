#include <iostream>
using namespace std;
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]); //indirect recursion

void printSolution(int sol[N][N]) //print
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<sol[i][j]<<" ";
		cout<<endl;
	}
}

bool isSafe(int maze[N][N], int x, int y) //check the path block or not
{
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}
bool solveMaze(int maze[N][N]) //solved or unsolved results
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout<<"Solution doesn't exist";
		return false;
	}
	printSolution(sol); //print
}
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) { //base condition
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y) == true) { //if path is not blocked
		if (sol[x][y] == 1) //check if already visited
			return false;
		sol[x][y] = 1; //mark as visited to each step
		if (solveMazeUtil(maze, x + 1, y, sol) == true){ //down
			cout<<"Down Called\n";
			return true;}
//		if (solveMazeUtil(maze, x - 1, y, sol) == true) //up
//			return true;
		if (solveMazeUtil(maze, x, y + 1, sol) == true){ //right
			cout<<"Right Called\n";
			return true;}
//		if (solveMazeUtil(maze, x, y - 1, sol) == true) //left
//			return true;
		sol[x][y] = 0; //backtrack
		return false;
	}
	return false;
}

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					   { 1, 1, 0, 1 },
					   { 0, 1, 0, 0 },
					   { 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}
