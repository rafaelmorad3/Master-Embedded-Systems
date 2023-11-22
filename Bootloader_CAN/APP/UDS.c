/*
 * UDS.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Lenovo
 */
/*
 * UDS.c
 *
 *  Created on: Jun 9, 2020
 *      Author: toshiba
 */
#include "Std_Types.h"
//#include "../../Transport/include/UART_TP.h"
#include "UDS.h"

#define NEGATIVE_RESPONSE_ID						0x7F

/*

u8 UDS_GetRequest (u8 ServiceID, void * RequestData,RxCbf_t cbf)
{
*/
	/*
	u8 LocalError = OK;
	uint_16t FrameLength;
	switch (ServiceID)
	{
	case DIAGNOSTIC_SESSION_CONTROL_SERVICE_ID:
		FrameLength = DIAGNOSTIC_SESSION_CONTROL_REQUEST_SIZE;
		break;
	case ECU_RESET_SERVICE_ID:
		FrameLength = ECU_RESET_REQUEST_SIZE;
		break;
	case REQUEST_SEED_ID:
		FrameLength = REQUEST_SEED_REQUEST_SIZE;
		break;
	case TRANSFER_KEY_ID:
		FrameLength = TRANSFER_KEY_REQUEST_SIZE;
		break;
	case READ_DATA_BY_IDENTIFIER_SERVICE_ID:
		FrameLength = READ_DATA_BY_IDENTIFIER_REQUEST_SIZE;
		break;
	case WRITE_DATA_BY_IDENTIFIER_SERVICE_ID:
		FrameLength = WRITE_DATA_BY_IDENTIFIER_REQUEST_SIZE;
		break;
	case REQUEST_DOWNLOAD_SERVICE_ID:
		FrameLength = REQUEST_DOWNLOAD_REQUEST_SIZE;
		break;
	case TRANSFER_DATA_SERVICE_ID:
		FrameLength = TRANSFER_DATA_REQUEST_SIZE;
		break;
	case REQUEST_TRANSFER_EXIT_SERVICE_ID:
		FrameLength = REQUEST_TRANSFER_EXIT_REQUEST_SIZE;
		break;
	case ROUTINE_CONTROL_SERVICE_ID:
		FrameLength = ROUTINE_CONTROL_REQUEST_SIZE;
		break;
	default :
		FrameLength = 0;
		LocalError =NOK;
		break;
	}
	LocalError|= UART_TP_SetRxCbf(cbf);
	LocalError|= UART_TP_Receive((u8 *)RequestData,FrameLength);
	return LocalError;*/
/*}
u8 UDS_SendPositiveResponse (u8 ServiceID, void * ResponseData,TxCbf_t cbf )
{*//*
	u8 LocalError = OK;
	uint_16t FrameLength;
	switch (ServiceID)
	{
	case DIAGNOSTIC_SESSION_CONTROL_SERVICE_ID:
		FrameLength = DIAGNOSTIC_SESSION_CONTROL_RESPONSE_SIZE;
		break;
	case ECU_RESET_SERVICE_ID:
		FrameLength = ECU_RESET_RESPONSE_SIZE;
		break;
	case REQUEST_SEED_ID:
		ServiceID = SECURITY_ACCESS_SERVICE_ID;
		FrameLength = REQUEST_SEED_RESPONSE_SIZE;
		break;
	case TRANSFER_KEY_ID:
		ServiceID = SECURITY_ACCESS_SERVICE_ID;
		FrameLength = TRANSFER_KEY_RESPONSE_SIZE;
		break;
	case READ_DATA_BY_IDENTIFIER_SERVICE_ID:
		FrameLength = READ_DATA_BY_IDENTIFIER_RESPONSE_SIZE;
		break;
	case WRITE_DATA_BY_IDENTIFIER_SERVICE_ID:
		FrameLength = WRITE_DATA_BY_IDENTIFIER_RESPONSE_SIZE;
		break;
	case REQUEST_DOWNLOAD_SERVICE_ID:
		FrameLength = REQUEST_DOWNLOAD_RESPONSE_SIZE;
		break;
	case TRANSFER_DATA_SERVICE_ID:
		FrameLength = TRANSFER_DATA_RESPONSE_SIZE;
		break;
	case REQUEST_TRANSFER_EXIT_SERVICE_ID:
		FrameLength = REQUEST_TRANSFER_EXIT_RESPONSE_SIZE;
		break;
	case ROUTINE_CONTROL_SERVICE_ID:
		FrameLength = ROUTINE_CONTROL_RESPONSE_SIZE;
		break;
	default :
		FrameLength = 0;
		LocalError =NOK;
		break;
	}
	((u8 *)ResponseData) [0] = ServiceID + SERVICE_ID_TO_RESPONSE_ID;
	LocalError|= UART_TP_SetTxCbf(cbf);
	LocalError|= UART_TP_Send((u8 *)ResponseData,FrameLength);
	return LocalError;*/
/*
}
u8 UDS_SendNegativeResponse (u8 ServiceID,u8 NRC,RxCbf_t cbf)
{
	*//*
	static NegativeResponse_t NegativeFrame;
	u8 LocalError = OK;
	NegativeFrame.NegativeResponseID = NEGATIVE_RESPONSE_ID;
	NegativeFrame.ServiceID = ServiceID;
	NegativeFrame.NRC = NRC;
	LocalError|= UART_TP_SetTxCbf(cbf);
	LocalError|= UART_TP_Send((u8 *)&NegativeFrame,NEGATIVE_RESPONSE_SIZE);
	return LocalError;
	*//*
}
*/
