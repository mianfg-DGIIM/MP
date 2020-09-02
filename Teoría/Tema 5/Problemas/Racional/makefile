DIRNAME=Racional

$(DIRNAME).exec: main.o $(DIRNAME).o
	g++ -o $(DIRNAME).exec main.o $(DIRNAME).o

main.o: main.cpp
	g++ -I./ -c main.cpp

$(DIRNAME).o: $(DIRNAME).cpp $(DIRNAME).h
	g++ -I./ -c $(DIRNAME).cpp
clean:
	rm -rf *.o *.exec