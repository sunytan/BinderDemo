/*
 * ITestServer.cpp
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */

#include "ITestServer.h"
#include <binder/Parcel.h>

namespace android{

class BpTestServer: public BpInterface<ITestServer>{

public:

	BpTestServer(const sp<IBinder>& impl)
        : BpInterface<ITestServer>(impl)
    {
    }

	void hello(){
		Parcel data, reply;
        data.writeInterfaceToken(ITestServer::getInterfaceDescriptor());
        remote()->transact(HELLO, data, &reply);
        interface_cast<ITestServer>(reply.readStrongBinder());
	}



};

IMPLEMENT_META_INTERFACE(TestServer, "android.ty.ITestServer");

status_t BnTestServer::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch (code) {
        case HELLO: {
            CHECK_INTERFACE(ITestServer, data, reply);
            hello();
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

}
