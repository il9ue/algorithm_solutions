/*
  anagram : https://algospot.com/judge/problem/read/ANAGRAM

   input : 
      3
      weird wired
      apple angle
      apple elppa

   output :
      Yes
      No
      Tes

*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Anagram1
{
public:
   Anagram1();
   ~Anagram1();
 
   bool compareSerials(string serialStr, string passwordStr) {
      bool cmpResult = false;
      int serialLen = serialStr.length();
      int pwLen = passwordStr.length();

      if (serialLen <= 1 || pwLen <= 1) {
         return cmpResult;
      }//
      if (serialLen != pwLen) {
         return cmpResult;
      }

      int serialSet[128] = {0};
      int passwordSet[128] = {0};
      for (int i = 0; i < serialLen; i++) {
         if (serialSet[serialStr.at(i)] != passwordSet[passwordStr.at(i)]) {
            cmpResult = false;
            break;
         }
         serialSet[serialStr.at(i)] += 1;
         passwordSet[passwordStr.at(i)] += 1;
         cmpResult = true;
      }
      return cmpResult;
   }
};