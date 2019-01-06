TestPoly: TestPoly.o Poly.o
	g++ -g $^ -o $@

Poly.o: Poly.cpp Poly.h
	g++ -g -c -Wall -pedantic $< -o $@

TestPoly.o: TestPoly.cpp Poly.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Poly.o TestPoly.o TestPoly