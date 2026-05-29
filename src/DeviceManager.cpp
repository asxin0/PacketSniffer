#include "DeviceManager.h"

#include <pcap.h>
#include <vector>
#include <string>
#include <iostream>

pcap_if_t* DeviceManager::LiveList()
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

std::vector<std::string> DeviceManager::LiveListPrint(pcap_if_t* devices)
{
    std::vector<std::string> deviceList {};

    while (devices != nullptr)
    {
        std::cout << devices->name << "\n";
        deviceList.push_back(devices->name);

        devices = devices->next;
    }

    return deviceList;
}

const std::string DeviceManager::SelectDevice()
{
    pcap_if_t* devices = LiveList();

    if (devices == nullptr)
    {
        return "";
    }

    std::vector<std::string> deviceList = LiveListPrint(devices);

    while (true)
    {
        std::string selectedDevice;
        std::cout << "\nWhich device do you wish to capture with: ";
        std::getline(std::cin, selectedDevice);

        for (size_t i = 0; i < deviceList.size(); i++)
        {
            if (selectedDevice == deviceList[i])
            {
                pcap_freealldevs(devices);
                return selectedDevice;
            }
        }

        std::cout << "Invalid device.";
    }
}
