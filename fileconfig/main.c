/*************************************************************************
  > File Name: main.c
  > Author: yuhaitao
  > Mail:acer_yuhaitao@163.com 
  > Created Time: Sat 10 Sep 2016 10:47:23 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "getset_configmsg.h"
#define bit 2

int dropsmb(unsigned char *str)
{
	while(*str)
	{
		if (*str == ',')
		{
			*str = '\0';
		}
		str++;
	}
	return 0;
}
/* 获取配置文件信息*/
int getconfigmsg(configmsg *MSG)
{
	FILE *fp = fopen(FILEPATH, "r");
	unsigned char buf[1024];
	unsigned char *p = NULL;

	int linesize = 0;

	if(fp == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}
	while(fgets(buf,1024,fp) != NULL)
	{
		//	printf("MSG->gateway_ID %s\n",MSG->gateway_ID);

#if 1
		//去掉行尾的\n
		linesize = strlen(buf);
		if(buf[linesize - 1] == '\n')
		{
			buf[linesize -1] = '\0';
		}
#endif
		//	printf("buf %s\n", buf);
		if((p = strstr(buf,MSG->gateway_ID)) != NULL)
		{
			p = p + strlen(MSG->gateway_ID) + bit;
			dropsmb(p);
			//	printf("bufsize = %d\n",strlen(buf));
			printf("gateway_ID:%s\n",p);
		}	
		else if((p = strstr(buf,MSG->server_address)) != NULL)
		{
			p = p + strlen(MSG->server_address) + bit;
			dropsmb(p);
			//	printf("bufsize = %d\n",strlen(buf));
			printf("MSG->server_address:%s\n",p);
		}
		else if((p = strstr(buf,MSG->server_port_up)) != NULL)
		{
			p = p + strlen(MSG->server_port_up) + bit;
			dropsmb(p);
			//	printf("bufsize = %d\n",strlen(buf));
			printf("MSG->server_port_up):%s\n",p);
		}
		else if((p = strstr(buf,MSG->serv_port_down)) != NULL)
		{
			p = p + strlen(MSG->serv_port_down) + bit;
			dropsmb(p);
			//	printf("bufsize = %d\n",strlen(buf));
			printf("serv_port_down:%s\n",p);
		}
		else if((p = strstr(buf,MSG->keepalive_interval)) != NULL)
		{
			p = p + strlen(MSG->keepalive_interval) + bit;
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("MSG->keepalive_interval:%s\n",p);
		}
		else if((p = strstr(buf,MSG->stat_interval)) != NULL)
		{
			p = p + strlen(MSG->stat_interval) + bit;
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("stat_interval:%s\n",p);
		}
		else if((p = strstr(buf,MSG->push_timeout_ms)) != NULL)
		{
			p = p + strlen(MSG->push_timeout_ms) + bit;
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("push_timeout_ms:%s\n",p);
		}
		else if((p = strstr(buf,MSG->forward_crc_valid)) != NULL)
		{
			p = p + strlen(MSG->forward_crc_valid) + bit;
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("forward_crc_valid:%s\n",p);
		}
		else if((p = strstr(buf,MSG->forward_crc_error)) != NULL)
		{
			p = p + strlen(MSG->forward_crc_error) + bit;
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("forward_crc_error:%s\n",p);
		}
		else if((p = strstr(buf,MSG->forward_crc_disabled)) != NULL)
		{
			p = p + strlen(MSG->forward_crc_disabled) + bit; 
			dropsmb(p);

			//	printf("bufsize = %d\n",strlen(buf));
			printf("forward_crc_disabled:%s\n",p);
		}
	}
	fclose(fp);
	return 0;
}

/* 设置配置文件信息*/
int setconfigmsg(configmsg *MSG, unsigned char *inbuf)
{
	FILE *fp = fopen(FILEPATH, "r");
	char buf1[1024];
	char buf2[1024];
	char 


	int linesize = 0;
	int len = 100;
	int ret;

	if(fp == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}
	while((fgets(buf, 1024, fp)) != NULL)
	{
	printf("ftellstart %ld\n",ftell(fp));
	ret = fseek(fp, len, SEEK_CUR);
	printf("%d\n",ret);
	printf("ftell %ld\n",ftell(fp));
	}
	fclose(fp);
	return 0;
}

int main(int argc, char *argv[])
{	

	configmsg MSG ={"gateway_ID","server_address",\
		"server_port_up","serv_port_down",\
			"keepalive_interval","stat_interval","push_timeout_ms",\
			"forward_crc_valid","forward_crc_error",\
			"forward_crc_disabled"
	};
	//getconfigmsg(&MSG);
	setconfigmsg(&MSG, "192.168.1.1");

	return 0;
}

