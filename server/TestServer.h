/*
 * TestServer.h
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */
#define LOG_TAG "tanyang"

#ifndef TESTSERVER_H_
#define TESTSERVER_H_

#include <utils/Log.h>
#include "ITestServer.h"

namespace android{

enum{
	HELLO = IBinder::FIRST_CALL_TRANSACTION,
};

class TestServer: public BnTestServer{

public:
	static  void instantiate();
	void hello();

private:
	TestServer();
	virtual ~TestServer();
};

}

#endif /* TESTSERVER_H_ */

