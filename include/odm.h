/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/


#ifndef	__HALDMOUTSRC_H__
#define __HALDMOUTSRC_H__

/*  */
/*  Definition */
/*  */
/*  */
/*  2011/09/22 MH Define all team supprt ability. */
/*  */

/*  */
/*  2011/09/22 MH Define for all teams. Please Define the constan in your precomp header. */
/*  */
/* define		DM_ODM_SUPPORT_AP			0 */
/* define		DM_ODM_SUPPORT_ADSL			0 */
/* define		DM_ODM_SUPPORT_CE			0 */
/* define		DM_ODM_SUPPORT_MP			1 */

/*  */
/*  2011/09/28 MH Define ODM SW team support flag. */
/*  */



/*  */
/*  Antenna Switch Relative Definition. */
/*  */

/*  */
/*  20100503 Joseph: */
/*  Add new function SwAntDivCheck8192C(). */
/*  This is the main function of Antenna diversity function before link. */
/*  Mainly, it just retains last scan result and scan again. */
/*  After that, it compares the scan result to see which one gets better RSSI. */
/*  It selects antenna with better receiving power and returns better scan result. */
/*  */
#define	TP_MODE		0
#define	RSSI_MODE		1
#define	TRAFFIC_LOW	0
#define	TRAFFIC_HIGH	1


/*  */
/* 3 Tx Power Tracking */
/* 3============================================================ */
#define		DPK_DELTA_MAPPING_NUM	13
#define		index_mapping_HP_NUM	15


/*  */
/* 3 PSD Handler */
/* 3============================================================ */

#define	AFH_PSD		1	/* 0:normal PSD scan, 1: only do 20 pts PSD */
#define	MODE_40M		0	/* 0:20M, 1:40M */
#define	PSD_TH2		3
#define	PSD_CHM		20   /*  Minimum channel number for BT AFH */
#define	SIR_STEP_SIZE	3
#define   Smooth_Size_1		5
#define	Smooth_TH_1	3
#define   Smooth_Size_2		10
#define	Smooth_TH_2	4
#define   Smooth_Size_3		20
#define	Smooth_TH_3	4
#define   Smooth_Step_Size 5
#define	Adaptive_SIR	1
#define	PSD_RESCAN		4
#define	PSD_SCAN_INTERVAL	700 /* ms */

/* 8723A High Power IGI Setting */
#define		DM_DIG_HIGH_PWR_IGI_LOWER_BOUND	0x22
#define			DM_DIG_Gmode_HIGH_PWR_IGI_LOWER_BOUND 0x28
#define		DM_DIG_HIGH_PWR_THRESHOLD	0x3a

/*  LPS define */
#define DM_DIG_FA_TH0_LPS				4 /*  4 in lps */
#define DM_DIG_FA_TH1_LPS				15 /*  15 lps */
#define DM_DIG_FA_TH2_LPS				30 /*  30 lps */
#define RSSI_OFFSET_DIG					0x05;

/* ANT Test */
#define			ANTTESTALL		0x00		/* Ant A or B will be Testing */
#define		ANTTESTA		0x01		/* Ant A will be Testing */
#define		ANTTESTB		0x02		/* Ant B will be testing */


/*  */
/*  structure and define */
/*  */

/*  */
/*  2011/09/20 MH Add for AP/ADSLpseudo DM structuer requirement. */
/*  We need to remove to other position??? */
/*  */
struct rtl8192cd_priv {
	u1Byte		temp;
};

struct rtw_dig {
	u1Byte		Dig_Enable_Flag;
	u1Byte		Dig_Ext_Port_Stage;

	int		RssiLowThresh;
	int		RssiHighThresh;

	u4Byte		FALowThresh;
	u4Byte		FAHighThresh;

	u1Byte		CurSTAConnectState;
	u1Byte		PreSTAConnectState;
	u1Byte		CurMultiSTAConnectState;

	u1Byte		PreIGValue;
	u1Byte		CurIGValue;
	u1Byte		BackupIGValue;

	s1Byte		BackoffVal;
	s1Byte		BackoffVal_range_max;
	s1Byte		BackoffVal_range_min;
	u1Byte		rx_gain_range_max;
	u1Byte		rx_gain_range_min;
	u1Byte		Rssi_val_min;

	u1Byte		PreCCK_CCAThres;
	u1Byte		CurCCK_CCAThres;
	u1Byte		PreCCKPDState;
	u1Byte		CurCCKPDState;

	u1Byte		LargeFAHit;
	u1Byte		ForbiddenIGI;
	u4Byte		Recover_cnt;

	u1Byte		DIG_Dynamic_MIN_0;
	u1Byte		DIG_Dynamic_MIN_1;
	bool		bMediaConnect_0;
	bool		bMediaConnect_1;

	u4Byte		AntDiv_RSSI_max;
	u4Byte		RSSI_max;
};

struct rtl_ps {
	u1Byte		PreCCAState;
	u1Byte		CurCCAState;

	u1Byte		PreRFState;
	u1Byte		CurRFState;

	int		    Rssi_val_min;

	u1Byte		initialize;
	u4Byte		Reg874,RegC70,Reg85C,RegA74;

};

struct false_alarm_stats {
	u4Byte	Cnt_Parity_Fail;
	u4Byte	Cnt_Rate_Illegal;
	u4Byte	Cnt_Crc8_fail;
	u4Byte	Cnt_Mcs_fail;
	u4Byte	Cnt_Ofdm_fail;
	u4Byte	Cnt_Cck_fail;
	u4Byte	Cnt_all;
	u4Byte	Cnt_Fast_Fsync;
	u4Byte	Cnt_SB_Search_fail;
	u4Byte	Cnt_OFDM_CCA;
	u4Byte	Cnt_CCK_CCA;
	u4Byte	Cnt_CCA_all;
	u4Byte	Cnt_BW_USC;	/* Gary */
	u4Byte	Cnt_BW_LSC;	/* Gary */
};

struct dyn_primary_cca {
	u1Byte		PriCCA_flag;
	u1Byte		intf_flag;
	u1Byte		intf_type;
	u1Byte		DupRTS_flag;
	u1Byte		Monitor_flag;
};

struct rx_hpc {
	u1Byte		RXHP_flag;
	u1Byte		PSD_func_trigger;
	u1Byte		PSD_bitmap_RXHP[80];
	u1Byte		Pre_IGI;
	u1Byte		Cur_IGI;
	u1Byte		Pre_pw_th;
	u1Byte		Cur_pw_th;
	bool		First_time_enter;
	bool		RXHP_enable;
	u1Byte		TP_Mode;
	struct timer_list PSDTimer;
};

