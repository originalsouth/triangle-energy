CC=g++
triang: triang.cc
	swig -c++ -python triang.i
	$(CC) -Wall -Wextra -O3 -fPIC -flto -c triang.cc
	$(CC) -Wall -Wextra -O3 -fPIC -flto -c triang_wrap.cxx -I/usr/include/python2.7
	$(CC) -shared triang.o triang_wrap.o -o _triang.so

clean:
	rm -f triang.o
	rm -f triang_wrap.cxx
	rm -f triang_wrap.o
	rm -f _triang.so
	rm -f triang.py
	rm -f *.pyc
