#pragma once

#include "packet/Packet.h"

#include <vector>

class PacketStorage
{
    private:
        std::vector<Packet> packetsCaptured{};

    public:
        bool addPacket(const Packet& packet);
        size_t getSize();
};
