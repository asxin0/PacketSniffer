#pragma once

#include "Packet.h"

#include <pcap.h>
#include <string>
#include <vector>

class PacketStorage
{
    private:
        std::vector<Packet> packetsCaptured{};

    public:
        bool addPacket(const Packet& packet);
        size_t getSize();
};
