CPPFLAGS+=-std=c++20 -O2 -Wall -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wctor-dtor-privacy  -Wnon-virtual-dtor -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo -Weffc++
.PHONY: all ctypes swig clear

all: ctypes swig

ctypes: mincode.c
	gcc -fPIC -pthread -shared $< -o libmincode.so

swig: mincode.o mincode_wrap.o
	g++ -pthread -shared $(CPPFLAGS) $^ -o _mincode.so

mincode.o: mincode.cpp
	g++ -fPIC $(CPPFLAGS) -c $< -o $@

mincode_wrap.o: mincode_wrap.cxx
	g++ -fPIC -I/usr/include/python3.8 $(CPPFLAGS) -c $< -o $@

mincode_wrap.cxx: mincode.swig
	swig -c++ -python mincode.swig

clear:
	rm -rf libctypesmincode.so libswigmincode.so mincode.py *.o *.gch *.cxx
