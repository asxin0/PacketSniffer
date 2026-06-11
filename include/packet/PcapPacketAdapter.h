#pragma once

#include "Packet.h"

#include <pcap.h>

class PcapPacketAdapter
{
    public:
        static PacketHeader PcapHdrToHdr(pcap_pkthdr* pcapHeader);
        static LinkLayerType toLinkLayer(int pcap);
};