#define ASSOCIATE_ENTRY_NUM					32 /*  Max size of AsocEntry[]. */
#define	ODM_ASSOCIATE_ENTRY_NUM				ASSOCIATE_ENTRY_NUM

/*  This indicates two different the steps. */
/*  In SWAW_STEP_PEAK, driver needs to switch antenna and listen to the signal on the air. */
/*  In SWAW_STEP_DETERMINE, driver just compares the signal captured in SWAW_STEP_PEAK */
/*  with original RSSI to determine if it is necessary to switch antenna. */
#define SWAW_STEP_PEAK		0
#define SWAW_STEP_DETERMINE	1

#define	TP_MODE		0
#define	RSSI_MODE		1
#define	TRAFFIC_LOW	0
#define	TRAFFIC_HIGH	1

struct sw_ant_switch {
	u1Byte		try_flag;
	s4Byte		PreRSSI;
	u1Byte		CurAntenna;
	u1Byte		PreAntenna;
	u1Byte		RSSI_Trying;
	u1Byte		TestMode;
	u1Byte		bTriggerAntennaSwitch;
	u1Byte		SelectAntennaMap;
	u1Byte		RSSI_target;

	/*  Before link Antenna Switch check */
	u1Byte		SWAS_NoLink_State;
	u4Byte		SWAS_NoLink_BK_Reg860;
	bool		ANTA_ON;	/* To indicate Ant A is or not */
	bool		ANTB_ON;	/* To indicate Ant B is on or not */

	s4Byte		RSSI_sum_A;
	s4Byte		RSSI_sum_B;
	s4Byte		RSSI_cnt_A;
	s4Byte		RSSI_cnt_B;

	u8Byte		lastTxOkCnt;
	u8Byte		lastRxOkCnt;
	u8Byte		TXByteCnt_A;
	u8Byte		TXByteCnt_B;
	u8Byte		RXByteCnt_A;
	u8Byte		RXByteCnt_B;
	u1Byte		TrafficLoad;
	struct timer_list SwAntennaSwitchTimer;
	/* Hybrid Antenna Diversity */
	u4Byte		CCK_Ant1_Cnt[ASSOCIATE_ENTRY_NUM];
	u4Byte		CCK_Ant2_Cnt[ASSOCIATE_ENTRY_NUM];
	u4Byte		OFDM_Ant1_Cnt[ASSOCIATE_ENTRY_NUM];
	u4Byte		OFDM_Ant2_Cnt[ASSOCIATE_ENTRY_NUM];
	u4Byte		RSSI_Ant1_Sum[ASSOCIATE_ENTRY_NUM];
	u4Byte		RSSI_Ant2_Sum[ASSOCIATE_ENTRY_NUM];
	u1Byte		TxAnt[ASSOCIATE_ENTRY_NUM];
	u1Byte		TargetSTA;
	u1Byte		antsel;
	u1Byte		RxIdleAnt;
};

struct edca_turbo {
	bool bCurrentTurboEDCA;
	bool bIsCurRDLState;
	u4Byte	prv_traffic_idx; /*  edca turbo */
};

struct odm_rate_adapt {
	u1Byte				Type;				/*  DM_Type_ByFW/DM_Type_ByDriver */
	u1Byte				HighRSSIThresh;		/*  if RSSI > HighRSSIThresh	=> RATRState is DM_RATR_STA_HIGH */
	u1Byte				LowRSSIThresh;		/*  if RSSI <= LowRSSIThresh	=> RATRState is DM_RATR_STA_LOW */
	u1Byte				RATRState;			/*  Current RSSI level, DM_RATR_STA_HIGH/DM_RATR_STA_MIDDLE/DM_RATR_STA_LOW */
	u4Byte				LastRATR;			/*  RATR Register Content */

};

#define IQK_MAC_REG_NUM		4
#define IQK_ADDA_REG_NUM		16
#define IQK_BB_REG_NUM_MAX	10
#define IQK_BB_REG_NUM		9
#define HP_THERMAL_NUM		8

#define AVG_THERMAL_NUM		8
#define IQK_Matrix_REG_NUM	8
#define IQK_Matrix_Settings_NUM	1+24+21

#define		DM_Type_ByFW			0
#define		DM_Type_ByDriver		1

/*  */
/*  Declare for common info */
/*  */
/*  Declare for common info */
/*  */
#define MAX_PATH_NUM_92CS		2

struct odm_phy_status_info {
	u1Byte		RxPWDBAll;
	u1Byte		SignalQuality;	 /*  in 0-100 index. */
	u1Byte		RxMIMOSignalQuality[MAX_PATH_NUM_92CS]; /* EVM */
	u1Byte		RxMIMOSignalStrength[MAX_PATH_NUM_92CS];/*  in 0~100 index */
	s1Byte		RxPower; /*  in dBm Translate from PWdB */
	s1Byte		RecvSignalPower;/*  Real power in dBm for this packet, no beautification and aggregation. Keep this raw info to be used for the other procedures. */
	u1Byte		BTRxRSSIPercentage;
	u1Byte		SignalStrength; /*  in 0-100 index. */
	u1Byte		RxPwr[MAX_PATH_NUM_92CS];/* per-path's pwdb */
	u1Byte		RxSNR[MAX_PATH_NUM_92CS];/* per-path's SNR */
};


struct odm_phy_dbg_info {
	/* ODM Write,debug info */
	s1Byte		RxSNRdB[MAX_PATH_NUM_92CS];
	u8Byte		NumQryPhyStatus;
	u8Byte		NumQryPhyStatusCCK;
	u8Byte		NumQryPhyStatusOFDM;
	/* Others */
	s4Byte		RxEVM[MAX_PATH_NUM_92CS];

};

struct odm_per_pkt_info {
	s8		Rate;
	u8		StationID;
	bool		bPacketMatchBSSID;
	bool		bPacketToSelf;
	bool		bPacketBeacon;
};

struct odm_mac_status_info {
	u1Byte	test;

};

