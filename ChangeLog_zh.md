# 更新

## v1.9.0

- 整合了 hpm_sdk v1.9.0

- 更新：
    - 升级CherryUSB协议栈到1.4.3
    - `uart/uart_v2`驱动支持可配置的IRQ优先级
    - `spi`驱动支持可配置的IRQ优先级
    - `i2c`驱动支持可配置的IRQ优先级
    - `gpio`驱动支持可配置的IRQ优先级
    - `mcan`驱动支持可配置的IRQ优先级

- 修复
    - `thernet_ptp_slave_demo`修复主设备和从设备之间的相同MAC地址问题

- 新增:
    - 增加`tsw`驱动支持
    - 增加`tsw phy`驱动支持
    - `spi`驱动增加DSPI/QSPI模式
    - 新增`tsn_lwip_tcpecho`示例


## v1.6.0

- 整合了 hpm_sdk v1.6.0
- 升级 RT-Thread 到 v5.0.2
- 新增示例:
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