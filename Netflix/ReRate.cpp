#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "ReRate.h"
#include <QMessageBox>



using namespace std;

ReRate::ReRate(QWidget* parent, Netflix* netflix)
{

this->netflix = netflix;
this->parent = parent;

introduction = new QLabel("Please Re-Rate The Movie, Select movie that you want to rerate");

MovieLabel = new QLabel("Movie you are going to rate : ");
showMovie = new QLabel("Currently You Don't Have Checked out Movie");
option = new QComboBox();

map<Movie*, int>::iterator itA;
for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
{
	string temp = itA->first->getTitle();
	option->addItem(temp.c_str());
}

QHBoxLayout* showMovieLayout = new QHBoxLayout;
showMovieLayout->addWidget(MovieLabel);
showMovieLayout->addWidget(option);



Rating1 = new QPushButton("RATE 1");
Rating2 = new QPushButton("RATE 2");
Rating3 = new QPushButton("RATE 3");
Rating4 = new QPushButton("RATE 4");
Rating5 = new QPushButton("RATE 5");


QHBoxLayout* rateButtonLayout = new QHBoxLayout;
rateButtonLayout->addWidget(Rating1);
rateButtonLayout->addWidget(Rating2);
rateButtonLayout->addWidget(Rating3);
rateButtonLayout->addWidget(Rating4);
rateButtonLayout->addWidget(Rating5);


quitRate = new QPushButton("Going Back to Main Menu");
QVBoxLayout* rateLayout = new QVBoxLayout;

rateLayout->addWidget(introduction);
rateLayout->addLayout(showMovieLayout);
rateLayout->addLayout(rateButtonLayout);
rateLayout->addWidget(quitRate);



connect(Rating1, SIGNAL(clicked()), this, SLOT(RatingClicked1()));
connect(Rating2, SIGNAL(clicked()), this, SLOT(RatingClicked2()));
connect(Rating3, SIGNAL(clicked()), this, SLOT(RatingClicked3()));
connect(Rating4, SIGNAL(clicked()), this, SLOT(RatingClicked4()));
connect(Rating5, SIGNAL(clicked()), this, SLOT(RatingClicked5()));
connect(quitRate, SIGNAL(clicked()), this, SLOT(quitClicked()));


setLayout(rateLayout);


}

void ReRate::RatingClicked1()
{
	string temp;
	temp = option->currentText().toStdString();

	map<Movie*, int>::iterator itA;
	for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
	{	
		if(temp == itA->first->getTitle())
		{
			netflix->getCurrentUser()->ratingInfo()->erase(itA);
			Movie* reRate = new Movie(temp);
			netflix->getCurrentUser()->rateMovie (reRate, 1);
			QMessageBox rerateSign;
			rerateSign.setText("Successfully Re-rate");
			rerateSign.exec();
			break;
		}
	}

}
void ReRate::RatingClicked2()
{
	string temp;
	temp = option->currentText().toStdString();

	map<Movie*, int>::iterator itA;
	for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
	{	
		if(temp == itA->first->getTitle())
		{
			netflix->getCurrentUser()->ratingInfo()->erase(itA);
			Movie* reRate = new Movie(temp);
			netflix->getCurrentUser()->rateMovie (reRate, 2);
			QMessageBox rerateSign;
			rerateSign.setText("Successfully Re-rate");
			rerateSign.exec();
			break;
		}
	}

}
void ReRate::RatingClicked3()
{
	string temp;
	temp = option->currentText().toStdString();

	map<Movie*, int>::iterator itA;
	for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
	{	
		if(temp == itA->first->getTitle())
		{
			netflix->getCurrentUser()->ratingInfo()->erase(itA);
			Movie* reRate = new Movie(temp);
			netflix->getCurrentUser()->rateMovie (reRate, 3);
			QMessageBox rerateSign;
			rerateSign.setText("Successfully Re-rate");
			rerateSign.exec();
			break;
		}
	}
}
void ReRate::RatingClicked4()
{
	string temp;
	temp = option->currentText().toStdString();

	map<Movie*, int>::iterator itA;
	for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
	{	
		if(temp == itA->first->getTitle())
		{
			netflix->getCurrentUser()->ratingInfo()->erase(itA);
			Movie* reRate = new Movie(temp);
			netflix->getCurrentUser()->rateMovie (reRate, 4);
			QMessageBox rerateSign;
			rerateSign.setText("Successfully Re-rate");
			rerateSign.exec();
			break;
		}
	}
}
void ReRate::RatingClicked5()
{
	string temp;
	temp = option->currentText().toStdString();

	map<Movie*, int>::iterator itA;
	for(itA = netflix->getCurrentUser()->ratingInfo()->begin(); itA != netflix->getCurrentUser()->ratingInfo()->end(); ++itA)
	{	
		if(temp == itA->first->getTitle())
		{
			netflix->getCurrentUser()->ratingInfo()->erase(itA);
			Movie* reRate = new Movie(temp);
			netflix->getCurrentUser()->rateMovie (reRate, 5);
			QMessageBox rerateSign;
			rerateSign.setText("Successfully Re-rate");
			rerateSign.exec();
			break;
		}
	}
}

void ReRate::quitClicked()
{
	//parent->show();
	close();
}

void ReRate::movieUpdate1()
{
//showMovie->setText(QString::fromStdString(netflix->getCurrentUser()->currentMovie ()->getTitle()));
}

void ReRate::closeEvent(QCloseEvent *event)
{

	parent->show();
	close();
	
}






