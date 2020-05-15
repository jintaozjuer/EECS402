proj2.exe: proj2.o ColorClass.o ColorImageClass.o RowColumnClass.o
	g++ proj2.o ColorClass.o ColorImageClass.o RowColumnClass.o -o proj2.exe

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.o	
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

clean:
	rm -f proj2.o ColorClass.o ColorImageClass.o RowColumnClass.o