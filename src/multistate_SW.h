/**
 * @file multistate_SW.h
 * @author Mohamed Hassanin
 * @brief multistate switch pattern 
 * @version 0.1
 * @date 2021-03-01
 */
#ifndef MULTISTATE_SW_H_
#define MULTISTATE_SW_H_
/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
#include <inttypes.h>
/// @endcond
#include "multistate_SW_cfg.h"
/**********************************************************************
* Function Prototypes
**********************************************************************/
void MSSW_Init(const MSSWConfig_t * const Config);
void MSSW_Update(void);

MSSWState_t MSSW_GetState(uint8_t Index);
void MSSW_SetState(uint8_t Index, MSSWState_t State);

uint16_t MSSW_GetCounter(uint8_t Index);
void MSSW_SetCounter(uint8_t Index, uint16_t Counter);

#endif /* end MULTISTATE_SW_H_ */
/************************* END OF FILE ********************************/
