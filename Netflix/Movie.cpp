#include <iostream>

#include "Movie.h"

Movie::Movie(std::string title)
{
	_title = title;
	actors = new vector<string>;
}
Movie::Movie(const Movie & other)
{
	_title = other._title;
	keywords = other.keywords;
	actors = other.actors;
}
Movie::~Movie()
{

}
std::string Movie::getTitle()const
{
	return _title;
}
void Movie::addKeyword(std::string keyword)
{	
        keywords.insert(keyword);
}
void Movie::addActor(std::string actor)
{	
	for(unsigned int i = 0; i < actors->size(); i++)
	{
		if(actors->at(i) == actor)
		{
			return;
		}
	}
	actors->push_back(actor);
        //actors.insert(actor);
}
set<std::string> Movie::getAllKeywords() const
{
	return keywords;
}
vector<string>* Movie::getAllActors() const
{
	return actors;
}
