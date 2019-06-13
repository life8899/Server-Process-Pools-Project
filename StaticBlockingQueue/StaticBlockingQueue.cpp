#ifndef  STATIC_BLOCKING_QUEUE
#define STATIC_BLOCKING_QUEUE
/////////////////////////////////////////////////////////////////////////////////
// StaticBlockingQueue.cpp - StaticBlockingQueue class definition              //
// ver 1.0                                                                     //
// Language:    C++, Visual Studio 2017                                        //
// Platform:    HP G1 800, Windows 10                                          //
// Application: Server Process Pools Project3, CSE687 - Object Oriented Design //
// Author:      Eric Voje, Kuohsun Tsai, Chaulladevi Bavda                     //
//              ervoje@syr.edu, kutsai@syr.edu, cvbavda@syr.edu                //
/////////////////////////////////////////////////////////////////////////////////

#include"../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"


template <typename T, int n>
class StaticBlockingQueue
{
public:
	BlockingQueue<T>& getQueue() {
		return queue;
	}
private:
	static BlockingQueue<T> queue;
};

template<typename T, int n>
BlockingQueue<T> StaticBlockingQueue<T, n>::queue;


#endif 