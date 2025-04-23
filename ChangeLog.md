# Change Log

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
    - Fixed the issue of the same MAC address between the master and slave devices in `thernet_ptp_slave_demo`

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