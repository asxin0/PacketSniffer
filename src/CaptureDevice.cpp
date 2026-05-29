#include <CaptureDevice.h>

#include <pcap.h>
#include <iostream>
#include <vector>
#include <string>

CaptureDevice::CaptureDevice(const std::string selectedName)
    :deviceName(selectedName)
{
}

void CaptureDevice::Open()
{
}
