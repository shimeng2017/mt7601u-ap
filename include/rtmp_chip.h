/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology	5th	Rd.
 * Science-based Industrial	Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2004, Ralink Technology, Inc.
 *
 * All rights reserved.	Ralink's source	code is	an unpublished work	and	the
 * use of a	copyright notice does not imply	otherwise. This	source code
 * contains	confidential trade secret material of Ralink Tech. Any attemp
 * or participation	in deciphering,	decoding, reverse engineering or in	any
 * way altering	the	source code	is stricitly prohibited, unless	the	prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	rtmp_chip.h

	Abstract:
	Ralink Wireless Chip related definition & structures

	Revision History:
	Who			When		  What
	--------	----------	  ----------------------------------------------
*/

#ifndef	__RTMP_CHIP_H__
#define	__RTMP_CHIP_H__

#include "rtmp_type.h"

struct _RTMP_ADAPTER;
struct _RSSI_SAMPLE;

#include "mac_ral/pbf.h"

#include "eeprom.h"


#ifdef RTMP_MAC_USB
#include "mac_ral/rtmp_mac.h"
#include "mac_ral/mac_usb.h"
#endif /* RTMP_MAC_USB */


















#ifdef RT3290
#include "chip/rt3290.h"
#endif /* RT3290 */

#ifdef RT65xx
#include "chip/rt6590.h"
#endif /* RT65xx */

#ifdef RT8592
#include "chip/rt6590.h"
#endif /* RT8592 */

#include "rtmp_mcu.h"

#ifdef MT7601
#include "chip/mt7601.h"
#endif /* MT7601 */

#define IS_RT3090A(_pAd)    ((((_pAd)->MACVersion & 0xffff0000) == 0x30900000))

/* We will have a cost down version which mac version is 0x3090xxxx */
#define IS_RT3090(_pAd)     ((((_pAd)->MACVersion & 0xffff0000) == 0x30710000) || (IS_RT3090A(_pAd)))

#define IS_RT3070(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x30700000)
#define IS_RT3071(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x30710000)
#define IS_RT2070(_pAd)		(((_pAd)->RfIcType == RFIC_2020) || ((_pAd)->EFuseTag == 0x27))

#define IS_RT2860(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x28600000)
#define IS_RT2872(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x28720000)
#define IS_RT2880(_pAd)		(IS_RT2860(_pAd) && IS_RBUS_INF(_pAd))

#define IS_RT30xx(_pAd)		(((_pAd)->MACVersion & 0xfff00000) == 0x30700000||IS_RT3090A(_pAd)||IS_RT3390(_pAd))

#define IS_RT3052B(_pAd)	(((_pAd)->CommonCfg.CID == 0x102) && (((_pAd)->CommonCfg.CN >> 16) == 0x3033)) 
#define IS_RT3052(_pAd)		(((_pAd)->MACVersion == 0x28720200) && (_pAd->Antenna.field.TxPath == 2))
#define IS_RT3050(_pAd)		(((_pAd)->MACVersion == 0x28720200) && ((_pAd)->RfIcType == RFIC_3020))
#define IS_RT3350(_pAd)		(((_pAd)->MACVersion == 0x28720200) && ((_pAd)->RfIcType == RFIC_3320))
#define IS_RT3352(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x33520000)
#define IS_RT5350(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x53500000)
#define IS_RT305x(_pAd)		(IS_RT3050(_pAd) || IS_RT3052(_pAd) || IS_RT3350(_pAd) || IS_RT3352(_pAd) || IS_RT5350(_pAd))
#define IS_RT3050_3052_3350(_pAd) (\
	((_pAd)->MACVersion == 0x28720200) && \
	((((_pAd)->CommonCfg.CN >> 16) == 0x3333) || (((_pAd)->CommonCfg.CN >> 16) == 0x3033)) \
)


/* RT3572, 3592, 3562, 3062 share the same MAC version */
#define IS_RT3572(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x35720000)

/* Check if it is RT3xxx, or Specified ID in registry for debug */
#define IS_DEV_RT3xxx(_pAd)( \
	(_pAd->DeviceID == NIC3090_PCIe_DEVICE_ID) || \
	(_pAd->DeviceID == NIC3091_PCIe_DEVICE_ID) || \
	(_pAd->DeviceID == NIC3092_PCIe_DEVICE_ID) || \
	(_pAd->DeviceID == NIC3592_PCIe_DEVICE_ID) || \
	((_pAd->DeviceID == NIC3593_PCI_OR_PCIe_DEVICE_ID) && (RT3593OverPCIe(_pAd))) \
)

#define RT3593_DEVICE_ID_CHECK(__DevId)			\
	(0)

#define RT3592_DEVICE_ID_CHECK(__DevId)			\
	(__DevId == NIC3592_PCIe_DEVICE_ID)

#define IS_RT2883(_pAd)		(0)

#define IS_RT3883(_pAd)		(0)

#define IS_VERSION_BEFORE_F(_pAd)			(((_pAd)->MACVersion&0xffff) <= 0x0211)
/* F version is 0x0212, E version is 0x0211. 309x can save more power after F version. */
#define IS_VERSION_AFTER_F(_pAd)			((((_pAd)->MACVersion&0xffff) >= 0x0212) || (((_pAd)->b3090ESpecialChip == TRUE)))

#define IS_RT3290(_pAd)	(((_pAd)->MACVersion & 0xffff0000) == 0x32900000)
#define IS_RT3290LE(_pAd)   ((((_pAd)->MACVersion & 0xffffffff) >= 0x32900011))

/* 3593 */
#define IS_RT3593(_pAd) (((_pAd)->MACVersion & 0xFFFF0000) == 0x35930000)

/* RT5392 */
#define IS_RT5392(_pAd)   ((_pAd->MACVersion & 0xFFFF0000) == 0x53920000) /* Include RT5392, RT5372 and RT5362 */

/* RT5390 */
#define IS_RT5390(_pAd)   ((((_pAd)->MACVersion & 0xFFFF0000) == 0x53900000) || IS_RT5390H(_pAd)) /* Include RT5390, RT5370 and RT5360 */

/* RT5390F */
#define IS_RT5390F(_pAd)	((IS_RT5390(_pAd)) && (((_pAd)->MACVersion & 0x0000FFFF) >= 0x0502))

/* RT5370G */
#define IS_RT5370G(_pAd)	((IS_RT5390(_pAd)) && (((_pAd)->MACVersion & 0x0000FFFF) >= 0x0503)) /* support HW PPAD ( the hardware rx antenna diversity ) */

/* RT5390R */
#define IS_RT5390R(_pAd)   ((IS_RT5390(_pAd)) && (((_pAd)->MACVersion & 0x0000FFFF) == 0x1502)) /* support HW PPAD ( the hardware rx antenna diversity ) */

/* PCIe interface NIC */
#define IS_MINI_CARD(_pAd) ((_pAd)->Antenna.field.BoardType == BOARD_TYPE_MINI_CARD)

