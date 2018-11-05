all: main bound zone zone_set

main:
	g++ tests-main.cpp -c -std=c++14 -fPIC

bound:
	g++ tests-main.o tests-bound.cpp -o tests -std=c++14 -fPIC
	./tests -r compact

zone:
	g++ tests-main.o tests-zone.cpp -o tests -std=c++14 -fPIC
	./tests -r compact

zone_set:
	g++ tests-main.o tests-zone-set.cpp -o tests -std=c++14 -fPIC
	./tests -r compact

clean:
	rm -rf tests