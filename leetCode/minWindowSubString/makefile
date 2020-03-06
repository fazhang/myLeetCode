TARGET=$(strip $(shell basename `pwd`) )
all:
	g++ --std=c++11  -Wformat=2 ${TARGET}.cpp -o ../bin/${TARGET}
clean:
	rm -f  ../bin/${TARGET}
