all:
	gcc nmSort.c -o nmSort
	gcc fpSort.c -o fpSort
	g++ foSort.cpp -o foSort
	g++ ftSort.cpp -o ftSort

clean:
	rm nmSort fpSort foSort ftSort