#include "packet/Packet.h"
#include "packet/PcapPacketAdapter.h"

PacketHeader PcapPacketAdapter::PcapHdrToHdr(pcap_pkthdr* pcapHeader)
{
    PacketHeader header;

    header.capturedLen = pcapHeader->caplen;
    header.originalLen = pcapHeader->len;
    header.timestampMs = pcapHeader->ts.tv_usec;
    header.timestampS = pcapHeader->ts.tv_sec;

    return header;
}
