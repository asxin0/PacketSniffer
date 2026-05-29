#pragma once

#include <pcap.h>
#include <vector>
#include <string>
#include <iostream>

class DeviceManager
{
    public:
        pcap_if_t* LiveList();
        std::vector<std::string> LiveListPrint(pcap_if_t* devices);
        const std::string SelectDevice();
};
