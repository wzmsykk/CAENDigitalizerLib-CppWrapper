

#ifndef __CAENDIGITIZER_H
#define __CAENDIGITIZER_H
#endif
#define win32
#include <stdarg.h>
#include "CAENDigitizerType.h"

#define FUNC_LOADED 3456
#define ERR_CANNOT_LOAD_FUNCTION -100L
#define ERR_CANNOT_LOAD_LIBRARY -101L

#if !defined(CAEN_USE_DIGITIZERS) && !defined(IGNORE_DPP_DEPRECATED)

#ifdef __GNUC__
#define DPP_DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DPP_DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("WARNING: DEPRECATED marking not supported on this compiler")
#define DPP_DEPRECATED(func) func
#endif

#else

#define DPP_DEPRECATED(func) func

#endif


//#define CAEN_DGTZ_GetMaxNumAggregatesBLT CAEN_DGTZ_GetMaxNumEventsBLT
//#define CAEN_DGTZ_SetMaxNumAggregatesBLT CAEN_DGTZ_SetMaxNumEventsBLT

#define MAX_PROBENAMES_LEN (50)
class CAENDev
{
public:
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint32_t VMEBaseAddress, int* handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_CloseDigitizer(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetInfo(int handle, CAEN_DGTZ_BoardInfo_t* BoardInfo) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_ReadRegister(int handle, uint32_t Address, uint32_t* Data) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_WriteRegister(int handle, uint32_t Address, uint32_t Data) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_Reset(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_ClearData(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SendSWtrigger(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SWStartAcquisition(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SWStopAcquisition(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetInterruptConfig(int handle, CAEN_DGTZ_EnaDis_t state, uint8_t level, uint32_t status_id, uint16_t event_number, CAEN_DGTZ_IRQMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetInterruptConfig(int handle, CAEN_DGTZ_EnaDis_t* state, uint8_t* level, uint32_t* status_id, uint16_t* event_number, CAEN_DGTZ_IRQMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_IRQWait(int handle, uint32_t timeout) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_VMEIRQWait(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint8_t IRQMask, uint32_t timeout, int* VMEHandle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_VMEIRQCheck(int VMEHandle, uint8_t* Mask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_VMEIACKCycle(int VMEHandle, uint8_t level, int32_t* board_id) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDESMode(int handle, CAEN_DGTZ_EnaDis_t enable) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDESMode(int handle, CAEN_DGTZ_EnaDis_t* enable) = 0;
/**************************************************************************//**
* \brief     Sets acquisition record length
*
* \param     [IN] handle  : digitizer handle
* \param     [IN] size    : the size of the record (in samples)
* \param    [IN] channel : \c int specifying the channel to set the record length for.
*                           DPP-PSD and DPP-CI require this parameter,
*                           DPP-PHA ignores it
*                           Now Always Provide A int Number.
* \return  0 = Success; negative numbers are error codes
******************************************************************************/
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetRecordLength(int handle, uint32_t size,int channel) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetRecordLength(int handle, uint32_t* size, int channel) = 0;//so as CAEN_DGTZ_SetRecordLength
	
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelEnableMask(int handle, uint32_t mask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelEnableMask(int handle, uint32_t* mask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupEnableMask(int handle, uint32_t mask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupEnableMask(int handle, uint32_t* mask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSWTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetExtTriggerInputMode(int handle, CAEN_DGTZ_TriggerMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetExtTriggerInputMode(int handle, CAEN_DGTZ_TriggerMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSWTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelSelfTrigger(int handle, CAEN_DGTZ_TriggerMode_t mode, uint32_t channelmask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelSelfTrigger(int handle, uint32_t channel, CAEN_DGTZ_TriggerMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupSelfTrigger(int handle, CAEN_DGTZ_TriggerMode_t mode, uint32_t groupmask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupSelfTrigger(int handle, uint32_t group, CAEN_DGTZ_TriggerMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelGroupMask(int handle, uint32_t group, uint32_t channelmask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelGroupMask(int handle, uint32_t group, uint32_t* channelmask) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetPostTriggerSize(int handle, uint32_t percent) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetPostTriggerSize(int handle, uint32_t* percent) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPPPreTriggerSize(int handle, int ch, uint32_t samples) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPPPreTriggerSize(int handle, int ch, uint32_t* samples) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelDCOffset(int handle, uint32_t channel, uint32_t Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelDCOffset(int handle, uint32_t channel, uint32_t* Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupDCOffset(int handle, uint32_t group, uint32_t Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupDCOffset(int handle, uint32_t group, uint32_t* Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelTriggerThreshold(int handle, uint32_t channel, uint32_t Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelTriggerThreshold(int handle, uint32_t channel, uint32_t* Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelPulsePolarity(int handle, uint32_t channel, CAEN_DGTZ_PulsePolarity_t pol) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelPulsePolarity(int handle, uint32_t channel, CAEN_DGTZ_PulsePolarity_t* pol) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupTriggerThreshold(int handle, uint32_t group, uint32_t Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupTriggerThreshold(int handle, uint32_t group, uint32_t* Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetZeroSuppressionMode(int handle, CAEN_DGTZ_ZS_Mode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetZeroSuppressionMode(int handle, CAEN_DGTZ_ZS_Mode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelZSParams(int handle, uint32_t channel, CAEN_DGTZ_ThresholdWeight_t weight, int32_t  threshold, int32_t nsamp) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelZSParams(int handle, uint32_t channel, CAEN_DGTZ_ThresholdWeight_t* weight, int32_t* threshold, int32_t* nsamp) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetAcquisitionMode(int handle, CAEN_DGTZ_AcqMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetAcquisitionMode(int handle, CAEN_DGTZ_AcqMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetRunSynchronizationMode(int handle, CAEN_DGTZ_RunSyncMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetRunSynchronizationMode(int handle, CAEN_DGTZ_RunSyncMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetAnalogMonOutput(int handle, CAEN_DGTZ_AnalogMonitorOutputMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetAnalogMonOutput(int handle, CAEN_DGTZ_AnalogMonitorOutputMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetAnalogInspectionMonParams(int handle, uint32_t channelmask, uint32_t offset, CAEN_DGTZ_AnalogMonitorMagnify_t mf, CAEN_DGTZ_AnalogMonitorInspectorInverter_t ami) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetAnalogInspectionMonParams(int handle, uint32_t* channelmask, uint32_t* offset, CAEN_DGTZ_AnalogMonitorMagnify_t* mf, CAEN_DGTZ_AnalogMonitorInspectorInverter_t* ami) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DisableEventAlignedReadout(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetEventPackaging(int handle, CAEN_DGTZ_EnaDis_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetEventPackaging(int handle, CAEN_DGTZ_EnaDis_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetMaxNumAggregatesBLT(int handle, uint32_t numAggr) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetMaxNumEventsBLT(int handle, uint32_t numEvents) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetMaxNumAggregatesBLT(int handle, uint32_t* numAggr) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetMaxNumEventsBLT(int handle, uint32_t* numEvents) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_MallocReadoutBuffer(int handle, char** buffer, uint32_t* size) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_ReadData(int handle, CAEN_DGTZ_ReadMode_t mode, char* buffer, uint32_t* bufferSize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeReadoutBuffer(char** buffer) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetNumEvents(int handle, char* buffer, uint32_t buffsize, uint32_t* numEvents) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetEventInfo(int handle, char* buffer, uint32_t buffsize, int32_t numEvent, CAEN_DGTZ_EventInfo_t* eventInfo, char** EventPtr) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DecodeEvent(int handle, char* evtPtr, void** Evt) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeEvent(int handle, void** Evt) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPPEvents(int handle, char* buffer, uint32_t buffsize, void** events, uint32_t* numEventsArray) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_MallocDPPEvents(int handle, void** events, uint32_t* allocatedSize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeDPPEvents(int handle, void** events) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_MallocDPPWaveforms(int handle, void** waveforms, uint32_t* allocatedSize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeDPPWaveforms(int handle, void* Waveforms) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DecodeDPPWaveforms(int handle, void* event, void* waveforms) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetNumEventsPerAggregate(int handle, uint32_t numEvents, ...) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetNumEventsPerAggregate(int handle, uint32_t* numEvents, ...) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPPEventAggregation(int handle, int threshold, int maxsize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPPParameters(int handle, uint32_t channelMask, void* params) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPPAcquisitionMode(int handle, CAEN_DGTZ_DPP_AcqMode_t mode, CAEN_DGTZ_DPP_SaveParam_t param) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPPAcquisitionMode(int handle, CAEN_DGTZ_DPP_AcqMode_t* mode, CAEN_DGTZ_DPP_SaveParam_t* param) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPPTriggerMode(int handle, CAEN_DGTZ_DPP_TriggerMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPPTriggerMode(int handle, CAEN_DGTZ_DPP_TriggerMode_t* mode) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetDPP_PHA_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t mode, CAEN_DGTZ_DPP_PHA_VirtualProbe1_t vp1, CAEN_DGTZ_DPP_PHA_VirtualProbe2_t vp2, CAEN_DGTZ_DPP_PHA_DigitalProbe_t dp)) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDPP_PHA_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t* mode, CAEN_DGTZ_DPP_PHA_VirtualProbe1_t* vp1, CAEN_DGTZ_DPP_PHA_VirtualProbe2_t* vp2, CAEN_DGTZ_DPP_PHA_DigitalProbe_t* dp)) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetDPP_PSD_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t mode, CAEN_DGTZ_DPP_PSD_VirtualProbe_t vp, CAEN_DGTZ_DPP_PSD_DigitalProbe1_t dp1, CAEN_DGTZ_DPP_PSD_DigitalProbe2_t dp2)) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDPP_PSD_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t* mode, CAEN_DGTZ_DPP_PSD_VirtualProbe_t* vp, CAEN_DGTZ_DPP_PSD_DigitalProbe1_t* dp1, CAEN_DGTZ_DPP_PSD_DigitalProbe2_t* dp2)) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetDPP_CI_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t mode, CAEN_DGTZ_DPP_CI_VirtualProbe_t vp, CAEN_DGTZ_DPP_CI_DigitalProbe1_t dp1, CAEN_DGTZ_DPP_CI_DigitalProbe2_t dp2)) = 0;
	virtual DPP_DEPRECATED(CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDPP_CI_VirtualProbe(int handle, CAEN_DGTZ_DPP_VirtualProbe_t* mode, CAEN_DGTZ_DPP_CI_VirtualProbe_t* vp, CAEN_DGTZ_DPP_CI_DigitalProbe1_t* dp1, CAEN_DGTZ_DPP_CI_DigitalProbe2_t* dp2)) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDPP_VirtualProbe(int handle, int trace, int probe) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPP_VirtualProbe(int handle, int trace, int* probe) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPP_SupportedVirtualProbes(int handle, int trace, int probes[], int* numProbes) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPP_VirtualProbeName(int probe, char name[]) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_AllocateEvent(int handle, void** Evt) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetIOLevel(int handle, CAEN_DGTZ_IOLevel_t level) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetIOLevel(int handle, CAEN_DGTZ_IOLevel_t* level) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetTriggerPolarity(int handle, uint32_t channel, CAEN_DGTZ_TriggerPolarity_t Polarity) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetTriggerPolarity(int handle, uint32_t channel, CAEN_DGTZ_TriggerPolarity_t* Polarity) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_RearmInterrupt(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDRS4SamplingFrequency(int handle, CAEN_DGTZ_DRS4Frequency_t frequency) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDRS4SamplingFrequency(int handle, CAEN_DGTZ_DRS4Frequency_t* frequency) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetOutputSignalMode(int handle, CAEN_DGTZ_OutputSignalMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetOutputSignalMode(int handle, CAEN_DGTZ_OutputSignalMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupFastTriggerThreshold(int handle, uint32_t group, uint32_t Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupFastTriggerThreshold(int handle, uint32_t group, uint32_t* Tvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetGroupFastTriggerDCOffset(int handle, uint32_t group, uint32_t DCvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetGroupFastTriggerDCOffset(int handle, uint32_t group, uint32_t* DCvalue) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetFastTriggerDigitizing(int handle, CAEN_DGTZ_EnaDis_t enable) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetFastTriggerDigitizing(int handle, CAEN_DGTZ_EnaDis_t* enable) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetFastTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetFastTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_LoadDRS4CorrectionData(int handle, CAEN_DGTZ_DRS4Frequency_t frequency) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetCorrectionTables(int handle, int frequency, void* CTable) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_EnableDRS4Correction(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DisableDRS4Correction(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DecodeZLEWaveforms(int handle, void* event, void* waveforms) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeZLEWaveforms(int handle, void* waveforms) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_MallocZLEWaveforms(int handle, void** waveforms, uint32_t* allocatedSize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_FreeZLEEvents(int handle, void** events) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_MallocZLEEvents(int handle, void** events, uint32_t* allocatedSize) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetZLEEvents(int handle, char* buffer, uint32_t buffsize, void** events, uint32_t* numEventsArray) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetZLEParameters(int handle, uint32_t channelMask, void* params) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMCorrectionLevel(int handle, CAEN_DGTZ_SAM_CORRECTION_LEVEL_t* level) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSAMCorrectionLevel(int handle, CAEN_DGTZ_SAM_CORRECTION_LEVEL_t level) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_EnableSAMPulseGen(int handle, int channel, unsigned short  pulsePattern, CAEN_DGTZ_SAMPulseSourceType_t pulseSource) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_DisableSAMPulseGen(int handle, int channel) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSAMPostTriggerSize(int handle, int SamIndex, uint8_t value) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMPostTriggerSize(int handle, int SamIndex, uint32_t* value) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSAMSamplingFrequency(int handle, CAEN_DGTZ_SAMFrequency_t frequency) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMSamplingFrequency(int handle, CAEN_DGTZ_SAMFrequency_t* frequency) = 0;
	virtual CAEN_DGTZ_ErrorCode _CAEN_DGTZ_Read_EEPROM(int handle, int EEPROMIndex, unsigned short add, int nbOfBytes, unsigned char* buf) = 0;
	virtual CAEN_DGTZ_ErrorCode _CAEN_DGTZ_Write_EEPROM(int handle, int EEPROMIndex, unsigned short add, int nbOfBytes, void* buf) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_LoadSAMCorrectionData(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode _CAEN_DGTZ_TriggerThreshold(int handle, CAEN_DGTZ_EnaDis_t endis) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SendSAMPulse(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSAMAcquisitionMode(int handle, CAEN_DGTZ_AcquisitionMode_t mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMAcquisitionMode(int handle, CAEN_DGTZ_AcquisitionMode_t* mode) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetTriggerLogic(int handle, CAEN_DGTZ_TrigerLogic_t logic, uint32_t majorityLevel) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetTriggerLogic(int handle, CAEN_DGTZ_TrigerLogic_t* logic, uint32_t* majorityLevel) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetChannelPairTriggerLogic(int handle, uint32_t channelA, uint32_t channelB, CAEN_DGTZ_TrigerLogic_t* logic, uint16_t* coincidenceWindow) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetChannelPairTriggerLogic(int handle, uint32_t channelA, uint32_t channelB, CAEN_DGTZ_TrigerLogic_t logic, uint16_t coincidenceWindow) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetDecimationFactor(int handle, uint16_t factor) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDecimationFactor(int handle, uint16_t* factor) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_SetSAMTriggerCountVetoParam(int handle, int channel, CAEN_DGTZ_EnaDis_t enable, uint32_t vetoWindow) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMTriggerCountVetoParam(int handle, int channel, CAEN_DGTZ_EnaDis_t* enable, uint32_t* vetoWindow) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetSAMCorrectionData(int handle, void* STable) = 0;

	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_Calibrate(int handle) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_ReadTemperature(int handle, int32_t ch, uint32_t* temp) = 0;
	virtual CAEN_DGTZ_ErrorCode CAEN_DGTZ_GetDPPFirmwareType(int handle, CAEN_DGTZ_DPPFirmware_t* firmware) = 0;

};
class CAENDigitizer :CAENDev
{
public:
	HMODULE hLinkdll;
	int	hDevice;
public:
	CAENDigitizer(const LPCTSTR name)
	{
		// Load DLL when Class is instantiated
		hLinkdll = NULL;
		hLinkdll = LoadLibrary(name);
		hDevice = 0;
	}

	~CAENDigitizer()
	{
		if (hDevice) {
			CAEN_DGTZ_CloseDigitizer(hDevice);
		}

		// unload the dll when the class is deleted
		if (hLinkdll != NULL)
			FreeLibrary(hLinkdll);


	}
	typedef CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_OpenDigitizer) (CAEN_DGTZ_ConnectionType, int, int, uint32_t, int*);
	LPCAEN_DGTZ_OpenDigitizer lpCAEN_DGTZ_OpenDigitizer = NULL;
	long isCAEN_DGTZ_OpenDigitizer = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint32_t VMEBaseAddress, int* handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_OpenDigitizer)
			{
				lpCAEN_DGTZ_OpenDigitizer = NULL;
				lpCAEN_DGTZ_OpenDigitizer = (LPCAEN_DGTZ_OpenDigitizer)GetProcAddress(hLinkdll, "CAEN_DGTZ_OpenDigitizer");
				isCAEN_DGTZ_OpenDigitizer = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_OpenDigitizer)
				return lpCAEN_DGTZ_OpenDigitizer(LinkType, LinkNum, ConetNode, VMEBaseAddress, handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_CloseDigitizer)(int);
	LPCAEN_DGTZ_CloseDigitizer lpCAEN_DGTZ_CloseDigitizer = NULL;
	long isCAEN_DGTZ_CloseDigitizer = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_CloseDigitizer(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_CloseDigitizer)
			{
				lpCAEN_DGTZ_CloseDigitizer = NULL;
				lpCAEN_DGTZ_CloseDigitizer = (LPCAEN_DGTZ_CloseDigitizer)GetProcAddress(hLinkdll, "CAEN_DGTZ_CloseDigitizer");
				isCAEN_DGTZ_CloseDigitizer = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_CloseDigitizer)
				return lpCAEN_DGTZ_CloseDigitizer(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_WriteRegister)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_WriteRegister lpCAEN_DGTZ_WriteRegister = NULL;
	long isCAEN_DGTZ_WriteRegister = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_WriteRegister(int handle, uint32_t Address, uint32_t Data) 
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_WriteRegister)
			{
				lpCAEN_DGTZ_WriteRegister = NULL;
				lpCAEN_DGTZ_WriteRegister = (LPCAEN_DGTZ_WriteRegister)GetProcAddress(hLinkdll, "CAEN_DGTZ_WriteRegister");
				isCAEN_DGTZ_WriteRegister = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_WriteRegister)
				return lpCAEN_DGTZ_WriteRegister(handle,Address,Data);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_ReadRegister)(int, uint32_t, uint32_t*);
	LPCAEN_DGTZ_ReadRegister lpCAEN_DGTZ_ReadRegister = NULL;
	long isCAEN_DGTZ_ReadRegister = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_ReadRegister(int handle, uint32_t Address, uint32_t* Data)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_ReadRegister)
			{
				lpCAEN_DGTZ_ReadRegister = NULL;
				lpCAEN_DGTZ_ReadRegister = (LPCAEN_DGTZ_ReadRegister)GetProcAddress(hLinkdll, "CAEN_DGTZ_ReadRegister");
				isCAEN_DGTZ_ReadRegister = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_ReadRegister)
				return lpCAEN_DGTZ_ReadRegister(handle, Address, Data);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetInfo)(int, CAEN_DGTZ_BoardInfo_t*);
	LPCAEN_DGTZ_GetInfo lpCAEN_DGTZ_GetInfo = NULL;
	long isCAEN_DGTZ_GetInfo = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetInfo(int handle, CAEN_DGTZ_BoardInfo_t* BoardInfo)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetInfo)
			{
				lpCAEN_DGTZ_GetInfo = NULL;
				lpCAEN_DGTZ_GetInfo = (LPCAEN_DGTZ_GetInfo)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetInfo");
				isCAEN_DGTZ_GetInfo = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetInfo)
				return lpCAEN_DGTZ_GetInfo(handle, BoardInfo);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_Reset)(int);
	LPCAEN_DGTZ_Reset lpCAEN_DGTZ_Reset = NULL;
	long isCAEN_DGTZ_Reset = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_Reset(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_Reset)
			{
				lpCAEN_DGTZ_Reset = NULL;
				lpCAEN_DGTZ_Reset = (LPCAEN_DGTZ_Reset)GetProcAddress(hLinkdll, "CAEN_DGTZ_Reset");
				isCAEN_DGTZ_Reset = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_Reset)
				return lpCAEN_DGTZ_Reset(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_ClearData)(int);
	LPCAEN_DGTZ_ClearData lpCAEN_DGTZ_ClearData = NULL;
	long isCAEN_DGTZ_ClearData = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_ClearData(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_ClearData)
			{
				lpCAEN_DGTZ_ClearData = NULL;
				lpCAEN_DGTZ_ClearData = (LPCAEN_DGTZ_ClearData)GetProcAddress(hLinkdll, "CAEN_DGTZ_ClearData");
				isCAEN_DGTZ_ClearData = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_ClearData)
				return lpCAEN_DGTZ_ClearData(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SendSWtrigger)(int);
	LPCAEN_DGTZ_SendSWtrigger lpCAEN_DGTZ_SendSWtrigger = NULL;
	long isCAEN_DGTZ_SendSWtrigger = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SendSWtrigger(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SendSWtrigger)
			{
				lpCAEN_DGTZ_SendSWtrigger = NULL;
				lpCAEN_DGTZ_SendSWtrigger = (LPCAEN_DGTZ_SendSWtrigger)GetProcAddress(hLinkdll, "CAEN_DGTZ_SendSWtrigger");
				isCAEN_DGTZ_SendSWtrigger = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SendSWtrigger)
				return lpCAEN_DGTZ_SendSWtrigger(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SWStartAcquisition)(int);
	LPCAEN_DGTZ_SWStartAcquisition lpCAEN_DGTZ_SWStartAcquisition = NULL;
	long isCAEN_DGTZ_SWStartAcquisition = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SWStartAcquisition(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SWStartAcquisition)
			{
				lpCAEN_DGTZ_SWStartAcquisition = NULL;
				lpCAEN_DGTZ_SWStartAcquisition = (LPCAEN_DGTZ_SWStartAcquisition)GetProcAddress(hLinkdll, "CAEN_DGTZ_SWStartAcquisition");
				isCAEN_DGTZ_SWStartAcquisition = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SWStartAcquisition)
				return lpCAEN_DGTZ_SWStartAcquisition(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SWStopAcquisition)(int);
	LPCAEN_DGTZ_SWStopAcquisition lpCAEN_DGTZ_SWStopAcquisition = NULL;
	long isCAEN_DGTZ_SWStopAcquisition = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SWStopAcquisition(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SWStopAcquisition)
			{
				lpCAEN_DGTZ_SWStopAcquisition = NULL;
				lpCAEN_DGTZ_SWStopAcquisition = (LPCAEN_DGTZ_SWStopAcquisition)GetProcAddress(hLinkdll, "CAEN_DGTZ_SWStopAcquisition");
				isCAEN_DGTZ_SWStopAcquisition = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SWStopAcquisition)
				return lpCAEN_DGTZ_SWStopAcquisition(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetInterruptConfig)(int, CAEN_DGTZ_EnaDis_t, uint8_t, uint32_t, uint16_t, CAEN_DGTZ_IRQMode_t);
	LPCAEN_DGTZ_SetInterruptConfig lpCAEN_DGTZ_SetInterruptConfig = NULL;
	long isCAEN_DGTZ_SetInterruptConfig = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetInterruptConfig(int handle, CAEN_DGTZ_EnaDis_t state, uint8_t level, uint32_t status_id, uint16_t event_number, CAEN_DGTZ_IRQMode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetInterruptConfig)
			{
				lpCAEN_DGTZ_SetInterruptConfig = NULL;
				lpCAEN_DGTZ_SetInterruptConfig = (LPCAEN_DGTZ_SetInterruptConfig)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetInterruptConfig");
				isCAEN_DGTZ_SetInterruptConfig = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetInterruptConfig)
				return lpCAEN_DGTZ_SetInterruptConfig(handle,state,level,status_id,event_number,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetInterruptConfig)(int, CAEN_DGTZ_EnaDis_t*, uint8_t*, uint32_t*, uint16_t*, CAEN_DGTZ_IRQMode_t*);
	LPCAEN_DGTZ_GetInterruptConfig lpCAEN_DGTZ_GetInterruptConfig = NULL;
	long isCAEN_DGTZ_GetInterruptConfig = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetInterruptConfig(int handle, CAEN_DGTZ_EnaDis_t* state, uint8_t* level, uint32_t* status_id, uint16_t* event_number, CAEN_DGTZ_IRQMode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetInterruptConfig)
			{
				lpCAEN_DGTZ_GetInterruptConfig = NULL;
				lpCAEN_DGTZ_GetInterruptConfig = (LPCAEN_DGTZ_GetInterruptConfig)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetInterruptConfig");
				isCAEN_DGTZ_GetInterruptConfig = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetInterruptConfig)
				return lpCAEN_DGTZ_GetInterruptConfig(handle, state, level, status_id, event_number, mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_IRQWait)(int, uint32_t);
	LPCAEN_DGTZ_IRQWait lpCAEN_DGTZ_IRQWait = NULL;
	long isCAEN_DGTZ_IRQWait = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_IRQWait(int handle, uint32_t timeout)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_IRQWait)
			{
				lpCAEN_DGTZ_IRQWait = NULL; CAEN_DGTZ_VMEIRQWait;
				lpCAEN_DGTZ_IRQWait = (LPCAEN_DGTZ_IRQWait)GetProcAddress(hLinkdll, "CAEN_DGTZ_IRQWait");
				isCAEN_DGTZ_IRQWait = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_IRQWait)
				return lpCAEN_DGTZ_IRQWait(handle,timeout);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_VMEIRQWait)(CAEN_DGTZ_ConnectionType,int,int,uint8_t,uint32_t,int*);
	LPCAEN_DGTZ_VMEIRQWait lpCAEN_DGTZ_VMEIRQWait = NULL;
	long isCAEN_DGTZ_VMEIRQWait = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_VMEIRQWait(CAEN_DGTZ_ConnectionType LinkType, int LinkNum, int ConetNode, uint8_t IRQMask, uint32_t timeout, int* VMEHandle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_VMEIRQWait)
			{
				lpCAEN_DGTZ_VMEIRQWait = NULL;
				lpCAEN_DGTZ_VMEIRQWait = (LPCAEN_DGTZ_VMEIRQWait)GetProcAddress(hLinkdll, "CAEN_DGTZ_VMEIRQWait");
				isCAEN_DGTZ_VMEIRQWait = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_VMEIRQWait)
				return lpCAEN_DGTZ_VMEIRQWait(LinkType,LinkNum,ConetNode,IRQMask,timeout,VMEHandle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_VMEIRQCheck)(int,uint8_t*);
	LPCAEN_DGTZ_VMEIRQCheck lpCAEN_DGTZ_VMEIRQCheck = NULL;
	long isCAEN_DGTZ_VMEIRQCheck = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_VMEIRQCheck(int VMEHandle, uint8_t* Mask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_VMEIRQCheck)
			{
				lpCAEN_DGTZ_VMEIRQCheck = NULL;
				lpCAEN_DGTZ_VMEIRQCheck = (LPCAEN_DGTZ_VMEIRQCheck)GetProcAddress(hLinkdll, "CAEN_DGTZ_VMEIRQCheck");
				isCAEN_DGTZ_VMEIRQCheck = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_VMEIRQCheck)
				return lpCAEN_DGTZ_VMEIRQCheck(VMEHandle,Mask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_VMEIACKCycle)(int, uint8_t, int32_t*);
	LPCAEN_DGTZ_VMEIACKCycle lpCAEN_DGTZ_VMEIACKCycle = NULL;
	long isCAEN_DGTZ_VMEIACKCycle = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_VMEIACKCycle(int VMEHandle, uint8_t level, int32_t* board_id)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_VMEIACKCycle)
			{
				lpCAEN_DGTZ_VMEIACKCycle = NULL;
				lpCAEN_DGTZ_VMEIACKCycle = (LPCAEN_DGTZ_VMEIACKCycle)GetProcAddress(hLinkdll, "CAEN_DGTZ_VMEIACKCycle");
				isCAEN_DGTZ_VMEIACKCycle = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_VMEIACKCycle)
				return lpCAEN_DGTZ_VMEIACKCycle(VMEHandle,level,board_id);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetDESMode)(int, CAEN_DGTZ_EnaDis_t);
	LPCAEN_DGTZ_SetDESMode lpCAEN_DGTZ_SetDESMode = NULL;
	long isCAEN_DGTZ_SetDESMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetDESMode(int handle, CAEN_DGTZ_EnaDis_t enable)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetDESMode)
			{
				lpCAEN_DGTZ_SetDESMode = NULL;
				lpCAEN_DGTZ_SetDESMode = (LPCAEN_DGTZ_SetDESMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetDESMode");
				isCAEN_DGTZ_SetDESMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetDESMode)
				return lpCAEN_DGTZ_SetDESMode(handle,enable);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetDESMode)(int, CAEN_DGTZ_EnaDis_t*);
	LPCAEN_DGTZ_GetDESMode lpCAEN_DGTZ_GetDESMode = NULL;
	long isCAEN_DGTZ_GetDESMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDESMode(int handle, CAEN_DGTZ_EnaDis_t* enable)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetDESMode)
			{
				lpCAEN_DGTZ_GetDESMode = NULL;
				lpCAEN_DGTZ_GetDESMode = (LPCAEN_DGTZ_GetDESMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetDESMode");
				isCAEN_DGTZ_GetDESMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetDESMode)
				return lpCAEN_DGTZ_GetDESMode(handle,enable);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetRecordLength)(int, uint32_t,int);
	LPCAEN_DGTZ_SetRecordLength lpCAEN_DGTZ_SetRecordLength = NULL;
	long isCAEN_DGTZ_SetRecordLength = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetRecordLength(int handle, uint32_t size,int channel)
	{


		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetRecordLength)
			{
				lpCAEN_DGTZ_SetRecordLength = NULL;
				lpCAEN_DGTZ_SetRecordLength = (LPCAEN_DGTZ_SetRecordLength)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetRecordLength");
				isCAEN_DGTZ_SetRecordLength = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetRecordLength)

				return lpCAEN_DGTZ_SetRecordLength(handle,size,channel);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetRecordLength)(int,uint32_t*,int);
	LPCAEN_DGTZ_GetRecordLength lpCAEN_DGTZ_GetRecordLength = NULL;
	long isCAEN_DGTZ_GetRecordLength = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetRecordLength(int handle, uint32_t* size,int channel)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetRecordLength)
			{
				lpCAEN_DGTZ_GetRecordLength = NULL;
				lpCAEN_DGTZ_GetRecordLength = (LPCAEN_DGTZ_GetRecordLength)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetRecordLength");
				isCAEN_DGTZ_GetRecordLength = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetRecordLength)
				return lpCAEN_DGTZ_GetRecordLength(handle,size,channel);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelEnableMask)(int, uint32_t);
	LPCAEN_DGTZ_SetChannelEnableMask lpCAEN_DGTZ_SetChannelEnableMask = NULL;
	long isCAEN_DGTZ_SetChannelEnableMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelEnableMask(int handle, uint32_t mask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelEnableMask)
			{
				lpCAEN_DGTZ_SetChannelEnableMask = NULL;
				lpCAEN_DGTZ_SetChannelEnableMask = (LPCAEN_DGTZ_SetChannelEnableMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelEnableMask");
				isCAEN_DGTZ_SetChannelEnableMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelEnableMask)
				return lpCAEN_DGTZ_SetChannelEnableMask(handle,mask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetChannelEnableMask)(int,uint32_t*);
	LPCAEN_DGTZ_GetChannelEnableMask lpCAEN_DGTZ_GetChannelEnableMask = NULL;
	long isCAEN_DGTZ_GetChannelEnableMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetChannelEnableMask(int handle, uint32_t* mask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetChannelEnableMask)
			{
				lpCAEN_DGTZ_GetChannelEnableMask = NULL;
				lpCAEN_DGTZ_GetChannelEnableMask = (LPCAEN_DGTZ_GetChannelEnableMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetChannelEnableMask");
				isCAEN_DGTZ_GetChannelEnableMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetChannelEnableMask)
				return lpCAEN_DGTZ_GetChannelEnableMask(handle,mask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetGroupEnableMask)(int,uint32_t);
	LPCAEN_DGTZ_SetGroupEnableMask lpCAEN_DGTZ_SetGroupEnableMask = NULL;
	long isCAEN_DGTZ_SetGroupEnableMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetGroupEnableMask(int handle, uint32_t mask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetGroupEnableMask)
			{
				lpCAEN_DGTZ_SetGroupEnableMask = NULL;
				lpCAEN_DGTZ_SetGroupEnableMask = (LPCAEN_DGTZ_SetGroupEnableMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetGroupEnableMask");
				isCAEN_DGTZ_SetGroupEnableMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetGroupEnableMask)
				return lpCAEN_DGTZ_SetGroupEnableMask(handle,mask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetGroupEnableMask)(int,uint32_t*);
	LPCAEN_DGTZ_GetGroupEnableMask lpCAEN_DGTZ_GetGroupEnableMask = NULL;
	long isCAEN_DGTZ_GetGroupEnableMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetGroupEnableMask(int handle, uint32_t* mask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetGroupEnableMask)
			{
				lpCAEN_DGTZ_GetGroupEnableMask = NULL;
				lpCAEN_DGTZ_GetGroupEnableMask = (LPCAEN_DGTZ_GetGroupEnableMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetGroupEnableMask");
				isCAEN_DGTZ_GetGroupEnableMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetGroupEnableMask)
				return lpCAEN_DGTZ_GetGroupEnableMask(handle,mask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetSWTriggerMode)(int, CAEN_DGTZ_TriggerMode_t);
	LPCAEN_DGTZ_SetSWTriggerMode lpCAEN_DGTZ_SetSWTriggerMode = NULL;
	long isCAEN_DGTZ_SetSWTriggerMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetSWTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetSWTriggerMode)
			{
				lpCAEN_DGTZ_SetSWTriggerMode = NULL;
				lpCAEN_DGTZ_SetSWTriggerMode = (LPCAEN_DGTZ_SetSWTriggerMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetSWTriggerMode");
				isCAEN_DGTZ_SetSWTriggerMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetSWTriggerMode)
				return lpCAEN_DGTZ_SetSWTriggerMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetExtTriggerInputMode)(int, CAEN_DGTZ_TriggerMode_t);
	LPCAEN_DGTZ_SetExtTriggerInputMode lpCAEN_DGTZ_SetExtTriggerInputMode = NULL;
	long isCAEN_DGTZ_SetExtTriggerInputMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetExtTriggerInputMode(int handle, CAEN_DGTZ_TriggerMode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetExtTriggerInputMode)
			{
				lpCAEN_DGTZ_SetExtTriggerInputMode = NULL;
				lpCAEN_DGTZ_SetExtTriggerInputMode = (LPCAEN_DGTZ_SetExtTriggerInputMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetExtTriggerInputMode");
				isCAEN_DGTZ_SetExtTriggerInputMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetExtTriggerInputMode)
				return lpCAEN_DGTZ_SetExtTriggerInputMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetExtTriggerInputMode)(int, CAEN_DGTZ_TriggerMode_t*);
	LPCAEN_DGTZ_GetExtTriggerInputMode lpCAEN_DGTZ_GetExtTriggerInputMode = NULL;
	long isCAEN_DGTZ_GetExtTriggerInputMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetExtTriggerInputMode(int handle, CAEN_DGTZ_TriggerMode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetExtTriggerInputMode)
			{
				lpCAEN_DGTZ_GetExtTriggerInputMode = NULL;
				lpCAEN_DGTZ_GetExtTriggerInputMode = (LPCAEN_DGTZ_GetExtTriggerInputMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetExtTriggerInputMode");
				isCAEN_DGTZ_GetExtTriggerInputMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetExtTriggerInputMode)
				return lpCAEN_DGTZ_GetExtTriggerInputMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetSWTriggerMode)(int, CAEN_DGTZ_TriggerMode_t*);
	LPCAEN_DGTZ_GetSWTriggerMode lpCAEN_DGTZ_GetSWTriggerMode = NULL;
	long isCAEN_DGTZ_GetSWTriggerMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetSWTriggerMode(int handle, CAEN_DGTZ_TriggerMode_t*mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetSWTriggerMode)
			{
				lpCAEN_DGTZ_GetSWTriggerMode = NULL;
				lpCAEN_DGTZ_GetSWTriggerMode = (LPCAEN_DGTZ_GetSWTriggerMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetSWTriggerMode");
				isCAEN_DGTZ_GetSWTriggerMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetSWTriggerMode)
				return lpCAEN_DGTZ_GetSWTriggerMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelSelfTrigger)(int, CAEN_DGTZ_TriggerMode_t, uint32_t);
	LPCAEN_DGTZ_SetChannelSelfTrigger lpCAEN_DGTZ_SetChannelSelfTrigger = NULL;
	long isCAEN_DGTZ_SetChannelSelfTrigger = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelSelfTrigger(int handle, CAEN_DGTZ_TriggerMode_t mode, uint32_t channelmask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelSelfTrigger)
			{
				lpCAEN_DGTZ_SetChannelSelfTrigger = NULL;
				lpCAEN_DGTZ_SetChannelSelfTrigger = (LPCAEN_DGTZ_SetChannelSelfTrigger)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelSelfTrigger");
				isCAEN_DGTZ_SetChannelSelfTrigger = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelSelfTrigger)
				return lpCAEN_DGTZ_SetChannelSelfTrigger(handle,mode,channelmask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetGroupSelfTrigger)(int, CAEN_DGTZ_TriggerMode_t, uint32_t);
	LPCAEN_DGTZ_SetGroupSelfTrigger lpCAEN_DGTZ_SetGroupSelfTrigger = NULL;
	long isCAEN_DGTZ_SetGroupSelfTrigger = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetGroupSelfTrigger(int handle, CAEN_DGTZ_TriggerMode_t mode, uint32_t groupmask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetGroupSelfTrigger)
			{
				lpCAEN_DGTZ_SetGroupSelfTrigger = NULL;
				lpCAEN_DGTZ_SetGroupSelfTrigger = (LPCAEN_DGTZ_SetGroupSelfTrigger)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetGroupSelfTrigger");
				isCAEN_DGTZ_SetGroupSelfTrigger = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetGroupSelfTrigger)
				return lpCAEN_DGTZ_SetGroupSelfTrigger(handle,mode,groupmask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelGroupMask)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_SetChannelGroupMask lpCAEN_DGTZ_SetChannelGroupMask = NULL;
	long isCAEN_DGTZ_SetChannelGroupMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelGroupMask(int handle, uint32_t group, uint32_t channelmask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelGroupMask)
			{
				lpCAEN_DGTZ_SetChannelGroupMask = NULL;
				lpCAEN_DGTZ_SetChannelGroupMask = (LPCAEN_DGTZ_SetChannelGroupMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelGroupMask");
				isCAEN_DGTZ_SetChannelGroupMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelGroupMask)
				return lpCAEN_DGTZ_SetChannelGroupMask(handle,group,channelmask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetChannelGroupMask)(int, uint32_t, uint32_t*);
	LPCAEN_DGTZ_GetChannelGroupMask lpCAEN_DGTZ_GetChannelGroupMask = NULL;
	long isCAEN_DGTZ_GetChannelGroupMask = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetChannelGroupMask(int handle, uint32_t group, uint32_t* channelmask)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetChannelGroupMask)
			{
				lpCAEN_DGTZ_GetChannelGroupMask = NULL;
				lpCAEN_DGTZ_GetChannelGroupMask = (LPCAEN_DGTZ_GetChannelGroupMask)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetChannelGroupMask");
				isCAEN_DGTZ_GetChannelGroupMask = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetChannelGroupMask)
				return lpCAEN_DGTZ_GetChannelGroupMask(handle,group,channelmask);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetPostTriggerSize)(int, uint32_t);
	LPCAEN_DGTZ_SetPostTriggerSize lpCAEN_DGTZ_SetPostTriggerSize = NULL;
	long isCAEN_DGTZ_SetPostTriggerSize = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetPostTriggerSize(int handle, uint32_t percent)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetPostTriggerSize)
			{
				lpCAEN_DGTZ_SetPostTriggerSize = NULL;
				lpCAEN_DGTZ_SetPostTriggerSize = (LPCAEN_DGTZ_SetPostTriggerSize)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetPostTriggerSize");
				isCAEN_DGTZ_SetPostTriggerSize = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetPostTriggerSize)
				return lpCAEN_DGTZ_SetPostTriggerSize(handle,percent);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetDPPPreTriggerSize)(int, int, uint32_t);
	LPCAEN_DGTZ_SetDPPPreTriggerSize lpCAEN_DGTZ_SetDPPPreTriggerSize = NULL;
	long isCAEN_DGTZ_SetDPPPreTriggerSize = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetDPPPreTriggerSize(int handle, int ch, uint32_t samples)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetDPPPreTriggerSize)
			{
				lpCAEN_DGTZ_SetDPPPreTriggerSize = NULL;
				lpCAEN_DGTZ_SetDPPPreTriggerSize = (LPCAEN_DGTZ_SetDPPPreTriggerSize)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetDPPPreTriggerSize");
				isCAEN_DGTZ_SetDPPPreTriggerSize = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetDPPPreTriggerSize)
				return lpCAEN_DGTZ_SetDPPPreTriggerSize(handle,ch,samples);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetDPPPreTriggerSize)(int,int,uint32_t*);
	LPCAEN_DGTZ_GetDPPPreTriggerSize lpCAEN_DGTZ_GetDPPPreTriggerSize = NULL;
	long isCAEN_DGTZ_GetDPPPreTriggerSize = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDPPPreTriggerSize(int handle, int ch, uint32_t* samples)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetDPPPreTriggerSize)
			{
				lpCAEN_DGTZ_GetDPPPreTriggerSize = NULL;
				lpCAEN_DGTZ_GetDPPPreTriggerSize = (LPCAEN_DGTZ_GetDPPPreTriggerSize)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetDPPPreTriggerSize");
				isCAEN_DGTZ_GetDPPPreTriggerSize = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetDPPPreTriggerSize)
				return lpCAEN_DGTZ_GetDPPPreTriggerSize(handle,ch,samples);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelDCOffset)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_SetChannelDCOffset lpCAEN_DGTZ_SetChannelDCOffset = NULL;
	long isCAEN_DGTZ_SetChannelDCOffset = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelDCOffset(int handle, uint32_t channel, uint32_t Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelDCOffset)
			{
				lpCAEN_DGTZ_SetChannelDCOffset = NULL;
				lpCAEN_DGTZ_SetChannelDCOffset = (LPCAEN_DGTZ_SetChannelDCOffset)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelDCOffset");
				isCAEN_DGTZ_SetChannelDCOffset = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelDCOffset)
				return lpCAEN_DGTZ_SetChannelDCOffset(handle,channel,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetGroupDCOffset)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_SetGroupDCOffset lpCAEN_DGTZ_SetGroupDCOffset = NULL;
	long isCAEN_DGTZ_SetGroupDCOffset = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetGroupDCOffset(int handle, uint32_t group, uint32_t Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetGroupDCOffset)
			{
				lpCAEN_DGTZ_SetGroupDCOffset = NULL;
				lpCAEN_DGTZ_SetGroupDCOffset = (LPCAEN_DGTZ_SetGroupDCOffset)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetGroupDCOffset");
				isCAEN_DGTZ_SetGroupDCOffset = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetGroupDCOffset)
				return lpCAEN_DGTZ_SetGroupDCOffset(handle,group,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetGroupDCOffset)(int, uint32_t, uint32_t*);
	LPCAEN_DGTZ_GetGroupDCOffset lpCAEN_DGTZ_GetGroupDCOffset = NULL;
	long isCAEN_DGTZ_GetGroupDCOffset = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetGroupDCOffset(int handle, uint32_t group, uint32_t* Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetGroupDCOffset)
			{
				lpCAEN_DGTZ_GetGroupDCOffset = NULL;
				lpCAEN_DGTZ_GetGroupDCOffset = (LPCAEN_DGTZ_GetGroupDCOffset)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetGroupDCOffset");
				isCAEN_DGTZ_GetGroupDCOffset = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetGroupDCOffset)
				return lpCAEN_DGTZ_GetGroupDCOffset(handle,group,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelTriggerThreshold)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_SetChannelTriggerThreshold lpCAEN_DGTZ_SetChannelTriggerThreshold = NULL;
	long isCAEN_DGTZ_SetChannelTriggerThreshold = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelTriggerThreshold(int handle, uint32_t channel, uint32_t Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelTriggerThreshold)
			{
				lpCAEN_DGTZ_SetChannelTriggerThreshold = NULL;
				lpCAEN_DGTZ_SetChannelTriggerThreshold = (LPCAEN_DGTZ_SetChannelTriggerThreshold)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelTriggerThreshold");
				isCAEN_DGTZ_SetChannelTriggerThreshold = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelTriggerThreshold)
				return lpCAEN_DGTZ_SetChannelTriggerThreshold(handle,channel,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetChannelTriggerThreshold)(int, uint32_t, uint32_t*);
	LPCAEN_DGTZ_GetChannelTriggerThreshold lpCAEN_DGTZ_GetChannelTriggerThreshold = NULL;
	long isCAEN_DGTZ_GetChannelTriggerThreshold = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetChannelTriggerThreshold(int handle, uint32_t channel, uint32_t* Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetChannelTriggerThreshold)
			{
				lpCAEN_DGTZ_GetChannelTriggerThreshold = NULL;
				lpCAEN_DGTZ_GetChannelTriggerThreshold = (LPCAEN_DGTZ_GetChannelTriggerThreshold)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetChannelTriggerThreshold");
				isCAEN_DGTZ_GetChannelTriggerThreshold = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetChannelTriggerThreshold)
				return lpCAEN_DGTZ_GetChannelTriggerThreshold(handle,channel,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelPulsePolarity)(int, uint32_t, CAEN_DGTZ_PulsePolarity_t);
	LPCAEN_DGTZ_SetChannelPulsePolarity lpCAEN_DGTZ_SetChannelPulsePolarity = NULL;
	long isCAEN_DGTZ_SetChannelPulsePolarity = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelPulsePolarity(int handle, uint32_t channel, CAEN_DGTZ_PulsePolarity_t pol)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelPulsePolarity)
			{
				lpCAEN_DGTZ_SetChannelPulsePolarity = NULL;
				lpCAEN_DGTZ_SetChannelPulsePolarity = (LPCAEN_DGTZ_SetChannelPulsePolarity)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelPulsePolarity");
				isCAEN_DGTZ_SetChannelPulsePolarity = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelPulsePolarity)
				return lpCAEN_DGTZ_SetChannelPulsePolarity(handle,channel,pol);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetGroupTriggerThreshold)(int, uint32_t, uint32_t);
	LPCAEN_DGTZ_SetGroupTriggerThreshold lpCAEN_DGTZ_SetGroupTriggerThreshold = NULL;
	long isCAEN_DGTZ_SetGroupTriggerThreshold = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetGroupTriggerThreshold(int handle, uint32_t group, uint32_t Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetGroupTriggerThreshold)
			{
				lpCAEN_DGTZ_SetGroupTriggerThreshold = NULL;
				lpCAEN_DGTZ_SetGroupTriggerThreshold = (LPCAEN_DGTZ_SetGroupTriggerThreshold)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetGroupTriggerThreshold");
				isCAEN_DGTZ_SetGroupTriggerThreshold = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetGroupTriggerThreshold)
				return lpCAEN_DGTZ_SetGroupTriggerThreshold(handle,group,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetGroupTriggerThreshold)(int, uint32_t, uint32_t*);
	LPCAEN_DGTZ_GetGroupTriggerThreshold lpCAEN_DGTZ_GetGroupTriggerThreshold = NULL;
	long isCAEN_DGTZ_GetGroupTriggerThreshold = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetGroupTriggerThreshold(int handle, uint32_t group, uint32_t* Tvalue)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetGroupTriggerThreshold)
			{
				lpCAEN_DGTZ_GetGroupTriggerThreshold = NULL;
				lpCAEN_DGTZ_GetGroupTriggerThreshold = (LPCAEN_DGTZ_GetGroupTriggerThreshold)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetGroupTriggerThreshold");
				isCAEN_DGTZ_GetGroupTriggerThreshold = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetGroupTriggerThreshold)
				return lpCAEN_DGTZ_GetGroupTriggerThreshold(handle,group,Tvalue);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetZeroSuppressionMode)(int, CAEN_DGTZ_ZS_Mode_t);
	LPCAEN_DGTZ_SetZeroSuppressionMode lpCAEN_DGTZ_SetZeroSuppressionMode = NULL;
	long isCAEN_DGTZ_SetZeroSuppressionMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetZeroSuppressionMode(int handle, CAEN_DGTZ_ZS_Mode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetZeroSuppressionMode)
			{
				lpCAEN_DGTZ_SetZeroSuppressionMode = NULL;
				lpCAEN_DGTZ_SetZeroSuppressionMode = (LPCAEN_DGTZ_SetZeroSuppressionMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetZeroSuppressionMode");
				isCAEN_DGTZ_SetZeroSuppressionMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetZeroSuppressionMode)
				return lpCAEN_DGTZ_SetZeroSuppressionMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetZeroSuppressionMode)(int, CAEN_DGTZ_ZS_Mode_t*);
	LPCAEN_DGTZ_GetZeroSuppressionMode lpCAEN_DGTZ_GetZeroSuppressionMode = NULL;
	long isCAEN_DGTZ_GetZeroSuppressionMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetZeroSuppressionMode(int handle, CAEN_DGTZ_ZS_Mode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetZeroSuppressionMode)
			{
				lpCAEN_DGTZ_GetZeroSuppressionMode = NULL;
				lpCAEN_DGTZ_GetZeroSuppressionMode = (LPCAEN_DGTZ_GetZeroSuppressionMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetZeroSuppressionMode");
				isCAEN_DGTZ_GetZeroSuppressionMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetZeroSuppressionMode)
				return lpCAEN_DGTZ_GetZeroSuppressionMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetChannelZSParams)(int, uint32_t, CAEN_DGTZ_ThresholdWeight_t, int32_t, int32_t);
	LPCAEN_DGTZ_SetChannelZSParams lpCAEN_DGTZ_SetChannelZSParams = NULL;
	long isCAEN_DGTZ_SetChannelZSParams = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetChannelZSParams(int handle, uint32_t channel, CAEN_DGTZ_ThresholdWeight_t weight, int32_t  threshold, int32_t nsamp)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetChannelZSParams)
			{
				lpCAEN_DGTZ_SetChannelZSParams = NULL;
				lpCAEN_DGTZ_SetChannelZSParams = (LPCAEN_DGTZ_SetChannelZSParams)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetChannelZSParams");
				isCAEN_DGTZ_SetChannelZSParams = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetChannelZSParams)
				return lpCAEN_DGTZ_SetChannelZSParams(handle,channel,weight,threshold,nsamp);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetChannelZSParams)(int, uint32_t, CAEN_DGTZ_ThresholdWeight_t*, int32_t*, int32_t*);
	LPCAEN_DGTZ_GetChannelZSParams lpCAEN_DGTZ_GetChannelZSParams = NULL;
	long isCAEN_DGTZ_GetChannelZSParams = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetChannelZSParams(int handle, uint32_t channel, CAEN_DGTZ_ThresholdWeight_t* weight, int32_t* threshold, int32_t* nsamp)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetChannelZSParams)
			{
				lpCAEN_DGTZ_GetChannelZSParams = NULL;
				lpCAEN_DGTZ_GetChannelZSParams = (LPCAEN_DGTZ_GetChannelZSParams)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetChannelZSParams");
				isCAEN_DGTZ_GetChannelZSParams = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetChannelZSParams)
				return lpCAEN_DGTZ_GetChannelZSParams(handle,channel,weight,threshold,nsamp);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetAcquisitionMode)(int, CAEN_DGTZ_AcqMode_t);
	LPCAEN_DGTZ_SetAcquisitionMode lpCAEN_DGTZ_SetAcquisitionMode = NULL;
	long isCAEN_DGTZ_SetAcquisitionMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetAcquisitionMode(int handle, CAEN_DGTZ_AcqMode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetAcquisitionMode)
			{
				lpCAEN_DGTZ_SetAcquisitionMode = NULL;
				lpCAEN_DGTZ_SetAcquisitionMode = (LPCAEN_DGTZ_SetAcquisitionMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetAcquisitionMode");
				isCAEN_DGTZ_SetAcquisitionMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetAcquisitionMode)
				return lpCAEN_DGTZ_SetAcquisitionMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetAcquisitionMode)(int, CAEN_DGTZ_AcqMode_t*);
	LPCAEN_DGTZ_GetAcquisitionMode lpCAEN_DGTZ_GetAcquisitionMode = NULL;
	long isCAEN_DGTZ_GetAcquisitionMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetAcquisitionMode(int handle, CAEN_DGTZ_AcqMode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetAcquisitionMode)
			{
				lpCAEN_DGTZ_GetAcquisitionMode = NULL;
				lpCAEN_DGTZ_GetAcquisitionMode = (LPCAEN_DGTZ_GetAcquisitionMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetAcquisitionMode");
				isCAEN_DGTZ_GetAcquisitionMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetAcquisitionMode)
				return lpCAEN_DGTZ_GetAcquisitionMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetRunSynchronizationMode)(int, CAEN_DGTZ_RunSyncMode_t);
	LPCAEN_DGTZ_SetRunSynchronizationMode lpCAEN_DGTZ_SetRunSynchronizationMode = NULL;
	long isCAEN_DGTZ_SetRunSynchronizationMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetRunSynchronizationMode(int handle, CAEN_DGTZ_RunSyncMode_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetRunSynchronizationMode)
			{
				lpCAEN_DGTZ_SetRunSynchronizationMode = NULL;
				lpCAEN_DGTZ_SetRunSynchronizationMode = (LPCAEN_DGTZ_SetRunSynchronizationMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetRunSynchronizationMode");
				isCAEN_DGTZ_SetRunSynchronizationMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetRunSynchronizationMode)
				return lpCAEN_DGTZ_SetRunSynchronizationMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetRunSynchronizationMode)(int, CAEN_DGTZ_RunSyncMode_t*);
	LPCAEN_DGTZ_GetRunSynchronizationMode lpCAEN_DGTZ_GetRunSynchronizationMode = NULL;
	long isCAEN_DGTZ_GetRunSynchronizationMode = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetRunSynchronizationMode(int handle, CAEN_DGTZ_RunSyncMode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetRunSynchronizationMode)
			{
				lpCAEN_DGTZ_GetRunSynchronizationMode = NULL;
				lpCAEN_DGTZ_GetRunSynchronizationMode = (LPCAEN_DGTZ_GetRunSynchronizationMode)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetRunSynchronizationMode");
				isCAEN_DGTZ_GetRunSynchronizationMode = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetRunSynchronizationMode)
				return lpCAEN_DGTZ_GetRunSynchronizationMode(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetAnalogMonOutput)(int, CAEN_DGTZ_AnalogMonitorOutputMode_t*);
	LPCAEN_DGTZ_GetAnalogMonOutput lpCAEN_DGTZ_GetAnalogMonOutput = NULL;
	long isCAEN_DGTZ_GetAnalogMonOutput = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetAnalogMonOutput(int handle, CAEN_DGTZ_AnalogMonitorOutputMode_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetAnalogMonOutput)
			{
				lpCAEN_DGTZ_GetAnalogMonOutput = NULL;
				lpCAEN_DGTZ_GetAnalogMonOutput = (LPCAEN_DGTZ_GetAnalogMonOutput)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetAnalogMonOutput");
				isCAEN_DGTZ_GetAnalogMonOutput = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetAnalogMonOutput)
				return lpCAEN_DGTZ_GetAnalogMonOutput(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetAnalogInspectionMonParams)(int, uint32_t, uint32_t, CAEN_DGTZ_AnalogMonitorMagnify_t, CAEN_DGTZ_AnalogMonitorInspectorInverter_t);
	LPCAEN_DGTZ_SetAnalogInspectionMonParams lpCAEN_DGTZ_SetAnalogInspectionMonParams = NULL;
	long isCAEN_DGTZ_SetAnalogInspectionMonParams = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetAnalogInspectionMonParams(int handle, uint32_t channelmask, uint32_t offset, CAEN_DGTZ_AnalogMonitorMagnify_t mf, CAEN_DGTZ_AnalogMonitorInspectorInverter_t ami)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetAnalogInspectionMonParams)
			{
				lpCAEN_DGTZ_SetAnalogInspectionMonParams = NULL;
				lpCAEN_DGTZ_SetAnalogInspectionMonParams = (LPCAEN_DGTZ_SetAnalogInspectionMonParams)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetAnalogInspectionMonParams");
				isCAEN_DGTZ_SetAnalogInspectionMonParams = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetAnalogInspectionMonParams)
				return lpCAEN_DGTZ_SetAnalogInspectionMonParams(handle,channelmask,offset,mf,ami);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetAnalogInspectionMonParams)(int, uint32_t*, uint32_t*, CAEN_DGTZ_AnalogMonitorMagnify_t*, CAEN_DGTZ_AnalogMonitorInspectorInverter_t*);
	LPCAEN_DGTZ_GetAnalogInspectionMonParams lpCAEN_DGTZ_GetAnalogInspectionMonParams = NULL;
	long isCAEN_DGTZ_GetAnalogInspectionMonParams = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetAnalogInspectionMonParams(int handle, uint32_t* channelmask, uint32_t* offset, CAEN_DGTZ_AnalogMonitorMagnify_t* mf, CAEN_DGTZ_AnalogMonitorInspectorInverter_t* ami)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetAnalogInspectionMonParams)
			{
				lpCAEN_DGTZ_GetAnalogInspectionMonParams = NULL;
				lpCAEN_DGTZ_GetAnalogInspectionMonParams = (LPCAEN_DGTZ_GetAnalogInspectionMonParams)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetAnalogInspectionMonParams");
				isCAEN_DGTZ_GetAnalogInspectionMonParams = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetAnalogInspectionMonParams)
				return lpCAEN_DGTZ_GetAnalogInspectionMonParams(handle, channelmask, offset, mf, ami);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_DisableEventAlignedReadout)(int);
	LPCAEN_DGTZ_DisableEventAlignedReadout lpCAEN_DGTZ_DisableEventAlignedReadout = NULL;
	long isCAEN_DGTZ_DisableEventAlignedReadout = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_DisableEventAlignedReadout(int handle)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_DisableEventAlignedReadout)
			{
				lpCAEN_DGTZ_DisableEventAlignedReadout = NULL;
				lpCAEN_DGTZ_DisableEventAlignedReadout = (LPCAEN_DGTZ_DisableEventAlignedReadout)GetProcAddress(hLinkdll, "CAEN_DGTZ_DisableEventAlignedReadout");
				isCAEN_DGTZ_DisableEventAlignedReadout = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_DisableEventAlignedReadout)
				return lpCAEN_DGTZ_DisableEventAlignedReadout(handle);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetEventPackaging)(int, CAEN_DGTZ_EnaDis_t);
	LPCAEN_DGTZ_SetEventPackaging lpCAEN_DGTZ_SetEventPackaging = NULL;
	long isCAEN_DGTZ_SetEventPackaging = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetEventPackaging(int handle, CAEN_DGTZ_EnaDis_t mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetEventPackaging)
			{
				lpCAEN_DGTZ_SetEventPackaging = NULL;
				lpCAEN_DGTZ_SetEventPackaging = (LPCAEN_DGTZ_SetEventPackaging)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetEventPackaging");
				isCAEN_DGTZ_SetEventPackaging = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetEventPackaging)
				return lpCAEN_DGTZ_SetEventPackaging(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetEventPackaging)(int, CAEN_DGTZ_EnaDis_t*);
	LPCAEN_DGTZ_GetEventPackaging lpCAEN_DGTZ_GetEventPackaging = NULL;
	long isCAEN_DGTZ_GetEventPackaging = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetEventPackaging(int handle, CAEN_DGTZ_EnaDis_t* mode)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetEventPackaging)
			{
				lpCAEN_DGTZ_GetEventPackaging = NULL;
				lpCAEN_DGTZ_GetEventPackaging = (LPCAEN_DGTZ_GetEventPackaging)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetEventPackaging");
				isCAEN_DGTZ_GetEventPackaging = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetEventPackaging)
				return lpCAEN_DGTZ_GetEventPackaging(handle,mode);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetMaxNumAggregatesBLT)(int, uint32_t);
	LPCAEN_DGTZ_SetMaxNumAggregatesBLT lpCAEN_DGTZ_SetMaxNumAggregatesBLT = NULL;
	long isCAEN_DGTZ_SetMaxNumAggregatesBLT = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetMaxNumAggregatesBLT(int handle, uint32_t numAggr)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetMaxNumAggregatesBLT)
			{
				lpCAEN_DGTZ_SetMaxNumAggregatesBLT = NULL;
				lpCAEN_DGTZ_SetMaxNumAggregatesBLT = (LPCAEN_DGTZ_SetMaxNumAggregatesBLT)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetMaxNumAggregatesBLT");
				isCAEN_DGTZ_SetMaxNumAggregatesBLT = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetMaxNumAggregatesBLT)
				return lpCAEN_DGTZ_SetMaxNumAggregatesBLT(handle, numAggr);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetMaxNumEventsBLT)(int, uint32_t);
	LPCAEN_DGTZ_SetMaxNumEventsBLT lpCAEN_DGTZ_SetMaxNumEventsBLT = NULL;
	long isCAEN_DGTZ_SetMaxNumEventsBLT = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetMaxNumEventsBLT(int handle, uint32_t numEvents)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetMaxNumEventsBLT)
			{
				lpCAEN_DGTZ_SetMaxNumEventsBLT = NULL;
				lpCAEN_DGTZ_SetMaxNumEventsBLT = (LPCAEN_DGTZ_SetMaxNumEventsBLT)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetMaxNumEventsBLT");
				isCAEN_DGTZ_SetMaxNumEventsBLT = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetMaxNumEventsBLT)
				return lpCAEN_DGTZ_SetMaxNumEventsBLT(handle, numEvents);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetMaxNumAggregatesBLT)(int, uint32_t*);
	LPCAEN_DGTZ_GetMaxNumAggregatesBLT lpCAEN_DGTZ_GetMaxNumAggregatesBLT = NULL;
	long isCAEN_DGTZ_GetMaxNumAggregatesBLT = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetMaxNumAggregatesBLT(int handle, uint32_t* numAggr)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetMaxNumAggregatesBLT)
			{
				lpCAEN_DGTZ_GetMaxNumAggregatesBLT = NULL;
				lpCAEN_DGTZ_GetMaxNumAggregatesBLT = (LPCAEN_DGTZ_GetMaxNumAggregatesBLT)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetMaxNumAggregatesBLT");
				isCAEN_DGTZ_GetMaxNumAggregatesBLT = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetMaxNumAggregatesBLT)
				return lpCAEN_DGTZ_GetMaxNumAggregatesBLT(handle, numAggr);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetMaxNumEventsBLT)(int, uint32_t*);
	LPCAEN_DGTZ_GetMaxNumEventsBLT lpCAEN_DGTZ_GetMaxNumEventsBLT = NULL;
	long isCAEN_DGTZ_GetMaxNumEventsBLT = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetMaxNumEventsBLT(int handle, uint32_t* numEvents)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetMaxNumEventsBLT)
			{
				lpCAEN_DGTZ_GetMaxNumEventsBLT = NULL;
				lpCAEN_DGTZ_GetMaxNumEventsBLT = (LPCAEN_DGTZ_GetMaxNumEventsBLT)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetMaxNumEventsBLT");
				isCAEN_DGTZ_GetMaxNumEventsBLT = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetMaxNumEventsBLT)
				return lpCAEN_DGTZ_GetMaxNumEventsBLT(handle,numEvents);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_MallocReadoutBuffer)(int, char**, uint32_t*);
	LPCAEN_DGTZ_MallocReadoutBuffer lpCAEN_DGTZ_MallocReadoutBuffer = NULL;
	long isCAEN_DGTZ_MallocReadoutBuffer = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_MallocReadoutBuffer(int handle, char** buffer, uint32_t* size)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_MallocReadoutBuffer)
			{
				lpCAEN_DGTZ_MallocReadoutBuffer = NULL;
				lpCAEN_DGTZ_MallocReadoutBuffer = (LPCAEN_DGTZ_MallocReadoutBuffer)GetProcAddress(hLinkdll, "CAEN_DGTZ_MallocReadoutBuffer");
				isCAEN_DGTZ_MallocReadoutBuffer = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_MallocReadoutBuffer)
				return lpCAEN_DGTZ_MallocReadoutBuffer(handle,buffer,size);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_FreeReadoutBuffer)(char**);
	LPCAEN_DGTZ_FreeReadoutBuffer lpCAEN_DGTZ_FreeReadoutBuffer = NULL;
	long isCAEN_DGTZ_FreeReadoutBuffer = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_FreeReadoutBuffer(char** buffer)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_FreeReadoutBuffer)
			{
				lpCAEN_DGTZ_FreeReadoutBuffer = NULL;
				lpCAEN_DGTZ_FreeReadoutBuffer = (LPCAEN_DGTZ_FreeReadoutBuffer)GetProcAddress(hLinkdll, "CAEN_DGTZ_FreeReadoutBuffer");
				isCAEN_DGTZ_FreeReadoutBuffer = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_FreeReadoutBuffer)
				return lpCAEN_DGTZ_FreeReadoutBuffer(buffer);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_ReadData)(int, CAEN_DGTZ_ReadMode_t, char*, uint32_t*);
	LPCAEN_DGTZ_ReadData lpCAEN_DGTZ_ReadData = NULL;
	long isCAEN_DGTZ_ReadData = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_ReadData(int handle, CAEN_DGTZ_ReadMode_t mode, char* buffer, uint32_t* bufferSize)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_ReadData)
			{
				lpCAEN_DGTZ_ReadData = NULL;
				lpCAEN_DGTZ_ReadData = (LPCAEN_DGTZ_ReadData)GetProcAddress(hLinkdll, "CAEN_DGTZ_ReadData");
				isCAEN_DGTZ_ReadData = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_ReadData)
				return lpCAEN_DGTZ_ReadData(handle,mode,buffer,bufferSize);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetNumEvents)(int, char*, uint32_t, uint32_t*);
	LPCAEN_DGTZ_GetNumEvents lpCAEN_DGTZ_GetNumEvents = NULL;
	long isCAEN_DGTZ_GetNumEvents = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetNumEvents(int handle, char* buffer, uint32_t buffsize, uint32_t* numEvents)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetNumEvents)
			{
				lpCAEN_DGTZ_GetNumEvents = NULL;
				lpCAEN_DGTZ_GetNumEvents = (LPCAEN_DGTZ_GetNumEvents)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetNumEvents");
				isCAEN_DGTZ_GetNumEvents = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetNumEvents)
				return lpCAEN_DGTZ_GetNumEvents(handle,buffer,buffsize,numEvents);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetEventInfo)(int, char*, uint32_t, int32_t, CAEN_DGTZ_EventInfo_t*, char**);
	LPCAEN_DGTZ_GetEventInfo lpCAEN_DGTZ_GetEventInfo = NULL;
	long isCAEN_DGTZ_GetEventInfo = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetEventInfo(int handle, char* buffer, uint32_t buffsize, int32_t numEvent, CAEN_DGTZ_EventInfo_t* eventInfo, char** EventPtr)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetEventInfo)
			{
				lpCAEN_DGTZ_GetEventInfo = NULL;
				lpCAEN_DGTZ_GetEventInfo = (LPCAEN_DGTZ_GetEventInfo)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetEventInfo");
				isCAEN_DGTZ_GetEventInfo = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetEventInfo)
				return lpCAEN_DGTZ_GetEventInfo(handle,buffer,buffsize,numEvent,eventInfo,EventPtr);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_DecodeEvent)(int, char*, void**);
	LPCAEN_DGTZ_DecodeEvent lpCAEN_DGTZ_DecodeEvent = NULL;
	long isCAEN_DGTZ_DecodeEvent = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_DecodeEvent(int handle, char* evtPtr, void** Evt)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_DecodeEvent)
			{
				lpCAEN_DGTZ_DecodeEvent = NULL;
				lpCAEN_DGTZ_DecodeEvent = (LPCAEN_DGTZ_DecodeEvent)GetProcAddress(hLinkdll, "CAEN_DGTZ_DecodeEvent");
				isCAEN_DGTZ_DecodeEvent = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_DecodeEvent)
				return lpCAEN_DGTZ_DecodeEvent(handle,evtPtr,Evt);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_FreeEvent)(int, void**);
	LPCAEN_DGTZ_FreeEvent lpCAEN_DGTZ_FreeEvent = NULL;
	long isCAEN_DGTZ_FreeEvent = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_FreeEvent(int handle, void** Evt)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_FreeEvent)
			{
				lpCAEN_DGTZ_FreeEvent = NULL;
				lpCAEN_DGTZ_FreeEvent = (LPCAEN_DGTZ_FreeEvent)GetProcAddress(hLinkdll, "CAEN_DGTZ_FreeEvent");
				isCAEN_DGTZ_FreeEvent = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_FreeEvent)
				return lpCAEN_DGTZ_FreeEvent(handle,Evt);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_GetDPPEvents)(int, char*, uint32_t, void**, uint32_t*);
	LPCAEN_DGTZ_GetDPPEvents lpCAEN_DGTZ_GetDPPEvents = NULL;
	long isCAEN_DGTZ_GetDPPEvents = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_GetDPPEvents(int handle, char* buffer, uint32_t buffsize, void** events, uint32_t* numEventsArray)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_GetDPPEvents)
			{
				lpCAEN_DGTZ_GetDPPEvents = NULL;
				lpCAEN_DGTZ_GetDPPEvents = (LPCAEN_DGTZ_GetDPPEvents)GetProcAddress(hLinkdll, "CAEN_DGTZ_GetDPPEvents");
				isCAEN_DGTZ_GetDPPEvents = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_GetDPPEvents)
				return lpCAEN_DGTZ_GetDPPEvents(handle,buffer,buffsize,events,numEventsArray);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_MallocDPPEvents)(int, void**, uint32_t*);
	LPCAEN_DGTZ_MallocDPPEvents lpCAEN_DGTZ_MallocDPPEvents = NULL;
	long isCAEN_DGTZ_MallocDPPEvents = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_MallocDPPEvents(int handle, void** events, uint32_t* allocatedSize)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_MallocDPPEvents)
			{
				lpCAEN_DGTZ_MallocDPPEvents = NULL;
				lpCAEN_DGTZ_MallocDPPEvents = (LPCAEN_DGTZ_MallocDPPEvents)GetProcAddress(hLinkdll, "CAEN_DGTZ_MallocDPPEvents");
				isCAEN_DGTZ_MallocDPPEvents = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_MallocDPPEvents)
				return lpCAEN_DGTZ_MallocDPPEvents(handle,events,allocatedSize);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_FreeDPPEvents)(int, void**);
	LPCAEN_DGTZ_FreeDPPEvents lpCAEN_DGTZ_FreeDPPEvents = NULL;
	long isCAEN_DGTZ_FreeDPPEvents = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_FreeDPPEvents(int handle, void** events)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_FreeDPPEvents)
			{
				lpCAEN_DGTZ_FreeDPPEvents = NULL;
				lpCAEN_DGTZ_FreeDPPEvents = (LPCAEN_DGTZ_FreeDPPEvents)GetProcAddress(hLinkdll, "CAEN_DGTZ_FreeDPPEvents");
				isCAEN_DGTZ_FreeDPPEvents = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_FreeDPPEvents)
				return lpCAEN_DGTZ_FreeDPPEvents(handle,events);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_MallocDPPWaveforms)(int, void**, uint32_t*);
	LPCAEN_DGTZ_MallocDPPWaveforms lpCAEN_DGTZ_MallocDPPWaveforms = NULL;
	long isCAEN_DGTZ_MallocDPPWaveforms = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_MallocDPPWaveforms(int handle, void** waveforms, uint32_t* allocatedSize)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_MallocDPPWaveforms)
			{
				lpCAEN_DGTZ_MallocDPPWaveforms = NULL;
				lpCAEN_DGTZ_MallocDPPWaveforms = (LPCAEN_DGTZ_MallocDPPWaveforms)GetProcAddress(hLinkdll, "CAEN_DGTZ_MallocDPPWaveforms");
				isCAEN_DGTZ_MallocDPPWaveforms = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_MallocDPPWaveforms)
				return lpCAEN_DGTZ_MallocDPPWaveforms(handle,waveforms,allocatedSize);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_FreeDPPWaveforms)(int, void*);
	LPCAEN_DGTZ_FreeDPPWaveforms lpCAEN_DGTZ_FreeDPPWaveforms = NULL;
	long isCAEN_DGTZ_FreeDPPWaveforms = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_FreeDPPWaveforms(int handle, void* Waveforms)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_FreeDPPWaveforms)
			{
				lpCAEN_DGTZ_FreeDPPWaveforms = NULL;
				lpCAEN_DGTZ_FreeDPPWaveforms = (LPCAEN_DGTZ_FreeDPPWaveforms)GetProcAddress(hLinkdll, "CAEN_DGTZ_FreeDPPWaveforms");
				isCAEN_DGTZ_FreeDPPWaveforms = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_FreeDPPWaveforms)
				return lpCAEN_DGTZ_FreeDPPWaveforms(handle, Waveforms);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_DecodeDPPWaveforms)(int, void*, void*);
	LPCAEN_DGTZ_DecodeDPPWaveforms lpCAEN_DGTZ_DecodeDPPWaveforms = NULL;
	long isCAEN_DGTZ_DecodeDPPWaveforms = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_DecodeDPPWaveforms(int handle, void* event, void* waveforms)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_DecodeDPPWaveforms)
			{
				lpCAEN_DGTZ_DecodeDPPWaveforms = NULL;
				lpCAEN_DGTZ_DecodeDPPWaveforms = (LPCAEN_DGTZ_DecodeDPPWaveforms)GetProcAddress(hLinkdll, "CAEN_DGTZ_DecodeDPPWaveforms");
				isCAEN_DGTZ_DecodeDPPWaveforms = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_DecodeDPPWaveforms)
				return lpCAEN_DGTZ_DecodeDPPWaveforms(handle,event,waveforms);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}
	typedef  CAEN_DGTZ_ErrorCode(CAENDGTZ_API* LPCAEN_DGTZ_SetNumEventsPerAggregate)(int, uint32_t, int);
	LPCAEN_DGTZ_SetNumEventsPerAggregate lpCAEN_DGTZ_SetNumEventsPerAggregate = NULL;
	long isCAEN_DGTZ_SetNumEventsPerAggregate = 0;
	CAEN_DGTZ_ErrorCode CAENDGTZ_API CAEN_DGTZ_SetNumEventsPerAggregate(int handle, uint32_t numEvents,int channel)
	{
		if (hLinkdll)
		{
			if (FUNC_LOADED != isCAEN_DGTZ_SetNumEventsPerAggregate)
			{
				lpCAEN_DGTZ_SetNumEventsPerAggregate = NULL;
				lpCAEN_DGTZ_SetNumEventsPerAggregate = (LPCAEN_DGTZ_SetNumEventsPerAggregate)GetProcAddress(hLinkdll, "CAEN_DGTZ_SetNumEventsPerAggregate");
				isCAEN_DGTZ_SetNumEventsPerAggregate = FUNC_LOADED;
			}
			if (NULL != lpCAEN_DGTZ_SetNumEventsPerAggregate)
				return lpCAEN_DGTZ_SetNumEventsPerAggregate(handle,numEvents,channel);
			else
				return (CAEN_DGTZ_GenericError);
		}
		else
			return(CAEN_DGTZ_GenericError);
	}

};
