objects :=  P3/16.o \
			P3/17.o \
			P3/18.o \
			P3/19.o \
			P3/20.o \
			P2/11.o \
			P2/12.o \
			P2/13.o \
			P2/14.o \
			P2/15.o \
			P1/1.o \
			P1/3.o \
			P1/4.o \
			P1/5.o \
			P1/6.o \
			P1/7.o \
			P1/9.o

main.exe: $(objects) main.cpp
	g++ $^ -o main.exe

$(objects): %.o : %.cpp
	g++ -c $^ -o $@

clean:
	rm P1/*.o
	rm P2/*.o
	rm P3/*.o