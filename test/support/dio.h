/** @file dio.h
* @brief The interface definition for the dio.
*
* This is the header file for the definition of the interface for a digital
* input/output peripheral on a standard microcontroller.
*/
#ifndef DIO_H_
#define DIO_H_
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "dio_cfg.h" /**< For dio configuration */
/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Dio_Init(const DioConfig_t * const Config);
DioPinState_t Dio_ChannelRead(DioChannel_t Channel);
void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State);
void Dio_ChannelToggle(DioChannel_t Channel);
void Dio_RegisterWrite(uint8_t volatile * const Address, uint8_t Value);
const volatile uint8_t Dio_RegisterRead(const volatile uint8_t * const Address);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*DIO_H_*/
/*** End of File ******************************************************/
