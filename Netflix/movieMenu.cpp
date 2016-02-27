#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "movieMenu.h"
//#include "Search.h"
#include <QMessageBox>


using namespace std;

movieMenu::movieMenu(QWidget* parent, Netflix* netflix)
{
this->netflix = netflix;
setNetflix(netflix);
this->parent = parent;
//Search * newSearch;


movieLabel = new QLabel("Welcome To csci 104-flix,  ");
showCurrentUserLabel = new QLabel("CurrentUser");//check it! it will updated!
QHBoxLayout* helloUserLayout = new QHBoxLayout;
helloUserLayout->addWidget(movieLabel);
helloUserLayout->addWidget(showCurrentUserLabel);

logoutButton = new QPushButton("Log&out");

//Second 
currentMovieLabel = new QLabel("Your Current Movie");
showMovieLabel = new QLabel("Current Checkout Movie");
QHBoxLayout* checkoutLayout = new QHBoxLayout;
checkoutLayout->addWidget(currentMovieLabel);
checkoutLayout->addWidget(showMovieLabel);

returnMovieButton = new QPushButton("Return Movie");
RateButton = new QPushButton("Rate Your Current Checked Out Movie!");


//similarity
showSimilarIntro = new QLabel("Recommendation");
showSimilar = new QLabel("Numbers");
QHBoxLayout* similarLayout = new QHBoxLayout;
similarLayout->addWidget(showSimilarIntro);
similarLayout->addWidget(showSimilar);
recommendedQueue = new QPushButton("Put Recommended Movie in Queue");


QVBoxLayout* currentMovieLayout = new QVBoxLayout;
//currentMovieLayout->addWidget(currentMovieLabel);
//currentMovieLayout->addWidget(showMovieLabel);//overwrite
currentMovieLayout->addLayout(similarLayout);
currentMovieLayout->addWidget(recommendedQueue);
currentMovieLayout->addLayout(checkoutLayout);
currentMovieLayout->addWidget(RateButton);
currentMovieLayout->addWidget(returnMovieButton);


//Third
//3-1Q
//cout<<netflix->getID()<<endl;
queueLabel = new QLabel("Front of Queue: ");
frontQueue = new QLabel("What is Front Queue");//should be changed

QHBoxLayout* queueInfo = new QHBoxLayout;
queueInfo->addWidget(queueLabel);
queueInfo->addWidget(frontQueue);

//3-2
rentMovieButton = new QPushButton("Rent Movie:");
deleteQueueButton = new QPushButton("Delete from Queue");
moveBackQueueButton = new QPushButton("Move to Back of Queue");
QHBoxLayout* queueOptionLayout = new QHBoxLayout;
queueOptionLayout->addWidget(rentMovieButton);
queueOptionLayout->addWidget(deleteQueueButton);
queueOptionLayout->addWidget(moveBackQueueButton);
//3-3
QVBoxLayout* queueMenu = new QVBoxLayout;
queueMenu->addLayout(queueInfo);
queueMenu->addLayout(queueOptionLayout);
//fourth
//4-1
searchMovie = new QLineEdit;
QFormLayout* searchBlankLayout = new QFormLayout;
searchBlankLayout->addRow("&Search", searchMovie);
//4-2
searchTitleButton = new QPushButton("Search by &Title");
searchKeywordButton = new QPushButton("Search by &Keyword");
searchActorButton = new QPushButton("Search by &Actor");
QHBoxLayout* movieButtonLayout = new QHBoxLayout;
movieButtonLayout->addWidget(searchTitleButton);
movieButtonLayout->addWidget(searchKeywordButton);
movieButtonLayout->addWidget(searchActorButton);
//4-3
QVBoxLayout* searchMovieLayout = new QVBoxLayout;
searchMovieLayout->addLayout(searchBlankLayout);
searchMovieLayout->addLayout(movieButtonLayout);
//final
QVBoxLayout* movieMenuLayout = new QVBoxLayout;
movieMenuLayout->addLayout(helloUserLayout);
movieMenuLayout->addLayout(currentMovieLayout);
movieMenuLayout->addLayout(queueMenu);
movieMenuLayout->addLayout(searchMovieLayout);
movieMenuLayout->addWidget(logoutButton);

connect(returnMovieButton, SIGNAL(clicked()), this, SLOT(returnMovieClicked()));
connect(rentMovieButton, SIGNAL(clicked()), this, SLOT(rentMovieClicked()));
connect(deleteQueueButton, SIGNAL(clicked()), this, SLOT(deleteQueueClicked()));
connect(moveBackQueueButton, SIGNAL(clicked()), this, SLOT(moveBackClicked()));
connect(searchTitleButton, SIGNAL(clicked()), this, SLOT(searchTitleClicked()));
connect(searchKeywordButton, SIGNAL(clicked()), this, SLOT(searchKeywordClicked()));
connect(searchActorButton, SIGNAL(clicked()), this, SLOT(searchActorClicked()));
connect(logoutButton, SIGNAL(clicked()), this, SLOT(logoutClicked()));
connect(RateButton, SIGNAL(clicked()), this, SLOT(ratingClicked()));
connect(recommendedQueue, SIGNAL(clicked()), this, SLOT(recommendedQueueClicked()));

//newSearch = new Search(this, netflix);
//transfer();
setLayout(movieMenuLayout);
}
//take netflix information and use it.
void movieMenu::setNetflix(Netflix * netflix)
{
	this->netflix = netflix;
	//newSearch->setNetflix(netflix);
}
void movieMenu::returnMovieClicked()
{
	
	if(netflix->getCurrentUser()->currentMovie() != NULL)
	{

		QMessageBox::StandardButton RateAsking;
		RateAsking = QMessageBox::question(this, "CONFIRMATION", "Returning movie, Do you want to re rate?", QMessageBox::Yes|QMessageBox::No);
		if(RateAsking == QMessageBox::Yes)
		{
			netflix->getCurrentUser()->returnMovie();
			ReRate * newReRate = new ReRate(this, netflix);
			newReRate->movieUpdate1();
			this->hide();
			newReRate->setWindowFlags(Qt::Window);
			newReRate->show();
			transfer();
		}
		else
		{
			netflix->getCurrentUser()->returnMovie();
			transfer();
		}

	}
	else
	{


		QMessageBox::StandardButton RateAsking;
		RateAsking = QMessageBox::question(this, "CONFIRMATION", "You don't have checked out movie. Do you want rerate movies you watched?", QMessageBox::Yes|QMessageBox::No);
		if(RateAsking == QMessageBox::Yes)
		{
			ReRate * newReRate = new ReRate(this, netflix);
			newReRate->movieUpdate1();
			this->hide();
			newReRate->setWindowFlags(Qt::Window);
			newReRate->show();
			transfer();
		}
		else
		{

		}

		/*
		QMessageBox currentMovieWarning;
		currentMovieWarning.setText("You dont have checkedout Movie! Check it again!");
		currentMovieWarning.exec();
		*/
	}
}

