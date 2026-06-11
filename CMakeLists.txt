cmake_minimum_required(VERSION 3.20)

project(ringcap)

set(CMAKE_CXX_STANDARD 20)

add_library(ringcap
    src/capture/DeviceManager.cpp
    src/capture/CaptureDevice.cpp
    src/capture/PacketSniffer.cpp
    src/capture/PacketStorage.cpp
    src/parser/EthernetLayer.cpp
    src/packet/PcapPacketAdapter.cpp
)

target_include_directories(ringcap PUBLIC include)

target_link_libraries(ringcap PRIVATE pcap)

add_executable(ringcap_demo
    src/main.cpp
)

target_link_libraries(ringcap_demo PRIVATE ringcap)
