#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "MovieRate.h"
#include <QMessageBox>


using namespace std;

MovieRate::MovieRate(QWidget* parent, Netflix* netflix)
{

this->netflix = netflix;
this->parent = parent;

introduction = new QLabel("Please Rate The Movie");

MovieLabel = new QLabel("Movie you are going to rate : ");
showMovie = new QLabel("space for movie");



QHBoxLayout* showMovieLayout = new QHBoxLayout;
showMovieLayout->addWidget(MovieLabel);
showMovieLayout->addWidget(showMovie);



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

void MovieRate::RatingClicked1()
{
	Movie * temp = netflix->getCurrentUser()->currentMovie();
	if(!netflix->getCurrentUser()->ratingInfo()->count(temp))
	{
		netflix->getCurrentUser()->rateMovie(temp, 1);
		QMessageBox ratingChecking1;
		ratingChecking1.setText("Successfully rated!");
		ratingChecking1.exec();
		
	}
	else
	{
		QMessageBox ratingWarning1;
		ratingWarning1.setText("You already have rated this movie. Please go back");
		ratingWarning1.exec();
	}

}
void MovieRate::RatingClicked2()
{
	Movie * temp = netflix->getCurrentUser()->currentMovie();
	if(!netflix->getCurrentUser()->ratingInfo()->count(temp))
	{
		netflix->getCurrentUser()->rateMovie(temp, 2);
		QMessageBox ratingChecking2;
		ratingChecking2.setText("Successfully rated!");
		ratingChecking2.exec();
	}
	else
	{
		QMessageBox ratingWarning2;
		ratingWarning2.setText("You already have rated this movie. Please go back");
		ratingWarning2.exec();
	}

}
void MovieRate::RatingClicked3()
{
	Movie * temp = netflix->getCurrentUser()->currentMovie();
	if(!netflix->getCurrentUser()->ratingInfo()->count(temp))
	{
		netflix->getCurrentUser()->rateMovie(temp, 3);
		QMessageBox ratingChecking3;
		ratingChecking3.setText("Successfully rated!");
		ratingChecking3.exec();
	}
	else
	{
		QMessageBox ratingWarning3;
		ratingWarning3.setText("You already have rated this movie. Please go back");
		ratingWarning3.exec();
	}

}
void MovieRate::RatingClicked4()
{
	Movie * temp = netflix->getCurrentUser()->currentMovie();
	if(!netflix->getCurrentUser()->ratingInfo()->count(temp))
	{
		netflix->getCurrentUser()->rateMovie(temp, 4);
		QMessageBox ratingChecking4;
		ratingChecking4.setText("Successfully rated!");
		ratingChecking4.exec();
	}
	else
	{
		QMessageBox ratingWarning4;
		ratingWarning4.setText("You already have rated this movie. Please go back");
		ratingWarning4.exec();
	}

}
void MovieRate::RatingClicked5()
{
	Movie * temp = netflix->getCurrentUser()->currentMovie();
	if(!netflix->getCurrentUser()->ratingInfo()->count(temp))
	{
		netflix->getCurrentUser()->rateMovie(temp, 5);
		QMessageBox ratingChecking5;
		ratingChecking5.setText("Successfully rated!");
		ratingChecking5.exec();
	}
	else
	{
		QMessageBox ratingWarning5;
		ratingWarning5.setText("You already have rated this movie. Please go back");
		ratingWarning5.exec();
	}

}

void MovieRate::quitClicked()
{
	//parent->show();
	close();
}

void MovieRate::movieUpdate()
{
showMovie->setText(QString::fromStdString(netflix->getCurrentUser()->currentMovie ()->getTitle()));
}

void MovieRate::closeEvent(QCloseEvent *event)
{

	parent->show();
	close();
	
}