/* 5390U (5370 using PCIe interface) */
#define IS_RT5390U(_pAd)   (IS_MINI_CARD(_pAd) && ((_pAd)->MACVersion & 0xFFFF0000) == 0x53900000)

/* RT5390H */
#define IS_RT5390H(_pAd)   (((_pAd->MACVersion & 0xFFFF0000) == 0x53910000) && (((_pAd)->MACVersion & 0x0000FFFF) >= 0x1500))

/* RT5390BC8 (WiFi + BT) */


/* RT5390D */
#define IS_RT5390D(_pAd)	((IS_RT5390(_pAd)) && (((_pAd)->MACVersion & 0x0000FFFF) >= 0x0502))

/* RT5392C */
#define IS_RT5392C(_pAd)	((IS_RT5392(_pAd)) && (((_pAd)->MACVersion & 0x0000FFFF) >= 0x0222)) /* Include RT5392, RT5372 and RT5362 */

#define IS_RT5592(_pAd)		(((_pAd)->MACVersion & 0xFFFF0000) == 0x55920000)
#define REV_RT5592C			0x0221

#define IS_RT65XX(_pAd)		((((_pAd)->MACVersion & 0xFFFF0000) == 0x65900000) ||\
							 (((_pAd)->MACVersion & 0xfffff000) == 0x85592000) || \
							 (((_pAd)->MACVersion & 0xfffff000) == 0x65900000) || \
							 (((_pAd)->MACVersion & 0xffff0000) == 0x76500000))

#define IS_RT6570(_pAd)		(((((_pAd)->MACVersion & 0xffff0000) == 0x76500000) || \
							 (((_pAd)->MACVersion & 0xffff0000) == 0x65900000)) && \
							((_pAd)->infType == RTMP_DEV_INF_USB))
#define IS_RT6590(_pAd)		((((_pAd)->MACVersion & 0xffff0000) == 0x65900000) || \
							 (((_pAd)->MACVersion & 0xffff0000) == 0x76500000))
#define IS_MT7650(_pAd)		(((_pAd)->chipCap.ChipID && 0xffff0000) == 0x76500000)

#define IS_MT76x2(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x76620000)
#define IS_MT7662(_pAd)		(((_pAd)->chipCap.ChipID && 0xffff0000) == 0x76620000)

#define IS_MT76xx(_pAd)		(IS_MT76x0(_pAd) || IS_MT76x2(_pAd))

#define IS_RT8592(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x85590000)
							
#define IS_RT8592(_pAd)		(((_pAd)->MACVersion & 0xffff0000) == 0x85590000)

#define IS_MT7601(_pAd)		((((_pAd)->MACVersion & 0xFFFF0000) == 0x76010000))

/* RT3592BC8 (WiFi + BT) */

#define IS_USB_INF(_pAd)		((_pAd)->infType == RTMP_DEV_INF_USB)
#define IS_PCIE_INF(_pAd)		((_pAd)->infType == RTMP_DEV_INF_PCIE)
#define IS_PCI_INF(_pAd)		(((_pAd)->infType == RTMP_DEV_INF_PCI) || IS_PCIE_INF(_pAd))
#define IS_PCI_ONLY_INF(_pAd)	((_pAd)->infType == RTMP_DEV_INF_PCI)
#define IS_RBUS_INF(_pAd) ((_pAd)->infType == RTMP_DEV_INF_RBUS)

#define RT_REV_LT(_pAd, _chip, _rev)\
	IS_##_chip(_pAd) && (((_pAd)->MACVersion & 0x0000FFFF) < (_rev))

#define RT_REV_GTE(_pAd, _chip, _rev)\
	IS_##_chip(_pAd) && (((_pAd)->MACVersion & 0x0000FFFF) >= (_rev))

/* Dual-band NIC (RF/BBP/MAC are in the same chip.) */

#define IS_RT_NEW_DUAL_BAND_NIC(_pAd) ((FALSE))


/* Is the NIC dual-band NIC? */

#define IS_DUAL_BAND_NIC(_pAd) (((_pAd->RfIcType == RFIC_2850) || (_pAd->RfIcType == RFIC_2750) || (_pAd->RfIcType == RFIC_3052)		\
								|| (_pAd->RfIcType == RFIC_3053) || (_pAd->RfIcType == RFIC_2853) || (_pAd->RfIcType == RFIC_3853) 	\
								|| IS_RT_NEW_DUAL_BAND_NIC(_pAd)) && !IS_RT5390(_pAd))


/* RT3593 over PCIe bus */
#define RT3593OverPCIe(_pAd) (IS_RT3593(_pAd) && (_pAd->CommonCfg.bPCIeBus == TRUE))

/* RT3593 over PCI bus */
#define RT3593OverPCI(_pAd) (IS_RT3593(_pAd) && (_pAd->CommonCfg.bPCIeBus == FALSE))

/*RT3390,RT3370 */
#define IS_RT3390(_pAd)				(((_pAd)->MACVersion & 0xFFFF0000) == 0x33900000)

/* ------------------------------------------------------ */
/* PCI registers - base address 0x0000 */
/* ------------------------------------------------------ */
#define CHIP_PCI_CFG		0x0000
#define CHIP_PCI_EECTRL		0x0004
#define CHIP_PCI_MCUCTRL	0x0008

#define OPT_14			0x114

#define RETRY_LIMIT		10

/* ------------------------------------------------------ */
/* BBP & RF	definition */
/* ------------------------------------------------------ */
#define	BUSY		                1
#define	IDLE		                0

/*------------------------------------------------------------------------- */
/* EEPROM definition */
/*------------------------------------------------------------------------- */
#define EEDO                        0x08
#define EEDI                        0x04
#define EECS                        0x02
#define EESK                        0x01
#define EERL                        0x80

#define EEPROM_WRITE_OPCODE         0x05
#define EEPROM_READ_OPCODE          0x06
#define EEPROM_EWDS_OPCODE          0x10
#define EEPROM_EWEN_OPCODE          0x13

#define NUM_EEPROM_BBP_PARMS		19	/* Include NIC Config 0, 1, CR, TX ALC step, BBPs */
#define NUM_EEPROM_TX_G_PARMS		7

#define VALID_EEPROM_VERSION        1
#define EEPROM_VERSION_OFFSET       0x02
#define EEPROM_NIC1_OFFSET          0x34	/* The address is from NIC config 0, not BBP register ID */
#define EEPROM_NIC2_OFFSET          0x36	/* The address is from NIC config 1, not BBP register ID */


#define EEPROM_COUNTRY_REGION			0x38

#define EEPROM_DEFINE_MAX_TXPWR			0x4e

#define EEPROM_FREQ_OFFSET			0x3a
#define EEPROM_LEDAG_CONF_OFFSET	0x3c
#define EEPROM_LEDACT_CONF_OFFSET	0x3e
#define EEPROM_LED_POLARITY_OFFSET	0x40
#if defined(BT_COEXISTENCE_SUPPORT) || defined(RT3290)
#define	EEPROM_NIC3_OFFSET			0x42
#endif /* defined(BT_COEXISTENCE_SUPPORT) || defined(RT3290) */

