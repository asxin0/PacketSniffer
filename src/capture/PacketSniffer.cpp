#include "capture/PacketSniffer.h"
#include "packet/Packet.h"
#include "packet/PcapPacketAdapter.h"

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

    int pcapLinkLayer = pcap_datalink(handle);
    LinkLayerType linkLayer = PcapPacketAdapter::toLinkLayer(pcapLinkLayer);

    while (packetsSniffed < 3)
    {
        pcap_pkthdr* pcapHeader = nullptr;
        const u_char* packetData = nullptr;

        int result = pcap_next_ex(handle, &pcapHeader, &packetData);

        if (result == 1)
        {
            PacketHeader header = PcapPacketAdapter::PcapHdrToHdr(pcapHeader);

            Packet newPacket(header, packetData, linkLayer);

            std::cout << "caplen: " << newPacket.header.capturedLen
                      << "\nlen: " << newPacket.header.originalLen
                      << "\nts: " << newPacket.header.timestampS
                      << "." << newPacket.header.timestampMs
                      << "\nLink layer: " << static_cast<int>(newPacket.linkLayerType) << "\n";

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
