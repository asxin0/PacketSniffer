#pragma once

#include "packet/Packet.h"
#include "EthernetLayer.h"

#include <string>
#include <vector>

enum class Protocol
{
    Ethernet,
    IPV4,
    IPV6,
    ARP,
    TCP,
    UDP,
    ICMP,
    Payload,
    Unknown,
    Parsed
};

struct PacketState
{
    Packet& packet;
    size_t contextOffset;
    Protocol currentProtocol;
};

class PacketParser
{
    public:
        PacketState createPacketState(Packet& packet);
        bool paraseNextLayer(PacketState& state);
};
