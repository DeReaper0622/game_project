#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "GraphicDisplay.h"
#include "window.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.
  GraphicDisplay *gd; // The graphic display. It can be treated as TextDisplay
  // Add private members, if necessary.

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();
  

  bool isWon() const; // Call to determine if grid is in a winning state.
  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);  // Switches cell at (r, c) between On and Off.
  void init(int r, int c);
  friend void operator<<(Xwindow &wd, const Grid &g);
};

#endif
