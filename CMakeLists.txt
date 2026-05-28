cmake_minimum_required(VERSION 3.20)

project(PacketSniffer)

set(CMAKE_CXX_STANDARD 20)

add_executable(PacketSniffer
    src/main.cpp
    src/DeviceManager.cpp
    src/CaptureDevice.cpp
    src/PacketSniffer.cpp
)

target_include_directories(PacketSniffer PRIVATE include)

target_link_libraries(PacketSniffer PRIVATE pcap)
