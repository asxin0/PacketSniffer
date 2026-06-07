cmake_minimum_required(VERSION 3.20)

project(PacketSniffer)

set(CMAKE_CXX_STANDARD 20)

add_executable(PacketSniffer
    src/main.cpp
    src/capture/DeviceManager.cpp
    src/capture/CaptureDevice.cpp
    src/capture/PacketSniffer.cpp
    src/capture/PacketStorage.cpp
    src/parser/EthernetLayer.cpp
    src/packet/PcapPacketAdapter.cpp
)

target_include_directories(PacketSniffer PRIVATE include)

target_link_libraries(PacketSniffer PRIVATE pcap)
