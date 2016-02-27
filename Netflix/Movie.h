#ifndef _MOVIE_H_
#define _MOVIE_H_
//#include "lib/set.h"
//#include "lib/map.h"
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::queue;
using std::vector;

using namespace std;

//MapItem <keyType, valueType>
class Movie {
  public: 
    Movie (std::string title);       // constructor for a movie with the given title

    Movie (const Movie & other);  // copy constructor

    ~Movie ();                  // destructor

    std::string getTitle () const;   // returns the title of the movie

    void addKeyword (std::string keyword); 
      /* Adds the (free-form) keyword to this movie.
         If the exact same keyword (up to capitalization) was already
         associated with the movie, then the keyword is not added again. */
    void addActor (std::string actor); 

    set<std::string> getAllKeywords () const;
      /* Returns a set of all keywords associated with the movie. */
    vector<std::string>* getAllActors () const;

  private:
	std::string _title;
	set<std::string> keywords;
	vector<string>* actors;

    // you get to decide what goes here
};

#endif	

