# Change Log

## v1.11.0

- Integrated hpm_sdk v1.11.0
- Upgraded RT-Thread to v5.2.2
- Added RT-Thread standard dynamic interrupt registration mechanism, supporting flexible switching between static binding and dynamic management modes
- Added support for generic startup files, while maintaining compatibility with existing startup methods

- Updated:
  - Switched CherryUSB stack from package support to RT-Thread component driver support
  - Enhanced UART V2 driver
  - Enhanced MCAN driver
  - Enhanced CAN driver
  - Enhanced ENET driver
  - Enhanced ENET PHY driver

- Added:
  - Added Software I2C driver
  - Added Software SPI driver
  - UART V2 driver added PUART support
  - TMR driver added PTMR support

## v1.10.0

- Integrated hpm_sdk v1.10.0

- Updated:
  - Upgrade `CherryUSB` stack to 1.5.0
  - RTC driver supports alarm setting and retrieval
  - RTC driver supports `timeval` setting and retrieval

- Fixed:
  - Fix the issue of only 32-bit timestamp support in RTC driver, which can support 32-bit and 64-bit timestamp based on `time_t` length
  - Fix the issue that the vectoredd interrupt mode cannot work properly in some conditions
  - Fix the issue that WDOG reset failed to work after executing `reset` command in shell

- Added:
  - Support zcc compiler
  - Support SEGGER Embedded Studio IDE, version 8.24

## v1.9.0

- Integrated hpm_sdk v1.9.0

- Updated:
  - Upgrade `CherryUSB` stack to 1.4.3
  - `uart/uart_v2` driver supports configurable IRQ priority
  - `spi` driver supports for configurable IRQ priority for
  - `i2c` driver support for configurable IRQ priority
  - `gpio` driver support for configurable IRQ priority
  - `mcan` driver supports configurable IRQ priority

- Fixed:
  - Fixed the issue of the same MAC address between the master and slave devices in `ethernet_ptp_slave_demo`

- Added:
  - Add `tsw` driver support
  - Add `tsw phy` driver support
  - DSPI/QSPI mode added for `spi` driver
  - add `tsn_lwip_tcpecho` example

## v1.6.0

- Integrated hpm_sdk v1.6.0
- Samples:
  - blink_led
  - mmcan_example
  - ethernet_demo
  - ethernet_ptp_master_demo
  - ethernet_ptp_slave_demo
  - flashdb_demo
  - uart_dma_demo
  - usb_device_generic_hid
  - usb_host_msc_udisk
  - pwm_demo
