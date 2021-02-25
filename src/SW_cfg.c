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
#include "Dio_cfg.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static SWConfig_t SWConfig[NUM_SWITCHES] = {
        {SW_RELEASED, PORTB_0},
        {SW_RELEASED, PORTB_1},
        {SW_RELEASED, PORTB_2}
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