void movieMenu::rentMovieClicked()
{
	
	
	if(!(netflix->getCurrentUser()->movieQueue()->empty()) && (netflix->getCurrentUser()->currentMovie() == NULL))
	{
		Movie* temp = netflix->getCurrentUser()->movieQueue()->front();
		netflix->getCurrentUser()->rentMovie(temp);
		netflix->getCurrentUser()->movieQueue()->pop();
		transfer();
	}
	else
	{
		QMessageBox rentMovieWarning;
		rentMovieWarning.setText("You already have checked out movie or no movie in your Queue");
		rentMovieWarning.exec();
	}
}

void movieMenu::deleteQueueClicked()
{

	if(!(netflix->getCurrentUser()->movieQueue()->empty()))
	{
		netflix->getCurrentUser()->movieQueue()->pop();
		transfer();
	}
	else
	{
		QMessageBox deleteWarning;
		deleteWarning.setText("No movie in your Queue");
		deleteWarning.exec();
		transfer();
	}
		
}

void movieMenu::moveBackClicked()
{
	if(!(netflix->getCurrentUser()->movieQueue()->empty()))
	{
		Movie* temp2 = netflix->getCurrentUser()->movieQueue()->front();
		netflix->getCurrentUser()->movieQueue()->pop();
		netflix->getCurrentUser()->movieQueue()->push(temp2);
		transfer();
	}
	else
	{
		QMessageBox moveBackWarning;
		moveBackWarning.setText("No Movie in your Queue");
		moveBackWarning.exec();
	}



}

void movieMenu::searchKeywordClicked()
{

	string temp = netflix->lowerCase(searchMovie->text().toStdString());
	if(netflix->getKeywordsMap()->count(temp))
	{
		KSearch * KnewSearch = new KSearch(this, netflix, temp);
		this->hide();
		KnewSearch->setWindowFlags(Qt::Window);
		KnewSearch->show();
	}
	else
	{
		QMessageBox KsearchWarning;
		KsearchWarning.setText("Your input is not in the database");
		KsearchWarning.exec();	
	}
	

}
void movieMenu::searchActorClicked()
{
	string temp = netflix->lowerCase(searchMovie->text().toStdString());
	if(netflix->getActorMap()->count(temp))
	{
		ASearch * AnewSearch = new ASearch(this, netflix, temp);
		this->hide();
		AnewSearch->setWindowFlags(Qt::Window);
		AnewSearch->show();
	}
	else
	{
		QMessageBox AsearchWarning;
		AsearchWarning.setText("Your input is not in the database");
		AsearchWarning.exec();
	}
}

