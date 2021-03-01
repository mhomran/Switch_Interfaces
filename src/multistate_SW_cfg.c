/**
 * @file multistate_SW_cfg.c
 * @author Mohamed Hassanin
 * @brief multistate switch pattern 
 * @version 0.1
 * @date 2021-03-01
 */

#include "multistate_SW_cfg.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static MSSWConfig_t SWConfig[MSSW_NUM_SWITCHES] = {
	{.Channel = PORTB_0}
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**
 * @brief return the configuration structure holding the configuration table of the module
 */
MSSWConfig_t *const 
MSSW_GetConfig(void) 
{
	return SWConfig;	
}
/************************* END OF FILE ********************************/