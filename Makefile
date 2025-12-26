main.exe: P3/o-files/16.o P3/o-files/17.o P3/o-files/18.o \
			P3/o-files/19.o P3/o-files/20.o \
			\
			P2/o-files/11.o P2/o-files/12.o P2/o-files/13.o \
			P2/o-files/14.o P2/o-files/15.o \
			\
			P1/o-files/1.o \
			P1/o-files/3.o \
			P1/o-files/4.o \
			P1/o-files/5.o \
			P1/o-files/6.o \
			P1/o-files/7.o \
			P1/o-files/9.o 
	g++ main.cpp p3/o-files/* p2/o-files/* p1/o-files/* -o main.exe

P3/o-files/16.o: P3/16.cpp
	g++ -c P3/16.cpp -o P3/o-files/16.o

P3/o-files/17.o: P3/17.cpp
	g++ -c P3/17.cpp -o P3/o-files/17.o

P3/o-files/18.o: P3/18.cpp
	g++ -c P3/18.cpp -o P3/o-files/18.o

P3/o-files/19.o: P3/19.cpp
	g++ -c P3/19.cpp -o P3/o-files/19.o

P3/o-files/20.o: P3/20.cpp
	g++ -c P3/20.cpp -o P3/o-files/20.o




P2/o-files/11.o: P2/11.cpp
	g++ -c P2/11.cpp -o P2/o-files/11.o

P2/o-files/12.o: P2/12.cpp
	g++ -c P2/12.cpp -o P2/o-files/12.o

P2/o-files/13.o: P2/13.cpp
	g++ -c P2/13.cpp -o P2/o-files/13.o

P2/o-files/14.o: P2/14.cpp
	g++ -c P2/14.cpp -o P2/o-files/14.o

P2/o-files/15.o: P2/15.cpp
	g++ -c P2/15.cpp -o P2/o-files/15.o



P1/o-files/1.o: P1/1.cpp
	g++ -c P1/1.cpp -o P1/o-files/1.o

P1/o-files/2.o: P1/2.cpp
	g++ -c P1/2.cpp -o P1/o-files/2.o

P1/o-files/3.o: P1/3.cpp
	g++ -c P1/3.cpp -o P1/o-files/3.o

P1/o-files/4.o: P1/4.cpp
	g++ -c P1/4.cpp -o P1/o-files/4.o

P1/o-files/5.o: P1/5.cpp
	g++ -c P1/5.cpp -o P1/o-files/5.o




P1/o-files/6.o: P1/6.cpp
	g++ -c P1/6.cpp -o P1/o-files/6.o

P1/o-files/7.o: P1/7.cpp
	g++ -c P1/7.cpp -o P1/o-files/7.o

P1/o-files/8.o: P1/8.cpp
	g++ -c P1/8.cpp -o P1/o-files/8.o

P1/o-files/9.o: P1/9.cpp
	g++ -c P1/9.cpp -o P1/o-files/9.o

P1/o-files/10.o: P1/10.cpp
	g++ -c P1/10.cpp -o P1/o-files/10.o