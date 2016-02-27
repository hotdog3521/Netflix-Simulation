#ifndef SEARCH_H
#define SEARCH_H
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
#include <queue>

using std::map;
using std::set;
using std::queue;

class Search : public QWidget
{
  Q_OBJECT

public:
  Search(QWidget* parent, Netflix* netflix, string userInput);
  //void setNetflix(Netflix * netflix);
  void printMovie(string x);
 
private slots:

void addQueueClicked();
void returnMainButtonClicked();

protected:
  void closeEvent(QCloseEvent *event);
  

private:
  QLabel* searchLabel;
  QLabel* showKeyword;
  QLabel* information;
  QPushButton* addQueueButton;
  QPushButton* returnMainButton;

  string str;
  string getUserSearch;
  Netflix* netflix;
  QWidget* parent;
};

#endif
