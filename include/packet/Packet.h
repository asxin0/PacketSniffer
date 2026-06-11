#pragma once

#include <string>
#include <vector>
#include <cstdint>

enum class LinkLayerType
{
    Ethernet,
    Unknown
};

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
        LinkLayerType linkLayerType;

        std::vector<std::uint8_t> rawBytes;

        Packet(const PacketHeader& pkthdr, const u_char* rawData, const LinkLayerType& linkLayer)
            :header(pkthdr),
             rawBytes(rawData, rawData + header.capturedLen),
             linkLayerType(linkLayer)
        {
        }
};
