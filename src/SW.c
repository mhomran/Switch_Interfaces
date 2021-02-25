/**
 * @file SW.h
 * @author Mohamed Hassanin Mohamed
 * @brief A switch module to interface with switches.
 * @version 0.1
 * @date 2021-02-21
 */
/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
#include <inttypes.h>
/// @endcond
#include "SW.h"
#include "SW_cfg.h"
#include "RuntimeError.h"

/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static SWConfig_t * gConfig;
/**********************************************************************
* Function Definitions
**********************************************************************/
void 
SW_Init(const SWConfig_t * const Config)
{
	gConfig = Config;

	for(int i = 0; i < NUM_SWITCHES; i++) 
		{
			gConfig[i].State = SW_RELEASED;
		}
}

SW_STATE_t SW_GetState(uint8_t Index) 
{
	return gConfig[Index].State;
}

/*********************************************************************
* Function : SW_NormalUpdate()
*//**
* \b Description: Utility function to be called from SW_Update to update
* the state of a switch<br/><br/>
* \b PRE-CONDITION: SW_Init is called<br/>
* @param PinNumber the pin number in the port
* @param state a pointer to the state of the switch
* @return uint8_t the pin voltage level.
*
* @see SW_Init
**********************************************************************/
static void SW_NormalUpdate(DioPinState_t PinValue, SW_STATE_t* state)
{
	switch(*state) {
	case SW_RELEASED:
		if(PinValue == SW_PRESSED_LEVEL) 
			{
				*state = SW_PREPRESSED;
			}
		else
			{
				*state = SW_RELEASED;
			}
	break;
	case SW_PREPRESSED:
		if(PinValue == SW_PRESSED_LEVEL)
			{
				*state = SW_PRESSED;
			}
		else 
			{
				*state = SW_RELEASED;
			}
	break;
	case SW_PRESSED:
		if(PinValue == SW_RELEASED_LEVEL)
			{
				*state = SW_PRERELEASED;
			}
		else 
			{
				*state = SW_PRESSED;
			}
	break;
	case SW_PRERELEASED:
		if(PinValue == SW_PRESSED_LEVEL) 
			{
				*state = SW_PRESSED;
			}
		else
			{
				*state = SW_RELEASED;
			}
	break;
	}
}

/*********************************************************************
* Function : SW_Update()
*//**
* \b Description: update the state of switches <br/><br/>
* \b PRE-CONDITION: SW_Init is called<br/>
* @return void
*
* @see SW_Init
**********************************************************************/
void SW_Update(void) {
	for(uint8_t i = 0; i < NUM_SWITCHES; i++) 
		{
			DioPinState_t PinState = Dio_ChannelRead(gConfig[i].Channel);
			SW_NormalUpdate(PinState, &(gConfig[i].State));
		}
}

/************************* END OF FILE ********************************/