#define EEPROM_LNA_OFFSET			0x44

#define EEPROM_RSSI_BG_OFFSET			0x46
#define EEPROM_RSSI_A_OFFSET			0x4a
#define EEPROM_TXMIXER_GAIN_2_4G		0x48
#define EEPROM_TXMIXER_GAIN_5G			0x4c

#define EEPROM_TXPOWER_DELTA			0x50	/* 20MHZ AND 40 MHZ use different power. This is delta in 40MHZ. */

#define EEPROM_G_TX_PWR_OFFSET			0x52
#define EEPROM_G_TX2_PWR_OFFSET			0x60

#define EEPROM_G_TSSI_BOUND1			0x6e
#define EEPROM_G_TSSI_BOUND2			0x70
#define EEPROM_G_TSSI_BOUND3			0x72
#define EEPROM_G_TSSI_BOUND4			0x74
#define EEPROM_G_TSSI_BOUND5			0x76

#ifdef MT7601
#define EEPROM_TX0_TSSI_SLOPE				0x6e
#define EEPROM_TX0_TSSI_OFFSET_GROUP1	0x70
#define EEPROM_TX0_TSSI_OFFSET			0x76
#define EEPROM_G_TARGET_POWER			0xD0
#define EEPROM_FREQ_OFFSET_COMPERSATION		0xDA
#endif /* MT7601 */


#define EEPROM_A_TX_PWR_OFFSET      		0x78
#define EEPROM_A_TX2_PWR_OFFSET			0xa6

#define MBSSID_MODE0 0
#define MBSSID_MODE1 1

enum FREQ_CAL_INIT_MODE {
	FREQ_CAL_INIT_MODE0,
	FREQ_CAL_INIT_MODE1,
	FREQ_CAL_INIT_MODE2,
	FREQ_CAL_INIT_UNKNOW,
};

enum FREQ_CAL_MODE {
	FREQ_CAL_MODE0,
	FREQ_CAL_MODE1,
	FREQ_CAL_MODE2,
};

enum RXWI_FRQ_OFFSET_FIELD {
	RXWI_FRQ_OFFSET_FIELD0, /* SNR1 */
	RXWI_FRQ_OFFSET_FIELD1, /* Frequency Offset */
};


#define EEPROM_A_TSSI_BOUND1		0xd4
#define EEPROM_A_TSSI_BOUND2		0xd6
#define EEPROM_A_TSSI_BOUND3		0xd8
#define EEPROM_A_TSSI_BOUND4		0xda
#define EEPROM_A_TSSI_BOUND5		0xdc

/* ITxBF calibration values EEPROM locations 0x1a0 to 0x1ab */
#define EEPROM_ITXBF_CAL				0x1a0

#define EEPROM_TXPOWER_BYRATE 			0xde	/* 20MHZ power. */
#define EEPROM_TXPOWER_BYRATE_20MHZ_2_4G	0xde	/* 20MHZ 2.4G tx power. */
#define EEPROM_TXPOWER_BYRATE_40MHZ_2_4G	0xee	/* 40MHZ 2.4G tx power. */
#define EEPROM_TXPOWER_BYRATE_20MHZ_5G		0xfa	/* 20MHZ 5G tx power. */
#define EEPROM_TXPOWER_BYRATE_40MHZ_5G		0x10a	/* 40MHZ 5G tx power. */

#define EEPROM_BBP_BASE_OFFSET			0xf0	/* The address is from NIC config 0, not BBP register ID */

/* */
/* Bit mask for the Tx ALC and the Tx fine power control */
/* */
#define GET_TX_ALC_BIT_MASK					0x1F	/* Valid: 0~31, and in 0.5dB step */
#define GET_TX_FINE_POWER_CTRL_BIT_MASK	0xE0	/* Valid: 0~4, and in 0.1dB step */
#define NUMBER_OF_BITS_FOR_TX_ALC			5	/* The length, in bit, of the Tx ALC field */


/* TSSI gain and TSSI attenuation */

#define EEPROM_TSSI_GAIN_AND_ATTENUATION	0x76

/*#define EEPROM_Japan_TX_PWR_OFFSET      0x90 // 802.11j */
/*#define EEPROM_Japan_TX2_PWR_OFFSET      0xbe */
/*#define EEPROM_TSSI_REF_OFFSET	0x54 */
/*#define EEPROM_TSSI_DELTA_OFFSET	0x24 */
/*#define EEPROM_CCK_TX_PWR_OFFSET  0x62 */
/*#define EEPROM_CALIBRATE_OFFSET	0x7c */

#define EEPROM_NIC_CFG1_OFFSET		0
#define EEPROM_NIC_CFG2_OFFSET		1
#define EEPROM_NIC_CFG3_OFFSET		2
#define EEPROM_COUNTRY_REG_OFFSET	3
#define EEPROM_BBP_ARRAY_OFFSET		4

#if defined(RTMP_INTERNAL_TX_ALC) || defined(RTMP_TEMPERATURE_COMPENSATION) 
/* */
/* The TSSI over OFDM 54Mbps */
/* */
#define EEPROM_TSSI_OVER_OFDM_54		0x6E

/* */
/* The TSSI value/step (0.5 dB/unit) */
/* */
#define EEPROM_TSSI_STEP_OVER_2DOT4G	0x77
#define EEPROM_TSSI_STEP_OVER_5DOT5G	0xDD
#define TSSI_READ_SAMPLE_NUM			3

/* */
/* Per-channel Tx power offset (for the extended TSSI mode) */
/* */
#define EEPROM_TX_POWER_OFFSET_OVER_CH_1	0x6F
#define EEPROM_TX_POWER_OFFSET_OVER_CH_3	0x70
#define EEPROM_TX_POWER_OFFSET_OVER_CH_5	0x71
#define EEPROM_TX_POWER_OFFSET_OVER_CH_7	0x72
#define EEPROM_TX_POWER_OFFSET_OVER_CH_9	0x73
#define EEPROM_TX_POWER_OFFSET_OVER_CH_11	0x74
#define EEPROM_TX_POWER_OFFSET_OVER_CH_13	0x75

/* */
/* Tx power configuration (bit3:0 for Tx0 power setting and bit7:4 for Tx1 power setting) */
/* */
#define EEPROM_CCK_MCS0_MCS1				0xDE
#define EEPROM_CCK_MCS2_MCS3				0xDF
#define EEPROM_OFDM_MCS0_MCS1			0xE0
#define EEPROM_OFDM_MCS2_MCS3			0xE1
#define EEPROM_OFDM_MCS4_MCS5			0xE2
#define EEPROM_OFDM_MCS6_MCS7			0xE3
#define EEPROM_HT_MCS0_MCS1				0xE4
#define EEPROM_HT_MCS2_MCS3				0xE5
#define EEPROM_HT_MCS4_MCS5				0xE6
#define EEPROM_HT_MCS6_MCS7				0xE7
#define EEPROM_HT_MCS8_MCS9                     	0xE8
#define EEPROM_HT_MCS10_MCS11                   	0xE9
#define EEPROM_HT_MCS12_MCS13                   	0xEA
#define EEPROM_HT_MCS14_MCS15                   	0xEB
#define EEPROM_HT_USING_STBC_MCS0_MCS1	0xEC
#define EEPROM_HT_USING_STBC_MCS2_MCS3	0xED
#define EEPROM_HT_USING_STBC_MCS4_MCS5	0xEE
#define EEPROM_HT_USING_STBC_MCS6_MCS7	0xEF