enum odm_ability {
	/*  BB Team */
	ODM_DIG				= 0x00000001,
	ODM_HIGH_POWER		= 0x00000002,
	ODM_CCK_CCA_TH		= 0x00000004,
	ODM_FA_STATISTICS		= 0x00000008,
	ODM_RAMASK			= 0x00000010,
	ODM_RSSI_MONITOR		= 0x00000020,
	ODM_SW_ANTDIV		= 0x00000040,
	ODM_HW_ANTDIV		= 0x00000080,
	ODM_BB_PWRSV			= 0x00000100,
	ODM_2TPATHDIV			= 0x00000200,
	ODM_1TPATHDIV			= 0x00000400,
	ODM_PSD2AFH			= 0x00000800
};

/*  */
/*  2011/20/20 MH For MP driver RT_WLAN_STA =  struct sta_info */
/*  Please declare below ODM relative info in your STA info structure. */
/*  */
struct odm_sta_info {
	/*  Driver Write */
	bool		bUsed;				/*  record the sta status link or not? */
	u1Byte		IOTPeer;			/*  Enum value.	HT_IOT_PEER_E */

	/*  ODM Write */
	/* 1 PHY_STATUS_INFO */
	u1Byte		RSSI_Path[4];		/*  */
	u1Byte		RSSI_Ave;
	u1Byte		RXEVM[4];
	u1Byte		RXSNR[4];

	/*  */
	/* 	Please use compile flag to disable the struictrue for other IC except 88E. */
	/* 	Move To lower layer. */
	/*  */
	/*  ODM Write Wilson will handle this part(said by Luke.Lee) */

};

/*  */
/*  2011/10/20 MH Define Common info enum for all team. */
/*  */
enum odm_common_info_def {

	/*  */
	/*  Fixed value: */
	/*  */

	/* HOOK BEFORE REG INIT----------- */
	ODM_CMNINFO_PLATFORM = 0,
	ODM_CMNINFO_ABILITY,		/*  ODM_ABILITY_E */
	ODM_CMNINFO_INTERFACE,		/*  ODM_INTERFACE_E */
	ODM_CMNINFO_MP_TEST_CHIP,
	ODM_CMNINFO_IC_TYPE,		/*  ODM_IC_TYPE_E */
	ODM_CMNINFO_CUT_VER,		/*  ODM_CUT_VERSION_E */
	ODM_CMNINFO_FAB_VER,		/*  ODM_FAB_E */
	ODM_CMNINFO_RF_TYPE,		/*  ODM_RF_PATH_E or ODM_RF_TYPE_E? */
	ODM_CMNINFO_BOARD_TYPE,		/*  ODM_BOARD_TYPE_E */
	ODM_CMNINFO_EXT_LNA,		/*  true */
	ODM_CMNINFO_EXT_PA,
	ODM_CMNINFO_EXT_TRSW,
	ODM_CMNINFO_PATCH_ID,		/* CUSTOMER ID */
	ODM_CMNINFO_BINHCT_TEST,
	ODM_CMNINFO_BWIFI_TEST,
	ODM_CMNINFO_SMART_CONCURRENT,
	/* HOOK BEFORE REG INIT-----------  */

	/*  */
	/*  Dynamic value: */
	/*  */
/*  POINTER REFERENCE-----------  */
	ODM_CMNINFO_MAC_PHY_MODE,	/*  ODM_MAC_PHY_MODE_E */
	ODM_CMNINFO_TX_UNI,
	ODM_CMNINFO_RX_UNI,
	ODM_CMNINFO_WM_MODE,		/*  ODM_WIRELESS_MODE_E */
	ODM_CMNINFO_BAND,		/*  ODM_BAND_TYPE_E */
	ODM_CMNINFO_SEC_CHNL_OFFSET,	/*  ODM_SEC_CHNL_OFFSET_E */
	ODM_CMNINFO_SEC_MODE,		/*  ODM_SECURITY_E */
	ODM_CMNINFO_BW,			/*  ODM_BW_E */
	ODM_CMNINFO_CHNL,

	ODM_CMNINFO_DMSP_GET_VALUE,
	ODM_CMNINFO_BUDDY_ADAPTOR,
	ODM_CMNINFO_DMSP_IS_MASTER,
	ODM_CMNINFO_SCAN,
	ODM_CMNINFO_POWER_SAVING,
	ODM_CMNINFO_ONE_PATH_CCA,	/*  ODM_CCA_PATH_E */
	ODM_CMNINFO_DRV_STOP,
	ODM_CMNINFO_PNP_IN,
	ODM_CMNINFO_INIT_ON,
	ODM_CMNINFO_ANT_TEST,
	ODM_CMNINFO_NET_CLOSED,
	ODM_CMNINFO_MP_MODE,
/*  POINTER REFERENCE----------- */

/* CALL BY VALUE------------- */
	ODM_CMNINFO_WIFI_DIRECT,
	ODM_CMNINFO_WIFI_DISPLAY,
	ODM_CMNINFO_LINK,
	ODM_CMNINFO_RSSI_MIN,
	ODM_CMNINFO_DBG_COMP,				/*  u8Byte */
	ODM_CMNINFO_DBG_LEVEL,				/*  u4Byte */
	ODM_CMNINFO_RA_THRESHOLD_HIGH,		/*  u1Byte */
	ODM_CMNINFO_RA_THRESHOLD_LOW,		/*  u1Byte */
	ODM_CMNINFO_RF_ANTENNA_TYPE,		/*  u1Byte */
	ODM_CMNINFO_BT_DISABLED,
	ODM_CMNINFO_BT_OPERATION,
	ODM_CMNINFO_BT_DIG,
	ODM_CMNINFO_BT_BUSY,					/* Check Bt is using or not */
	ODM_CMNINFO_BT_DISABLE_EDCA,
/* CALL BY VALUE-------------*/

	/*  */
	/*  Dynamic ptr array hook itms. */
	/*  */
	ODM_CMNINFO_STA_STATUS,
	ODM_CMNINFO_PHY_STATUS,
	ODM_CMNINFO_MAC_STATUS,

	ODM_CMNINFO_MAX,
};

/*  */
/*  2011/10/20 MH Define ODM support ability.  ODM_CMNINFO_ABILITY */
/*  */
enum odm_ability_def {
	/*  */
	/*  BB ODM section BIT 0-15 */
	/*  */
	ODM_BB_DIG					= BIT0,
	ODM_BB_RA_MASK				= BIT1,
	ODM_BB_DYNAMIC_TXPWR		= BIT2,
	ODM_BB_FA_CNT					= BIT3,
	ODM_BB_RSSI_MONITOR			= BIT4,
	ODM_BB_CCK_PD					= BIT5,
	ODM_BB_ANT_DIV				= BIT6,
	ODM_BB_PWR_SAVE				= BIT7,
	ODM_BB_PWR_TRA				= BIT8,
	ODM_BB_RATE_ADAPTIVE			= BIT9,
	ODM_BB_PATH_DIV				= BIT10,
	ODM_BB_PSD					= BIT11,
	ODM_BB_RXHP					= BIT12,

