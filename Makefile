CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
# -pedantic-errors : ANSI C89 표준의 모든 오류 메시지 표시
# Wall : 모호한 코딩에 경고 출력
# Werror : 경고 발생시 컴파일 중단
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := helloworld

INCLUDE  := -I./incxxx/
# g++ compile 옵션
# 1) -l 옵션 : 헤더 파일 경로 옵션 (ex. -I/usr/include)
# 2) -include 옵션 : 헤더 파일을 소스내에 추가할 때 사용한다.

SRC      :=  $(wildcard src/*.cpp) 
#testFunction_1.cpp helloworld.cpp
# wildcard 함수는 옆의 경로에서 해당 형식의 파일들을 불러온다.

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*