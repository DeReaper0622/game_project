#ifndef GRAPHIC
#define GRAPHIC
#include <iostream>
#include <vector>
#include "observer.h"
#include "cell.h"
#include "window.h"
#include "info.h"
class Cell;

class GraphicDisplay: public Observer {//same methods with TextDisplay class
    std::vector<std::vector<bool>> theGrid;  // The actual grid, use bool to indicate on or off.
    const int gridSize;    // Size of the grid.
public:
    GraphicDisplay(int n);

    void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;

    ~GraphicDisplay();

    friend void operator<<(Xwindow &wd, const GraphicDisplay &gd);
};

#endif


