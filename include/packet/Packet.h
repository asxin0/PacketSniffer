#pragma once

#include <string>
#include <vector>
#include <cstdint>

struct PacketHeader
{
    std::uint64_t timestampS;
    std::uint32_t timestampMs;
    std::uint32_t originalLen;
    std::uint32_t capturedLen;
};

class Packet
{
    public:
        PacketHeader header;
        std::vector<std::uint8_t> rawBytes;

        Packet(const PacketHeader& pkthdr, const u_char* rawData)
            :header(pkthdr),
             rawBytes(rawData, rawData + header.capturedLen)
        {
        }
};
