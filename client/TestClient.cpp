/*
 * TestClient.cpp
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */

#include "ITestServer.h"
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

using namespace android;

int main(int argc, char* argv[]){
    ALOGD("test client start");
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> b;
    sp<ITestServer> sTestServer;

    do{
        b = sm->getService(String16("ty.testserver"));
        if(b!=0) break;
        ALOGE("TestService is not working, waiting...");
        usleep(500000);
    }while(true);

    sTestServer = interface_cast<ITestServer>(b);
    sTestServer->hello();

    ALOGE("Client start end");
    return 0;

}

