/*
 * UDS.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */

#ifndef UDS_H_
#define UDS_H_


#define MARKER_ID 									0xAABB
#define APP_ENTRY_POINT_ID 							0xCCDD


/*General values for all types of frames*/

#define DATA_BLOCK_SIZE								1024
#define NEGATIVE_RESPONSE_SIZE						3
#define SERVICE_ID_TO_RESPONSE_ID					0x40


/*NRC codes list*/
#define GENERAL_REJECT_CODE							0x10
#define SERVICE_NOT_SUPPORTED_CODE					0x11
#define SUB_FUNCTION_NOT_SUPPORTED_CODE				0x12
#define INVALID_FORMAT_CODE							0x13
#define CONDITIONS_NOT_CORRECT_CODE					0x22
#define REQUEST_SEQUENCE_ERROR_CODE					0x24
#define REQUEST_OUT_OF_RANGE_CODE					0x31
#define SECURITY_ACCESS_DENIED_CODE					0x33
#define GENERAL_PROGRAMMING_FAILURE_CODE			0x72
#define RESPONSE_PENDING_CODE						0x78

/*Negative response struct*/
typedef struct
{
	u8 NegativeResponseID;
	u8 ServiceID;
	u8 NRC;

}NegativeResponse_t;

/*List of services used */
/*Diagnostic session control*/
#define DIAGNOSTIC_SESSION_CONTROL_SERVICE_ID		0x10
#define DEFAULT_SESSION_ID							0x01
#define PROGRAMMING_SESSION_ID						0x02
#define EXTENDED_DIAGNOSTIC_SESSION_ID				0x03
#define SAFETY_SYSTEM_DIAGNOSTIC_SESSION_ID			0x04
#define DIAGNOSTIC_SESSION_CONTROL_REQUEST_SIZE		0x02
#define DIAGNOSTIC_SESSION_CONTROL_RESPONSE_SIZE	0x04


typedef struct
{
	u8 ServiceID;
	u8 SessionID;
}DiagSessCtrlReq_t;

typedef struct
{
	u8 ResponseID;
	u8 SessionID;
	u16 ResponseTime;
}DiagSessCtrlResponse_t;

/*ECU Reset service*/
#define ECU_RESET_SERVICE_ID						0x11
#define HARD_RESET_ID								0x01
#define SOFT_RESET_ID								0x02
#define ECU_RESET_REQUEST_SIZE						0x02
#define ECU_RESET_RESPONSE_SIZE						0x02

typedef struct
{
	u8 ServiceID;
	u8 ResetID;
}ECUResetReq_t;

typedef struct
{
	u8 ResponseID;
	u8 ResetID;
}ECUResetResponse_t;


/*Security Access : Request seed - Transfer Key*/
#define SECURITY_ACCESS_SERVICE_ID					0x27
#define REQUEST_SEED_ID								0x01/*use those insted of SECURITY_ACCESS_SERVICE_ID*/
#define TRANSFER_KEY_ID								0x02/*use those insted of SECURITY_ACCESS_SERVICE_ID*/
#define REQUEST_SEED_REQUEST_SIZE					0x02
#define REQUEST_SEED_RESPONSE_SIZE					0x04
#define TRANSFER_KEY_REQUEST_SIZE					0x04
#define TRANSFER_KEY_RESPONSE_SIZE					0x02

typedef struct
{
	u8 ServiceID;
	u8 SubFuncID;
}RequestSeedReq_t;

typedef struct
{
	u8 ResponseID;
	u8 SubFuncID;
	u16 Seed;
}RequestSeedResponse_t;

typedef struct
{
	u8 ServiceID;
	u8 SubFuncID;
	u16 Key;
}TransferKeyReq_t;

typedef struct
{
	u8 ResponseID;
	u8 SubFuncID;
}TransferKeyResponse_t;


