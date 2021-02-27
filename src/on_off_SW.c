/**
 * @file on_off_SW.c
 * @author Mohamed Hassanin
 * @brief A module for the ON/OFF switch pattern
 * @version 0.1
 * @date 2021-02-27
 */
/**********************************************************************
* Includes
**********************************************************************/
#include "on_off_SW.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static OnOffSWConfig_t * gConfig;
/**********************************************************************
* Function Definitions
**********************************************************************/
/*********************************************************************
* Function : OnOffSW_Init()
*//**
* \b Description: Initialization function for the ON/OFF SW module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the switches.
* @return void 
**********************************************************************/
void 
OnOffSW_Init(const OnOffSWConfig_t * const Config)
{
	if(Config == 0x0) 
		{
			//choose your error handling method
		}

	gConfig = (OnOffSWConfig_t *)Config;

	for(int i = 0; i < ON_OFF_SW_NUM_SWITCHES; i++) 
		{
			gConfig[i].State = ON_OFF_SW_OFF;
		}
}

OnOffSWState_t
OnOffSW_GetState(uint8_t Index)
{
	return gConfig[Index].State;
}

void 
OnOffSW_Update(void)
{

}
/************************* END OF FILE ********************************/
