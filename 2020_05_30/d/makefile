SOURCE = src.cpp
TARGET = proj
MAKEFILE = makefile
CXX = g++
CXX_VERSION = -std=c++17
CXX_OPTION = -O

${TARGET} : ${SOURCE} ${MAKEFILE}
	${CXX} ${CXX_VERSION} ${CXX_OPTION} -o ${TARGET} ${SOURCE}

run :
	./proj

clean :
	rm ${TARGET}