/* */
/* Bit mask for the Tx ALC and the Tx fine power control */
/* */

#define DEFAULT_BBP_TX_FINE_POWER_CTRL 	0

#endif /* RTMP_INTERNAL_TX_ALC || RTMP_TEMPERATURE_COMPENSATION */


#ifdef RT_BIG_ENDIAN
typedef union _EEPROM_ANTENNA_STRUC {
	struct {
		unsigned short RssiIndicationMode:1; 	/* RSSI indication mode */
		unsigned short Rsv:1;
		unsigned short BoardType:2; 		/* 0: mini card; 1: USB pen */
		unsigned short RfIcType:4;			/* see E2PROM document */
		unsigned short TxPath:4;			/* 1: 1T, 2: 2T, 3: 3T */
		unsigned short RxPath:4;			/* 1: 1R, 2: 2R, 3: 3R */
	} field;
	unsigned short word;
} EEPROM_ANTENNA_STRUC, *PEEPROM_ANTENNA_STRUC;
#else
typedef union _EEPROM_ANTENNA_STRUC {
	struct {
		unsigned short RxPath:4;			/* 1: 1R, 2: 2R, 3: 3R */
		unsigned short TxPath:4;			/* 1: 1T, 2: 2T, 3: 3T */
		unsigned short RfIcType:4;			/* see E2PROM document */
		unsigned short BoardType:2; 		/* 0: mini card; 1: USB pen */
		unsigned short Rsv:1;
		unsigned short RssiIndicationMode:1; 	/* RSSI indication mode */	
	} field;
	unsigned short word;
} EEPROM_ANTENNA_STRUC, *PEEPROM_ANTENNA_STRUC;
#endif


/*
  *   EEPROM operation related marcos
  */
#define RT28xx_EEPROM_READ16(_pAd, _offset, _value)			\
	(_pAd)->chipOps.eeread((RTMP_ADAPTER *)(_pAd), (unsigned short)(_offset), (unsigned short *)&(_value))

#define RT28xx_EEPROM_WRITE16(_pAd, _offset, _value)		\
	(_pAd)->chipOps.eewrite((RTMP_ADAPTER *)(_pAd), (unsigned short)(_offset), (unsigned short)(_value))


#if defined(RTMP_INTERNAL_TX_ALC) || defined(RTMP_TEMPERATURE_COMPENSATION) 
/* The Tx power tuning entry */
typedef struct _TX_POWER_TUNING_ENTRY_STRUCT {
	char	RF_TX_ALC; 		/* 3390: RF R12[4:0]: Tx0 ALC, 5390: RF R49[5:0]: Tx0 ALC */
	char 	MAC_PowerDelta;	/* Tx power control over MAC 0x1314~0x1324 */
} TX_POWER_TUNING_ENTRY_STRUCT, *PTX_POWER_TUNING_ENTRY_STRUCT;
#endif /* defined(RTMP_INTERNAL_TX_ALC) || defined(RTMP_TEMPERATURE_COMPENSATION) */

/*
	2860: 28xx
	2870: 28xx

	30xx:
		3090
		3070
		2070 3070

	33xx:	30xx
		3390 3090
		3370 3070

	35xx:	30xx
		3572, 2870, 28xx
		3062, 2860, 28xx
		3562, 2860, 28xx

	3593, 28xx, 30xx, 35xx

	< Note: 3050, 3052, 3350 can not be compiled simultaneously. >
	305x:
		3052
		3050
		3350, 3050

	3352: 305x

	2880: 28xx
	2883:
	3883:
*/

struct _RTMP_CHIP_CAP_ {
	unsigned int ChipID;
	/* register */
	REG_PAIR *pRFRegTable;
	REG_PAIR *pBBPRegTable;
	unsigned char bbpRegTbSize;

	unsigned int MaxNumOfRfId;
	unsigned int MaxNumOfBbpId;

#define RF_REG_WT_METHOD_NONE			0
#define RF_REG_WT_METHOD_STEP_ON		1
	unsigned char RfReg17WtMethod;

	/* beacon */
	bool FlgIsSupSpecBcnBuf;	/* SPECIFIC_BCN_BUF_SUPPORT */
	unsigned char BcnMaxNum;	/* software use */
	unsigned char BcnMaxHwNum;	/* hardware limitation */
	unsigned char WcidHwRsvNum;	/* hardware available WCID number */
	unsigned short BcnMaxHwSize;	/* hardware maximum beacon size */
	unsigned short BcnBase[HW_BEACON_MAX_NUM];	/* hardware beacon base address */
	
	/* function */
	/* use unsigned char, not bit-or to speed up driver */
	bool FlgIsHwWapiSup;

	/* VCO calibration mode */
	unsigned char	VcoPeriod; /* default 10s */
#define VCO_CAL_DISABLE		0	/* not support */
#define VCO_CAL_MODE_1		1	/* toggle RF7[0] */
#define VCO_CAL_MODE_2		2	/* toggle RF3[7] */
#define VCO_CAL_MODE_3		3	/* toggle RF4[7] */	
	unsigned char	FlgIsVcoReCalMode;

	bool FlgIsHwAntennaDiversitySup;
	bool FlgSwBasedPPAD;
#ifdef STREAM_MODE_SUPPORT
	bool FlgHwStreamMode;
#endif /* STREAM_MODE_SUPPORT */
#ifdef TXBF_SUPPORT
	bool FlgHwTxBfCap;
#endif /* TXBF_SUPPORT */
#ifdef FIFO_EXT_SUPPORT
	bool FlgHwFifoExtCap;
#endif /* FIFO_EXT_SUPPORT */


	enum ASIC_CAP asic_caps;
	enum PHY_CAP phy_caps;
	
#ifdef TXRX_SW_ANTDIV_SUPPORT
	bool bTxRxSwAntDiv;
#endif /* TXRX_SW_ANTDIV_SUPPORT */

	/* ---------------------------- signal ---------------------------------- */
#define SNR_FORMULA1		0	/* ((0xeb     - pAd->StaCfg.LastSNR0) * 3) / 16; */
#define SNR_FORMULA2		1	/* (pAd->StaCfg.LastSNR0 * 3 + 8) >> 4; */
#define SNR_FORMULA3		2	/* (pAd->StaCfg.LastSNR0) * 3) / 16; */
	unsigned char SnrFormula;

	unsigned char MaxNss;			/* maximum Nss, 3 for 3883 or 3593 */

	bool bTempCompTxALC;

