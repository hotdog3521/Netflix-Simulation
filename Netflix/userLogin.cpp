#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "userLogin.h"
#include "Netflix.h"
#include <QMessageBox>

using namespace std;

userLogin::userLogin(QWidget* parent, Netflix* netflix)
{
this->netflix = netflix;


this->newSignup = new Signup(this, netflix);



loginButton = new QPushButton("&Login");
newUserButton = new QPushButton("&New User");
quitButton = new QPushButton("&Quit");

loginText = new QLineEdit;
loginLabel = new QLabel("Welcome to CSCI 104-Flix");


QFormLayout* fLayout = new QFormLayout;
fLayout->addRow("&Login:", loginText);
  
QHBoxLayout* loginRow = new QHBoxLayout;
loginRow->addWidget(loginButton);
loginRow->addWidget(newUserButton);
loginRow->addWidget(quitButton);

QVBoxLayout* mainLayout = new QVBoxLayout;
mainLayout->addWidget(loginLabel);
mainLayout->addLayout(fLayout);
mainLayout->addLayout(loginRow);

connect(loginButton, SIGNAL(clicked()), this, SLOT(loginClicked()));
connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUserClicked()));
connect(quitButton, SIGNAL(clicked()), this, SLOT(quitClicked()));

newMenu = new movieMenu(this, netflix);
newSignup = new Signup(this, netflix);
 

setLayout(mainLayout);
}

void userLogin::setNetflix(Netflix * netflix)
{
	this->netflix = netflix;
	newSignup->setNetflix(netflix);
	newMenu->setNetflix(netflix);
}

void userLogin::loginClicked()
{
	string temp = loginText->text().toStdString();
	if(netflix->mapContain(temp))
	{
		
		netflix->storeCurrentUser(temp);
		newMenu->transfer();
		this->hide();
		newMenu->setWindowFlags(Qt::Window);
		newMenu->show();
	}
	else
	{
		QMessageBox loginWarning;
		loginWarning.setText("Your ID does not exist in our database");
		loginWarning.exec();
		
	}

}
void userLogin::newUserClicked()
{
	this->hide();
	newSignup->setWindowFlags(Qt::Window);
	newSignup->show();
}
void userLogin::quitClicked()
{
QMessageBox::StandardButton Asking;
Asking = QMessageBox::question(this, "Quit.", "Quit! Sure?", QMessageBox::Yes|QMessageBox::No);
if(Asking == QMessageBox::Yes)
{
  close();
}
else
{}
}

