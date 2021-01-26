#pragma once

#include <cstdint>
#include <array>
#include "error.hpp"

namespace pci{

    using namespace pci;

    struct Device {
        uint8_t bus, device, function, header_type;
    };

    const uint16_t kConfigAddress = 0x0cf8;
    const uint16_t kConfigData = 0x0cfc;

    inline std::array<Device, 32> devices;
    inline int num_device;

    void WriteAddress(uint32_t address);

    void WriteData(uint32_t value);

    uint32_t ReadData();

    uint16_t ReadVendorId(uint8_t bus, uint8_t device, uint8_t function);

    uint16_t ReadDeviceId(uint8_t bus, uint8_t device, uint8_t function);

    uint8_t ReadHeaderType(uint8_t bus, uint8_t device, uint8_t function);

    uint32_t ReadClassCode(uint8_t bus, uint8_t device, uint8_t function);

    uint32_t ReadBusNumbers(uint8_t bus, uint8_t device, uint8_t function);

    bool IsSingleFunctionDevice(uint8_t header_type);

    Error ScanAllBus();

    Error ScanBus(uint8_t bus);

    Error ScanDevice(uint8_t bus, uint8_t device);

    Error ScanFunction(uint8_t bus, uint8_t device, uint8_t function);

    Error AddDevice(uint8_t bus, uint8_t device, uint8_t function, uint8_t header_type);
}



