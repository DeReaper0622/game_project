#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
  Info the_info {r,c,isOn};//construct a info object with all of the cell status and returns it
  return the_info;
}

void Cell::setOn() {//set the cell on during the initialization
  isOn = true;
  notifyObservers(SubscriptionType::All);//since it is set on, therefore does not notify the neighbouring cells
}

void Cell::toggle() {//switch the cell during game
  if (isOn){
    isOn=false;
  }
  else{
    isOn=true;
  }
  notifyObservers(SubscriptionType::All);
  notifyObservers(SubscriptionType::SwitchOnly);//notify all observers
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
  if (isOn){
    isOn=false;
  }
  else{
    isOn=true;
  }
  notifyObservers(SubscriptionType::All);//neighbouring cell is switched, switch but do not notify neighbour cells
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
