#pragma once

#include "CaptureDevice.h"
#include "PacketStorage.h"

#include <pcap.h>
#include <string>
#include <iostream>
#include <vector>

class PacketSniffer
{
    private:
        char errbuf[PCAP_ERRBUF_SIZE];
        const CaptureDevice& device;
        PacketStorage& storage;

    public:
        PacketSniffer(CaptureDevice& captureDevice, PacketStorage& storage);

        void CaptureLoop();
};
