#pragma once

#include <cstdint>
#include <array>
#include "error.hpp"

namespace pci{

    using namespace pci;

    struct Classcode {
        uint8_t base, sub, interface;

        bool Match(uint8_t b) {
            return b == base;
        }

        bool Match(uint8_t b, uint8_t s) {
            return Match(b) && s == sub;
        }

        bool Match(uint8_t b, uint8_t s, uint8_t i) {
            return Match(b, s) && i == interface;
        }
    };
    
    struct Device {
        uint8_t bus, device, function, header_type;
        Classcode class_code;
    };

    const uint16_t kConfigAddress = 0x0cf8;
    const uint16_t kConfigData = 0x0cfc;

    inline std::array<Device, 32> devices;
    inline int num_device;

    void WriteAddress(uint32_t address);

    void WriteData(uint32_t value);

    uint32_t ReadData();

    uint16_t ReadVendorId(uint8_t bus, uint8_t device, uint8_t function);

    inline uint16_t ReadVendorId(const Device& dev) {
        return ReadVendorId(dev.bus, dev.device, dev.function);
    }

    
    uint16_t ReadDeviceId(uint8_t bus, uint8_t device, uint8_t function);

    uint8_t ReadHeaderType(uint8_t bus, uint8_t device, uint8_t function);

    Classcode ReadClassCode(uint8_t bus, uint8_t device, uint8_t function);

    uint32_t ReadBusNumbers(uint8_t bus, uint8_t device, uint8_t function);
    
    uint32_t ReadConfReg(const Device& dev, uint8_t reg_addr);

    void WriteConfReg(const Device& dev, uint8_t reg_addr, uint32_t value);
    
    WithError<uint64_t> ReadBar(Device& device, unsigned int bar_index);

    bool IsSingleFunctionDevice(uint8_t header_type);

    Error ScanAllBus();

    Error ScanBus(uint8_t bus);

    Error ScanDevice(uint8_t bus, uint8_t device);

    Error ScanFunction(uint8_t bus, uint8_t device, uint8_t function);

    Error AddDevice(uint8_t bus, uint8_t device, uint8_t function, uint8_t header_type);

    constexpr uint8_t CalcBarAddress(unsigned int bar_index) {
        return 0x10 + 4 * bar_index;
    }
}