#define READ_DATA_BY_IDENTIFIER_SERVICE_ID			0x22
#define READ_DATA_BY_IDENTIFIER_REQUEST_SIZE		0x04
#define READ_DATA_BY_IDENTIFIER_RESPONSE_SIZE		0x08


typedef struct
{
	u8 ServiceID;
	u8 Reserved;
	u16 DataID;
}ReadDataByIDReq_t;

typedef struct
{
	u8 ResponseID;
	u8 Reserved [3];
	u32 Data;
}ReadDataByIDResponse_t;


#define WRITE_DATA_BY_IDENTIFIER_SERVICE_ID			0x2E
#define WRITE_DATA_BY_IDENTIFIER_REQUEST_SIZE		0x08
#define WRITE_DATA_BY_IDENTIFIER_RESPONSE_SIZE		0x02
typedef struct
{
	u8 ServiceID;
	u8 Reserved;
	u16 DataID;
	u32 Data;
}WriteDataByIDReq_t;

typedef struct
{
	u8 ResponseID;
	u8 reserved;
}WriteDataByIDResponse_t;

#define REQUEST_DOWNLOAD_SERVICE_ID					0x34
#define REQUEST_DOWNLOAD_REQUEST_SIZE				0x04
#define REQUEST_DOWNLOAD_RESPONSE_SIZE				0x04
#define WORD_SIZE									0X04
typedef struct
{
	u8 ServiceID;
	u8 MemAddLength;
	u16 AppSize;
}RequestDownloadReq_t;

typedef struct
{
	u8 ResponseID;
	u8 Reserved;
	u16 DataBlockSize;
}RequestDownloadResponse_t;


#define TRANSFER_DATA_SERVICE_ID					0x36
#define TRANSFER_DATA_REQUEST_SIZE					0x08+DATA_BLOCK_SIZE
#define TRANSFER_DATA_RESPONSE_SIZE					0x04
typedef struct
{
	u8 ServiceID;
	u8 BlockNum;
	u16 BlockSize;
	u32 BlockAddress;
	u8 Data [DATA_BLOCK_SIZE];
}TransferDataReq_t;

typedef struct
{
	u8 ResponseID;
	u8 BlockNum;
	u16 CheckSum;
}TransferDataResponse_t;

#define REQUEST_TRANSFER_EXIT_SERVICE_ID			0x37
#define REQUEST_TRANSFER_EXIT_REQUEST_SIZE			0x02
#define REQUEST_TRANSFER_EXIT_RESPONSE_SIZE			0x02

typedef struct
{
	u8 ServiceID;
	u8 reserved;
}ReqTransferExitReq_t;

typedef struct
{
	u8 ResponseID;
	u8 reserved;

}ReqTransferExitResponse_t;

#define ROUTINE_CONTROL_SERVICE_ID					0x31
#define ROUTINE_CONTROL_REQUEST_SIZE				0x04
#define ROUTINE_CONTROL_RESPONSE_SIZE				0x04
#define START_ROUTINE_ID							0x01
#define STOP_ROUTINE_ID								0x02
#define QUERY_ROUTINE_RESULT_ID						0x03
#define ERASE_APPLICATION_ROUTINE_ID				0xABCD
#define VALIDATE_BLOCK_ROUTINE_ID					0x9876


typedef struct
{
	u8 ServiceID;
	u8 ControlRoutineSignalID;
	u16 RoutineID;
}RoutineControlReq_t;

typedef struct
{
	u8 ResponseID;
	u8 ControlRoutineSignalID;
	u16 RoutineID;
}RoutineControlResponse_t;

/*UDS APIs*//*
u8 UDS_GetRequest (u8 ServiceID, void * RequestData,RxCbf_t cbf);
u8 UDS_SendPositiveResponse (u8 ServiceID, void * ResponseData,TxCbf_t cbf );
u8 UDS_SendNegativeResponse (u8 ServiceID,u8 NRC,RxCbf_t cbf);

*/
#endif /* APP_INCLUDE_UDS_H_ */

