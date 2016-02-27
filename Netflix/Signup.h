#ifndef SIGNUP_H
#define SIGNUP_H
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "lib/map.h"
#include "lib/set.h"
#include "lib/Queue.h"
#include "User.h"
#include "Movie.h"
#include "Netflix.h"
//#include "userLogin.h"


class Signup : public QWidget
{
  Q_OBJECT

public:
  Signup(QWidget* parent = NULL,  Netflix * netflix = NULL);
  void setNetflix(Netflix * netflix);
  
private slots:
  void confirmClicked();
  void cancelClicked();


protected:
  void closeEvent(QCloseEvent *event);
 

private:
  QLineEdit* sNameText;
  QLineEdit* sLoginText;
  QLabel* signupLabel;
  QPushButton* sConfirmButton;
  QPushButton* sCancelButton;
  QWidget* parent;
  //userLogin* newLogin;
  Netflix* netflix;
};

#endif
