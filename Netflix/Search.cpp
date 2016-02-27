#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "Search.h"
#include <QMessageBox>


using namespace std;

Search::Search(QWidget* parent, Netflix* netflix, string userInput)
{
this->netflix = netflix;
//setNetflix(netflix); 
getUserSearch = userInput;
this->parent = parent;

searchLabel = new QLabel("The Princess Bride");
showKeyword = new QLabel("put movie");
information = new QLabel("------Movie Info----------------");


addQueueButton = new QPushButton("Add it in Queue");
returnMainButton = new QPushButton("Returning to main menu");

QHBoxLayout* searchMovieButtons = new QHBoxLayout;
searchMovieButtons->addWidget(addQueueButton);
searchMovieButtons->addWidget(returnMainButton);

QVBoxLayout* searchMovie = new QVBoxLayout;
searchMovie->addWidget(searchLabel);
searchMovie->addWidget(information);
searchMovie->addWidget(showKeyword);
searchMovie->addLayout(searchMovieButtons);
printMovie(getUserSearch);


connect(addQueueButton, SIGNAL(clicked()), this, SLOT(addQueueClicked()));
connect(returnMainButton, SIGNAL(clicked()), this, SLOT(returnMainButtonClicked()));

setLayout(searchMovie);
}
//void Search::setNetflix(QWidget* parent, Netflix * netflix, string userInput)
//{
//	//this->netflix = netflix;
//}

void Search::addQueueClicked()
{
	Movie *temp = NULL;
	temp = new Movie(getUserSearch);
	netflix->getCurrentUser()->movieQueue()->push(temp);
	QMessageBox Addingsign1;
	Addingsign1.setText("ADDED!!!");
	Addingsign1.exec();
}
void Search::returnMainButtonClicked()
{
	close();
/*
QMessageBox::StandardButton Asking;
Asking = QMessageBox::question(this, "Quit.", "Quiting! Sure?", QMessageBox::Yes|QMessageBox::No);
if(Asking == QMessageBox::Yes)
{
	parent->show();
	close();
}
else
{}
*/
}
void Search::printMovie(string x)
{  
	//map<string, Movie*>* getTitleMap();
	//temp=netflix->getTitleMap()->get(x)->getAllKeywords();	

	set<string> temp; // to store data getAllKeywords
	map<string, Movie*>::iterator p;
	p = netflix->getTitleMap()->find(x);

	temp = p->second->getAllKeywords();
			
	set<string>::iterator itB;

	for(itB = temp.begin(); itB != temp.end(); ++itB) 
	{ 
		str = str + (*itB) + "\n";
	}
	searchLabel->setText(QString::fromStdString(x));	
	showKeyword->setText(QString::fromStdString(str));
	
}
void Search::closeEvent(QCloseEvent *event)
{

	parent->show();
	close();

}









