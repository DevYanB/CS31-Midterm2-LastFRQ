#include <iostream>
#include <string>
using namespace std;

int analyze(string flight, int& max);

int main()
{
   string test = "UUUDDUUUUDD"; //can be any test string, or get user input with getline
   int m;
   cout << analyze(test, m) << endl;
   if (analyze(test, m) != -1) { //print out the max only if it has been edited
      cout << m;
   }
   return 0;
}

int analyze(string flight, int& max)
{
   for (int c = 0; c < flight.length(); c++) { //haha c++
      if (flight[c] != 'U' && flight[c] != 'D') { //if there is any character in string != U or D, return -1
         return -1;
      }
   }
   max = 0;
   int start = 100; //the starting height for Thor
   int distance = 0; //represents the net distance
   for (int i = 0; i < flight.length(); i++) {
      if (flight[i] == 'D') { //for every D in the string, subtract 10 from the distance
         distance -= 10;
      }
      else if (flight[i] == 'U') {
         distance += 10; //for every U in the string, add 10 to the distance
      }
      if (start + distance == 0) { //if at any point, the net distance plus the start is 0, meaning Thor has "crashed", return 0
         return 0;
      }
      else if (start + distance > max) { //checks for the max height after each addition/subtraction
         max = start + distance;
      }
   }
   return start + distance; //returns the ending height of Thor's flight
}