#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include "Signup.h"
#include <QMessageBox>


using namespace std;

Signup::Signup(QWidget* parent, Netflix * netflix)
{
this->netflix = netflix;
this->parent = parent;
setNetflix(netflix);
sConfirmButton = new QPushButton("Confir&m");
sCancelButton = new QPushButton("&Cancel");

signupLabel = new QLabel("Please sign up for CSCI 104 Flix");

sLoginText = new QLineEdit;
sNameText = new QLineEdit;
 
QFormLayout* sLayout = new QFormLayout;
sLayout->addRow("&Login:", sLoginText);
sLayout->addRow("&Name:", sNameText);
  
QHBoxLayout* signupRow = new QHBoxLayout;
signupRow->addWidget(sConfirmButton);
signupRow->addWidget(sCancelButton);

QVBoxLayout* signupLayout = new QVBoxLayout;
signupLayout->addWidget(signupLabel);
signupLayout->addLayout(sLayout);
signupLayout->addLayout(signupRow);

connect(sConfirmButton, SIGNAL(clicked()), this, SLOT(confirmClicked()));
connect(sCancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));

setLayout(signupLayout);

}
void Signup::setNetflix(Netflix * netflix)
{

	this->netflix = netflix;
}


void Signup::confirmClicked()
{
	string temp = sLoginText->text().toStdString();
	if(netflix->mapContain(temp))
	{
		QMessageBox signupWarning;
		signupWarning.setText("Your input exists in the database");
		signupWarning.exec();
	}
	else
	{
		string id = sLoginText->text().toStdString();
		string name = sNameText->text().toStdString();
		netflix->createUser(id,name);
		QMessageBox signupSuccess;
		signupSuccess.setText("Successfully created!");
		signupSuccess.exec();
		parent->show();
		close();
	}
}
void Signup::cancelClicked()
{
parent->show();
close();	
}
void Signup::closeEvent(QCloseEvent *event)
{
parent->show();
close();
}
