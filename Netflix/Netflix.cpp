#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "Netflix.h"
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include "lib/MergeSort.h"
#include <math.h>


using std::map;
using namespace std;

Netflix::Netflix()
{
  //users = new Map <string, User*>;
  //movies = new Map <string, Movie*>;
  //keywords = new Map <string, Set<Movie*>*>;
  this->userLogin = NULL;
  users = new map <string, User*>;
  movies = new map <string, Movie*>;
  keywords = new map <string, set<Movie*>*>;
  actors = new map <string, set<Movie*>*>;
  //BaconGame = new vector<Actor*>; 
}

void Netflix::readUserData(string x)
{
	//convert string to char.
	char *convert1 = new char[x.length() + 1];
	strcpy(convert1, x.c_str());
	ifstream userInfo(convert1);
	string cmd1, ID, Name, MovieInput, QueueInput, dummy, dummy2, dummy3, queueEnd, ratingStart, dummy4, stringRate, dummy5, dummy6, dummy7;
	userInfo>>cmd1;
	//Map<string, User*> usersADD;
	while(!userInfo.fail())
	{	
		Movie *F = NULL;// create movie
		User *A = NULL;
		
		bool isNewUser = true;
		while(cmd1 !="END")
		{
			if(cmd1 =="BEGIN")
			{
				
				if(isNewUser)
				{
					userInfo >> ID;	
					isNewUser = false;
					
				}	
				else
				{
					getline(userInfo, dummy);
					dummy2 = removeSpaces(dummy);
					if(dummy2 == "QUEUE")
					{
						while(getline(userInfo, QueueInput) && (QueueInput != "END QUEUE"))
						{
							
							Movie *qmovie = NULL;
							qmovie = new Movie(lowerCase(QueueInput));
							A->movieQueue()->push(qmovie);
							//getline(userInfo, QueueInput);
							
						}
						
					}
					//userInfo>>cmd1;
					//getline(userInfo, ratingStart);
					//dummy4 = removeSpaces(ratingStart);
					//if(dummy4 == "BEGIN RATINGS")
					userInfo>>dummy5;
				   if(dummy5 == "BEGIN")
				   {
					getline(userInfo, dummy6);
					dummy7 = removeSpaces(dummy6);
					if(dummy7 == "RATINGS")
					{
						stringstream ss;
						int rate;
						string stringRate;
						string movieName;
						
						while(true)
						{	
							userInfo >> stringRate;
						 	if(stringRate != "END")
							{	
								ss << stringRate;
								ss >> rate;
								getline(userInfo, movieName);
								Movie* classRateMovie;
								string temp11 = lowerCase(removeSpaces(movieName));
								classRateMovie = new Movie(temp11);
								switch(rate)
								{
									case 1:
										A->rateMovie(classRateMovie, 1);
										break;
									case 2:
										A->rateMovie(classRateMovie, 2);
										break;
									case 3:
										A->rateMovie(classRateMovie, 3);
										break;
									case 4:
										A->rateMovie(classRateMovie, 4);
										break;
									case 5:
										A->rateMovie(classRateMovie, 5);
										break;
								}//switch end
							}// ratemovie if end
							else
							{
								string endType;
								getline(userInfo, endType);
								break;
							}
								
				
						}//while ends

					}//inner if ends
				   }// big if ends
				   else
				   {
					string trash;
					getline(userInfo, trash);
				   }
		
					
				isNewUser = true;
				}
	
			}
			else if(cmd1 =="NAME:")
			{
				getline(userInfo, Name);	
				A = new User(ID, removeSpaces(Name));

				
			}
			else if(cmd1 == "MOVIE:")
			{
				getline(userInfo, MovieInput);
				string temp = lowerCase(removeSpaces(MovieInput));
				if(temp != "")
				{
					F = new Movie(temp); 
					A->rentMovie(F);
				}
				
			}
			userInfo>>cmd1;	
			
		}
		typedef pair < string, User* > userInsert;
		users->insert( userInsert(ID,A));
		userInfo>>cmd1;	

	}
	userInfo.close();

}

