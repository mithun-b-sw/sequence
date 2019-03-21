#------------------
# CppUTest run test
#------------------

ifndef SILENCE
	#Set this to @ to keep the makefile quiet
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = sequence
CPPUTEST_HOME = ../deps/cpputest

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

SRC_DIRS = \
	../app

TEST_SRC_DIRS = \
	./src

INCLUDE_DIRS = \
	./ \
	../app \
	$(CPPUTEST_HOME)/include

CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror 
CPPUTEST_CFLAGS = -std=c89

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
