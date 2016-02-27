#include <iostream>
#include "User.h"

User::User(std::string ID, std::string name)
{
	_ID = ID;
	_name = name;
	movieQ = new queue<Movie*>;
	checkedOut = NULL;
	movieRating = new map<Movie*, int>;
}
User::User(const User & other)//copy constructor
{
	_ID = other._ID;
	_name = other._name;
	movieQ = other.movieQ;
	checkedOut = other.checkedOut;	
}
User::~User()
{
	delete movieQ;
}
std::string User::getID() const
{
	return _ID;
}
std::string User::getName() const
{
	return _name;
}

queue<Movie*>* User::movieQueue ()
{
	return movieQ;

}
void User::rentMovie (Movie *m)
{
	if(checkedOut == NULL)
	{
		this->checkedOut = m; 
	}
}
void User::returnMovie ()
{
	checkedOut = NULL;
}
Movie* User::currentMovie ()
{
	return checkedOut;
}
void User::rateMovie (Movie* rateM, int rate)
{			
	//cout<<"testing "<<rateM->getTitle()<<" "<<rate<<endl;
	//typedef pair < Movie*, int > rateInsert;
	//movieRating->insert( rateInsert(rateM, rate));
	movieRating->insert(make_pair(rateM,rate));

}
map<Movie*, int>* User::ratingInfo()
{
	return movieRating;
}
bool User::rateContain(string checking)
{
	bool contain;
	contain = false;
	map<Movie*, int>::iterator itA;
	for(itA = movieRating->begin(); itA != movieRating->end(); ++itA)
	{
		string compare = itA->first->getTitle();
		if(compare == checking)
		{
			contain = true;
		}
	}

	return contain;
		
}