	bool bLimitPowerRange; /* TSSI compensation range limit */

#if defined(RTMP_INTERNAL_TX_ALC) || defined(RTMP_TEMPERATURE_COMPENSATION)
	unsigned char TxAlcTxPowerUpperBound_2G;
	const TX_POWER_TUNING_ENTRY_STRUCT *TxPowerTuningTable_2G;
#ifdef A_BAND_SUPPORT
	unsigned char TxAlcTxPowerUpperBound_5G;
	const TX_POWER_TUNING_ENTRY_STRUCT *TxPowerTuningTable_5G;
#endif /* A_BAND_SUPPORT */

#ifdef MT7601
	MT7601_TX_ALC_DATA TxALCData;
#endif /* MT7601 */
#endif /* defined(RTMP_INTERNAL_TX_ALC) || defined(RTMP_TEMPERATURE_COMPENSATION) */

#if defined(RTMP_INTERNAL_TX_ALC) || defined(SINGLE_SKU_V2)
	short	PAModeCCK[4];
	short	PAModeOFDM[8];
	short	PAModeHT[16];
#endif /* defined(RTMP_INTERNAL_TX_ALC) || defined(SINGLE_SKU_V2) */

#ifdef MT7601
	char	TemperatureRef25C;
	unsigned char	TemperatureMode;
	bool	bPllLockProtect;
	char	CurrentTemperBbpR49;
	int	TemperatureDPD;					// temperature when do DPD calibration
	int	CurrentTemperature;					// (BBP_R49 - Ref25C) * offset
#endif /* MT7601 */
	/* ---------------------------- packet ---------------------------------- */
	unsigned char TXWISize;
	unsigned char RXWISize;

	/* ---------------------------- others ---------------------------------- */
#ifdef RTMP_EFUSE_SUPPORT
	unsigned short EFUSE_USAGE_MAP_START;
	unsigned short EFUSE_USAGE_MAP_END;
	unsigned char EFUSE_USAGE_MAP_SIZE;
	unsigned char *EFUSE_DEFAULT_BIN;
	unsigned short EFUSE_DEFAULT_BIN_SIZE;
#endif /* RTMP_EFUSE_SUPPORT */

#ifdef RTMP_FLASH_SUPPORT
	unsigned char *eebuf;
#endif /* RTMP_FLASH_SUPPORT */

#ifdef CARRIER_DETECTION_SUPPORT
	unsigned char carrier_func;
#endif /* CARRIER_DETECTION_SUPPORT */
#ifdef DFS_SUPPORT
	unsigned char DfsEngineNum;
#endif /* DFS_SUPPORT */

	/*
		Define the burst size of WPDMA of PCI
		0 : 4 DWORD (16bytes)
		1 : 8 DWORD (32 bytes)
		2 : 16 DWORD (64 bytes)
		3 : 32 DWORD (128 bytes)
	*/
	unsigned char WPDMABurstSIZE;

	/* 
 	 * 0: MBSSID_MODE0 
 	 * (The multiple MAC_ADDR/BSSID are distinguished by [bit2:bit0] of byte5) 
 	 * 1: MBSSID_MODE1
 	 * (The multiple MAC_ADDR/BSSID are distinguished by [bit4:bit2] of byte0) 
 	 */
	unsigned char MBSSIDMode;



#ifdef RT5592EP_SUPPORT
	unsigned int Priv; /* Flag for RT5592 EP */
#endif /* RT5592EP_SUPPORT */

#ifdef CONFIG_ANDES_SUPPORT
	unsigned int WlanMemmapOffset;
	unsigned int InbandPacketMaxLen;
	unsigned char CmdRspRxRing;
	bool IsComboChip;
#endif

#ifdef SINGLE_SKU_V2
	char	Apwrdelta;
	char	Gpwrdelta;
#endif /* SINGLE_SKU_V2 */

#ifdef RTMP_USB_SUPPORT
	unsigned char DataBulkInAddr;
	unsigned char CommandRspBulkInAddr;
	unsigned char WMM0ACBulkOutAddr[4];
	unsigned char WMM1ACBulkOutAddr;
	unsigned char CommandBulkOutAddr;
#endif
	
	enum MCU_TYPE MCUType;
	unsigned char *FWImageName;
};

typedef void (*CHIP_SPEC_FUNC)(void *pAd, void *pData, unsigned long Data);

/* The chip specific function ID */
typedef enum _CHIP_SPEC_ID
{		
	CHIP_SPEC_RESV_FUNC
} CHIP_SPEC_ID;

#define CHIP_SPEC_ID_NUM 	CHIP_SPEC_RESV_FUNC


struct _RTMP_CHIP_OP_ {
	/*  Calibration access related callback functions */
	int (*eeinit)(struct _RTMP_ADAPTER *pAd);
	int (*eeread)(struct _RTMP_ADAPTER *pAd, unsigned short offset, unsigned short * pValue);
	int (*eewrite)(struct _RTMP_ADAPTER *pAd, unsigned short offset, unsigned short value);

	/* MCU related callback functions */
	int (*loadFirmware)(struct _RTMP_ADAPTER *pAd);
	int (*eraseFirmware)(struct _RTMP_ADAPTER *pAd);
	int (*sendCommandToMcu)(struct _RTMP_ADAPTER *pAd, unsigned char cmd, unsigned char token, unsigned char arg0, unsigned char arg1, bool FlgIsNeedLocked);	/* int (*sendCommandToMcu)(RTMP_ADAPTER *pAd, unsigned char cmd, unsigned char token, unsigned char arg0, unsigned char arg1); */
#ifdef CONFIG_ANDES_SUPPORT
	int (*sendCommandToAndesMcu)(struct _RTMP_ADAPTER *pAd, unsigned char QueIdx, unsigned char cmd, unsigned char *pData, unsigned short DataLen, bool FlgIsNeedLocked);
#endif /* CONFIG_ANDES_SUPPORT */

	void (*AsicRfInit)(struct _RTMP_ADAPTER *pAd);
	void (*AsicBbpInit)(struct _RTMP_ADAPTER *pAd);
	void (*AsicMacInit)(struct _RTMP_ADAPTER *pAd);

	void (*AsicRfTurnOn)(struct _RTMP_ADAPTER *pAd);
	void (*AsicRfTurnOff)(struct _RTMP_ADAPTER *pAd);
	void (*AsicReverseRfFromSleepMode)(struct _RTMP_ADAPTER *pAd, bool FlgIsInitState);
	void (*AsicHaltAction)(struct _RTMP_ADAPTER *pAd);

	/* Power save */
	void (*EnableAPMIMOPS)(IN struct _RTMP_ADAPTER *pAd, IN bool ReduceCorePower);
	void (*DisableAPMIMOPS)(IN struct _RTMP_ADAPTER *pAd);

	/* Chip tuning */
	void (*RxSensitivityTuning)(IN struct _RTMP_ADAPTER *pAd);

	/* MAC */
	void (*BeaconUpdate)(struct _RTMP_ADAPTER *pAd, unsigned short Offset, unsigned int Value, unsigned char Unit);

