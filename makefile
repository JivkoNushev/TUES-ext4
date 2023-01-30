CXX = gcc
CXXFLAGS = -Wall
EXEC = fs

TUNE_FS = tues_tune2fs.o file_sys_t.o wrapper_functions.o utils.o

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

TUNE_DEPENDENCIES = tues_tune2fs.c file_sys_t.h utils.h wrapper_functions.h

tues_tune2fs.o: ${TUNE_DEPENDENCIES}
	${CXX} ${CXXFLAGS} -c tues_tune2fs.c


#----------------------FILE_T---------------------#

FILE_SYS_T_DEPENDENCIES = file_sys_t.c file_sys_t.h

file_sys_t.o: ${FILE_SYS_T_DEPENDENCIES}
	${CXX} ${CXXFLAGS} -c file_sys_t.c


#---------------WRAPPER_FUNCTIONS-----------------#

WRAPPER_FUNCTIONS_DEPENDENCIES = wrapper_functions.c wrapper_functions.h

wrapper_functions.o: ${WRAPPER_FUNCTIONS_DEPENDENCIES}
	${CXX} ${CXXFLAGS} -c wrapper_functions.c

#----------------------UTILS---------------------#

UTILS_DEPENDENCIES = utils.c utils.h

utils.o: ${UTILS_DEPENDENCIES}
	${CXX} ${CXXFLAGS} -c utils.c	


#---------------------CLEAR-----------------------#
clear:
	${CLEAN} *.o