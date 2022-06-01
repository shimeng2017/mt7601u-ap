/****************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 * (c) Copyright 2002, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ****************************************************************************
     
     Module Name:
     ap_ids.c
     
     Abstract:
     IDS definition
     
     Revision History:
     Who         When          What
     --------    ----------    ----------------------------------------------
 */

void RTMPIdsPeriodicExec(
	IN void * SystemSpecific1, 
	IN void * FunctionContext, 
	IN void * SystemSpecific2, 
	IN void * SystemSpecific3);

bool RTMPSpoofedMgmtDetection(
	IN PRTMP_ADAPTER	pAd,
	IN PHEADER_802_11 	pHeader,
	IN char				Rssi0,
	IN char				Rssi1,
	IN char				Rssi2,
	IN unsigned char			AntSel);

void RTMPConflictSsidDetection(
	IN PRTMP_ADAPTER	pAd,
	IN unsigned char *			pSsid,
	IN unsigned char			SsidLen,
	IN char				Rssi0,
	IN char				Rssi1,
	IN char				Rssi2,
	IN unsigned char			AntSel);

bool RTMPReplayAttackDetection(
	IN PRTMP_ADAPTER	pAd,
	IN unsigned char *			pAddr2,
	IN char				Rssi0,
	IN char				Rssi1,
	IN char				Rssi2,
	IN unsigned char			AntSel,
	IN unsigned char			BW);

void RTMPUpdateStaMgmtCounter(
	IN PRTMP_ADAPTER	pAd,
	IN unsigned short			type);

void RTMPClearAllIdsCounter(
	IN PRTMP_ADAPTER	pAd);

void RTMPIdsStart(
	IN PRTMP_ADAPTER	pAd);

void RTMPIdsStop(
	IN PRTMP_ADAPTER	pAd);

void rtmp_read_ids_from_file(
			IN  PRTMP_ADAPTER pAd,
			char *tmpbuf,
			char *buffer);

