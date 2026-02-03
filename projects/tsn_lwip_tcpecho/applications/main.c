/*
 * Copyright (c) 2025 HPMicro
 *
 * Change Logs:
 * Date         Author         Notes
 * 2025-03-31   Jiading        first version
 *
 */


#include <rtthread.h>
#include <rtdevice.h>
#include "rtt_board.h"
#include "lwip/sys.h"
#include "lwip/api.h"


#ifndef TCP_LOCAL_PORT
#define TCP_LOCAL_PORT (5001U)
#endif

void thread_entry(void *arg);
void tcp_echo_thread(void *arg);

int main(void)
{
    app_init_led_pins();

    static uint32_t led_thread_arg = 0;
    rt_thread_t led_thread = rt_thread_create("led_th", thread_entry, &led_thread_arg, 1024, 25, 10);
    rt_thread_startup(led_thread);

    sys_thread_new("tcp_echo_thread", tcp_echo_thread, NULL, 4096, 25);

    return 0;
}

void tcp_echo_thread(void *arg)
{
    struct netconn *conn, *newconn;
    struct netbuf *buf;
    void *data;
    u16_t len;
    err_t err;

    LWIP_UNUSED_ARG(arg);

#if LWIP_IPV6
    conn = netconn_new(NETCONN_TCP_IPV6);
    netconn_bind(conn, IP6_ADDR_ANY, TCP_LOCAL_PORT);
#else /* LWIP_IPV6 */
    conn = netconn_new(NETCONN_TCP);
    netconn_bind(conn, IP_ADDR_ANY, TCP_LOCAL_PORT);
#endif /* LWIP_IPV6 */
    LWIP_ASSERT("tcpecho: invalid conn", (conn != NULL));

    netconn_listen(conn);

    while (1) {
        if (netconn_accept(conn, &newconn) == ERR_OK) {
            while (netconn_recv(newconn, &buf) == ERR_OK) {
                do {
                    netbuf_data(buf, &data, &len);
                    err = netconn_write(newconn, data, len, NETCONN_COPY);
                    if (err != ERR_OK) {
                        LWIP_ASSERT("tcpecho: netconn_write: error %s\n", lwip_strerr(err));
                    }
                } while (netbuf_next(buf) >= 0);
                netbuf_delete(buf);
            }
            netconn_close(newconn);
            netconn_delete(newconn);
        }
    }
}

void thread_entry(void *arg)
{
    while(1) {
        app_led_write(0, APP_LED_ON);
        rt_thread_mdelay(500);
        app_led_write(0, APP_LED_OFF);
        rt_thread_mdelay(500);
        app_led_write(1, APP_LED_ON);
        rt_thread_mdelay(500);
        app_led_write(1, APP_LED_OFF);
        rt_thread_mdelay(500);
        app_led_write(2, APP_LED_ON);
        rt_thread_mdelay(500);
        app_led_write(2, APP_LED_OFF);
        rt_thread_mdelay(500);
    }
}
