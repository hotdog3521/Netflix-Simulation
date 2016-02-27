#ifndef MOVIERATE_H
#define MOVIERATE_H
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
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using std::map;
using std::set;
using std::queue;

class MovieRate : public QWidget
{
  Q_OBJECT

public:
  MovieRate(QWidget* parent, Netflix* netflix);
  void movieUpdate();
private slots:
  void RatingClicked1();
  void RatingClicked2();
  void RatingClicked3();
  void RatingClicked4();
  void RatingClicked5();
  void quitClicked();	

protected:
  void closeEvent(QCloseEvent *event);

private:

  QPushButton* Rating1;
  QPushButton* Rating2;
  QPushButton* Rating3;
  QPushButton* Rating4;
  QPushButton* Rating5;
  QPushButton* quitRate;
  
  QLabel* introduction;
  QLabel* MovieLabel;
  QLabel* showMovie;

  Netflix* netflix;
QWidget* parent;

};

#endif
