#ifndef _USER_H_
#define _USER_H_
//#include "lib/Queue.h"
//#include "lib/set.h"
#include "Movie.h"
//#include "lib/map.h"
#include <map>
#include <set>
#include <queue>
#include <string>

using std::map;
using std::set;
using std::queue;
using namespace std;
//string var;

class User {
  public:
    User (std::string ID, std::string name);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User (const User & other); // copy constructor

    ~User ();            // destructor

    std::string getID () const;    // returns the ID associated with this user

    std::string getName () const;  // returns the name associated with this user
    

    queue<Movie*> * movieQueue (); 
      /* returns a pointer to the user's movie queue.
         This is the easiest way to ensure that you can modify the queue.
         (If you return by reference, that's also possible, but you'd need
         to be very careful not to invoke any deep copy constructors or
         assignments. A pointer is thus safer.) */

    void rentMovie (Movie *m);
      /* sets the user's currently rented movie to m.
         If the user already has a movie checked out, then it does nothing.
         (So no overwriting the current movie.) */

    void returnMovie ();
      /* returns the movie that the user currently has checked out.
         Does nothing if the user doesn't currently have a movie. */

    Movie* currentMovie ();
      /* returns the user's current checked out movie.
         Returns NULL if the user has no movie checked out. */
    void rateMovie (Movie* rateMovie, int rate);
    map<Movie*, int>* ratingInfo();
    bool rateContain(string checking);

  private:
	std::string _ID;
	std::string _name;
	queue<Movie*>* movieQ;
	Movie* checkedOut;
	map<Movie*, int>* movieRating;
	
    // you get to decide what goes here.
};

#endif	

