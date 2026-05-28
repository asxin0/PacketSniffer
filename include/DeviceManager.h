#pragma once

#include <pcap.h>
#include <vector>
#include <string>
#include <iostream>

class DeviceManager
{
    public:
        pcap_if_t* DeviceLiveList();
        void DeviceLiveListPrint(pcap_if_t* devices);
};
