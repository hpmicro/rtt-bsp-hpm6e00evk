# 更新
## v1.11.0

- 整合了hpm_sdk v1.11.0
- 升级RT-Thread 到 v5.2.2
- 新增 RT-Thread 标准动态中断注册机制，支持在静态绑定与动态管理模式间灵活切换
- 新增通用启动文件（generic startup）支持，同时兼容原有启动方式

- 更新：
  - CherryUSB协议栈从软件包支持改为RT-Thread的组件驱动支持
  - 增强UART V2驱动
  - 增强MCAN驱动
  - 增强CAN驱动
  - 增强ENET驱动
  - 增强ENET PHY驱动

- 修复：

- 新增：
  - 新增软件I2C驱动
  - 新增软件SPI驱动
  - UART V2驱动新增PUART
  - TMR驱动新增PTMR


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
