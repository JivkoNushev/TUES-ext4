CXX = gcc
CXXFLAGS = -Wall
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

#---------------------TUNE_FS---------------------#

TUNE_DEPENDENCIES = tues_tune2fs.c file_t.h

tues_tune2fs.o: ${TUNE_DEPENDENCIES}
	${CXX} ${CXXFLAGS} -c tues_tune2fs.c


#---------------------CLEAR-----------------------#
clear:
	${CLEAN} *.o