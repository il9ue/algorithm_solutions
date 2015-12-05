


// 2015.12.04. Friday
// Algorithm Practice #1
//  :: get shortest paths to room "s (end location)", with multiple block rooms somewhere in the maze.
//    

#include <vector>
#include <queue>
#include <string>

class Point
{
private:
   int row = 0;
   int column = 0;
public:
   Point();
   ~Point();
   Point(int r, int c) {
      this.row = r;
      this.column = c;
   }//

   int getRow() {
      return this.row;
   }

   int getColumn() {
      return this.column;
   }
};

class MazePath
{
public:
   MazePath();
   ~MazePath();

   map<Point, int> roomMap;
   map<Point, int> roomMemo;

   void initialize(int numRoom) {
   	// put 1s to all the point to rooms..
   	int roomlen = roomMap.size();
   	if (roomlen > 0) {
   		roomMap.erase(roomMap.begin(), roomMap.end());
   	}

   	for (auto& x: roomMap) {
   		x.second = 1;
   	}

   	for (auto& y: roomMemo) {
   		y.second = -1;
   	}
   }

   // get shortest path from (r,c) to endlocations, if there are block paths
   vector<vector<Point>> shortestPaths(Point currentRoom, vector<Point> blockPaths, vector<Point> endLocations) {

   	if (currentRoom == NULL) return NULL;

   	vector<vector<Point>> resultPaths;
   	vector<Point> vPaths;
   	for (i = 0; i < endLocations.size(); i++) {
   		if (currentRoom != NULL && currentRoom == endLocations.at(i)) {
   			vPaths.emplace(currentRoom);
   		}
   		resultPaths.emplace(vPaths);
   	}

   	if (!blockPaths.empty()) {

   	}
   	else {
   		// general case, where there are no blocked rooms which means no exception to consider
   		int way = 0;

   		while (!endLocations.empty()) {
   			Point destSpot = endLocations.back();
   			endLocations.pop_back(); // remove the referred spot..
   			vector<Point> tmpPaths = computePaths(currentRoom, destSpot, NULL, vPaths, way);
   			resultPaths.emplace(tmpPaths);

   			resultPaths = getMinimum(resultPaths);
   		}
   	}

   	return resultPaths.size() > 0 ? resultPaths : NULL;
   }

   vector<vector<Point>> getMinimum(vector<vector<Point>> pathSet) {
   	if (pathSet.empty()) return NULL;
   	int value = 0;
   	int minValue = (int)1e9;

   	map<vector<vector<Point>>, int> minSet;

   	for (auto& l : rooms) {
   		for (int i = 0; i < pathSet.size(); ++i) {
   			if (minSet)
   			for (int j = 0; j < pathSet.at(i).size(); j++) {
   				if (rooms.first == pathSet.at(i)) {
   					value += room.second;
   				}
   			}
   			minValue = min(value, minValue);
   			if (minSet.at(0).second > minValue ) {
   				minSet.erase(minSet.begin());
   				minSet.emplace(pathSet);
   			} 
   		}
   	}
   	return minSet.at(0);
   }


   // sub-routine. Do repetitive summations and return path containers..
   // returns distance from current room to dest room 
   vector<Point> computePaths(Point currentRoom, Point endRoom, vector<Point> blocks, vector<Point> pathContainer, int &ways) {
      if (currentRoom.getColumn() == endRoom.getColumn() && currentRoom.getRow() == currentRoom.getColumn()) {

      }
      if (currentRoom.getRow() < 0 || currentRoom.getColumn() < 0) {
      	return NULL;
      }

      // currentRoome is next to endRoom
      if ((currentRoom.getRow() + 1 == endRoom.getRow() && currentRoom.getColumn() == endRoom.getColumn()) ||
         (currentRoom.getRow() - 1 == endRoom.getRow() && currentRoom.getColumn() == endRoom.getColumn()) ||
         (currentRoom.getRow() == endRoom.getRow() && currentRoom.getColumn() + 1 == endRoom.getColumn()) ||
         (currentRoom.getRow() == endRoom.getRow() && currentRoom.getColumn() - 1 == endRoom.getColumn())) {
      	
      	return pathContainer != NULL ? pathContainer : NULL;
      }
   	else {
   		map<Point, int>::iterator it = roomMap.find(currentRoom);
      	if (it != roomMap.end()) {
      		roomMap.second += 1;
	  			roomMemo.second = 0;
      	}
   	}

  		for (auto& p: roomMemo) {
  			if (roomMemo.second > -1) {
  				return pathContainer;
  			}
  		} 

  		// modify the usage of computePaths parameters..
      ways += computePaths(curLocation(endRoom.getRow(), endRoom.getColumn() - 1) 
      		+ curLocation(endRoom.getRow(), endRoom.getColumn() + 1) 
      		+ curLocation(endRoom.getRow() - 1, endRoom.getColumn())	
      		+ curLocation(endRoom.getRow() + 1, endRoom.getColumn()));

      return pathContainer;
   }
};












