/**
 * @file SW_cfg.c
 * @author Mohamed Hassanin Mohamed
 * @brief A switch module to interface with switches.
 * @version 0.1
 * @date 2021-02-21
 */
/**********************************************************************
* Includes
**********************************************************************/
#include "SW_cfg.h"
#include "../dio/dio_cfg.h"
#include "../port.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static SWConfig_t SWConfig[MAX_SW_NUM] = {
  {.Channel = MY_SW_CHANNEL},
  {.Channel = MY_ON_OFF_SW_CHANNEL}
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**
 * @brief return the configuration structure holding the configuration table of the module
 */
SWConfig_t *const 
SW_GetConfig(void) 
{
  return SWConfig;
}

/************************* END OF FILE ********************************/
