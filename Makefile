output: caso_1.o
	g++ caso_1.o -o output

caso_1.o: Caso_1.cpp
	g++ -c Caso_1.cpp

clean:
	rm *.o output
