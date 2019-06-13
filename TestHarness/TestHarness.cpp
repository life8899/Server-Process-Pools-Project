/////////////////////////////////////////////////////////////////////
// TestHarness.cpp - Handler for executing function tests          //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "TestHarness.h"
#include "..\Logger\Logger.h"
#include "..\Executive\Executive.h"
#include "..\Executive\ITest.h"
#include "..\Executive\TestDriver.h"

using namespace TestHarness;
using namespace Executive;
using namespace Logging;

/////////////////////////////////////////////////////////////////////
//
//    Harness Function Definitions
//
/////////////////////////////////////////////////////////////////////

// Execute any tests held by this harness
bool Harness::execute()
{
	_log.write("Executing tests.");
	bool result = _testDriver->execute();
	_log.write("Execution completed.");
	return result;
}

// Parse XML file for test instructions
void Harness::parseTestXML(std::string path)
{
	std::ifstream fp(path, std::ifstream::in);
	std::string line;

	// Open file
	if (!fp.is_open())
	{
		// Open failed
		_log.write("Failed to open file at: " + path);
		return;
	}

	// Read XML file
	bool testfound = false;
	bool exefound = false;
	std::string testfile = "";
	std::string libpath = "";

	while (std::getline(fp, line))
	{
		// Look for <TestRequest> tag
		if (!testfound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("TestRequest"))
			{
				// Found TestRequest object
				testfound = true;
			}
		}
		
		// Look for <exe> tag
		if (testfound && !exefound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("exe"))
			{
				// Found exe
				exefound = true;
				testfile = line.substr(line.find(">") + 1, line.rfind("<"));
			}
		}

		// Look for libraries or close brackets
		if (testfound && exefound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("/TestRequest"))
			{
				//TestedCode t();
				//_testDriver->addTest(t);

				testfound = false;
				exefound = false;
			}
		}
	}

	fp.close();
}

// Add TestedCode object
void Harness::addTest(TestedCode t)
{
	_testDriver->addTest(t);
}

// Create new TestHarness object
Harness::Harness()
{
	_log.write("Created new TestHarness.\n");
	_testDriver = TestFactory::create();
}

// Create new TestHarness object
Harness::~Harness()
{
	delete _testDriver;
}

#ifdef TEST_TESTHARNESS

int main()
{
	//Log log(&cout, log_verbose);
	Logger& log = StaticLogger<1>::instance();
	log.attach(&std::cout);
	log.start();
	log.write("Testing TestHarness functions.");

	Harness th = Harness();

	th.parseTestXML("");

	bool result = th.execute();

	if (result)
		log.write("Test Passed!");
	else
		log.write("Test Failed.");

	log.write("End test.");
}

#endif

