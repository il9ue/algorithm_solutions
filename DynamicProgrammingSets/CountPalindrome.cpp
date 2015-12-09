/*
  countPalindrome.cpp
  - https://algospot.com/judge/problem/read/COUNTPALIN
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MultiPalindrome
{
public:
   MultiPalindrome();
   ~MultiPalindrome();
   
   int countPalins(string str) {
      vector<string> palinList;
      string candidate = str;

      palinList = makePalins(0, candidate.size(), candidate, palinList);
      return palinList.length();
   }//

   vector<string> makePalins(int beginPos, int endPos, string pStr, vector<string> pList) {
      if ((beginPos >= endPos) || pStr == "") {
         return NULL;
      }

      vector<string> tmpList;
      pList.emplace(pStr);

      for (int i = beginPos; i < endPos; i++) {
         pStr += pStr[i]
      }
      
      vector<string>::iterator it = find(pList.begin(), pList.end(), pStr);
      if (it != pList.end() && isPalin(pStr)) {
         pList.emplace(pStr);
      }
      
      int nuStartPos = endPos == pStr.length() ? beginPos + 1 : beginPos;
      tmpList = makePalins(nuStartPos, nuStartPos + 1, pStr, pList);
      return tmpList;
   }

   bool isPalin(string str) {
      int strSize = str.length();
      bool retVal = false;

      if (str == NULL || strSize <= 1) {
         return false;
      }
      int charSet[128] = {0};
      int mid = strSize % 2 == 0 ? strSize / 2 : (strSize / 2) + 1;

      for (int i = 0; i < strSize; i++) {
         if ((str.at(i) != str.at(strSize - i)) && (charSet[str.at(i)] % 2 == 1))  {
            break;
         }
         retVal = true;
      }
      return retVal;
   }
};