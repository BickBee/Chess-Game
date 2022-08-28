CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
EXEC = chess
OBJECTS = main.o board.o piece.o king.o queen.o knight.o pawn.o rook.o bishop.o move.o player.o game.o human.o computerPlayer1.o subject.o textDisplay.o graphicDisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
