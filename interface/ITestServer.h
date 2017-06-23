/*
 * ITestServer.h
 *
 *  Created on: 2017年6月23日
 *      Author: ubuntu
 */

#ifndef ITESTSERVER_H_
#define ITESTSERVER_H_

#include <utils/Log.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android{

class ITestServer :public IInterface {

public:
	DECLARE_META_INTERFACE(TestServer);

	virtual void hello() = 0;
};


class BnTestServer: public BnInterface<ITestServer>
{

public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

} //namespace android

#endif /* ITESTSERVER_H_ */
