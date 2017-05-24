#include "GraphicDisplay.h"
using namespace std;

GraphicDisplay::GraphicDisplay(int n):gridSize{n}{
  theGrid.resize(n);
  for(int i=0;i<n;++i){
    theGrid[i].resize(n);
    for(int j=0;j<n;++j){
      theGrid[i][j]=false;
    }
  }//set every the Grid element to false
}

void GraphicDisplay::notify(Subject &whoNotified) {
  Info read = whoNotified.getInfo();
  theGrid[read.row][read.col] = read.state;
}//change the state to the read state when notified

GraphicDisplay::~GraphicDisplay() {}

SubscriptionType GraphicDisplay::subType() const {
  return SubscriptionType::All;//same as TextDisplay
}

void operator<<(Xwindow &wd, const GraphicDisplay &gd){
  int len = 500/gd.gridSize;//grid size gets smaller if there are more cells
  int num = gd.gridSize;
  for(int i=0;i<num;++i){
    for(int j=0;j<num;++j){
      if(gd.theGrid[i][j]){
        wd.fillRectangle(j*len,i*len,len,len,Xwindow::White);
      }//if it is on, then print it white
      else{
        wd.fillRectangle(j*len,i*len,len,len,Xwindow::Black);
      }//print it black if it is off
    }
  }
}
//similar implementation as TextDisplay, but prints to Xwindow instead of stdout