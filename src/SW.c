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
#include "Dio.h"

/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static SWConfig_t * gConfig;
/**********************************************************************
* Function Prototypes
**********************************************************************/
static void SW_FSM(DioPinState_t PinValue, SWState_t* State);
/**********************************************************************
* Function Definitions
**********************************************************************/
/*********************************************************************
* Function : SW_Init()
*//**
* \b Description: Initialization function for the SW module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the switches.
* @return void 
**********************************************************************/
void 
SW_Init(const SWConfig_t * const Config)
{
  if(Config == 0x0)
    {
      //choose your error handling method
    }

  gConfig = (SWConfig_t *)Config;

  for(int i = 0; i < MAX_SW_NUM; i++)
    {
      gConfig[i].State = SW_RELEASED;
    }
}

/**
 * @brief Getter to the switch state
 * 
 * @param Index the index of a switch inside the configuration table.
 * @return SWState_t The state of the switch
 */
SWState_t
SW_GetState(SW_t Index) 
{
  if(!(Index < MAX_SW_NUM))
    {
      //TODO:choose your error handling method
      return SW_PRESSED;
    }
  return gConfig[Index].State;
}

/**
 * @brief Setter to the switch state
 * 
 * @param Index the index of a switch inside the configuration table.
 * @param State The state of the switch
 */
void 
SW_SetState(SW_t Index, SWState_t State) 
{
  if(!(State < MAX_SW_STATE && Index < MAX_SW_NUM))
    {
      //TODO:choose your error handling method
      return;
    }
  gConfig[Index].State = State;
}

/*********************************************************************
* Function : SW_FSM()
*//**
* \b Description: Utility function to be called from SW_Update to update
* the state of a switch<br/><br/>
* \b PRE-CONDITION: SW_Init is called<br/>
* @param PinNumber the pin number in the port
* @param state a pointer to the state of the switch
**********************************************************************/
static void 
SW_FSM(DioPinState_t PinValue, SWState_t* State)
{
  if(!(State != 0x0 &&
  *State < MAX_SW_STATE &&
  PinValue < MAX_DIO_PIN_STATE))
    {
      //TODO:choose your error handling method
      return;
    }

  switch(*State) {
  case SW_RELEASED:
    if(PinValue == SW_PRESSED_LEVEL)
      {
	*State = SW_PREPRESSED;
      }
    else
      {
	*State = SW_RELEASED;
      }
  break;
  case SW_PREPRESSED:
    if(PinValue == SW_PRESSED_LEVEL)
      {
	*State = SW_PRESSED;
      }
    else
      {
	*State = SW_RELEASED;
      }
  break;
  case SW_PRESSED:
    if(PinValue == SW_RELEASED_LEVEL)
      {
	*State = SW_PRERELEASED;
      }
    else
      {
	*State = SW_PRESSED;
      }
  break;
  case SW_PRERELEASED:
    if(PinValue == SW_PRESSED_LEVEL)
      {
	*State = SW_PRESSED;
      }
    else
      {
	*State = SW_RELEASED;
      }
  break;
  default:
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
void 
SW_Update(void) {
  for(uint8_t i = 0; i < MAX_SW_NUM; i++)
    {
      DioPinState_t PinState = Dio_ChannelRead(gConfig[i].Channel);
      SW_FSM(PinState, &(gConfig[i].State));
    }
}

/************************* END OF FILE ********************************/
