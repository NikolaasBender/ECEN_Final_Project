#include <iostream>
#include <string>
#include <vector>


using namespace std;

void termOut(std::vector<string>& urls, std::vector<int>& urlCnt){
 
  //THIS RINTS THE URL AND HOW MANY TIMES IT WAS FOUND
  for(int i = 0; i < urlCnt.size(); i++){
    cout << urls.at(i) << " was found " << urlCnt.at(i)<< " times";
    cout<< "\n";
  }

  return;

}

void topT(std::vector<string>& urls, std::vector<int>& urlCnt){

  //THE LARGEST INT
  int lgst = 0;
  //THE CORRESPONDING URL
  string lgstU;
  //LOOKS FOR THE LARGEST INT
  for(int i = 0; i < urlCnt.size(); i++){
    //IF THE NUMBER AT THE INDEX IS LARGER GO INTO THIS STATEMENT
    if(urlCnt.at(i) > lgst){
      //LARGEST IS UPDATED TO BE THE NEW INT
      lgst = urlCnt.at(i);
      //THE URL IS UPDATED
      lgstU = urls.at(i);
    }
  }
  //PRINTS ITS FINDINGS
  cout << lgstU << " was the most common url with " << lgst << " occurences.\n"; 

  int lgst2 = 0;
  string lgstU2;
  //LOOKS FOR THE SECOND LARGEST
   for(int i = 0; i < urlCnt.size(); i++){
    //IF THE NUMBER AT THE INDEX IS LARGER GO INTO THIS STATEMENT
     if(urlCnt.at(i) > lgst2 && urlCnt.at(i) < lgst){
      //LARGEST IS UPDATED TO BE THE NEW INT
      lgst2 = urlCnt.at(i);
      //THE URL IS UPDATED
      lgstU2 = urls.at(i);
    }
  }
 cout << lgstU2 << " was the second most common url with " << lgst2 << " occurences.\n";

     int lgst3 = 0;
  string lgstU3;
  //LOOKS FOR THE SECOND LARGEST
   for(int i = 0; i < urlCnt.size(); i++){
    //IF THE NUMBER AT THE INDEX IS LARGER GO INTO THIS STATEMENT
     if(urlCnt.at(i) > lgst3 && urlCnt.at(i) < lgst2){
      //LARGEST IS UPDATED TO BE THE NEW INT
      lgst3 = urlCnt.at(i);
      //THE URL IS UPDATED
      lgstU3 = urls.at(i);
    }
  }

    cout << lgstU3 << " was the third most common url with " << lgst3 << " occurences.\n";
}
