#pragma once

#include "packet/Packet.h"

#include <iostream>
#include <vector>
#include <string>
#include <optional>

class EthernetHeader
{
    uint8_t macOrigin[6];
    uint8_t macDestination[6];
    uint16_t etherType;
};

class EthernetLayer
{
    public:
        static std::optional<EthernetHeader> Parse(Packet& Packet);
};
