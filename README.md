# Sequence: Abstract library to genetate sequence

This is a example project to use the "setup_CppUTest" project for unit testing.  

#### Objectives:  

This project is about building a library for sequence number generation in C program.
It uses test setup from "setup_CppUTest" project (https://github.com/mithun-b-sw/setup_CppUTest.git).
The "setup_CppUTest" project gives a bare test setup environment with CppUTest a unit testing framework for C and C++.  

#### The following are changes done to this setup:  
1. This test setup need a source folder, where the actual source files of Sequence Library goes in.
2. Adding a new folder path in make file for INCLUDE_DIRS, so that CppUTest header files should be sepearte from project related header files.

#### Key features:  
The abstract nature of the datatype used will hide the internal details is shown here.  
Handy example of test cases with use of malloc() and free().
These examples ensure memory leak proof code using CppUTest memory leak detection feature.  

### How can I use "setup_CppUTest" for a new project?

1. create a folder in a local with your project name
2. open terminal, cd to your project folder ( this uses the optional directory argument for "git clone")  
    $ git clone https://github.com/mithun-b-sw/setup_CppUTest.git .
3. make necessary changes, add to staging  
    $ git add -A
4. commit  
    $ git commit
5. this completes setting up new repository, if this need to uploaded to a different repository continue with the following steps.
6. first check "origin" name is already taken  
    $ git remote -v
7. if so, then use a different name in following command in place of "origin"  
    $ git remote add origin https://github.com/mithun-b-sw/sequence.git
8. push to "origin" only if the origin is newy cleated at 'step 7' else use same name used at 'step 7' in place of "origin"  
    $ git push -u origin master

#### TODO:
The "lib" folder contains libCppUTest.a libCppUTestExt.a compiled one Ubuntu 15.04  
Compatiblity problem can be there with other Linux distribution, 
which you can fix by compiling these static libaries on your native system.  


Known compilation errors:  
1. In case you are using latest gnu c++ compiler, you may encounter error (warning, actually) as:  
  compiling AllTests.cpp  
  In file included from <command-line>:0:0:  
  ./../deps/cpputest/include/CppUTest/MemoryLeakDetectorNewMacros.h:63:10: error: ‘void operator delete(void*, size_t)’ is a usual (non-placement) deallocation function in C++14 (or with -fsized-deallocation) [-Werror=c++14-compat]  
     void operator delete (void* mem, size_t size) UT_NOTHROW;  
          ^  
  ./../deps/cpputest/include/CppUTest/MemoryLeakDetectorNewMacros.h:64:10: error: ‘void operator delete [](void*, size_t)’ is a usual (non-placement) deallocation function in C++14 (or with -fsized-deallocation) [-Werror=c++14-compat]  
     void operator delete[] (void* mem, size_t size) UT_NOTHROW;  
          ^  
  cc1plus: all warnings being treated as errors  

    which can be temporarily fixed by commenting following lines in MemoryLeakDetectorNewMacros.h file  
    void operator delete (void* mem, size_t size) UT_NOTHROW;  
    void operator delete[] (void* mem, size_t size) UT_NOTHROW;  