	/*  */
	/*  MAC DM section BIT 16-23 */
	/*  */
	ODM_MAC_EDCA_TURBO			= BIT16,
	ODM_MAC_EARLY_MODE			= BIT17,

	/*  */
	/*  RF ODM section BIT 24-31 */
	/*  */
	ODM_RF_TX_PWR_TRACK			= BIT24,
	ODM_RF_RX_GAIN_TRACK			= BIT25,
	ODM_RF_CALIBRATION				= BIT26,

};

/* 	ODM_CMNINFO_INTERFACE */
enum odm_interface_def {
	ODM_ITRF_PCIE	=	0x1,
	ODM_ITRF_USB	=	0x2,
	ODM_ITRF_SDIO	=	0x4,
	ODM_ITRF_ALL	=	0x7,
};

/*  ODM_CMNINFO_IC_TYPE */
enum odm_ic_type {
	ODM_RTL8192S	=	BIT0,
	ODM_RTL8192C	=	BIT1,
	ODM_RTL8192D	=	BIT2,
	ODM_RTL8723A	=	BIT3,
	ODM_RTL8188E	=	BIT4,
	ODM_RTL8812	=	BIT5,
	ODM_RTL8821	=	BIT6,
};

#define ODM_IC_11N_SERIES		(ODM_RTL8192S|ODM_RTL8192C|ODM_RTL8192D|ODM_RTL8723A|ODM_RTL8188E)
#define ODM_IC_11AC_SERIES		(ODM_RTL8812)

/* ODM_CMNINFO_CUT_VER */
enum odm_cut_version {
	ODM_CUT_A		=	1,
	ODM_CUT_B		=	2,
	ODM_CUT_C		=	3,
	ODM_CUT_D		=	4,
	ODM_CUT_E		=	5,
	ODM_CUT_F		=	6,
	ODM_CUT_TEST	=	7,
};

/*  ODM_CMNINFO_FAB_VER */
enum odm_fab_Version {
	ODM_TSMC	=	0,
	ODM_UMC		=	1,
};

/*  ODM_CMNINFO_RF_TYPE */
/*  */
/*  For example 1T2R (A+AB = BIT0|BIT4|BIT5) */
/*  */
enum odm_rf_path {
	ODM_RF_TX_A	=	BIT0,
	ODM_RF_TX_B	=	BIT1,
	ODM_RF_TX_C	=	BIT2,
	ODM_RF_TX_D	=	BIT3,
	ODM_RF_RX_A	=	BIT4,
	ODM_RF_RX_B	=	BIT5,
	ODM_RF_RX_C	=	BIT6,
	ODM_RF_RX_D	=	BIT7,
};

enum odm_rf_type {
	ODM_1T1R	=	0,
	ODM_1T2R	=	1,
	ODM_2T2R	=	2,
	ODM_2T3R	=	3,
	ODM_2T4R	=	4,
	ODM_3T3R	=	5,
	ODM_3T4R	=	6,
	ODM_4T4R	=	7,
};

/*  ODM Dynamic common info value definition */

enum odm_mac_phy_mode {
	ODM_SMSP	= 0,
	ODM_DMSP	= 1,
	ODM_DMDP	= 2,
};

enum odm_bt_coexist {
	ODM_BT_BUSY		= 1,
	ODM_BT_ON			= 2,
	ODM_BT_OFF		= 3,
	ODM_BT_NONE		= 4,
};

/*  ODM_CMNINFO_OP_MODE */
enum odm_operation_mode {
	ODM_NO_LINK		= BIT0,
	ODM_LINK			= BIT1,
	ODM_SCAN			= BIT2,
	ODM_POWERSAVE	= BIT3,
	ODM_AP_MODE		= BIT4,
	ODM_CLIENT_MODE	= BIT5,
	ODM_AD_HOC		= BIT6,
	ODM_WIFI_DIRECT	= BIT7,
	ODM_WIFI_DISPLAY	= BIT8,
};

/*  ODM_CMNINFO_WM_MODE */
enum odm_wireless_mode {
	ODM_WM_UNKNOW	= 0x0,
	ODM_WM_B	= BIT0,
	ODM_WM_G	= BIT1,
	ODM_WM_A	= BIT2,
	ODM_WM_N24G	= BIT3,
	ODM_WM_N5G	= BIT4,
	ODM_WM_AUTO	= BIT5,
	ODM_WM_AC	= BIT6,
};

/*  ODM_CMNINFO_BAND */
enum odm_band_type {
	ODM_BAND_2_4G	= BIT0,
	ODM_BAND_5G		= BIT1,
};

/*  ODM_CMNINFO_SEC_CHNL_OFFSET */
enum odm_sec_chnl_offset {
	ODM_DONT_CARE	= 0,
	ODM_BELOW		= 1,
	ODM_ABOVE			= 2
};

/*  ODM_CMNINFO_SEC_MODE */
enum odm_security {
	ODM_SEC_OPEN			= 0,
	ODM_SEC_WEP40		= 1,
	ODM_SEC_TKIP			= 2,
	ODM_SEC_RESERVE			= 3,
	ODM_SEC_AESCCMP			= 4,
	ODM_SEC_WEP104		= 5,
	ODM_WEP_WPA_MIXED    = 6, /*  WEP + WPA */
	ODM_SEC_SMS4			= 7,
};

/*  ODM_CMNINFO_BW */
enum odm_bw {
	ODM_BW20M		= 0,
	ODM_BW40M		= 1,
	ODM_BW80M		= 2,
	ODM_BW160M		= 3,
	ODM_BW10M		= 4,
};

/*  ODM_CMNINFO_BOARD_TYPE */
enum odm_board_type {
	ODM_BOARD_NORMAL	= 0,
	ODM_BOARD_HIGHPWR	= 1,
	ODM_BOARD_MINICARD	= 2,
	ODM_BOARD_SLIM		= 3,
	ODM_BOARD_COMBO		= 4,
};

