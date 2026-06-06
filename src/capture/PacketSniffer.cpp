#include "capture/PacketSniffer.h"
#include "Packet.h"

#include <pcap.h>
#include <iostream>
#include <vector>
#include <string>

PacketSniffer::PacketSniffer(CaptureDevice& captureDevice, PacketStorage& packetStorage)
    :device(captureDevice),
     storage(packetStorage)
{
}

void PacketSniffer::CaptureLoop()
{
    int packetsSniffed = 0;
    pcap_t* handle = device.HandleGetter();

    while (packetsSniffed < 20)
    {
        pcap_pkthdr* header = nullptr;
        const u_char* packetData = nullptr;

        int result = pcap_next_ex(handle, &header, &packetData);

        if (result == 1)
        {
            std::cout << "Captured len: " << header->caplen
                      << "\nOriginal len: " << header->len
                      << "\n" << header->ts.tv_sec << "."
                      << header->ts.tv_usec << "\n\n";

            Packet newPacket(header, packetData);

            for (u_char c : newPacket.rawBytes)
            {
                std::cout << c;
            }

            std::cout << "\n\n";
            storage.addPacket(newPacket);

            packetsSniffed++;
        }
        else if (result == -1)
        {
            std::cerr << "Big fat error";
            break;
        }
        else if (result == 0)
        {
            std::cout << "\nWaiting on packet...\n\n";
            continue;
        }
    }
}
