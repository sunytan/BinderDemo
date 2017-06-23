#BinderDemo
学习Binder通讯的一个实例

1，Client 端
2，Interface：
BpTestServer, 同时实现实现BpInterface 和ITestServer接口
BnTestServer：
(service端需要实现继承实现 BnTestService 接口)



流程如下：

Client端  通过调用ITestServer接口（实际由BpTestServer接口实现）的hello方法。
hello方法中通过remote()->transact(); 
实际调用BpBinder->transact方法
实际由IPCThreadState::self()->transact
再到  IPCThreadState中的 waitForResponse 
再到  IPCThreadState中的 executeCommand 
在其case：BR_TRANSACTION 中
实际由                    error = reinterpret_cast<BBinder*>(tr.cookie)->transact(tr.code, buffer,
                            &reply, tr.flags);


status_t BBinder::transact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    data.setDataPosition(0);

    status_t err = NO_ERROR;
    switch (code) {
        case PING_TRANSACTION:
            reply->writeInt32(pingBinder());
            break;
        default:
            err = onTransact(code, data, reply, flags); //实际调用BnTestServer的 onTransact方法。
            break;
    }


BnTestServer中调用 hello 方法，hello 方法实际由 TestServer实现
实际调用到了Server端的方法

总：

Client  --> BpInterface  --> BnXXXServer  --> XXXServer



