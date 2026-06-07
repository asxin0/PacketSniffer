#pragma once

#include <iostream>
#include <vector>
#include <string>

class EthernetHeader
{
    uint8_t macOrigin[6];
    uint8_t macDestination[6];
    uint16_t etherType;
};

class EthernetLayer
{
};