/*  ODM_CMNINFO_ONE_PATH_CCA */
enum odm_cca_path {
	ODM_CCA_2R			= 0,
	ODM_CCA_1R_A			= 1,
	ODM_CCA_1R_B			= 2,
};

struct odm_ra_info {
	u1Byte RateID;
	u4Byte RateMask;
	u4Byte RAUseRate;
	u1Byte RateSGI;
	u1Byte RssiStaRA;
	u1Byte PreRssiStaRA;
	u1Byte SGIEnable;
	u1Byte DecisionRate;
	u1Byte PreRate;
	u1Byte HighestRate;
	u1Byte LowestRate;
	u4Byte NscUp;
	u4Byte NscDown;
	u2Byte RTY[5];
	u4Byte TOTAL;
	u2Byte DROP;
	u1Byte Active;
	u2Byte RptTime;
	u1Byte RAWaitingCounter;
	u1Byte RAPendingCounter;
	u1Byte PTActive;  /*  on or off */
	u1Byte PTTryState;  /*  0 trying state, 1 for decision state */
	u1Byte PTStage;  /*  0~6 */
	u1Byte PTStopCount; /* Stop PT counter */
	u1Byte PTPreRate;  /*  if rate change do PT */
	u1Byte PTPreRssi; /*  if RSSI change 5% do PT */
	u1Byte PTModeSS;  /*  decide whitch rate should do PT */
	u1Byte RAstage;  /*  StageRA, decide how many times RA will be done between PT */
	u1Byte PTSmoothFactor;
};

struct ijk_matrix_regs_set {
	bool		bIQKDone;
	s4Byte		Value[1][IQK_Matrix_REG_NUM];
};

struct odm_rf_cal {
	/* for tx power tracking */

	u4Byte	RegA24; /*  for TempCCK */
	s4Byte	RegE94;
	s4Byte	RegE9C;
	s4Byte	RegEB4;
	s4Byte	RegEBC;

	/* u1Byte bTXPowerTracking; */
	u1Byte		TXPowercount;
	bool bTXPowerTrackingInit;
	bool bTXPowerTracking;
	u1Byte		TxPowerTrackControl; /* for mp mode, turn off txpwrtracking as default */
	u1Byte		TM_Trigger;
	u1Byte		InternalPA5G[2];	/* pathA / pathB */

	u1Byte		ThermalMeter[2];    /*  ThermalMeter, index 0 for RFIC0, and 1 for RFIC1 */
	u1Byte		ThermalValue;
	u1Byte		ThermalValue_LCK;
	u1Byte		ThermalValue_IQK;
	u1Byte	ThermalValue_DPK;
	u1Byte	ThermalValue_AVG[AVG_THERMAL_NUM];
	u1Byte	ThermalValue_AVG_index;
	u1Byte	ThermalValue_RxGain;
	u1Byte	ThermalValue_Crystal;
	u1Byte	ThermalValue_DPKstore;
	u1Byte	ThermalValue_DPKtrack;
	bool	TxPowerTrackingInProgress;
	bool	bDPKenable;

	bool	bReloadtxpowerindex;
	u1Byte	bRfPiEnable;
	u4Byte	TXPowerTrackingCallbackCnt; /* cosa add for debug */

	u1Byte	bCCKinCH14;
	u1Byte	CCK_index;
	u1Byte	OFDM_index[2];
	bool bDoneTxpower;

	u1Byte	ThermalValue_HP[HP_THERMAL_NUM];
	u1Byte	ThermalValue_HP_index;
	struct ijk_matrix_regs_set IQKMatrixRegSetting[IQK_Matrix_Settings_NUM];

	u1Byte	Delta_IQK;
	u1Byte	Delta_LCK;

	/* for IQK */
	u4Byte	RegC04;
	u4Byte	Reg874;
	u4Byte	RegC08;
	u4Byte	RegB68;
	u4Byte	RegB6C;
	u4Byte	Reg870;
	u4Byte	Reg860;
	u4Byte	Reg864;

	bool	bIQKInitialized;
	bool bLCKInProgress;
	bool	bAntennaDetected;
	u4Byte	ADDA_backup[IQK_ADDA_REG_NUM];
	u4Byte	IQK_MAC_backup[IQK_MAC_REG_NUM];
	u4Byte	IQK_BB_backup_recover[9];
	u4Byte	IQK_BB_backup[IQK_BB_REG_NUM];

	/* for APK */
	u4Byte	APKoutput[2][2]; /* path A/B; output1_1a/output1_2a */
	u1Byte	bAPKdone;
	u1Byte	bAPKThermalMeterIgnore;
	u1Byte	bDPdone;
	u1Byte	bDPPathAOK;
	u1Byte	bDPPathBOK;
};

/*  ODM Dynamic common info value definition */

struct fast_ant_train {
	u1Byte	Bssid[6];
	u1Byte	antsel_rx_keep_0;
	u1Byte	antsel_rx_keep_1;
	u1Byte	antsel_rx_keep_2;
	u4Byte	antSumRSSI[7];
	u4Byte	antRSSIcnt[7];
	u4Byte	antAveRSSI[7];
	u1Byte	FAT_State;
	u4Byte	TrainIdx;
	u1Byte	antsel_a[ODM_ASSOCIATE_ENTRY_NUM];
	u1Byte	antsel_b[ODM_ASSOCIATE_ENTRY_NUM];
	u1Byte	antsel_c[ODM_ASSOCIATE_ENTRY_NUM];
	u4Byte	MainAnt_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	u4Byte	AuxAnt_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	u4Byte	MainAnt_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
	u4Byte	AuxAnt_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
	u1Byte	RxIdleAnt;
	bool		bBecomeLinked;
};

enum fat_state {
	FAT_NORMAL_STATE		= 0,
	FAT_TRAINING_STATE		= 1,
};

enum ant_div_type {
	NO_ANTDIV			= 0xFF,
	CG_TRX_HW_ANTDIV		= 0x01,
	CGCS_RX_HW_ANTDIV		= 0x02,
	FIXED_HW_ANTDIV			= 0x03,
	CG_TRX_SMART_ANTDIV		= 0x04,
	CGCS_RX_SW_ANTDIV		= 0x05,
};

/*  2011/09/22 MH Copy from SD4 defined structure. We use to support PHY DM integration. */
struct odm_dm_struct {
	/* 	Add for different team use temporarily */
	struct adapter *		Adapter;		/*  For CE/NIC team */
	struct rtl8192cd_priv *priv;			/*  For AP/ADSL team */
	/*  WHen you use Adapter or priv pointer, you must make sure the pointer is ready. */
	bool			odm_ready;

