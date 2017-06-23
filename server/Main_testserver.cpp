/*
 * Main_testserver.cpp
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */

#include "TestServer.h"
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

using namespace android;


int main(int argc, char* argv[]){

    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm(defaultServiceManager());
    ALOGI("ServiceManager: %p", sm.get());
    TestServer::instantiate();
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

}
