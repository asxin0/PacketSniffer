#include "DeviceManager.h"
#include "CaptureDevice.h"
#include "PacketSniffer.h"

#include <iostream>

int main ()
{
    DeviceManager device;
    const std::string selectedDevice = device.SelectDevice();

    if (selectedDevice == "")
    {
        std::cerr << "Big fat error";
        return 1;
    }

    CaptureDevice captureDev(selectedDevice);

    if (!captureDev.Open())
    {
        std::cerr << "Big fat error";
        return 1;
    }

    PacketSniffer sniffer(captureDev);
    sniffer.CaptureLoop();

    return 0;
}
