#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
  theDisplay.resize(n);
  for (int i=0;i<n;++i){
    theDisplay[i].resize(n);
    for(int j=0;j<n;++j){
      theDisplay[i][j] = '_';
    }
  }
}

void TextDisplay::notify(Subject &whoNotified) {
  Info read = whoNotified.getInfo();
  if (read.state) {
    theDisplay[read.row][read.col]='X';
  }
  else{
    theDisplay[read.row][read.col]='_';
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  int len = td.gridSize;
  for(int i=0;i<len;++i){
    for(int j=0;j<len;++j){
      out<<td.theDisplay[i][j];
    }
    out<<endl;
  }
  return out;
}
