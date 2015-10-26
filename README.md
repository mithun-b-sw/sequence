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

#### TODO:
The "lib" folder contains libCppUTest.a libCppUTestExt.a compiled one Ubuntu 15.04  
Compatiblity problem can be there with other Linux distribution, 
which you can fix by compiling these static libaries on your native system.  

