/*
 * TestServer.cpp
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */

#include "TestServer.h"
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>

namespace android{

void TestServer::instantiate(){
		ALOGD("instantiate");
	    defaultServiceManager()->addService(
	            String16("ty.testserver"), new TestServer());
}

TestServer::TestServer() {
	// TODO Auto-generated constructor stub
	ALOGD("TestServer Create");
}

TestServer::~TestServer() {
	// TODO Auto-generated destructor stub
	ALOGD("TestServer Destroy");
}


void TestServer::hello(){
	ALOGD("Hello");
}

}
