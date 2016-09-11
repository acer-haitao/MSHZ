/*************************************************************************
    > File Name: getset_configmsg.h
    > Author: yuhaitao
    > Mail:acer_yuhaitao@163.com 
    > Created Time: Sat 10 Sep 2016 11:06:56 AM CST
 ************************************************************************/

#ifndef 	_GETSET_CONFIGMSG_
#define     _GETSET_CONFIGMSG_
#define N 24

typedef struct {
	unsigned char gateway_ID[N];
	unsigned char server_address[N];
	unsigned char server_port_up[N];
	unsigned char serv_port_down[N];
	unsigned char keepalive_interval[N];
	unsigned char stat_interval[N];
	unsigned char push_timeout_ms[N];
	unsigned char forward_crc_valid[N];
	unsigned char forward_crc_error[N];
	unsigned char forward_crc_disabled[N];
}configmsg;

#define  FILEPATH "/home/linux/MSHZ/fileconfig/global_conf.json"
int  getconfigmsg(configmsg *MSG);
int  setconfigmsg();
#endif
