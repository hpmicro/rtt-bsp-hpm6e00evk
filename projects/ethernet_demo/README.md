# 网络连通性及吞吐性能测试

## 概述

本示例演示了基于RT-Thread 网络连通性测试和吞吐性能测试

## 硬件设置

* 使用USB Type-C线缆连接PC USB端口和PWR DEBUG端口
* 使用以太网线缆连接PC以太网端口和开发板RGMII或RMII端口

## 软件设置

* 使用flash_release编译运行，可以获得更好的网络性能

## 运行示例

* 编译下载程序
* 串口终端显示

```console
 \ | /
- RT -     Thread Operating System
 / | \     5.0.2 build Apr 19 2025 10:18:07
 2006 - 2022 Copyright by RT-Thread team
lwIP-2.1.2 initialized!
[27] I/sal.skt: Socket Abstraction Layer initialize success.
msh />[4067] I/NO_TAG: ENET0
[4070] I/NO_TAG: PHY Status: Link up
[4074] I/NO_TAG: PHY Speed: 1000Mbps
[4078] I/NO_TAG: PHY Duplex: full duplex
```

## 功能验证

### 1. IP分配查询及DHCP状态确认

```console
msh />ifconfig
network interface device: ET (Default)
MTU: 1500
MAC: 98 2c bc b1 9f 17
FLAGS: UP LINK_UP INTERNET_DOWN DHCP_ENABLE ETHARP BROADCAST
ip address: 192.168.100.6
gw address: 192.168.100.1
net mask  : 255.255.255.0
dns server #0: 192.168.100.1
dns server #1: 0.0.0.0

```

**注： 若DHCP开启，则DHCP状态为“DHCP_ENABLE”，需要将网口连接至路由器或具有DHCP服务的PC  **   

### 2. PING测试

  （1）Windows系统中，打开cmd, 运行ping

```console
C:\Users>ping 192.168.100.6

正在 Ping 192.168.100.6 具有 32 字节的数据:
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255

192.168.100.6 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 4，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 0ms，最长 = 0ms，平均 = 0ms
```

  （2）开发板Ping PC

```console
msh />ping 192.168.100.5
ping: not found specified netif, using default netdev ET.
60 bytes from 192.168.100.5 icmp_seq=0 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=1 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=2 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=3 ttl=64 time=0 ms

```

### 3. **iperf测试**

- **TCP服务端模式**

  - MCU端输入命令

    ```console
    msh /> iperf -s
    ```

  -  PC端输入命令

    ```console
    C:\Users>iperf -c 192.168.100.6 -i 1
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Client connecting to 192.168.100.6, TCP port 5001
    TCP window size: 64.0 KByte (default)
    ------------------------------------------------------------
    [360] local 192.168.100.5 port 56599 connected with 192.168.100.6 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [360]  0.0- 1.0 sec  51.7 MBytes   433 Mbits/sec
    [360]  1.0- 2.0 sec  52.2 MBytes   438 Mbits/sec
    [360]  2.0- 3.0 sec  52.5 MBytes   440 Mbits/sec
    [360]  3.0- 4.0 sec  52.4 MBytes   440 Mbits/sec
    [360]  4.0- 5.0 sec  52.5 MBytes   440 Mbits/sec
    [360]  5.0- 6.0 sec  51.5 MBytes   432 Mbits/sec
    [360]  6.0- 7.0 sec  51.7 MBytes   434 Mbits/sec
    [360]  7.0- 8.0 sec  52.3 MBytes   438 Mbits/sec
    [360]  8.0- 9.0 sec  52.5 MBytes   441 Mbits/sec
    [360]  9.0-10.0 sec  51.7 MBytes   434 Mbits/sec
    [360]  0.0-10.0 sec   521 MBytes   437 Mbits/sec
    ```

  - 观察MCU端结果

    ```console
    msh />[24473] I/iperf: new client connected from (192.168.100.5, 56599)
    [29479] I/iperf: iperfd01: 438.6830 Mbps!
    [34472] W/iperf: client disconnected (192.168.100.5, 56599)
    ```

    

