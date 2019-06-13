#ifndef TESTHARNESS_H
#define TESTHARNESS_H

/////////////////////////////////////////////////////////////////////
// TestHarness.h - Handler for executing function tests            //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The TestHarness package provides the Harness object which handles the
* execution of test functions in a safe environment. The Harness object
* also creates a Log object that will print messages to the log.
*
* Maintenance History:
* --------------------
* Version 1.0:
*   Initial version. Harness object executes functions in a try-catch block.
*
* Version 2.0:
* 
*/

#include <string>

#include "..\Logger\Logger.h"
#include "..\Executive\Executive.h"
#include "..\Executive\ITest.h"
#include "..\Executive\TestDriver.h"

namespace TestHarness
{
	// Object that contains all of the information to execute our function under test
	class Harness {
	public:
		bool execute();
		void parseTestXML(std::string path);
		void addTest(Executive::TestedCode t);

		// Constructors
		Harness();
		~Harness();

	private:
		Logging::Logger& _log = Logging::StaticLogger<1>::instance();
		Executive::ITest* _testDriver;
	};
}

#endif