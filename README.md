# Setup CppUTest in few steps  

Test Driven Development (TDD) is slowing changing the way software develped. This project deals with create a C project setup to make is easier to adapt TDD. To perform TDD we use CppUTest, which can produce unit test output compatible with XUnit test.  
The CppUTest (http://cpputest.github.io/) is a unit testing and mocking framework for C and C++.  

With this project the setup for CppUTest which is made easy and no need to install CppUTest.  
Just clone, make..!  
Add new unit test cases and continue with some project specific changes like updating makefile  

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

