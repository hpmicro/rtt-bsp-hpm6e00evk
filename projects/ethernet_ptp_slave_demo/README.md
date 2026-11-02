# lwIP PTP Slave V1

## 概述

本示例展示PTP Slave的功能

- Master与Slave通过PTP协议通讯，从而实现Slave端的时钟同步

## 硬件设置

- 使用USB Type-C线缆连接PC USB端口和PWR DEBUG端口
- 使用以太网线缆连接开发板RGMII或者RMII端口和另一块开发板的RGMII或RMII端口

## 编译设置

- 在双网口的开发板上，默认支持的是RGMII接口
- 在双网口的开发板上，仅支持一个网口，若需要使用另一个网口，可以通过如下两种方式之一：
    - RT-Thread Settings->硬件->芯片设备驱动->Enable Ethernet
    - menuconfig->Hardware Drivers Config->On-chip Peripheral Drivers->Enable Ethernet

## 运行示例

- 编译下载程序（J-Link JTAG）
- 串口终端显示（Slave 与 Master 直连以太网，使能 `LWIP_PTP` 硬件时间戳后）

```console
 \ | /
- RT -     Thread Operating System
 / | \     5.2.2 build Jul 18 2026 14:19:34
 2006 - 2024 Copyright by RT-Thread team
lwIP-2.1.2 initialized!
[29] I/sal.skt: Socket Abstraction Layer initialize success.
(D 0.006480120) event POWER UP
(D 0.009325800) initClock
(D 0.011709560) state PTP_INITIALIZING
(D 0.015226480) manufacturerIdentity: PTPd;1.0.1
(D 0.019615240) netShutdown
(D 0.022161920) netInit
(D 0.024542400) initData
(D 0.026850760) initTimer
(D 0.029221720) initClock
(D 0.031599560) sync message interval: 1000
(D 0.035546520) clock identifier: DFLT
(D 0.039052800) 256*log2(clock variance): -4000
(D 0.043347160) clock stratum: 255
(D 0.046504960) clock preferred?: no
(D 0.049836560) bound interface name:
(D 0.053341960) communication technology: 1
(D 0.057285480) uuid: 98:2c:bc:b1:9f:18
(D 0.060885360) PTP subdomain name: _DFLT
(D 0.064653600) subdomain address: 224.0.1.129
(D 0.068862640) event port address: 3f 1
(D 0.072565120) general port address: 40 1
(D 0.076429200) initClock
(D 0.078798560) state PTP_LISTENING
(D 0.082043480) initClock
(D 0.084413720) state PTP_SLAVE
msh />
[4119] I/NO_TAG: ENET0
[4122] I/NO_TAG: PHY Status: Link up
[4126] I/NO_TAG: PHY Speed: 1000Mbps
[4130] I/NO_TAG: PHY Duplex: full duplex

(D 3.989802520) addForeign: new record (0,1) 1 1 98:2c:bc:b1:9f:17
(D 3.995830720) event MASTER_CLOCK_CHANGED
(D 3.999692880) state PTP_UNCALIBRATED
(D 4.003201280) toState: Q = 0, R = 7
(D 1297.957036300) updateOffset
(D 1297.959939900) one-way delay:           0s      18905ns
(D 1297.965285600) offset from master:      0s         99ns
(D 1297.970632460) observed drift:          -3361
(D 1298.961531980) updateOffset
(D 1298.964433360) one-way delay:           0s      18905ns
(D 1298.969781420) offset from master:      0s         57ns
(D 1298.975127240) observed drift:          -3358
(D 1299.957671380) updateOffset
(D 1299.960585200) one-way delay:           0s      18897ns
(D 1299.965930980) offset from master:      0s         30ns
(D 1299.971275580) observed drift:          -3356
(D 1300.957963960) updateOffset
(D 1300.960874540) one-way delay:           0s      18897ns
(D 1300.966222040) offset from master:      0s          7ns
(D 1300.971567300) observed drift:          -3356
(D 1301.958294920) updateOffset
(D 1301.961208840) one-way delay:           0s      18897ns
(D 1301.966558980) offset from master:      0s         -5ns
(D 1301.971906360) observed drift:          -3356
(D 1302.958668520) updateOffset
(D 1302.961575280) one-way delay:           0s      18897ns
(D 1302.966923340) offset from master:      0s        -11ns
(D 1302.972269040) observed drift:          -3356
(D 1303.958931520) updateOffset
(D 1303.961835480) one-way delay:           0s      18897ns
(D 1303.967187140) offset from master:      0s        -14ns
(D 1303.972534680) observed drift:          -3356
(D 1304.959234120) updateOffset
(D 1304.962140540) one-way delay:           0s      18897ns
(D 1304.967493000) offset from master:      0s        -16ns
(D 1304.972839200) observed drift:          -3357
(D 1305.959526800) updateOffset
(D 1305.962428420) one-way delay:           0s      18897ns
(D 1305.967777240) offset from master:      0s        -16ns
(D 1305.973122980) observed drift:          -3358
(D 1306.959848580) updateOffset
(D 1306.962755980) one-way delay:           0s      18897ns
(D 1306.968110520) offset from master:      0s        -17ns
(D 1306.973463180) observed drift:          -3359
(D 1307.960162220) updateOffset
(D 1307.963064920) one-way delay:           0s      18897ns
(D 1307.968418580) offset from master:      0s        -17ns
```

同步稳定后，`offset from master` 可收敛并维持在约 ±100ns 以内（上例连续多次采样均在 100ns 内）。
