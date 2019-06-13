/////////////////////////////////////////////////////////////////////
// Executive.cpp - executes test functions                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai, Chaulladevi Bavda         //
//              ervoje@syr.edu, kutsai@syr.edu, cvbavda@syr.edu    //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <thread>
#include<stdexcept>
#include <Windows.h>
#include "Executive.h"
#include "TestDriver.h"
#include "ITest.h"
#include "..\Logger\Logger.h"
#include "..\TestHarness\TestHarness.h"
#include "../Message/Message.cpp"

using std::logic_error;
using std::string;


using namespace Executive;
using namespace TestHarness;
using namespace Logging;

// Constructor
Executor::Executor()
{
	_log.write("Executor object created.\n");
}

// Destructor
Executor::~Executor()
{
}

// Function that handles execution of a TestedCode object
bool Executor::execute(TestedCode t)
{
	bool funcRet = false;
	//_log.write("Executor execution started.\n");
	Rslt::write("Executor execution started.\n");

	// Run the function within a safe try/catch block
	try {
		funcRet = (t.func() == 0);

		if (funcRet == true) {
			// Test Passed
			_log.write("Test Passed");
			if (!t.passMsg.empty())
				_log.write(t.passMsg);
		}
		else {
			// Test Failed
			_log.write("Test  Failed");
			if (!t.failMsg.empty())
				_log.write(t.failMsg);
		}
	}
	catch (const char* msg) {
		// Caught an exception
		std::cerr << msg;
		_log.write("Exception Thrown!");
		_log.write("Test Failed");
		if (!t.failMsg.empty())
			_log.write(t.failMsg);
	}

	return funcRet;
}

#ifdef TEST_EXECUTIVE

// Private test function 1 fails
bool testfunc1() {
	return false;
}

// Private test function 2 passes
bool testfunc2() {
	return true;
}

// Private test function 3 throws an exception
bool testfunc3() {
	throw "Exception thrown from testfunc3...\n";
	return true;
}

// Example code
int main()
{
	Rslt::attach(&std::cout);
	Rslt::start();
	Rslt::write("Testing Execute Package\n");

	Rslt::flush();

	// Create our TestedCode objects
	TestedCode t1((int (*)()) testfunc1);
	t1.failMsg = "Example Test 1 Failed!";
	t1.passMsg = "Example Test 1 Passed!";
	TestedCode t2((int (*)()) testfunc2);
	TestedCode t3((int (*)()) testfunc3);

	Harness th = Harness();

	th.addTest(t1);
	th.addTest(t2);
	th.addTest(t3);

	th.execute();

	Rslt::flush();

	//ITest* testDriver = TestFactory::create();

	//testDriver->addTest(t1);
	//testDriver->addTest(t2);
	//testDriver->addTest(t3);
	//testDriver->execute();

	// ToDo: Create TestHarness
	

	// Parse TestRequest XML
	
	

	// Execute tests




	

	

	//log.logMessage(log_min, "End test.")




}
#endif