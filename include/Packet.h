#pragma once

#include <pcap.h>
#include <string>
#include <vector>
#include <cstdint>

class Packet
{
    public:
        timeval timestamp;
        std::uint32_t originalLen;
        std::uint32_t capturedLen;
        std::vector<u_char> rawBytes;

        Packet(pcap_pkthdr* header, const u_char* rawData)
            :timestamp(header->ts),
             originalLen(header->len),
             capturedLen(header->caplen),
             rawBytes(rawData, rawData + header->caplen)
        {
        }


};
