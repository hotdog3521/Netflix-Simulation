#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "lib/map.h"
#include "lib/set.h"
#include "lib/Queue.h"
#include "User.h"
#include "Movie.h"
#include "Signup.h"
#include "movieMenu.h"
//#include "Search.h"
#include <QCloseEvent>

class userLogin : public QWidget
{
  Q_OBJECT

public:
  userLogin(QWidget* parent = NULL, Netflix* netflix = NULL);
  void setNetflix(Netflix * netflix);


private slots:
  void loginClicked();
  void newUserClicked();
  void quitClicked();
  

protected:
 

private:
  QLabel* loginLabel;
  QLineEdit* loginText;
  QPushButton* loginButton;
  QPushButton* quitButton;
  QPushButton* newUserButton;
  Signup* newSignup;
  movieMenu* newMenu;
  Search* newSearch;
  Netflix* netflix;
};

#endif
