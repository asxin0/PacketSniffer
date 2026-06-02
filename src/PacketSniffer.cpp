#include "PacketSniffer.h"

#include <pcap.h>
#include <iostream>
#include <vector>
#include <string>

PacketSniffer::PacketSniffer(CaptureDevice& CaptureDevice)
    :device(CaptureDevice)
{
}

void PacketSniffer::CaptureLoop()
{
    int packetsSniffed = 0;
    pcap_t* handle = device.HandleGetter();

    while (packetsSniffed < 10)
    {
        pcap_pkthdr* header = nullptr;
        const unsigned char* packetData = nullptr;

        int result = pcap_next_ex(handle, &header, &packetData);

        if (result == 1)
        {
            std::cout << "Captured len: " << header->caplen
                      << "\nwtf is this: " << header->comment
                      << "\nOrginal len: " << header->len
                      << "\n" << header->ts.tv_sec << "."
                      << header->ts.tv_usec << "\n\n";

            packetsSniffed++;
        }
        else if (result == -1)
        {
            std::cerr << "Big fat error";
            break;
        }
    }
}