- **TCP客户端模式**

  - PC端输入命令

    ```console
    C:\Users>iperf -s -i 1
    ```

  - MCU端输入命令

    ```console
    msh />iperf -c 192.168.100.5
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 64.0 KByte (default)
    ------------------------------------------------------------
    [412] local 192.168.100.5 port 5001 connected with 192.168.100.6 port 52432
    [ ID] Interval       Transfer     Bandwidth
    [412]  0.0- 1.0 sec  47.0 MBytes   395 Mbits/sec
    [412]  1.0- 2.0 sec  45.8 MBytes   384 Mbits/sec
    [412]  2.0- 3.0 sec  46.2 MBytes   388 Mbits/sec
    [412]  3.0- 4.0 sec  47.0 MBytes   394 Mbits/sec
    [412]  4.0- 5.0 sec  47.2 MBytes   396 Mbits/sec
    [412]  5.0- 6.0 sec  46.5 MBytes   390 Mbits/sec
    [412]  6.0- 7.0 sec  47.0 MBytes   394 Mbits/sec
    [412]  7.0- 8.0 sec  46.5 MBytes   390 Mbits/sec
    [412]  8.0- 9.0 sec  47.1 MBytes   395 Mbits/sec
    [412]  9.0-10.0 sec  46.8 MBytes   392 Mbits/sec
    [412] 10.0-11.0 sec  44.5 MBytes   373 Mbits/sec
    [412] 11.0-12.0 sec  47.2 MBytes   396 Mbits/sec
    [412] 12.0-13.0 sec  47.1 MBytes   395 Mbits/sec
    [412] 13.0-14.0 sec  47.1 MBytes   395 Mbits/sec
    [412] 14.0-15.0 sec  47.0 MBytes   394 Mbits/sec
    [412] 15.0-16.0 sec  46.8 MBytes   392 Mbits/sec
    [412] 16.0-17.0 sec  46.8 MBytes   392 Mbits/sec
    [412] 17.0-18.0 sec  47.0 MBytes   394 Mbits/sec
    [412] 18.0-19.0 sec  47.0 MBytes   394 Mbits/sec
    [412] 19.0-20.0 sec  47.2 MBytes   396 Mbits/sec
    ```

  - 观察MCU端结果

    ```console
    msh /[171941] I/iperf: Connect to iperf server successful!
    >[176946] I/iperf: iperfc01: 391.3610 Mbps!
    [181946] I/iperf: iperfc01: 392.5670 Mbps!
    [186946] I/iperf: iperfc01: 391.0070 Mbps!
    [191946] I/iperf: iperfc01: 393.9690 Mbps!
    ```

- **UDP服务端模式**

  - MCU端输入命令

    ```console
    msh />iperf -u -s
    ```

  - PC端输入命令

    ```console
    C:\Users>iperf -u -c 192.168.100.6 -i 1 -b 1000M -t 20
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Client connecting to 192.168.100.6, UDP port 5001
    Sending 1470 byte datagrams
    UDP buffer size: 64.0 KByte (default)
    ------------------------------------------------------------
    [360] local 192.168.100.5 port 60720 connected with 192.168.100.6 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [360]  0.0- 1.0 sec  80.4 MBytes   675 Mbits/sec
    [360]  1.0- 2.0 sec  83.0 MBytes   697 Mbits/sec
    [360]  2.0- 3.0 sec  83.4 MBytes   700 Mbits/sec
    [360]  3.0- 4.0 sec  83.2 MBytes   698 Mbits/sec
    [360]  4.0- 5.0 sec  83.0 MBytes   696 Mbits/sec
    [360]  5.0- 6.0 sec  82.5 MBytes   692 Mbits/sec
    [360]  6.0- 7.0 sec  81.6 MBytes   684 Mbits/sec
    [360]  7.0- 8.0 sec  77.2 MBytes   648 Mbits/sec
    [360]  8.0- 9.0 sec  82.4 MBytes   691 Mbits/sec
    [360]  9.0-10.0 sec  83.0 MBytes   697 Mbits/sec
    [360] 10.0-11.0 sec  83.5 MBytes   700 Mbits/sec
    [360] 11.0-12.0 sec  81.4 MBytes   683 Mbits/sec
    [360] 12.0-13.0 sec  80.6 MBytes   676 Mbits/sec
    [360] 13.0-14.0 sec  83.1 MBytes   697 Mbits/sec
    [360] 14.0-15.0 sec  81.7 MBytes   685 Mbits/sec
    [360] 15.0-16.0 sec  84.0 MBytes   705 Mbits/sec
    [360] 16.0-17.0 sec  74.6 MBytes   626 Mbits/sec
    [360] 17.0-18.0 sec  80.8 MBytes   678 Mbits/sec
    [360] 18.0-19.0 sec  82.3 MBytes   690 Mbits/sec
    [360] 19.0-20.0 sec  81.7 MBytes   685 Mbits/sec
    [ ID] Interval       Transfer     Bandwidth
    [360]  0.0-20.0 sec  1.60 GBytes   685 Mbits/sec
    [360] WARNING: did not receive ack of last datagram after 10 tries.
    [360] Sent 1165231 datagrams
    ```

  - 观察MCU端结果

    ```console
    msh />[259857] I/iperf: iperfd01: 471.7210 Mbps! lost:56588 total:257149
    
    [264864] I/iperf: iperfd01: 533.4140 Mbps! lost:64208 total:291000
    
    [269871] I/iperf: iperfd01: 538.0010 Mbps! lost:64748 total:293490
    
    [274878] I/iperf: iperfd01: 527.6380 Mbps! lost:64146 total:288482
    
    [281801] I/iperf: iperfd01: 46.2830 Mbps! lost:-2322562 total:-2295352
    
    ```
    
    

