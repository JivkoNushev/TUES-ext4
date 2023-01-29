CXX = gcc
CXXFLAGS = -g -Wall
EXEC = fs

TUNE_FS = tues_tune2fs.o

OBJECTS = ${TUNE_FS}

ifeq (${OS}, Windows_NT)
	CLEAN = del
	EXEC := ${EXEC}.exe
else
	CLEAN = rm
endif

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJECTS}

tues_tune2fs.o: tues_tune2fs.c
	${CXX} ${CXXFLAGS} -c tues_tune2fs.c

clear:
	rm *.o