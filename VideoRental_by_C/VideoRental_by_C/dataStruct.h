#pragma once

#define NAME_SIZE 170 // NODE ���� ������ subs.s_name���ڿ��� ũ��
#define PHONE_SIZE 12 // NODE ���� ������  subs.s_phone���ڿ��� ũ��
#define RESIDE_SIZE 100 // NODE ���� ������ subs.s_reside���ڿ��� ũ��
#define SRENTNAME_SIZE 60 // NODE ���� ������ subs.s_rent.sRentName�� ���ڿ� ũ�� �� video.v_name�� ���ڿ� ũ��
#define SRNDAY_SIZE 12 // NODE ���� ������ subs.s_rent.SRNday�� ���ڿ� ũ��

#define GENRE_SIZE 25 // NODE ���� ������ videos.v_genre�� ���ڿ� ũ��


typedef struct sRent {
	int sRentNum; 
	char sRentName[3][SRENTNAME_SIZE];
	char SRNday[3][SRNDAY_SIZE];
}sRent;

typedef struct subs {
	int s_id;
	char s_name[NAME_SIZE];
	char s_phone[PHONE_SIZE];
	char s_reside[RESIDE_SIZE];
	sRent s_rent;
}subs;

// SNode�� ��� �� �� �ִ���� 522 �� �ڿ� |

typedef struct videos {
	char v_genre[GENRE_SIZE];
	char v_name[SRENTNAME_SIZE];
	char v_author[NAME_SIZE];
	char VRLday[SRNDAY_SIZE]; // ������

	int v_num;
	int v_rentNum;
}videos;

// VNode�� ��� �� �� �ִ���� 264 �� �ڿ� |

typedef union subs_or_videos {
	subs *pSubs;
	videos *pVideos;
}subs_or_videos;