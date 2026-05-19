<!-- generated-from-dump2 -->
# Embedded Engineering Roadmap

Markdown-only repo enumerating the (very long) skill tree to become a competent embedded systems engineer, with curated book + course + tool links at each node. Topic clusters: digital logic and computer architecture (Patterson/Hennessy, nand2tetris), microcontroller fundamentals (AVR, STM32, ESP32), RTOS (FreeRTOS, Zephyr, ThreadX), low-level languages (C, modern C++, embedded Rust), buses and protocols (I2C, SPI, UART, CAN, USB, Modbus, BLE), DSP, control systems (PID, Kalman), PCB design and EMC, IoT (MQTT, LoRa, Matter), safety/certification (MISRA-C, IEC 61508). Useful both as a self-study sequence and as a check on the size of the field — embedded is unusually broad because the abstractions don't stack the way they do in cloud or web, so each layer needs explicit study.

```text
# Top-level topic order suggested by the roadmap:
#   1. Digital logic & computer architecture
#   2. Microcontroller architecture (memory map, peripherals, interrupts)
#   3. C, advanced C, then C++ (the embedded subset)
#   4. Toolchain: gcc-arm, make, JTAG/SWD, OpenOCD, GDB
#   5. Communication protocols (UART/SPI/I2C/CAN/USB/...)
#   6. RTOS concepts (task, mutex, queue, priority inversion)
#   7. Power management, low-power design, bootloaders/OTA
#   8. Field-bus / industrial: Modbus, CAN, EtherCAT
#   9. Wireless: BLE, Wi-Fi, LoRa, Zigbee, Matter
#  10. DSP basics; control theory and PID/Kalman
#  11. Safety standards: MISRA, IEC 61508, ISO 26262
```

## References
- <https://github.com/m3y54m/Embedded-Engineering-Roadmap>
