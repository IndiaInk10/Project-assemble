#pragma once

#define NAME_SIZE 170 // NODE 안의 데이터 subs.s_name문자열의 크기
#define PHONE_SIZE 12 // NODE 안의 데이터  subs.s_phone문자열의 크기
#define RESIDE_SIZE 100 // NODE 안의 데이터 subs.s_reside문자열의 크기
#define SRENTNAME_SIZE 60 // NODE 안의 데이터 subs.s_rent.sRentName의 문자열 크기 및 video.v_name의 문자열 크기
#define SRNDAY_SIZE 12 // NODE 안의 데이터 subs.s_rent.SRNday의 문자열 크기

#define GENRE_SIZE 25 // NODE 안의 데이터 videos.v_genre의 문자열 크기


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

// SNode일 경우 한 줄 최대길이 522 맨 뒤에 |

typedef struct videos {
	char v_genre[GENRE_SIZE];
	char v_name[SRENTNAME_SIZE];
	char v_author[NAME_SIZE];
	char VRLday[SRNDAY_SIZE]; // 개봉일

	int v_num;
	int v_rentNum;
}videos;

// VNode일 경우 한 줄 최대길이 264 맨 뒤에 |

typedef union subs_or_videos {
	subs *pSubs;
	videos *pVideos;
}subs_or_videos;