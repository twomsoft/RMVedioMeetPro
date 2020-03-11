#pragma once
#include <inttypes.h>

typedef uint64_t rc_userid;
typedef uint64_t rc_roomid;

typedef int rc_bool;

#define EQUAL(a,b) ((a)==(b))

#define empty_id (0u)

// ���ͬʱ��������
#define MAX_SPEAKERS (5u)

// ��¼�������� (�û���¼�¼�)
enum record_op
{
	record_op_append,
	record_op_delete,
	record_op_modify,
};

// ����ģʽ
enum rc_speak_mode
{
	speak_mode_queuing,	//���Ŷ�ģʽ
	speak_mode_hosting, //����ģʽ���������˾���˭����
	speak_mode_activity,//���Ի�Ծģʽ��˵������������
};

// ����״̬
enum rc_onoff
{
	state_off,
	state_on,
};

// ����������
enum rc_room_flag
{
	room_flag_password = (1),	//��Ҫ����
	room_flag_invite = (1 << 1),	//����ģʽ (δ��������˲��ܽ���)
};

// �������б�
typedef rc_userid rc_speaker_list[MAX_SPEAKERS];

#include "Errorcode.h"
