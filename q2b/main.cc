#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  Xwindow wd;//create a Xwindow object
  int moves = 0;

  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n);
      }
      else if (cmd == "init") {
        int r=0,c=0;
        cin>>r>>c;
        while(r>-1 && c>-1){
          g.init(r,c);
          cin>>r>>c;
        }
        wd << g;//print the grid on Xwindow
      }
      else if (cmd == "game") {
        cin >> moves;
        if(moves!=1) {
          cout << moves << " moves left" << endl;
        }
        else{
          cout << moves << " move left" << endl;
        }
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r,c);
        if(g.isWon()){
          cout<<"Won"<<endl;
          return 0;
        }//check isWon every switch
        wd<<g;//print the new game on the Xwindow
        moves--;
        if(moves!=1) {
          cout << moves << " moves left" << endl;
        }
        else{
          cout << moves << " move left" << endl;
        }
        if (moves==0){
          if (g.isWon()){
            cout<<"Won"<<endl;
            break;
          }
          else{
            cout<<"Lost"<<endl;
            break;
          }
        }
      }
    }
  }//basically same code as q2a, because graphic display is implemented similarly as Text Display
  catch (ios::failure &) {
  }
}