- UDP客户端模式

  - PC端输入命令

    ```console
    C:\Users>iperf -u -s -i 1
    ```

  - MCU端输入命令

    ```console
    msh />iperf -u -c 192.168.100.5
    ```

  - 观察MCU端结果

    ```console
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size: 64.0 KByte (default)
    ------------------------------------------------------------
    [344] local 192.168.100.5 port 5001 connected with 192.168.100.6 port 62510
    [ ID] Interval       Transfer     Bandwidth       Jitter   Lost/Total Datagrams
    [344]  0.0- 1.0 sec  85.8 MBytes   720 Mbits/sec  0.011 ms 10989/72213 (15%)
    [344]  1.0- 2.0 sec  85.7 MBytes   719 Mbits/sec  0.005 ms    3/61103 (0.0049%)
    [344]  2.0- 3.0 sec  80.4 MBytes   675 Mbits/sec  0.010 ms 3721/61099 (6.1%)
    [344]  3.0- 4.0 sec  85.6 MBytes   718 Mbits/sec  0.004 ms    0/61026 (0%)
    [344]  4.0- 5.0 sec  85.3 MBytes   716 Mbits/sec  0.013 ms  218/61090 (0.36%)
    [344]  5.0- 6.0 sec  85.3 MBytes   716 Mbits/sec  0.004 ms  259/61114 (0.42%)
    [344]  6.0- 7.0 sec  85.6 MBytes   718 Mbits/sec  0.009 ms    0/61095 (0%)
    [344]  7.0- 8.0 sec  84.7 MBytes   711 Mbits/sec  0.057 ms  653/61070 (1.1%)
    [344]  8.0- 9.0 sec  85.2 MBytes   715 Mbits/sec  0.007 ms  277/61080 (0.45%)
    [344]  9.0-10.0 sec  85.7 MBytes   719 Mbits/sec  0.054 ms    0/61136 (0%)
    [344] 10.0-11.0 sec  85.6 MBytes   718 Mbits/sec  0.011 ms    0/61076 (0%)
    [344] 11.0-12.0 sec  85.6 MBytes   718 Mbits/sec  0.065 ms    0/61090 (0%)
    [344] 12.0-13.0 sec  85.4 MBytes   717 Mbits/sec  0.045 ms  211/61143 (0.35%)
    [344] 13.0-14.0 sec  85.7 MBytes   719 Mbits/sec  0.006 ms    0/61114 (0%)
    [344] 14.0-15.0 sec  85.6 MBytes   718 Mbits/sec  0.065 ms   34/61089 (0.056%)
    [344] 15.0-16.0 sec  85.7 MBytes   719 Mbits/sec  0.010 ms    0/61165 (0%)
    [344] 16.0-17.0 sec  85.2 MBytes   715 Mbits/sec  0.003 ms  330/61107 (0.54%)
    [344] 17.0-18.0 sec  85.7 MBytes   719 Mbits/sec  0.004 ms    0/61137 (0%)
    [344] 18.0-19.0 sec  85.4 MBytes   717 Mbits/sec  0.003 ms  215/61142 (0.35%)
    [344] 19.0-20.0 sec  85.6 MBytes   718 Mbits/sec  0.058 ms    0/61077 (0%)
    ```

    

  - 观察MCU端结果

    ```console
    [66131] I/iperf: iperf udp mode run...
    ```

    **注：此模式下，MCU端无统计信息输出，且无退出机制，需要按reset键重启MCU。**

  

  