	/* BBP adjust */
	void (*ChipBBPAdjust)(IN struct _RTMP_ADAPTER *pAd);

	/* AGC */
	void (*ChipAGCInit)(struct _RTMP_ADAPTER *pAd, unsigned char bw);
	unsigned char (*ChipAGCAdjust)(struct _RTMP_ADAPTER *pAd, char Rssi, unsigned char OrigR66Value);
	
	/* Channel */
	void (*ChipSwitchChannel)(struct _RTMP_ADAPTER *pAd, unsigned char ch, bool bScan);

	/* IQ Calibration */
	void (*ChipIQCalibration)(struct _RTMP_ADAPTER *pAd, unsigned char Channel);

	/* TX ALC */
	unsigned int (*TSSIRatio)(int delta_power);
	void (*InitDesiredTSSITable)(IN struct _RTMP_ADAPTER *pAd);
	int (*ATETssiCalibration)(struct _RTMP_ADAPTER *pAd, char * arg);
	int (*ATETssiCalibrationExtend)(struct _RTMP_ADAPTER *pAd, char * arg);
	int (*ATEReadExternalTSSI)(struct _RTMP_ADAPTER *pAd, char * arg);

	void (*AsicTxAlcGetAutoAgcOffset)(
				IN struct _RTMP_ADAPTER	*pAd,
				IN char *				pDeltaPwr,
				IN char *				pTotalDeltaPwr,
				IN char *				pAgcCompensate,
				IN char * 				pDeltaPowerByBbpR1);


	
	void (*AsicGetTxPowerOffset)(struct _RTMP_ADAPTER *pAd, unsigned long *TxPwr);
	void (*AsicExtraPowerOverMAC)(struct _RTMP_ADAPTER *pAd);
	
	/* Antenna */
	void (*AsicAntennaDefaultReset)(struct _RTMP_ADAPTER *pAd, union _EEPROM_ANTENNA_STRUC *pAntenna);
	void (*SetRxAnt)(struct _RTMP_ADAPTER *pAd, unsigned char Ant);

	/* EEPROM */
	void (*NICInitAsicFromEEPROM)(IN struct _RTMP_ADAPTER *pAd);

	/* Temperature Compensation */
	void (*InitTemperCompensation)(IN struct _RTMP_ADAPTER *pAd);
	void (*TemperCompensation)(IN struct _RTMP_ADAPTER *pAd);
	
	/* high power tuning */
	void (*HighPowerTuning)(struct _RTMP_ADAPTER *pAd, struct _RSSI_SAMPLE *pRssi);
	
	/* Others */
	void (*NetDevNickNameInit)(IN struct _RTMP_ADAPTER *pAd);

	/* The chip specific function list */
	CHIP_SPEC_FUNC ChipSpecFunc[CHIP_SPEC_ID_NUM];
	
	void (*AsicResetBbpAgent)(IN struct _RTMP_ADAPTER *pAd);

#ifdef CARRIER_DETECTION_SUPPORT
	void (*ToneRadarProgram)(struct _RTMP_ADAPTER *pAd, unsigned long  threshold);
#endif /* CARRIER_DETECTION_SUPPORT */
	void (*CckMrcStatusCtrl)(struct _RTMP_ADAPTER *pAd);
	void (*RadarGLRTCompensate)(struct _RTMP_ADAPTER *pAd);
	
	void (*Calibration)(struct _RTMP_ADAPTER *pAd, unsigned int CalibrationID, unsigned int Parameter);

	INT (*BurstWrite)(struct _RTMP_ADAPTER *pAd, unsigned int Offset, unsigned int *Data, unsigned int Cnt);

	INT (*BurstRead)(struct _RTMP_ADAPTER *pAd, unsigned int Offset, unsigned int Cnt, unsigned int *Data);

	INT (*RandomRead)(struct _RTMP_ADAPTER *pAd, RTMP_REG_PAIR *RegPair, unsigned int Num);

	INT (*RFRandomRead)(struct _RTMP_ADAPTER *pAd, BANK_RF_REG_PAIR *RegPair, unsigned int Num);

	INT (*ReadModifyWrite)(struct _RTMP_ADAPTER *pAd, R_M_W_REG *RegPair, unsigned int Num);

	INT (*RFReadModifyWrite)(struct _RTMP_ADAPTER *pAd, RF_R_M_W_REG *RegPair, unsigned int Num);

	INT (*RandomWrite)(struct _RTMP_ADAPTER *pAd, RTMP_REG_PAIR *RegPair, unsigned int Num);

	INT (*RFRandomWrite)(struct _RTMP_ADAPTER *pAd, BANK_RF_REG_PAIR *RegPair, unsigned int Num);

	void (*DisableTxRx)(struct _RTMP_ADAPTER *pAd, unsigned char Level);

	void (*AsicRadioOn)(struct _RTMP_ADAPTER *pAd, unsigned char Stage);

	void (*AsicRadioOff)(struct _RTMP_ADAPTER *pAd, unsigned char Stage);

	INT (*PwrSavingOP)(struct _RTMP_ADAPTER *pAd, unsigned int PwrOP, unsigned int PwrLevel, 
							unsigned int ListenInterval, unsigned int PreTBTTLeadTime,
							unsigned char TIMByteOffset, unsigned char TIMBytePattern);

#ifdef MICROWAVE_OVEN_SUPPORT
	void (*AsicMeasureFalseCCA)(IN struct _RTMP_ADAPTER *pAd);

	void (*AsicMitigateMicrowave)(IN struct _RTMP_ADAPTER *pAd);
#endif /* MICROWAVE_OVEN_SUPPORT */

#if (defined(WOW_SUPPORT) && defined(RTMP_MAC_USB)) || defined(NEW_WOW_SUPPORT)
	void (*AsicWOWEnable)(
				IN struct _RTMP_ADAPTER *pAd);
	void (*AsicWOWDisable)(
				IN struct _RTMP_ADAPTER *pAd);
#endif /* (defined(WOW_SUPPORT) && defined(RTMP_MAC_USB)) || defined(NEW_WOW_SUPPORT) */

};

#define RTMP_CHIP_ENABLE_AP_MIMOPS(__pAd, __ReduceCorePower)				\
		if (__pAd->chipOps.EnableAPMIMOPS != NULL)							\
			__pAd->chipOps.EnableAPMIMOPS(__pAd, __ReduceCorePower)

#define RTMP_CHIP_DISABLE_AP_MIMOPS(__pAd)									\
		if (__pAd->chipOps.DisableAPMIMOPS != NULL)							\
			__pAd->chipOps.DisableAPMIMOPS(__pAd)

#define PWR_SAVING_OP(__pAd, __PwrOP, __PwrLevel, __ListenInterval, \
						__PreTBTTLeadTime, __TIMByteOffset, __TIMBytePattern)	\
