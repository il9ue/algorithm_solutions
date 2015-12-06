/*
	JumpGame.cpp

	20151206 DanQ
*/

#include <string>
#include <vector>
#include <map>

#define LENGTHS(x)  (sizeof(x) / sizeof((x)[0]))
#define FOR(i, n)	(for (int i = 0; i < n; i++))

using namespace std;

class JumpGame
{
public:
	JumpGame();
	~JumpGame();

	bool findPaths(int **maze) {
		if (maze == NULL) {
			return false;
		}

		int len = LENGTHS(*maze);
		int **cache = new int[len][len];
		cache[len][len] = {{0}}; // 2d array initialization

		int found = findPaths(maze, len, len, cache);
		return found > 0 ? true : false;
	}	

	int findPaths(int **maze, int r, int c, int **cache) {
		// r == c
		int nPaths = 0;
		if (c < 0 || r < 0) return -1;
		if (maze[r][c - 1] == 1) {
			c = c - 1;
			FOR(i, c)
				if (maze[r][i] + i == maze[r][c]) {
					nPaths += findPaths(maze, r, i, cache);
				}
		}
		else if (maze[r - 1][c] == 1) {
			r = r - 1;
			FOR(i, r)
				if (maze[i][c] + i == maze[r][c]) {
					nPaths += findPaths(maze, i, c, cache);
				}
		}
		else {
			r = r - 1;
			c = c - 1;
			nPaths += findPaths(maze, r, c, cache);
		}
		return nPaths;
	}
};