
#ifndef READINGTOOLS_H
#define READINGTOOLS_H

#include <string.h>
#include <vector>

using namespace std;

//RETURNS THE NUMBER OF TIMES IT FOUND A CERTIAN STRING
int fndr(string find_me, string fl);

//THIS RETURNS A URL
string urlfndr(std::string in);

//THIS CHECKS IF THE URL EXISTS AND STORES IT ACCORDINGLY WITH ITS COUNT
void urlCheck(vector<string>& rec, vector<int>& recnum, std::string& url, std::string& file);

//THIS STORES EACH LINE WITH A URL INTO A VECTOR
//std::vector master(std::string in);

//THIS IS FOR DEALING WITH THE USER FLAGS
int parseArgs(int argc, char const * const argv[], int *n);

#endif
