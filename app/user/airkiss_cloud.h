/*
 * airkiss_cloud.h
 *
 *  Created on: 2016��3��31��
 *      Author: itmaktub
 */

#ifndef APP_USER_AIRKISS_CLOUD_H_
#define APP_USER_AIRKISS_CLOUD_H_

#if defined(GLOBAL_DEBUG)
#define AIRKISS_CLOUD_DEBUG(format, ...)  log_printf("AIRKISS_CLOUD: ", format,  ##__VA_ARGS__)
#else
#define AIRKISS_CLOUD_DEBUG(format, ...)
#endif

#define AIRKISS_HEAP_MAX    1024*4

//TODO
#define DEVICE_LICENCE  "FIXME"

typedef enum airkiss_cloud_receive_msg_t
{
    AIRKISS_CLOUD_NOTIFY_MSG,
    AIRKISS_CLOUD_RESPONSE_MSG,
    AIRKISS_CLOUD_EVENT_MSG
}airkiss_cloud_receive_msg_t;

typedef enum airkiss_cloud_error_msg_t
{
    AIRKISS_CLOUD_ERROR_OK            = 0,                    //  0   �����첽����ɹ�
    AIRKISS_CLOUD_ERROR_BUSY          = 11500,                //  1 150 0   ϵͳ��æ
    AIRKISS_CLOUD_ERROR_NOT_CONNECT   = 11501,                //  1 150 1   �豸û����
    AIRKISS_CLOUD_ERROR_POWER_OFF     = 11502,                //  1 150 2   �豸�Ѿ��ػ�
    AIRKISS_CLOUD_ERROR_UNKOWN        = 11503                 //  1 150 3   �豸��ʱ�޷���������΢��ƽ̨�Ժ�����
}airkiss_cloud_error_msg_t;

enum
{
    AIRKISS_CLOUD_FUNC_ABILITY        = 0x0001,              //    0x0001  ΢��Ӳ��ƽ̨������ҵ��FuncID
    AIRKISS_CLOUD_FUNC_FIRMWARE       = 0x0020                //    0x0020  ΢��Ӳ��ƽ̨�̼�����ҵ��FuncID
};

uint8_t airkiss_cloud_start(void);

typedef int (* airiss_cloud_receive_notify_callback_t)(const uint8_t *dat, uint32_t len);
typedef void (* airiss_cloud_initdone_callback_t)(void);


#define airkiss_cloud_send_ablity_msg(dat)  airkiss_cloud_sendmessage(AIRKISS_CLOUD_FUNC_ABILITY, dat, os_strlen(dat));

//��Ϣ�ص�����ע��ӿ�
void airiss_cloud_receive_notify_callback_register(airiss_cloud_receive_notify_callback_t airiss_cloud_receive_notify_callback);
//airkiss cloud ��ʼ���ɹ���Ļص�ע��ӿ�
void airiss_cloud_initdone_callback_register(airiss_cloud_initdone_callback_t airiss_cloud_initdone_callback);


#endif /* APP_USER_AIRKISS_CLOUD_H_ */
