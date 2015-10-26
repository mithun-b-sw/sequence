#------------------
# CppUTest run test
#------------------

ifndef SILENCE
	#Set this to @ to keep the makefile quiet
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = sequence
CPPUTEST_HOME = .

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

SRC_DIRS = src

TEST_SRC_DIRS = tests

INCLUDE_DIRS = \
	include/sequence \
	$(CPPUTEST_HOME)/include

CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror 
CPPUTEST_CFLAGS = -std=c89

include $(CPPUTEST_HOME)/MakefileWorker.mk