	struct rtl8192cd_priv *fake_priv;
	u8Byte			DebugComponents;
	u4Byte			DebugLevel;

/*  ODM HANDLE, DRIVER NEEDS NOT TO HOOK------ */
	bool			bCckHighPower;
	u1Byte			RFPathRxEnable;		/*  ODM_CMNINFO_RFPATH_ENABLE */
	u1Byte			ControlChannel;
/*  ODM HANDLE, DRIVER NEEDS NOT TO HOOK------ */

/* 1  COMMON INFORMATION */
	/*  Init Value */
/* HOOK BEFORE REG INIT----------- */
	/*  ODM Platform info AP/ADSL/CE/MP = 1/2/3/4 */
	u1Byte			SupportPlatform;
	/*  ODM Support Ability DIG/RATR/TX_PWR_TRACK/ �K�K = 1/2/3/�K */
	u4Byte			SupportAbility;
	/*  ODM PCIE/USB/SDIO/GSPI = 0/1/2/3 */
	u1Byte			SupportInterface;
	/*  ODM composite or independent. Bit oriented/ 92C+92D+ .... or any other type = 1/2/3/... */
	u4Byte			SupportICType;
	/*  Cut Version TestChip/A-cut/B-cut... = 0/1/2/3/... */
	u1Byte			CutVersion;
	/*  Fab Version TSMC/UMC = 0/1 */
	u1Byte			FabVersion;
	/*  RF Type 4T4R/3T3R/2T2R/1T2R/1T1R/... */
	u1Byte			RFType;
	/*  Board Type Normal/HighPower/MiniCard/SLIM/Combo/... = 0/1/2/3/4/... */
	u1Byte			BoardType;
	/*  with external LNA  NO/Yes = 0/1 */
	u1Byte			ExtLNA;
	/*  with external PA  NO/Yes = 0/1 */
	u1Byte			ExtPA;
	/*  with external TRSW  NO/Yes = 0/1 */
	u1Byte			ExtTRSW;
	u1Byte			PatchID; /* Customer ID */
	bool			bInHctTest;
	bool			bWIFITest;

	bool			bDualMacSmartConcurrent;
	u4Byte			BK_SupportAbility;
	u1Byte			AntDivType;
/* HOOK BEFORE REG INIT----------- */

	/*  */
	/*  Dynamic Value */
	/*  */
/*  POINTER REFERENCE----------- */

	u1Byte			u1Byte_temp;
	bool			bool_temp;
	struct adapter *adapter_temp;

	/*  MAC PHY Mode SMSP/DMSP/DMDP = 0/1/2 */
	u1Byte			*pMacPhyMode;
	/* TX Unicast byte count */
	u8Byte			*pNumTxBytesUnicast;
	/* RX Unicast byte count */
	u8Byte			*pNumRxBytesUnicast;
	/*  Wireless mode B/G/A/N = BIT0/BIT1/BIT2/BIT3 */
	u1Byte			*pWirelessMode; /* ODM_WIRELESS_MODE_E */
	/*  Frequence band 2.4G/5G = 0/1 */
	u1Byte			*pBandType;
	/*  Secondary channel offset don't_care/below/above = 0/1/2 */
	u1Byte			*pSecChOffset;
	/*  Security mode Open/WEP/AES/TKIP = 0/1/2/3 */
	u1Byte			*pSecurity;
	/*  BW info 20M/40M/80M = 0/1/2 */
	u1Byte			*pBandWidth;
	/*  Central channel location Ch1/Ch2/.... */
	u1Byte			*pChannel;	/* central channel number */
	/*  Common info for 92D DMSP */

	bool			*pbGetValueFromOtherMac;
	struct adapter **pBuddyAdapter;
	bool			*pbMasterOfDMSP; /* MAC0: master, MAC1: slave */
	/*  Common info for Status */
	bool			*pbScanInProcess;
	bool			*pbPowerSaving;
	/*  CCA Path 2-path/path-A/path-B = 0/1/2; using ODM_CCA_PATH_E. */
	u1Byte			*pOnePathCCA;
	/* pMgntInfo->AntennaTest */
	u1Byte			*pAntennaTest;
	bool			*pbNet_closed;
/*  POINTER REFERENCE----------- */
	/*  */
/* CALL BY VALUE------------- */
	bool			bWIFI_Direct;
	bool			bWIFI_Display;
	bool			bLinked;
	u1Byte			RSSI_Min;
	u1Byte			InterfaceIndex; /*  Add for 92D  dual MAC: 0--Mac0 1--Mac1 */
	bool			bIsMPChip;
	bool			bOneEntryOnly;
	/*  Common info for BTDM */
	bool			bBtDisabled;			/*  BT is disabled */
	bool			bBtHsOperation;		/*  BT HS mode is under progress */
	u1Byte			btHsDigVal;			/*  use BT rssi to decide the DIG value */
	bool			bBtDisableEdcaTurbo;	/*  Under some condition, don't enable the EDCA Turbo */
	bool			bBtBusy;			/*  BT is busy. */
/* CALL BY VALUE------------- */

	/* 2 Define STA info. */
	/*  _ODM_STA_INFO */
	/*  2012/01/12 MH For MP, we need to reduce one array pointer for default port.?? */
	struct sta_info *pODM_StaInfo[ODM_ASSOCIATE_ENTRY_NUM];

	u2Byte			CurrminRptTime;
	struct odm_ra_info RAInfo[ODM_ASSOCIATE_ENTRY_NUM]; /* Use MacID as array index. STA MacID=0, VWiFi Client MacID={1, ODM_ASSOCIATE_ENTRY_NUM-1} */
	/*  */
	/*  2012/02/14 MH Add to share 88E ra with other SW team. */
	/*  We need to colelct all support abilit to a proper area. */
	/*  */
	bool				RaSupport88E;

	/*  Define ........... */

	/*  Latest packet phy info (ODM write) */
	struct odm_phy_dbg_info PhyDbgInfo;

	/*  Latest packet phy info (ODM write) */
	struct odm_mac_status_info *pMacInfo;

	/*  Different Team independt structure?? */

