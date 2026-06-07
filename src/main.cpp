#include "capture/DeviceManager.h"
#include "capture/CaptureDevice.h"
#include "capture/PacketSniffer.h"

#include <iostream>

int main ()
{
    DeviceManager device;
    const std::string selectedDevice = device.SelectDevice();

    if (selectedDevice == "")
    {
        return 1;
    }

    CaptureDevice captureDev(selectedDevice);

    if (!captureDev.Open())
    {
        return 1;
    }

    PacketStorage storageSys;

    PacketSniffer sniffer(captureDev, storageSys);
    sniffer.CaptureLoop();

    std::cout << storageSys.getSize();

    captureDev.Close();

    return 0;
}
