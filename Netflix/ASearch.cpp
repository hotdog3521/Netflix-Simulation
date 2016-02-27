#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "ASearch.h"
#include <QMessageBox>


using namespace std;

ASearch::ASearch(QWidget* parent, Netflix* netflix, string userInput)
{
this->netflix = netflix;
getUserKeyword = userInput;
this->parent = parent;


KeywordsearchLabel = new QLabel("Show movie");
KshowKeyword = new QLabel("put movie");//overwrite list of keywords
Kinformation = new QLabel("------Movie Info----------------");


KeywordnextMovieButton = new QPushButton("Next Movie");
KeywordaddQueueButton = new QPushButton("Add it in Queue");
KeywordreturnMainButton = new QPushButton("Returning to main menu");

QHBoxLayout* searchKeywordButtons = new QHBoxLayout;
searchKeywordButtons->addWidget(KeywordnextMovieButton);
searchKeywordButtons->addWidget(KeywordaddQueueButton);
searchKeywordButtons->addWidget(KeywordreturnMainButton);

QVBoxLayout* searchKeyword = new QVBoxLayout;
searchKeyword->addWidget(KeywordsearchLabel);
searchKeyword->addWidget(Kinformation);
searchKeyword->addWidget(KshowKeyword);


searchKeyword->addLayout(searchKeywordButtons);

printKeyword(getUserKeyword);

connect(KeywordnextMovieButton, SIGNAL(clicked()), this, SLOT(KeywordNextMovieClicked()));
connect(KeywordaddQueueButton, SIGNAL(clicked()), this, SLOT(KeywordAddQueueClicked()));
connect(KeywordreturnMainButton, SIGNAL(clicked()), this, SLOT(KeywordReturnMainButtonClicked()));

setLayout(searchKeyword);
}

void ASearch::KeywordNextMovieClicked()
{
	if(++itA != temp1->end() )
	{
		//++itA;
		printKeyword2(getUserKeyword);
	}
	else
	{
		QMessageBox incrementWarning;
		incrementWarning.setText("No More Movie Corresponding the keyword!");
		incrementWarning.exec();
	}

}
void ASearch::KeywordAddQueueClicked()
{
	
	Movie *temp = NULL;
	temp = new Movie(putqueue);
	netflix->getCurrentUser()->movieQueue()->push(temp);
	QMessageBox Addingsign;
	Addingsign.setText("ADDED!!!");
	Addingsign.exec();

}
void ASearch::KeywordReturnMainButtonClicked()
{
/*
QMessageBox::StandardButton Asking;
Asking = QMessageBox::question(this, "Quit.", "Quiting! Sure?", QMessageBox::Yes|QMessageBox::No);
if(Asking == QMessageBox::Yes)
{
*/
	//parent->show();

	close();


}

void ASearch::printKeyword(string x)
{
	//Set<Movie*>* temp1; what senond is
	//map <string, Set<Movie*>*>* keywords; --> keyword map looks like
	//map <string, User*>* users;
	//map<string, User*>::iterator p;
	//p = users->find(id);
	//userLogin = p -> second;
	
	map<string, set<Movie*>*>::iterator p;
	p = netflix->getActorMap()->find(x);
	temp1 = p -> second;

	//temp1 = netflix->getKeywordsMap()->get(x);
	itA = temp1->begin();//first element
	string temp2 = (*itA)->getTitle(); //first string
	set<string> temp3 = (*itA)->getAllKeywords();
	
	for(itB = temp3.begin(); itB != temp3.end(); ++itB) 
	{ 
		Keywordstr = Keywordstr + (*itB) + "\n";
 
	}
	putqueue = (*itA)->getTitle();
	KeywordsearchLabel->setText(QString::fromStdString((*itA)->getTitle()));	
	KshowKeyword->setText(QString::fromStdString(Keywordstr));
}
void ASearch::printKeyword2(string x)
{
	//Set<Movie*>* temp1;
	map<string, set<Movie*>*>::iterator p;
	p = netflix->getActorMap()->find(x);
	temp1 = p -> second;
	//temp1 = netflix->getKeywordsMap()->get(x);
	//first element
	string temp2 = (*itA)->getTitle(); //first string
	set<string> temp3 = (*itA)->getAllKeywords();
	Keywordstr = "";
	
	for(itB = temp3.begin(); itB != temp3.end(); ++itB) 
	{ 
		Keywordstr = Keywordstr + (*itB) + "\n";
 
	}
	putqueue = (*itA)->getTitle();
	KeywordsearchLabel->setText(QString::fromStdString((*itA)->getTitle()));	
	KshowKeyword->setText(QString::fromStdString(Keywordstr));
}

void ASearch::closeEvent(QCloseEvent *event)
{

	parent->show();
	close();

	
}


