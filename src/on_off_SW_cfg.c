/**
 * @file on_off_SW_cfg.c
 * @author Mohamed Hassanin Mohamed
 * @brief A module for the ON/OFF switch pattern
 * @version 0.1
 * @date 2021-02-27
 */

#include "on_off_SW_cfg.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static OnOffSWConfig_t SWConfig[ON_OFF_SW_NUM_SWITCHES] = {
  {.Index = 0}
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**
 * @brief return the configuration structure holding the configuration table of the module
 */
OnOffSWConfig_t *const 
OnOffSW_GetConfig(void) 
{
  return SWConfig;
}
/************************* END OF FILE ********************************/
