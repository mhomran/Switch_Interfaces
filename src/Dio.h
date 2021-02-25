/** 
 * @file Dio.h
 * @author Mohamed Hassanin
 * @brief The interface definition for the dio.
 * This is the header file for the definition of the interface for a digital
 * input/output peripheral on a standard microcontroller.
 * @version 0.1
 * @date 2021-01-12
*/
#ifndef DIO_H_
#define DIO_H_
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "Dio_cfg.h" /**< For dio configuration */
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**********************************************************************
* Configuration Constants
**********************************************************************/
/**********************************************************************
* Macros
**********************************************************************/
/**********************************************************************
* Typedefs
**********************************************************************/
/**********************************************************************
* Variables
**********************************************************************/
/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Dio_Init(const DioConfig_t * const Config);

DioPinState_t Dio_ChannelRead(DioChannel_t Channel);
void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State);

void Dio_SetChannelDirection(DioChannel_t Channel, DioDirection_t Direction);

void Dio_RegisterWrite(uint8_t volatile * const Address, uint8_t Value);
const volatile uint8_t Dio_RegisterRead(const volatile uint8_t * const Address);

#if DIO_TOGGLE == STD_ON
void Dio_ChannelToggle(DioChannel_t Channel);
#endif
#if DIO_PULLUP == STD_ON
void Dio_Pullup(DioChannel_t Channel, DioResistor_t State);
#endif
#if DIO_PULLDOWN == STD_ON
void Dio_Pulldown(DioChannel_t Channel, DioResistor_t State);
#endif
#if DIO_MODE_CHANGE == STD_ON
void Dio_ChangeMode(DioChannel_t Channel, DioMode_t Mode)
#endif
#if DIO_SPEED_CHANGE == STD_ON
void Dio_ChangeSpeed(DioChannel_t Channel, DioSpeed_t Speed)
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*DIO_H_*/
/*************** END OF FILE ********************************/