do {	\
		if (__pAd->chipOps.PwrSavingOP != NULL)	\
			__pAd->chipOps.PwrSavingOP(__pAd, __PwrOP, __PwrLevel,	\
										__ListenInterval,__PreTBTTLeadTime, \
										__TIMByteOffset, __TIMBytePattern);	\
} while (0)

#define RTMP_CHIP_RX_SENSITIVITY_TUNING(__pAd)								\
		if (__pAd->chipOps.RxSensitivityTuning != NULL)						\
			__pAd->chipOps.RxSensitivityTuning(__pAd)

#define RTMP_CHIP_ASIC_AGC_ADJUST(__pAd, __Rssi, __R66)					\
		if (__pAd->chipOps.ChipAGCAdjust != NULL)						\
			__R66 = __pAd->chipOps.ChipAGCAdjust(__pAd, __Rssi, __R66)

#define RTMP_CHIP_ASIC_TSSI_TABLE_INIT(__pAd)								\
		if (__pAd->chipOps.InitDesiredTSSITable != NULL)					\
			__pAd->chipOps.InitDesiredTSSITable(__pAd)

#define RTMP_CHIP_ATE_TSSI_CALIBRATION(__pAd, __pData)					\
		if (__pAd->chipOps.ATETssiCalibration != NULL)					\
			__pAd->chipOps.ATETssiCalibration(__pAd, __pData)

#define RTMP_CHIP_ATE_TSSI_CALIBRATION_EXTEND(__pAd, __pData)			\
		if (__pAd->chipOps.ATETssiCalibrationExtend != NULL)				\
			__pAd->chipOps.ATETssiCalibrationExtend(__pAd, __pData)	

#define RTMP_CHIP_ATE_READ_EXTERNAL_TSSI(__pAd, __pData)					\
		if (__pAd->chipOps.ATEReadExternalTSSI != NULL)					\
			__pAd->chipOps.ATEReadExternalTSSI(__pAd, __pData)	

#define RTMP_CHIP_ASIC_TX_POWER_OFFSET_GET(__pAd, __pCfgOfTxPwrCtrlOverMAC)					\
		if (__pAd->chipOps.AsicGetTxPowerOffset != NULL)					\
			__pAd->chipOps.AsicGetTxPowerOffset(__pAd, __pCfgOfTxPwrCtrlOverMAC)	
		
#define RTMP_CHIP_ASIC_AUTO_AGC_OFFSET_GET(									\
		__pAd, __pDeltaPwr, __pTotalDeltaPwr, __pAgcCompensate, __pDeltaPowerByBbpR1)	\
		if (__pAd->chipOps.AsicTxAlcGetAutoAgcOffset != NULL)				\
			__pAd->chipOps.AsicTxAlcGetAutoAgcOffset(						\
		__pAd, __pDeltaPwr, __pTotalDeltaPwr, __pAgcCompensate, __pDeltaPowerByBbpR1)

#define RTMP_CHIP_ASIC_EXTRA_POWER_OVER_MAC(__pAd)					\
		if (__pAd->chipOps.AsicExtraPowerOverMAC != NULL)					\
			__pAd->chipOps.AsicExtraPowerOverMAC(__pAd)

#define RTMP_CHIP_ASIC_GET_TSSI_RATIO(__pAd, __DeltaPwr)					\
			__pAd->chipOps.TSSIRatio(__DeltaPwr)

#define RTMP_CHIP_ASIC_FREQ_CAL_STOP(__pAd)									\
		if (__pAd->chipOps.AsicFreqCalStop != NULL)							\
			__pAd->chipOps.AsicFreqCalStop(__pAd)

#define RTMP_CHIP_IQ_CAL(__pAd, __pChannel)										\
		if (__pAd->chipOps.ChipIQCalibration != NULL)								\
			 __pAd->chipOps.ChipIQCalibration(__pAd, __pChannel)

#define RTMP_CHIP_HIGH_POWER_TUNING(__pAd, __pRssi)							\
		if (__pAd->chipOps.HighPowerTuning != NULL)							\
			__pAd->chipOps.HighPowerTuning(__pAd, __pRssi)

#define RTMP_CHIP_ANTENNA_INFO_DEFAULT_RESET(__pAd, __pAntenna)				\
		if (__pAd->chipOps.AsicAntennaDefaultReset != NULL)					\
			__pAd->chipOps.AsicAntennaDefaultReset(__pAd, __pAntenna)

#define RTMP_NET_DEV_NICKNAME_INIT(__pAd)									\
		if (__pAd->chipOps.NetDevNickNameInit != NULL)						\
			__pAd->chipOps.NetDevNickNameInit(__pAd)

#define RTMP_EEPROM_ASIC_INIT(__pAd)										\
		if (__pAd->chipOps.NICInitAsicFromEEPROM != NULL)					\
			__pAd->chipOps.NICInitAsicFromEEPROM(__pAd)

#define RTMP_CHIP_ASIC_INIT_TEMPERATURE_COMPENSATION(__pAd)								\
		if (__pAd->chipOps.InitTemperCompensation != NULL)					\
			__pAd->chipOps.InitTemperCompensation(__pAd)

#define RTMP_CHIP_ASIC_TEMPERATURE_COMPENSATION(__pAd)						\
		if (__pAd->chipOps.TemperCompensation != NULL)					\
			__pAd->chipOps.TemperCompensation(__pAd)

#define RTMP_CHIP_SPECIFIC(__pAd, __FuncId, __pData, __Data)				\
		if ((__FuncId >= 0) && (__FuncId < CHIP_SPEC_RESV_FUNC))				\
		{																	\
			if (__pAd->chipOps.ChipSpecFunc[__FuncId] != NULL)					\
				__pAd->chipOps.ChipSpecFunc[__FuncId](__pAd, __pData, __Data);	\
		}

#define RTMP_CHIP_ASIC_RESET_BBP_AGENT(__pAd)	\
		if (__pAd->chipOps.AsicResetBbpAgent != NULL)				\
			__pAd->chipOps.AsicResetBbpAgent(__pAd)

#define RTMP_CHIP_UPDATE_BEACON(__pAd, Offset, Value, Unit)		\
		if (__pAd->chipOps.BeaconUpdate != NULL)					\
			__pAd->chipOps.BeaconUpdate(__pAd, Offset, Value, Unit)

#ifdef CARRIER_DETECTION_SUPPORT
#define	RTMP_CHIP_CARRIER_PROGRAM(__pAd, threshold)							\
		if(__pAd->chipOps.ToneRadarProgram != NULL)					\
			__pAd->chipOps.ToneRadarProgram(__pAd, threshold)
#endif /* CARRIER_DETECTION_SUPPORT */

#define RTMP_CHIP_CCK_MRC_STATUS_CTRL(__pAd)						\
		if(__pAd->chipOps.CckMrcStatusCtrl != NULL)				\
			__pAd->chipOps.CckMrcStatusCtrl(__pAd)

#define RTMP_CHIP_RADAR_GLRT_COMPENSATE(__pAd)						\
					if(__pAd->chipOps.RadarGLRTCompensate != NULL)				\
						__pAd->chipOps.RadarGLRTCompensate(__pAd)


