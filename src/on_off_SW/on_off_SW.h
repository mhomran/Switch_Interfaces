/**
 * @file on_off_SW.h
 * @author Mohamed Hassanin
 * @brief A module for the ON/OFF switch pattern
 * @version 0.1
 * @date 2021-02-27
 */
#ifndef ON_OFF_SW_H
#define ON_OFF_SW_H
/**********************************************************************
* Includes
**********************************************************************/
#include "on_off_SW_cfg.h"
/**********************************************************************
* Function Prototypes
**********************************************************************/
extern void OnOffSW_Init(const OnOffSWConfig_t * const Config);
extern void OnOffSW_Update(void);
extern OnOffSWState_t OnOffSW_GetState(OnOffSW_t Index);
extern void OnOffSW_SetState(OnOffSW_t Index, OnOffSWState_t State);

#endif /* end ON_OFF_SW_H */
/************************* END OF FILE ********************************/
