#ifndef ASEARCH_H_
#define ASEARCH_H_
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
//#include "lib/map.h"
//#include "lib/set.h"
//#include "lib/Queue.h"
#include "User.h"
#include "Movie.h"
#include "Netflix.h"
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using std::map;
using std::set;
using std::queue;

class ASearch : public QWidget
{
  Q_OBJECT

public:
  ASearch(QWidget* parent, Netflix* netflix, string userInput);
  void printKeyword(string x);
  void printKeyword2(string x);
 
private slots:
void KeywordNextMovieClicked();
void KeywordAddQueueClicked();
void KeywordReturnMainButtonClicked();


protected:
  void closeEvent(QCloseEvent *event);

private:
  QLabel* KeywordsearchLabel;
  QLabel* KshowKeyword;
  QLabel* Kinformation;
  QPushButton* KeywordnextMovieButton;
  QPushButton* KeywordaddQueueButton;
  QPushButton* KeywordreturnMainButton;
  set<string>::iterator itB;
  set<Movie*>::iterator itA;
  string Keywordstr;
  string getUserKeyword;
  Netflix* netflix;
  QWidget* parent;
  string putqueue;
  set<Movie*>* temp1;
};

#endif