void Netflix::readMovieData(string y)
{

char *convert2 = new char[y.length() + 1];
strcpy(convert2, y.c_str());


	ifstream movieInfo(convert2);
	delete[] convert2;
	string cmd2, title, keyword, actor;

	movieInfo.is_open();
	movieInfo>>cmd2;
	//Map <string, Movie*> movies;
	//Map <string, Set<Movie*>*> keywords;
	//Map <string, Set<Movie*>*> actors;
	while(!movieInfo.fail())
	{	
		
		Movie *B = NULL;// create movie
		while(cmd2 !="END")
		{
			if(cmd2 =="BEGIN")
			{	
				getline(movieInfo, title);
				B = new Movie(lowerCase(removeSpaces(title)));
			}
			else if(cmd2 =="KEYWORD:")
			{
				getline(movieInfo, keyword);
				string temp = lowerCase(removeSpaces(keyword));

				B->addKeyword(temp);
				
				if(keywords->count(temp))
				{
					//cout<<"22Keyword check : "<<temp<<endl;
					map<string, set<Movie*>*>::iterator p;
					p = keywords->find(temp);
					set<Movie*> *E = p -> second;
					E->insert(B);
				}
				else
				{	
					//cout<<"33Keyword check : "<<temp<<endl;
					//map <string, Set<Movie*>*>* keywords;
					set<Movie*> *E = new set<Movie*>;			
					E->insert(B);
					typedef pair < string, set<Movie*>* > keywordInsert;
					keywords->insert(keywordInsert(temp, E));
					
					//keywords->add(temp, E);
				}
			}
			else if(cmd2 == "ACTOR:")
			{
				getline(movieInfo, actor);
				string temp = lowerCase(removeSpaces(actor));
				
				B->addActor(temp);
				
				if(actors->count(temp))
				{
					map<string, set<Movie*>*>::iterator p1;
					p1 = actors->find(temp);
					set<Movie*> *AC = p1 -> second;
					AC->insert(B);
				}
				else
				{
					set<Movie*> *AC = new set<Movie*>;			
					AC->insert(B);
					typedef pair < string, set<Movie*>* > actorInsert;
					actors->insert(actorInsert(temp, AC));
				}

			}
			movieInfo>>cmd2;
			//Map <string, Movie*>* movies;	
			//movies->insert(lowerCase(removeSpaces(title)), B);
			typedef pair < string, Movie* > movieInsert;
			movies->insert( movieInsert(lowerCase(removeSpaces(title)), B));
	
		
		}
		movieInfo>>cmd2;
	}
	movieInfo.close();

}

string Netflix::removeSpaces(string input)
{ 
	int i = 0;
	while(input[i] == ' ')
	{
		i++;
	}
	
	input = input.substr(i, input.length() - i);

	return input;
}

