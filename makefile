
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = ArtifactItem.o ArtifactSpace.o BlankSpace.o EmptySpace.o ExitSpace.o Game.o Gem.o inputValidate.o Item.o main.o menus.o MummySpace.o OrnamentSpace.o Player.o ShopSpace.o Space.o TheEye.o TheMap.o TheTent.o

SRCS = ArtifactItem.cpp ArtifactSpace.cpp BlankSpace.cpp EmptySpace.cpp ExitSpace.cpp Game.cpp Gem.cpp inputValidate.cpp Item.cpp main.cpp menus.cpp MummySpace.cpp OrnamentSpace.cpp Player.cpp ShopSpace.cpp Space.cpp TheEye.cpp TheMap.cpp TheTent.cpp

HEADERS = ArtifactItem.hpp ArtifactSpace.hpp BlankSpace.hpp EmptySpace.hpp ExitSpace.hpp Game.hpp Gem.hpp inputValidate.hpp Item.hpp menus.hpp MummySpace.hpp OrnamentSpace.hpp Player.hpp ShopSpace.hpp Space.hpp TheEye.hpp TheMap.hpp TheTent.hpp

finalProject: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o finalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o
