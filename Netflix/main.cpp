#include <QApplication>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "Netflix.h"
#include "userLogin.h"

int main(int argc, char* argv[])
{

  QApplication app(argc, argv);
  Netflix* netflix = new Netflix();
  ifstream data(argv[1]);

  string userData, movieData;
  getline(data, userData);
  getline(data, movieData);

  netflix->takeaddress(userData);
  netflix->readUserData(userData);
  netflix->readMovieData(movieData);
  

  userLogin userlogin(NULL, netflix);
  //userlogin.setNetflix(netflix);




  userlogin.show();
  return app.exec();

}