	/* ODM Structure */
	struct fast_ant_train DM_FatTable;
	struct rtw_dig	DM_DigTable;
	struct rtl_ps	DM_PSTable;
	struct dyn_primary_cca DM_PriCCA;
	struct rx_hpc	DM_RXHP_Table;
	struct false_alarm_stats FalseAlmCnt;
	struct false_alarm_stats FlaseAlmCntBuddyAdapter;
	struct sw_ant_switch DM_SWAT_Table;
	bool		RSSI_test;

	struct edca_turbo DM_EDCA_Table;
	u4Byte		WMMEDCA_BE;
	/*  Copy from SD4 structure */
	/*  */
	/*  ================================================== */
	/*  */

	bool			*pbDriverStopped;
	bool			*pbDriverIsGoingToPnpSetPowerSleep;
	bool			*pinit_adpt_in_progress;

	/* PSD */
	bool			bUserAssignLevel;
	struct timer_list PSDTimer;
	u1Byte			RSSI_BT;			/* come from BT */
	bool			bPSDinProcess;
	bool			bDMInitialGainEnable;

	/* for rate adaptive, in fact,  88c/92c fw will handle this */
	u1Byte			bUseRAMask;

	struct odm_rate_adapt RateAdaptive;


	struct odm_rf_cal RFCalibrateInfo;

	/*  */
	/*  TX power tracking */
	/*  */
	u1Byte			BbSwingIdxOfdm;
	u1Byte			BbSwingIdxOfdmCurrent;
	u1Byte			BbSwingIdxOfdmBase;
	bool			BbSwingFlagOfdm;
	u1Byte			BbSwingIdxCck;
	u1Byte			BbSwingIdxCckCurrent;
	u1Byte			BbSwingIdxCckBase;
	bool			BbSwingFlagCck;
	u1Byte			*mp_mode;
	/*  */
	/*  ODM system resource. */
	/*  */

	/*  ODM relative time. */
	struct timer_list PathDivSwitchTimer;
	/* 2011.09.27 add for Path Diversity */
	struct timer_list CCKPathDiversityTimer;
	struct timer_list FastAntTrainingTimer;
};		/*  DM_Dynamic_Mechanism_Structure */

#define ODM_RF_PATH_MAX 2

enum ODM_RF_RADIO_PATH {
    ODM_RF_PATH_A = 0,   /* Radio Path A */
    ODM_RF_PATH_B = 1,   /* Radio Path B */
    ODM_RF_PATH_C = 2,   /* Radio Path C */
    ODM_RF_PATH_D = 3,   /* Radio Path D */
};

enum ODM_RF_CONTENT {
	odm_radioa_txt = 0x1000,
	odm_radiob_txt = 0x1001,
	odm_radioc_txt = 0x1002,
	odm_radiod_txt = 0x1003
};

enum odm_bb_config_type {
    CONFIG_BB_PHY_REG,
    CONFIG_BB_AGC_TAB,
    CONFIG_BB_AGC_TAB_2G,
    CONFIG_BB_AGC_TAB_5G,
    CONFIG_BB_PHY_REG_PG,
};

/*  Status code */
enum rt_status {
	RT_STATUS_SUCCESS,
	RT_STATUS_FAILURE,
	RT_STATUS_PENDING,
	RT_STATUS_RESOURCE,
	RT_STATUS_INVALID_CONTEXT,
	RT_STATUS_INVALID_PARAMETER,
	RT_STATUS_NOT_SUPPORT,
	RT_STATUS_OS_API_FAILED,
};

/* 3=========================================================== */
/* 3 DIG */
/* 3=========================================================== */

enum dm_dig_op {
	RT_TYPE_THRESH_HIGH	= 0,
	RT_TYPE_THRESH_LOW	= 1,
	RT_TYPE_BACKOFF		= 2,
	RT_TYPE_RX_GAIN_MIN	= 3,
	RT_TYPE_RX_GAIN_MAX	= 4,
	RT_TYPE_ENABLE		= 5,
	RT_TYPE_DISABLE		= 6,
	DIG_OP_TYPE_MAX
};

#define		DM_DIG_THRESH_HIGH			40
#define		DM_DIG_THRESH_LOW			35

#define		DM_SCAN_RSSI_TH				0x14 /* scan return issue for LC */


#define		DM_false_ALARM_THRESH_LOW	400
#define		DM_false_ALARM_THRESH_HIGH	1000

#define		DM_DIG_MAX_NIC				0x3e
#define		DM_DIG_MIN_NIC				0x1e /* 0x22/0x1c */

#define		DM_DIG_MAX_AP					0x32
#define		DM_DIG_MIN_AP					0x20

#define		DM_DIG_MAX_NIC_HP			0x46
#define		DM_DIG_MIN_NIC_HP			0x2e

#define		DM_DIG_MAX_AP_HP				0x42
#define		DM_DIG_MIN_AP_HP				0x30

/* vivi 92c&92d has different definition, 20110504 */
/* this is for 92c */
#define		DM_DIG_FA_TH0				0x200/* 0x20 */
#define		DM_DIG_FA_TH1				0x300/* 0x100 */
#define		DM_DIG_FA_TH2				0x400/* 0x200 */
/* this is for 92d */
#define		DM_DIG_FA_TH0_92D			0x100
#define		DM_DIG_FA_TH1_92D			0x400
#define		DM_DIG_FA_TH2_92D			0x600

#define		DM_DIG_BACKOFF_MAX			12
#define		DM_DIG_BACKOFF_MIN			-4
#define		DM_DIG_BACKOFF_DEFAULT		10

/* 3=========================================================== */
/* 3 AGC RX High Power Mode */
/* 3=========================================================== */
#define          LNA_Low_Gain_1                      0x64
#define          LNA_Low_Gain_2                      0x5A
#define          LNA_Low_Gain_3                      0x58

#define          FA_RXHP_TH1                           5000
#define          FA_RXHP_TH2                           1500
#define          FA_RXHP_TH3                             800
#define          FA_RXHP_TH4                             600
#define          FA_RXHP_TH5                             500

/* 3=========================================================== */
/* 3 EDCA */
/* 3=========================================================== */

/* 3=========================================================== */
/* 3 Dynamic Tx Power */
/* 3=========================================================== */
/* Dynamic Tx Power Control Threshold */
#define		TX_POWER_NEAR_FIELD_THRESH_LVL2	74
#define		TX_POWER_NEAR_FIELD_THRESH_LVL1	67
#define		TX_POWER_NEAR_FIELD_THRESH_AP		0x3F