void movieMenu::searchTitleClicked()
{
	string temp = netflix->lowerCase(searchMovie->text().toStdString());
	if(netflix->getTitleMap()->count(temp))
	{	
		Search * newSearch = new Search(this, netflix, temp);
		this->hide();
		newSearch->setWindowFlags(Qt::Window);
		newSearch->show();
	}
	else
	{
		QMessageBox searchWarning;
		searchWarning.setText("Your input is not in the database");
		searchWarning.exec();	
	}


}

void movieMenu::logoutClicked()
{
QMessageBox::StandardButton Asking;
Asking = QMessageBox::question(this, "Quit.", "Quit! Sure?", QMessageBox::Yes|QMessageBox::No);
if(Asking == QMessageBox::Yes)
{
netflix->savingData();
parent->show();
close();
}
else
{}
}

//overwrite!
void movieMenu::transfer()
{
	showCurrentUserLabel->setText(QString::fromStdString(netflix->getCurrentUser()->getName()+"  ("+netflix->getCurrentUser()->getID() + ")"));
	

	//update similarity!!!
	//getting users in the data, putting into vector.(Except current user)
	vector<string> UserData;	
	map<string, User*>* temp = netflix->getUserMap();	
	map<string, User*>::iterator itA;
	for(itA = temp->begin(); itA != temp->end(); ++itA)
	{
		if(netflix->getCurrentUser()->getID() != itA->second->getID())
		{	
			UserData.push_back(itA->second->getID());// put User class into a vector.
		}
	}
	//getting whole movies, putting them in to vector
	map<string, Movie*>* temp1 = netflix->getTitleMap();
	map<string, Movie*>::iterator itB;
	set<string> listOfMovie;
	for(itB = temp1->begin(); itB != temp1->end(); ++itB)
	{	
		listOfMovie.insert(itB->second->getTitle());
	}
	//getting rated movies of current user, then putting them into vectors
	map<Movie*, int>::iterator itC;
	map<Movie*, int>* temp2 = netflix->getCurrentUser()->ratingInfo();
	vector<string> currentUserMovie;
	for(itC = temp2->begin(); itC != temp2->end(); ++itC)
	{	
		currentUserMovie.push_back(itC->first->getTitle());
	}
	//sorting and putting movies that current user does not rate.
	
	set<string>::iterator itD;
	vector<string> unRatedMovie; // there are going to be only current user's unrated movies.
		
	for(unsigned int i = 0; i < currentUserMovie.size(); i++)
	{	
		if(listOfMovie.count(currentUserMovie[i]) == 1)
		{      
			listOfMovie.erase(currentUserMovie[i]);
		}

	}
	set<string>::iterator iterA;
	for(iterA = listOfMovie.begin(); iterA != listOfMovie.end(); ++iterA)
	{
		unRatedMovie.push_back(*iterA);
	}	
	double SumOfRate = 0;
	double RM = 0;
	double W = 0;
	map<double, string> interestingness;
	//vector<string> UserData; --> vector of User saved all users in data Base except current user.
	for(unsigned int i = 0; i < unRatedMovie.size(); i++)//iterating movies first
	{
		for(unsigned int j = 0; j < UserData.size(); j++)//iteratring users for one specific movie
		{ 
			//map<string, user*>    UserData[i] is string which is ID!
			map<Movie*, int>::iterator itA;
			map<string, int> MovieWithRate;
			
			map<string, User*>::iterator Class;
			Class = netflix->getUserMap()->find(UserData[j]);
			User* UserClass = Class->second;
			
			for(itA = UserClass->ratingInfo()->begin(); itA != UserClass->ratingInfo()->end(); ++itA) 
			{	
				MovieWithRate.insert(make_pair(itA->first->getTitle(), itA->second));
			}

			if( MovieWithRate.count(unRatedMovie[i]))
			{
				//saving string movie name and corresponding rate.
				map<string, int>::iterator temp;
				temp = MovieWithRate.find(unRatedMovie[i]);
				int rateNumber = temp->second;
				
				vector<double> similar = netflix->setIntersection(netflix->getCurrentUser()->ratingInfo(),UserClass->ratingInfo());
					// doubleVariable have total that all similarity are added and eventually is divided for 
					// finding basic similarity.
					double doubleVariable = 0;
					for(unsigned int i = 0; i < similar.size(); i++)
					{
						doubleVariable = doubleVariable + similar[i];
					}
				//to find basic similarity, just divide doubleVariable
				// by vector size(movies that two users have in common).
				W = W + (1-doubleVariable/similar.size());
				RM = (1-doubleVariable/similar.size())*rateNumber; //R(M) 
				SumOfRate = SumOfRate + RM;
			}
			
		}
		//create map to store interasted calculation as a key and movie as a value
		//cout<<SumOfRate/W<<unRatedMovie[i]<<endl;
		interestingness.insert(make_pair(SumOfRate/W, unRatedMovie[i]));
	}
	//map<string, double> interestingness;
	vector<double> highestInter;
	map<double, string>::iterator iter1;
	for(iter1 = interestingness.begin(); iter1 != interestingness.end(); ++iter1)
	{
		highestInter.push_back(iter1->first);
	}
	vector<double> highestInter1 = MergeSort::sort(highestInter);
	map<double, string>::iterator iter2;
	//last element is the largest one.
	iter2 = interestingness.find(highestInter1[highestInter1.size()-1]);
	

	//Update recommendation
	if(currentUserMovie.size()==netflix->getTitleMap()->size())
	{
		showSimilar->setText("No recommendation available, you rated every movie");
	}
	else
	{
		showSimilar->setText(QString::fromStdString(iter2->second));
		netflix->setRecommendation(iter2->second);
	}

	//update queue information
	if(!(netflix->getCurrentUser()->movieQueue()->empty())){
	
		frontQueue->setText(QString::fromStdString(netflix->getCurrentUser()->movieQueue()->front()->getTitle()));
	}
	else
	{
		frontQueue->setText("There is no movie in Queue");
	}

	if(netflix->getCurrentUser()->currentMovie() != NULL)
	{
		showMovieLabel->setText(QString::fromStdString(netflix->getCurrentUser()->currentMovie ()->getTitle()));
	}
	else
	{
		showMovieLabel->setText("There is no checked out Movie!");
	}

		

}


