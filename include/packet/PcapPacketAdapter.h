#pragma once

#include "Packet.h"

#include <pcap.h>

class PcapPacketAdapter
{
    public:
        PacketHeader PcapHdrToHdr(pcap_pkthdr* pcapHeader);
};
