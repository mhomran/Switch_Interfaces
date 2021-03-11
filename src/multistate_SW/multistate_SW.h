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

#include "../multistate_SW/multistate_SW_cfg.h"
/**********************************************************************
* Function Prototypes
**********************************************************************/
extern void MSSW_Init(const MSSWConfig_t * const Config);
extern void MSSW_Update(void);

extern MSSWState_t MSSW_GetState(MSSW_t Index);
extern void MSSW_SetState(MSSW_t Index, MSSWState_t State);

extern uint16_t MSSW_GetCounter(MSSW_t Index);
extern void MSSW_SetCounter(MSSW_t Index, uint16_t Counter);

#endif /* end MULTISTATE_SW_H_ */
/************************* END OF FILE ********************************/
