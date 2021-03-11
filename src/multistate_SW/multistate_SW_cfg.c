/**
 * @file multistate_SW_cfg.c
 * @author Mohamed Hassanin
 * @brief multistate switch pattern 
 * @version 0.1
 * @date 2021-03-01
 */

#include "../multistate_SW/multistate_SW_cfg.h"

#include "../port.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static MSSWConfig_t SWConfig[MAX_MSSW_NUM] = {
  {.Channel = MY_MSSW_CHANNEL}
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**
 * @brief return the configuration structure holding the configuration table of the module
 */
extern MSSWConfig_t *const 
MSSW_GetConfig(void) 
{
  return SWConfig;
}
/************************* END OF FILE ********************************/
