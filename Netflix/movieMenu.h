#ifndef MOVIEMENU_H
#define MOVIEMENU_H
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
#include "Search.h"
#include "KSearch.h"
#include "ASearch.h"
#include "MovieRate.h"
#include "ReRate.h"
#include <map>
#include <set>
#include <queue>
#include "lib/MergeSort.h"

using std::map;
using std::set;
using std::queue;

class movieMenu : public QWidget
{
  Q_OBJECT

public:
  movieMenu(QWidget* parent = NULL, Netflix* netflix = NULL);
  void setNetflix(Netflix * netflix);
  void setUser(User * user);
  void transfer();
 
private slots:
  void rentMovieClicked();
  void returnMovieClicked();
  void deleteQueueClicked();
  void moveBackClicked();
  void searchKeywordClicked();
  void searchTitleClicked();
  void ratingClicked();
  void logoutClicked();
  void searchActorClicked();
  void recommendedQueueClicked();
 
protected:
  void closeEvent(QCloseEvent *event);


private:

  QLabel * showCurrentUserLabel;
  QLabel * movieLabel;
  QLabel * currentMovieLabel;
  QLabel * queueLabel;
  QLabel * frontQueue;
  QLabel * showMovieLabel;
  QLabel * showSimilar;
  QLabel * showSimilarIntro;
  QLineEdit* searchMovie;
  User * theUser;

  QPushButton * recommendedQueue;
  QPushButton * RateButton;
  QPushButton * searchTitleButton;
  QPushButton * searchKeywordButton;
  QPushButton * searchActorButton;
  QPushButton * returnMovieButton;
  QPushButton * rentMovieButton;
  QPushButton * deleteQueueButton;
  QPushButton * moveBackQueueButton;
  QPushButton * logoutButton;
  Search * newSearch;
  KSearch * KnewSearch;
  ASearch * AnewSearch;
  Netflix * netflix;
  QWidget* parent;
  MovieRate * newMovieRate;
  ReRate * newReRate;
};

#endif
