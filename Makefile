.PHONY : test clean distclean

test : deps/cpputest/lib/libCppUTest.a
	cd ./test ; make test

deps/cpputest/lib/libCppUTest.a : deps/cpputest/configure
	cd ./deps/cpputest && ./configure && make

deps/cpputest/configure : deps/cpputest/autogen.sh
	cd ./deps/cpputest && ./autogen.sh

# fix this by making use of git submodule
deps/cpputest/autogen.sh : deps
	cd ./deps && git clone git://github.com/cpputest/cpputest.git cpputest

deps:
	mkdir -p deps

clean :
	cd ./test ; make clean

distclean :
	cd ./deps/cpputest ; make distclean
	make clean

# TODO: add targets to perform code coverage using gcov
