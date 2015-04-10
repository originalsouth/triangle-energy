CC=g++
triang: triang.cc
	$(CC) -Wall -Wextra -std=c++11 -O3 -flto -o triang triang.cc

clean:
	rm -f triang
