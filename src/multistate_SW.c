/**
 * @file multistate_SW.c
 * @author Mohamed Hassanin
 * @brief multistate switch pattern 
 * @version 0.1
 * @date 2021-03-01
 */

/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
#include <inttypes.h>
/// @endcond
#include "multistate_SW.h"
#include "Dio.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static MSSWConfig_t * gConfig;
/**********************************************************************
* Function Definitions
**********************************************************************/
/*********************************************************************
* Function : MSSW_Init()
*//**
* \b Description: Initialization function for the mutlistate SW module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the switches.
* @return void 
**********************************************************************/
void 
MSSW_Init(const MSSWConfig_t * const Config)
{
	if(Config == 0x0) 
		{
			//choose your error handling method
		}

	gConfig = (MSSWConfig_t *)Config;

	for(int i = 0; i < MSSW_NUM_SWITCHES; i++) 
		{
			gConfig[i].State = MSSW_RELEASED;
		}
}

/**
 * @brief Getter to the switch state
 * 
 * @param Index the index of a switch inside the configuration table.
 * @return MSSWState_t The state of the switch
 */
MSSWState_t
MSSW_GetState(uint8_t Index) 
{
	return gConfig[Index].State;
}
/************************* END OF FILE ********************************/

