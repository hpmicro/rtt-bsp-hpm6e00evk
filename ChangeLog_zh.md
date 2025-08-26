# 更新

## v1.10.0

- 整合了 hpm_sdk v1.10.0

- 更新：
  - 升级CherryUSB协议栈到1.5.0
  - RTC驱动支持闹钟警报设置和获取
  - RTC驱动支持 `timeval` 的设置和获取

- 修复：
  - 修复RTC驱动只支持32bit timestamp问题，可根据time_t长度支持32bit和64bit timestamp
  - 修复中断向量模式在某些条件下工作异常的问题
  - 修复shell 执行`reset`命令后，看门狗复位失效的问题

- 新增
  - 支持zcc编译器
  - 支持SEGGER Embedded Studio IDE，版本为8.24

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
  - `ethernet_ptp_slave_demo`修复主设备和从设备之间的相同MAC地址问题

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
