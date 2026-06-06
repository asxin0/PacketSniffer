#include <Packet.h>

#include "Packet.h"
#include "capture/PacketStorage.h"

#include <string>
#include <vector>
#include <iostream>

bool PacketStorage::addPacket(const Packet& packet)
{
    size_t vectorSize = packetsCaptured.size();

    packetsCaptured.push_back(packet);

    if (vectorSize + 1 == packetsCaptured.size())
    {
        return true;
    }

    return false;
}

size_t PacketStorage::getSize()
{
    return packetsCaptured.size();
}
