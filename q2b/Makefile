CXX=g++-5
CXXFLAGS=-std=c++14 -Werror=vla
a4q2b: GraphicDisplay.o cell.o grid.o subject.o window.o  main.o
	${CXX} ${CXXFLAGS} GraphicDisplay.o cell.o grid.o subject.o window.o main.o -o a4q2b -lX11
window.0: window.cc window.h
	${CXX} ${CXXFLAGS} -c window.cc
subject.o: subject.cc subject.h observer.h subscriptions.h
	${CXX} ${CXXFLAGS} -c subject.cc
cell.o: cell.cc cell.h GraphicDisplay.h subject.h observer.h info.h
	${CXX} ${CXXFLAGS} -c cell.cc
GraphicDisplay.o: GraphicDisplay.cc GraphicDisplay.h observer.h cell.h info.h window.h
	${CXX} ${CXXFLAGS} -c GraphicDisplay.cc
grid.o: grid.cc grid.h cell.h GraphicDisplay.h window.h
	${CXX} ${CXXFLAGS} -c grid.cc
main.o: main.cc grid.h window.h
	${CXX} ${CXXFLAGS} -c main.cc
clean:
	rm *.o a4q2b
.PHONY: clean
