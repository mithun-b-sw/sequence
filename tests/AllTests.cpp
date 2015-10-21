#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

int main(int ac, const char** av)
{
	/* These checks are here to make sure assertions outside test runs don't crash */
	CHECK(true);
	LONGS_EQUAL(1, 1);

	return CommandLineTestRunner::RunAllTests(ac, av);
}

#include "AllTests.h"

/**
 * To compile the git master node's zip file 
 * from : https://github.com/cpputest/cpputest
 * needs to run
 * --> $ ./autogen.sh
 * to generate "configure" file and there was a problem ( --> https://github.com/kergoth/tslib/issues/30 )
 * in "configure.ac" which is needed for "autogen.sh" file.
 *
 * The zip file "cpputest-3.7.1.zip" download from "http://cpputest.github.io/"
 * This do not need to run "autogen.sh" so "./configure" command directly works.
 *
 */
