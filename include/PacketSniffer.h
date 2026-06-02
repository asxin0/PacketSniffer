#pragma once

#include "CaptureDevice.h"

#include <pcap.h>
#include <string>
#include <iostream>
#include <vector>

class PacketSniffer
{
    private:
        char errbuf[PCAP_ERRBUF_SIZE];
        const CaptureDevice& device;

    public:
        PacketSniffer(CaptureDevice& captureDevice);

        void CaptureLoop();
};