#define		TxHighPwrLevel_Normal		0
#define		TxHighPwrLevel_Level1		1
#define		TxHighPwrLevel_Level2		2
#define		TxHighPwrLevel_BT1			3
#define		TxHighPwrLevel_BT2			4
#define		TxHighPwrLevel_15			5
#define		TxHighPwrLevel_35			6
#define		TxHighPwrLevel_50			7
#define		TxHighPwrLevel_70			8
#define		TxHighPwrLevel_100			9

/* 3=========================================================== */
/* 3 Rate Adaptive */
/* 3=========================================================== */
#define		DM_RATR_STA_INIT			0
#define		DM_RATR_STA_HIGH			1
#define			DM_RATR_STA_MIDDLE		2
#define			DM_RATR_STA_LOW			3

/* 3=========================================================== */
/* 3 BB Power Save */
/* 3=========================================================== */


enum dm_1r_cca {
	CCA_1R =0,
	CCA_2R = 1,
	CCA_MAX = 2,
};

enum dm_rf {
	RF_Save =0,
	RF_Normal = 1,
	RF_MAX = 2,
};

/* 3=========================================================== */
/* 3 Antenna Diversity */
/* 3=========================================================== */
enum dm_swas {
	Antenna_A = 1,
	Antenna_B = 2,
	Antenna_MAX = 3,
};


/*  Maximal number of antenna detection mechanism needs to perform, added by Roger, 2011.12.28. */
#define	MAX_ANTENNA_DETECTION_CNT	10

/*  */
/*  Extern Global Variables. */
/*  */
#define	OFDM_TABLE_SIZE_92C	37
#define	OFDM_TABLE_SIZE_92D	43
#define	CCK_TABLE_SIZE		33

extern	u4Byte OFDMSwingTable[OFDM_TABLE_SIZE_92D];
extern	u1Byte CCKSwingTable_Ch1_Ch13[CCK_TABLE_SIZE][8];
extern	u1Byte CCKSwingTable_Ch14 [CCK_TABLE_SIZE][8];



/*  */
/*  check Sta pointer valid or not */
/*  */
#define IS_STA_VALID(pSta)		(pSta)
/*  20100514 Joseph: Add definition for antenna switching test after link. */
/*  This indicates two different the steps. */
/*  In SWAW_STEP_PEAK, driver needs to switch antenna and listen to the signal on the air. */
/*  In SWAW_STEP_DETERMINE, driver just compares the signal captured in SWAW_STEP_PEAK */
/*  with original RSSI to determine if it is necessary to switch antenna. */
#define SWAW_STEP_PEAK		0
#define SWAW_STEP_DETERMINE	1

void ODM_Write_DIG(struct odm_dm_struct *pDM_Odm,		u1Byte	CurrentIGI);
void ODM_Write_CCK_CCA_Thres(struct odm_dm_struct *pDM_Odm, 	u1Byte	CurCCK_CCAThres);

void
ODM_SetAntenna(
		struct odm_dm_struct *pDM_Odm,
		u1Byte		Antenna);


#define dm_RF_Saving	ODM_RF_Saving
void ODM_RF_Saving(		struct odm_dm_struct *pDM_Odm,
								u1Byte		bForceInNormal );

#define SwAntDivRestAfterLink	ODM_SwAntDivRestAfterLink
void ODM_SwAntDivRestAfterLink(		struct odm_dm_struct *pDM_Odm);

#define dm_CheckTXPowerTracking		ODM_TXPowerTrackingCheck
void
ODM_TXPowerTrackingCheck(
			struct odm_dm_struct *pDM_Odm
	);

bool
ODM_RAStateCheck(
			struct odm_dm_struct *pDM_Odm,
			s4Byte			RSSI,
			bool			bForceUpdate,
			pu1Byte			pRATRState
	);

#define dm_SWAW_RSSI_Check	ODM_SwAntDivChkPerPktRssi
void ODM_SwAntDivChkPerPktRssi(struct odm_dm_struct *pDM_Odm, u1Byte StationID, struct odm_phy_status_info *pPhyInfo);

u4Byte ConvertTo_dB(u4Byte Value);

u4Byte
GetPSDData(
	struct odm_dm_struct *pDM_Odm,
	unsigned int	point,
	u1Byte initial_gain_psd);

void
odm_DIGbyRSSI_LPS(
			struct odm_dm_struct *pDM_Odm
	);

u4Byte ODM_Get_Rate_Bitmap(
		struct odm_dm_struct *pDM_Odm,
		u4Byte		macid,
		u4Byte		ra_mask,
		u1Byte		rssi_level);

void ODM_DMInit( 	struct odm_dm_struct *pDM_Odm);

void
ODM_DMWatchdog(
			struct odm_dm_struct *pDM_Odm			/*  For common use in the future */
	);

void
ODM_CmnInfoInit(
			struct odm_dm_struct *pDM_Odm,
			enum odm_common_info_def CmnInfo,
			u4Byte			Value
	);

void
ODM_CmnInfoHook(
			struct odm_dm_struct *pDM_Odm,
			enum odm_common_info_def CmnInfo,
			void *			pValue
	);

void
ODM_CmnInfoPtrArrayHook(
			struct odm_dm_struct *pDM_Odm,
			enum odm_common_info_def CmnInfo,
			u2Byte			Index,
			void *			pValue
	);

void
ODM_CmnInfoUpdate(
			struct odm_dm_struct *pDM_Odm,
			u4Byte			CmnInfo,
			u8Byte			Value
	);

void
ODM_InitAllTimers(
    struct odm_dm_struct *pDM_Odm
    );

void
ODM_CancelAllTimers(
    struct odm_dm_struct *pDM_Odm
    );

void
ODM_ReleaseAllTimers(
    struct odm_dm_struct *pDM_Odm
    );

void
ODM_ResetIQKResult(
    struct odm_dm_struct *pDM_Odm
    );

void
ODM_AntselStatistics_88C(
			struct odm_dm_struct *pDM_Odm,
			u1Byte			MacId,
			u4Byte			PWDBAll,
			bool			isCCKrate
);

void
ODM_SingleDualAntennaDefaultSetting(
			struct odm_dm_struct *pDM_Odm
	);

bool
ODM_SingleDualAntennaDetection(
			struct odm_dm_struct *pDM_Odm,
			u1Byte			mode
	);

void odm_dtc(struct odm_dm_struct *pDM_Odm);

#endif
