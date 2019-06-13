
#include <string>
#include "TestDriver.h"
#include "Executive.h"
#include "..\Logger\Logger.h"

using namespace Executive;
using namespace Logging;

//////////////////////////
// TestDriver Functions
//////////////////////////

// TestDriver constructor
TestDriver::TestDriver()
{
	//_log.logMessage(log_verbose, "TestDriver created.");
	_nTests = 0;
}

// Add test object
void TestDriver::addTest(TestedCode t)
{
	_tests.push_back(t);
	_nTests++;
	//_log.logMessage(log_verbose, "Test added to TestDriver.");
}

// Execute all TestedCode objects held by this TestDriver
bool TestDriver::execute()
{
	int nTests = 0;
	int nPassed = 0;
	int nFailed = 0;
	bool overallResult = true;

	// Loop through each test and execute them one by one
	for (auto& test : _tests)
	{
		//_log.logMessage(log_min, "Test " + to_string(++nTests));
		bool result = _exe.execute((TestedCode) test);

		if (result)
			nPassed++;
		else
			nFailed++;

		overallResult &= result;
	}

	//_log.logMessage(log_min, "Total Tests : " + to_string(nTests));
	//_log.logMessage(log_min, "Tests Passed : " + to_string(nPassed));
	//_log.logMessage(log_min, "Tests Failed : " + to_string(nFailed));

	return overallResult;
}

// Return the number of tests this TestDriver contains
int TestDriver::nTests()
{
	return _nTests;
}
