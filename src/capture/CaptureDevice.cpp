#include <capture/CaptureDevice.h>

#include <pcap.h>
#include <iostream>
#include <vector>
#include <string>

CaptureDevice::CaptureDevice(const std::string selectedName)
    :deviceName(selectedName)
{
}

bool CaptureDevice::Open()
{
    const char* device = deviceName.c_str();

    handle = pcap_open_live (
        device,
        65536,
        1,
        1000,
        errbuf
    );

    if (handle == nullptr)
    {
        std::cerr << "Big fat error" << errbuf << "\n";
        return false;
    }

    return true;
}

void CaptureDevice::Close()
{
    if (handle != nullptr)
    {
        pcap_close(handle);
        handle = nullptr;
    }
}

pcap_t* CaptureDevice::HandleGetter() const
{
    return handle;
}
