#include "DeviceManager.h"

#include <pcap.h>
#include <vector>
#include <string>
#include <iostream>

pcap_if_t* DeviceManager::DeviceLiveList()
{
    pcap_if_t* allDevices;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&allDevices, errbuf) == -1)
    {
        std::cerr << "Big fat error";
        return nullptr;
    }

    return allDevices;
}

void DeviceManager::DeviceLiveListPrint(pcap_if_t* devices)
{
    while (devices != nullptr)
    {
        std::cout << devices->name << "\n";
        devices = devices->next;
    }
}
