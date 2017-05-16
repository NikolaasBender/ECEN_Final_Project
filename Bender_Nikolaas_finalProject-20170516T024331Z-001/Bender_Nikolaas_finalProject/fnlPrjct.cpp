#include "smplrdt.hpp"
#include "readingTools.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//THIS IS THE PATH TO THE FILE
std::string path = "/home/programmer/Bender_Nikolaas_finalProject/rdin.txt";

//THIS MAKES THE FILE TO READ FROM NEW.TXT
std::ifstream infile(path);

int main(int const argc, char const * const argv[]){

  //THIS IS FOR THE FLAGGING SYSTEM FOR THE EXTRA FUNCTIONALITY 
  string argvin;
  if(argc == 2){
    argvin = argv[1];
  }

  //FOR SIMPLICITY
  string usage = "-l LOOKS FOR A SPECIFIC URL\n-f LOOKS FOR A KEY WORD IN THE HISTORY FILE\n";
  
  string cla; 
  //THESE ARE SOME STRINGS THAT ARE NEEDED
  //URL
  string url;
  //THE LINE OF INVESTIGATION
  string cpy;

  //THE URLS
  std::vector<string> urls;
  //THE COUNT OF THE URLS
  std::vector<int> urlCnt;

  //LOOPS THROUGH THE FILE LOOKING FOR 
   while(std::getline(infile, cpy)){

     //FINDS THE URL IN THE STRING
     url =  urlfndr(cpy);

     //ADDS URLS AND THEIR COUNT TO THE VECTORS
     if(url != string("")){
       urlCheck(urls, urlCnt, url, path);
     }
   }


   //THE DECISION MAKING INT
   int n;
   //THE STRING THE PROGRAM MIGHT NEED TO FIND
   std::string findMe;
   
   if(argc == 1){
     //PRINTS THE TOP 3 URLS
     topT(urls, urlCnt);
   }
   if(argc == 2){

     if(argvin == "-h"){
       cout << usage;
     }
     
     //IF THE USER PUT IN -f
     if(argvin == "-f"){
       cout << "PLEASE ENTER THE KEYWORD YOU WANT TO FIND\n";
       cin >> findMe;
       cout << findMe << " WAS FOUND " << fndr(findMe, path) << " TIMES\n";
     }
     //THIS ONE LOOKS FOR A URL IN THE PREMADE VECTORS
     if(argvin == "-l"){
       cout << "THIS FLAG REQUIRES A SPECIFIC URL (ex: https://www.google.com/)\n";
       cin >> findMe;
       //FOR INDEXING
       int i = 0;
       while(i <= urls.size()){
	 if(urls.at(i) == findMe){
	   cout << findMe << " WAS FOUND " << urlCnt.at(i) << " TIMES\n";
	 }
	 i++;
       }
     }

     //THIS IS IF THE USER TRIES TO BREAK STUFF
     if(argvin != "-h" && argvin != "-l" && argvin != "-f"){
       cout << "THE PROGRAM DOES NOT HAVE THAT FUNCTIONALITY YET\n" << "MAYBE IN A FUTURE UPDATE\n" << "IN THE MEANTIME THIS IS WHAT YOU CAN DO\n" << usage;
     }
   } 
  
  return 0;
}
