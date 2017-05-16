#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include "readingTools.hpp"

using namespace std;






//==============================
//RETURNS HOW MANY TIMES IT FOUND A URL
//==============================

int fndr(std::string find_me , std::string fl){
  //POINTS AT THE FILE  
  std::ifstream infile(fl);

//DECLARING THE STRING FOR USE
  std::string cpy;

  //AN INT USED TO RETURN THE NUMBER OF TIMES THE STRING OCCURS
  int fnd = 0;
  
  //LOOPS THROUGH THE FILE
  while(std::getline(infile, cpy)){

    //FINDS THE STRING IN THE FILE
   
    if (cpy.find(find_me) != std::string::npos){
       fnd ++;
    }
  }

  return fnd;
  
}








//==================================================
//==================================================
//THIS FINDS AND RETURNS A URL

string urlfndr(std::string in){

  std::string url;

  //VARIABLES FOR THE START AND END MARKER
  std::string h = "http";
  std::string slash = "/";
  std::smatch sm;

  //IF THOSE STRINGS APPEAR GO IN
  if (std::regex_match (in, sm, std::regex(".*(http.?://[^/]*\/).*"))){

    //CUTS OUT THE URL
    url = sm[1];

  }
  return url;
  
}







//==================================================
//==================================================
//THIS CHECKS IF THE URL IS IN THE VECTOR

void urlCheck(vector<string>& rec, vector<int>& recnum, std::string& url, std::string& file){

  //IF THE URL IS FOUND BREAK OUT 
  for(int i = 0; i < rec.size(); i++){
    if(url.compare(rec.at(i)) == 0){
      return;
    }
  }
  //IF THE VECTOR DOESN'T CONTAIN THE URL THEN 
  //ADD THE URL TO THE NAME VECTOR AND ADD ITS COUNT TO THE COUNT VECTOR
  rec.push_back(url);
  recnum.push_back(fndr(url, file));
}








