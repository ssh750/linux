// VScode에서 c/cpp를 사용하기 위해서는 3개의 설정 파일이 필요
//.vscode 폴더를 생성하고 거기 아래에 있는 파일들
// https://webnautes.tistory.com/1158

#include "testFunction_1.h"

int a(1);

int main()
{
    testFunction_1(a);
    return 0;
}


/*
터미널 컴파일 g++ -o helloworld helloworld.cpp 

make https://www.tuwlab.com/ece/27193 
make에서의 변수 사용 방법은 쉘스크립트 변수 사용법과 동일
Make를 기술한 파일 Makefile은 쉘명령이 순차적으로 실행함. 
target : dependency
      recipe  이 3개의 빌드블록으로 구성됨. 
ex. 
app.out: main.o foo.o bar.o
    gcc -o app.out main.o foo.o bar.o 
main.o: foo.h bar.h main.c
    foo.o: foo.h foo.c
    bar.o: bar.h bar.c

CC=<컴파일러>
CFLAGS=<컴파일 옵션>
LDFLAGS=<링크 옵션>
LDLIBS=<링크 라이브러리 목록>
OBJS=<Object 파일 목록>
TARGET=<빌드 대상 이름>
 
all: $(TARGET)
 
clean:
    rm -f *.o
    rm -f $(TARGET)
 
$(TARGET): $(OBJS)
$(CC) -o $@ $(OBJS)

$@: 현재 Target 이름
$^: 현재 Target이 의존하는 대상들의 전체 목록
$?: 현재 Target이 의존하는 대상들 중 변경된 것들의 목록

위의 내용은 변수를 사용하면 아래와 같이 변경됨
CC=gcc
CFLAGS=-g -Wall
OBJS=main.o foo.o bar.o
TARGET=app.out
 
$(TARGET): $(OBJS)
    $(CC) -o $@ $(OBJS)
 
main.o: foo.h bar.h main.c
foo.o: foo.h foo.c
bar.o: bar.h bar.c
clean:
    rm -f *.o
    rm -f $(TARGET)

CMake : makefile을 쉽게 만드는 툴 (Clion IDE 등 여러 IDE에서 사용 가능)
Make보다 추상화된 상위 레벨의 빌드시스템 

CC -- the C compiler to use
CXX -- the C++ compiler to use
LD -- the linker to use
CFLAGS -- compilation flag for C source files
CXXFLAGS -- compilation flags for C++ source files
CPPFLAGS -- flags for the c-preprocessor (typically include file paths and symbols defined on the command line), used by C and C++
LDFLAGS -- linker flags
LDLIBS -- libraries to link

*/