#ifndef ITEST_H
#define ITEST_H
/////////////////////////////////////////////////////////////////////
// ITest.h - Abstract class for handling test objects              //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

namespace Executive
{
	// Class that holds individual test functions
	struct TestedCode {
	public:
		TestedCode(int (*func)())
		{
			this->func = func;
		}
		~TestedCode() {}

		std::string passMsg = "";
		std::string failMsg = "";
		int (*func)() = 0;
	};

	// Generic Test object
	struct ITest
	{
		virtual ~ITest() {}

		virtual void addTest(TestedCode t) = 0;
		virtual bool execute() = 0;
		virtual int nTests() = 0;
	}; 

	// Factory that crates abstract ITest objects
	struct TestFactory
	{
		static ITest* create();
	};
}

#endif