//capitalization 
string Netflix::lowerCase(string input)
{
	for (unsigned int i=0;i<input.length();i++)
	{ 
		input[i]=tolower(input[i]);
	}
	return input;
}
bool Netflix::mapContain(string contain1)
{
	return users->count(contain1);

}
void Netflix::createUser(string id1, string name1)
{
	typedef pair < string, User* > createUser;
	User *A = new User(id1, name1);
	users->insert(createUser(id1, A));
}
void Netflix::storeCurrentUser(string id)
{	
	//map <string, User*>* users;
	map<string, User*>::iterator p;
	p = users->find(id);
	userLogin = p -> second;
}
User* Netflix::getCurrentUser()
{	
	return userLogin;
}
map<string, User*>* Netflix::getUserMap()
{
	return users;
}
map<string, Movie*>* Netflix::getTitleMap()
{
	return movies;
}
map<string, set<Movie*>*>* Netflix::getKeywordsMap()
{
	return keywords;
}
map<string, set<Movie*>*>* Netflix::getActorMap()
{
	return actors;
}
void Netflix::takeaddress(string x)
{
	savingAddress = x;
}
void Netflix::savingData()
{
	char *convert1 = new char[savingAddress.length() + 1];
	strcpy(convert1, savingAddress.c_str());
	
	ofstream output;
	output.open(convert1,ios::out);

	map<string, User*>::iterator itD;
	//itD = users->find(id);
		
	map<Movie*, int>::iterator itE;
	for(itD = users->begin(); itD != users->end(); ++itD)
	{

		output << "BEGIN"<<" "<< itD->second->getID() << endl;
		output << "NAME:"<<" "<< itD->second->getName() << endl;
		if(itD->second->currentMovie() != NULL){
		output << "MOVIE:" <<" "<<itD->second->currentMovie()->getTitle() <<endl;}
		else{output << "MOVIE:"<<endl;}
		output << "BEGIN QUEUE"<<endl;
		//while(!((*itD).second->movieQueue()->isEmpty()))
		for(unsigned int i = 0; i<itD->second->movieQueue()->size(); i++)
		{
			output << itD->second->movieQueue()->front() ->getTitle() << endl;
			Movie* temp1 = itD->second->movieQueue()->front();
			itD->second->movieQueue()->pop();
			itD->second->movieQueue()->push(temp1);	
		}
		output << "END QUEUE" << endl;
		output << "BEGIN RATINGS" << endl;
		
		for(itE = itD->second->ratingInfo()->begin(); itE != itD->second->ratingInfo()->end(); ++itE)
		{
			output << itE->second << " " << itE->first->getTitle() << endl;
		}
		output << "END RATINGS" << endl;
		output << "END" << endl;	
	}				
	output.close();
	delete[] convert1;
}
vector<double> Netflix::setIntersection(map<Movie*, int>* A, map<Movie*, int>* B)
{



	map<Movie*, int>::iterator itA;
	map<Movie*, int>::iterator itB;

	map<string, int> mapCheck1;
	map<string, int> mapCheck2;


	vector<string> vA;
	vector<string> vB;
	
	//using iterator and put elements in set into each vector called This and Other.
	for(itA = A->begin(); itA != A->end(); ++itA) 
	{
		vA.push_back(itA->first->getTitle());
		mapCheck1.insert(make_pair(itA->first->getTitle(), itA->second));
	}

	for(itB = B->begin(); itB != B->end(); ++itB) 
	{
		vB.push_back(itB->first->getTitle());
		mapCheck2.insert(make_pair(itB->first->getTitle(), itB->second));
	}
	//After putting elements, then sorting T and O
	std::vector<string> sorting1 = MergeSort::sort(vA);
	std::vector<string> sorting2 = MergeSort::sort(vB);
	
	vector<string> vC;
	//find intersection, and put that into new vector C	
	unsigned int i = 0;
 	unsigned int j = 0;
	// find the intersected movies between two users.
	while(i < sorting1.size() && j < sorting2.size())
	{
		if(sorting1[i] < sorting2[j])
		{
			i++;
		}
		else if(sorting1[i] > sorting2[j])
		{
			j++;
		}
		else
		{
			vC.push_back(sorting1[i]);
			i++;
			j++;
		}
	}
	//vactor<string> vC;
	//map<string, int> mapCheck;
	
	double rate1, rate2;
	double similarity;
	vector<double> rateVector;
	map<string, int>::iterator S1;
	map<string, int>::iterator S2;

	//each time iterate, rate1 and rate2 have rate of movie and calculate similarity and put them into vector
	//it is iterating as many movie as two users have in common.
	//it returns vector that holds basic similarities and to find basic similarity, just add all similarities in the vector
	//and divided by size of vector(number of movies that two users in common.  
	for(unsigned int i = 0; i < vC.size(); i++)
	{
		S1 = mapCheck1.find(vC[i]);
		S2 = mapCheck2.find(vC[i]);
		rate1 = S1 -> second;
		rate2 = S2 -> second;
		similarity = fabs(rate1 - rate2) / 4;
		rateVector.push_back(similarity);

	}


	return rateVector;


}
void Netflix::setRecommendation(string x)
{
	recommendation = x;
}
string Netflix::getRecommendation()
{
	return recommendation;
}


