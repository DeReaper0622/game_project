#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(): gridSize{0}{}

Grid::~Grid() {
  delete gd;
}

void Grid::clearGrid() {
  if (gridSize!=0) {
    gridSize=0;
    delete gd;
  }
}

bool Grid::isWon() const {
  for (auto a: theGrid){
    for (auto b: a){
      if (b.getState()){
        return false;
      }
    }
  }
  return true;
}

void Grid::init(int n) {
  clearGrid();
  gridSize=n;
  gd= new GraphicDisplay{n};
  theGrid.resize(gridSize);
  for (int i=0;i<n;++i){
    theGrid[i].resize(gridSize);
    for(int j=0;j<n;++j){
      Cell create;
      create.setCoords(i,j);
      create.attach(gd);
      theGrid[i][j]=create;
    }//attach each cell to graphic display
  }

  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j){
      if((i-1)>=0){
        theGrid[i][j].attach(&theGrid[i-1][j]);
      }
      if((i+1)<n){
        theGrid[i][j].attach(&theGrid[i+1][j]);
      }
      if((j-1)>=0){
        theGrid[i][j].attach(&theGrid[i][j-1]);
      }
      if((j+1)<n){
        theGrid[i][j].attach(&theGrid[i][j+1]);
      }
    }
  }//attach each grid to its neighbouring cells
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

void Grid::init(int r, int c) {
  turnOn(r,c);
}

void operator<<(Xwindow &wd, const Grid &g) {
  wd<<*(g.gd);
}//gd can be used as text display
