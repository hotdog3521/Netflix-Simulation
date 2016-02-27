#ifndef NETFLIX_H
#define NETFLIX_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <locale>
//#include "lib/map.h"
//#include "lib/set.h"
//#include "lib/Queue.h"
#include "User.h"
#include "Movie.h"
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>

using std::map;
using std::set;
using std::queue;
using std::string;
using namespace std;

class Netflix{

public:
  Netflix();
  void readUserData(string x);
  void readMovieData(string y);
  bool mapContain(string contain1);
  void createUser(string id1, string Name1);
  void storeCurrentUser(string id);
  void showQueueMovie(string id2);
  void showCurrentMovie(string id3);
  User* getCurrentUser();
  map<string, User*>* getUserMap();
  map<string, Movie*>* getTitleMap();
  map<string, set<Movie*>*>* getKeywordsMap();
  map<string, set<Movie*>*>* getActorMap();
  string removeSpaces(string input);
  string lowerCase(string input);
  void savingData();
  void takeaddress(string x);
  vector<double> setIntersection(map<Movie*, int>* A, map<Movie*, int>* B);
  void setRecommendation(string x);
  string getRecommendation();

private:
  //Map <string, User*>* users;
  //Map <string, Movie*>* movies;
  //Map <string, Set<Movie*>*>* keywords;
  map <string, User*>* users;
  map <string, Movie*>* movies;
  map <string, set<Movie*>*>* keywords;
  map <string, set<Movie*>*>* actors;


  string savingAddress;
  string currentUser;
  string viewQueue;
  string viewCurrentMovie;
  User* userLogin;
  string recommendation;
};

#endif