void movieMenu::ratingClicked()
{		
	if(netflix->getCurrentUser()->currentMovie() != NULL)
	{
		Movie * temp = netflix->getCurrentUser()->currentMovie();
		string trueChecking = temp->getTitle();
		if(!(netflix->getCurrentUser()->rateContain(trueChecking))) 

		{
			MovieRate * newMovieRate = new MovieRate(this, netflix);
			newMovieRate->movieUpdate();
			this->hide();
			newMovieRate->setWindowFlags(Qt::Window);
			newMovieRate->show();

		}
		else
		{




			QMessageBox::StandardButton RateAsking;
			RateAsking = QMessageBox::question(this, "CONFIRMATION", "You have already rated it. Do you want to rate it again?", QMessageBox::Yes|QMessageBox::No);
			if(RateAsking == QMessageBox::Yes)
			{
				//delete current movie from the map for re-rate.
				Movie * temp = netflix->getCurrentUser()->currentMovie();
				map<Movie*, int>::iterator D;
				D = netflix->getCurrentUser()->ratingInfo()->find (temp);
				netflix->getCurrentUser()->ratingInfo()->erase (D);


				MovieRate * newMovieRate = new MovieRate(this, netflix);
				newMovieRate->movieUpdate();
				this->hide();
				newMovieRate->setWindowFlags(Qt::Window);
				newMovieRate->show();
			}
			else
			{

			}
			/*
			QMessageBox ratingWarning1;
			ratingWarning1.setText("You have already rated it");
			ratingWarning1.exec();
			*/
		}
	}
	else
	{
			

			QMessageBox ratingWarning;
			ratingWarning.setText("You dont have checkedout Movie! Check it again!");
			ratingWarning.exec();

	}


}
void movieMenu::recommendedQueueClicked()
{

	if(netflix->getCurrentUser()->ratingInfo()->size()==netflix->getTitleMap()->size())
	{
		QMessageBox recommendationWarning;
		recommendationWarning.setText("You dont have recommendation");
		recommendationWarning.exec();
	}
	else
	{
		Movie * temp = new Movie(netflix->getRecommendation());
		netflix->getCurrentUser()->movieQueue()->push(temp);
		QMessageBox recommendationConfirm;
		recommendationConfirm.setText("It is added!");
		recommendationConfirm.exec();
	}

}

void movieMenu::closeEvent(QCloseEvent *event)
{

netflix->savingData();
parent->show();
close();

}


