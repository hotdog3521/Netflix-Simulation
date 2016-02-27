#ifndef RERATE_H
#define RERATE_H
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
#include <QComboBox>

using std::map;
using std::set;
using std::queue;

class ReRate : public QWidget
{
  Q_OBJECT

public:
  ReRate(QWidget* parent, Netflix* netflix);
  void movieUpdate1();
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
  QComboBox* option;
  
  QLabel* introduction;
  QLabel* MovieLabel;
  QLabel* showMovie;

  Netflix* netflix;
QWidget* parent;

};

#endif
