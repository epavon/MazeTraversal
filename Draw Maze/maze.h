//maze.h
#ifndef MAZE
#define MAZE
#include "disjointSet.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <memory>

namespace cMaze
{
	struct wall
	{
		int x, y;
		wall() {}
		wall(int a, int b): x(a), y(b) {}
		inline bool isEqual(wall b) const { return ( x == b.x && y == b.y); }
		void print() const { std::cout << x << "	" << y << "\n"; }
	};

	class maze
	{
	public:
		explicit maze(int n, int m);
		maze(const maze& source);
		void createMaze();
		void printMaze();
		int numOfWalls() const;
		/* Given the index in the walls array, it will return the 1st node of the wall */
		inline int wallFP(int i) const { return walls[i].x; }
		/* Given the index in the walls array, it will return the 2nd node of the wall  */
		inline int wallSP(int i) const { return walls[i].y; }
		/* Given two nodes, it will return true if there is a wall between them, false otherwise */
		bool isWall(int a, int b) const;
		inline size_t GetNumRows() const { return rows; }
		inline size_t GetNumCols() const { return cols; }

	private:
		size_t rows, cols;
		std::vector<wall> walls;
		std::unique_ptr<cDisjointSet::DisjSets> cels;

		// Helper functions
		void makeWalls();
		void destroyWalls();
	};
}
#endif
