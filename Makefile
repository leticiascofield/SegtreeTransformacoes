CC=g++
CFLAGS= -Wall -g

TARGET= ./bin/tp3.out
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/Matriz.o ${OBJ_DIR}/SegTree.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/Matriz.o: ${INCLUDE_DIR}/Matriz.hpp ${SRC_DIR}/Matriz.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Matriz.cpp -o ${OBJ_DIR}/Matriz.o

${OBJ_DIR}/SegTree.o: ${INCLUDE_DIR}/Matriz.hpp ${INCLUDE_DIR}/SegTree.hpp ${SRC_DIR}/SegTree.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/SegTree.cpp -o ${OBJ_DIR}/SegTree.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Matriz.hpp ${INCLUDE_DIR}/SegTree.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./tp3.out

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}