#define RTMP_CHIP_CALIBRATION(__pAd, __CalibrationID, __parameter) \
do {	\
	if(__pAd->chipOps.Calibration != NULL) \
		__pAd->chipOps.Calibration(__pAd, __CalibrationID, __parameter); \
} while (0)

#define BURST_WRITE(_pAd, _Offset, _pData, _Cnt)	\
do {												\
		if (_pAd->chipOps.BurstWrite != NULL)		\
			_pAd->chipOps.BurstWrite(_pAd, _Offset, _pData, _Cnt);\
} while (0)

#define BURST_READ(_pAd, _Offset, _Cnt, _pData)	\
do {											\
		if (_pAd->chipOps.BurstRead != NULL)	\
			_pAd->chipOps.BurstRead(_pAd, _Offset, _Cnt, _pData);	\
} while (0)

#define RANDOM_READ(_pAd, _RegPair, _Num)	\
do {										\
		if (_pAd->chipOps.RandomRead != NULL)	\
			_pAd->chipOps.RandomRead(_pAd, _RegPair, _Num);	\
} while (0)

#define RF_RANDOM_READ(_pAd, _RegPair, _Num)	\
do {											\
		if (_pAd->chipOps.RFRandomRead != NULL)	\
			_pAd->chipOps.RFRandomRead(_pAd, _RegPair, _Num); \
} while (0)

#define READ_MODIFY_WRITE(_pAd, _RegPair, _Num)	\
do {	\
		if (_pAd->chipOps.ReadModifyWrite != NULL)	\
			_pAd->chipOps.ReadModifyWrite(_pAd, _RegPair, _Num);	\
} while (0)

#define RF_READ_MODIFY_WRITE(_pAd, _RegPair, _Num)	\
do {	\
		if (_pAd->chipOps.RFReadModifyWrite != NULL)	\
			_pAd->chipOps.RFReadModifyWrite(_pAd, _RegPair, _Num);	\
} while (0)

#define RANDOM_WRITE(_pAd, _RegPair, _Num)	\
do {	\
		if (_pAd->chipOps.RandomWrite != NULL)	\
			_pAd->chipOps.RandomWrite(_pAd, _RegPair, _Num);	\
} while (0)

#define RF_RANDOM_WRITE(_pAd, _RegPair, _Num)	\
do {	\
		if (_pAd->chipOps.RFRandomWrite != NULL)	\
			_pAd->chipOps.RFRandomWrite(_pAd, _RegPair, _Num);	\
} while (0)

#define DISABLE_TX_RX(_pAd, _Level)	\
do {	\
	if (_pAd->chipOps.DisableTxRx != NULL)	\
		_pAd->chipOps.DisableTxRx(_pAd, _Level);	\
} while (0)

#define ASIC_RADIO_ON(_pAd, _Stage)	\
do {	\
	if (_pAd->chipOps.AsicRadioOn != NULL)	\
		_pAd->chipOps.AsicRadioOn(_pAd, _Stage);	\
} while (0)

#define ASIC_RADIO_OFF(_pAd, _Stage)	\
do {	\
	if (_pAd->chipOps.AsicRadioOff != NULL)	\
		_pAd->chipOps.AsicRadioOff(_pAd, _Stage);	\
} while (0)

#ifdef MICROWAVE_OVEN_SUPPORT
#define ASIC_MEASURE_FALSE_CCA(_pAd)	\
do {	\
	if (_pAd->chipOps.AsicMeasureFalseCCA != NULL)	\
		_pAd->chipOps.AsicMeasureFalseCCA(_pAd);	\
} while (0)

#define ASIC_MITIGATE_MICROWAVE(_pAd)	\
do {	\
	if (_pAd->chipOps.AsicMitigateMicrowave != NULL)	\
		_pAd->chipOps.AsicMitigateMicrowave(_pAd);	\
} while (0)
#endif /* MICROWAVE_OVEN_SUPPORT */

#if (defined(WOW_SUPPORT) && defined(RTMP_MAC_USB)) || defined(NEW_WOW_SUPPORT)
#define ASIC_WOW_ENABLE(_pAd)	\
do {	\
	if (_pAd->chipOps.AsicWOWEnable != NULL)	\
		_pAd->chipOps.AsicWOWEnable(_pAd);	\
} while (0)

#define ASIC_WOW_DISABLE(_pAd)	\
do {	\
	if (_pAd->chipOps.AsicWOWDisable != NULL)	\
		_pAd->chipOps.AsicWOWDisable(_pAd);	\
} while(0)
#endif /* (defined(WOW_SUPPORT) && defined(RTMP_MAC_USB)) || defined(NEW_WOW_SUPPORT) */

/* function prototype */
void RtmpChipOpsHook(void *pCB);

void RtmpChipBcnInit(struct _RTMP_ADAPTER *pAd);
void RtmpChipBcnSpecInit(struct _RTMP_ADAPTER *pAd);
#ifdef RLT_MAC
void rlt_bcn_buf_init(struct _RTMP_ADAPTER *pAd);
#endif /* RLT_MAC */

void RtmpChipWriteHighMemory(
	IN	struct _RTMP_ADAPTER *pAd,
	IN	unsigned short			Offset,
	IN	unsigned int			Value,
	IN	unsigned char			Unit);

void RtmpChipWriteMemory(
	IN	struct _RTMP_ADAPTER *pAd,
	IN	unsigned short			Offset,
	IN	unsigned int			Value,
	IN	unsigned char			Unit);

void RTMPReadChannelPwr(struct _RTMP_ADAPTER *pAd);
void RTMPReadTxPwrPerRate(struct _RTMP_ADAPTER *pAd);


void NetDevNickNameInit(IN struct _RTMP_ADAPTER *pAd);



#ifdef GREENAP_SUPPORT
void EnableAPMIMOPSv2(struct _RTMP_ADAPTER *pAd, bool ReduceCorePower);
void DisableAPMIMOPSv2(struct _RTMP_ADAPTER *pAd);
void EnableAPMIMOPSv1(struct _RTMP_ADAPTER *pAd, bool ReduceCorePower);
void DisableAPMIMOPSv1(struct _RTMP_ADAPTER *pAd);
#endif /* GREENAP_SUPPORT */


/* global variable */
extern FREQUENCY_ITEM RtmpFreqItems3020[];
extern FREQUENCY_ITEM FreqItems3020_Xtal20M[];
extern unsigned char NUM_OF_3020_CHNL;
extern FREQUENCY_ITEM *FreqItems3020;
extern RTMP_RF_REGS RF2850RegTable[];
extern unsigned char NUM_OF_2850_CHNL;

bool AsicWaitPDMAIdle(struct _RTMP_ADAPTER *pAd, INT round, INT wait_us);
INT AsicSetPreTbttInt(struct _RTMP_ADAPTER *pAd, bool enable);
INT AsicReadAggCnt(struct _RTMP_ADAPTER *pAd, unsigned long *aggCnt, int cnt_len);

#endif /* __RTMP_CHIP_H__ */
