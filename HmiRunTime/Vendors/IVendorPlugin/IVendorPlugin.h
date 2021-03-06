#ifndef IDEVICEPLUGIN_H
#define IDEVICEPLUGIN_H

#include "../../HmiRunTime/Port/IPort.h"
#include "../../HmiRunTime/Tag/IOTag.h"
#include <QStringList>


/*
* 注意本类不要派生自QObject
*/
class IVendorPlugin
{
public:
    virtual ~IVendorPlugin() {}

    // 初始化设备
    virtual bool initailizeDevice(void* pObj) = 0;
    // 连接设备
    virtual bool connectDevice(void* pObj) = 0;
    // 断开设备连接
    virtual bool disconnectDevice(void* pObj) = 0;
    // 反初始化设备
    virtual bool unInitailizeDevice(void* pObj) = 0;

    // 写变量前处理
    virtual bool beforeWriteIOTag(IOTag* pTag) = 0;
    // 写变量
    virtual int writeIOTag(IPort *pPort, IOTag* pTag) = 0;
    // 写变量后处理
    virtual bool afterWriteIOTag(IOTag* pTag) = 0;

    // 读变量前处理
    virtual bool beforeReadIOTag(IOTag* pTag) = 0;
    // 读变量
    virtual int readIOTag(IPort *pPort, IOTag* pTag) = 0;
    // 读变量后处理
    virtual bool afterReadIOTag(IOTag* pTag) = 0;
};


QT_BEGIN_NAMESPACE

#define DevicePluginInterface_iid "HmiRunTime.Device.PluginInterface"
Q_DECLARE_INTERFACE(IVendorPlugin, DevicePluginInterface_iid)

QT_END_NAMESPACE

#endif // IDEVICEPLUGIN_H
