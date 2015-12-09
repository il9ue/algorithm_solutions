
/*
	AsymTiling 
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AsymTiling
{
public:
	AsymTiling();
	~AsymTiling();

	int dp[101];
	int MOD = 1000000007;

	int tilingCount(int n) {
		if (n <= 1) {
			return 1;
		}//

		int &current = dp[n];
		if (current) {
			return current;
		}

		int nTiling = tilingCount(n - 1) + tilingCount(n - 2);
		return nTiling % MOD;
	}

   int symTiles(int n) {
      if (n <= 2) {
         return n;
      }
      int nSym = 0;
      if (n % 2 == 1) {
         nSym = n / 2;
         return nSym;
      }
      else if (n % 2 == 0) {
         nSym = (n / 2) + 1;
         return nSym;
      }  
   }

	int countAsymTiles(int nTiles) {
      int total = tilingCount(nTiles);
      int symCount = symTiles(nTiles);
      return total - symCount;
   }
};