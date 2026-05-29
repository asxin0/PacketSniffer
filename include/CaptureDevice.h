#pragma once

#include <pcap.h>
#include <vector>
#include <string>
#include <iostream>

class CaptureDevice
{
    private:
        const std::string deviceName;
        pcap_t* handle = nullptr;
        char errbuf[PCAP_ERRBUF_SIZE];

    public:
        CaptureDevice(const std::string selectedName);

        void Open();
        void Close();
};
