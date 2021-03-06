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
#include "../multistate_SW/multistate_SW.h"

#include <inttypes.h>
/// @endcond
#include "../dio/dio.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static MSSWConfig_t * gConfig; /**< a configuration pointer to the configuration table */
/**********************************************************************
* Function Prototypes
**********************************************************************/
static void MSSW_FSM(DioState_t PinValue, MSSWState_t* State, uint16_t* Counter);
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
extern void 
MSSW_Init(const MSSWConfig_t * const Config)
{
  if(Config == 0x0)
    {
	    //choose your error handling method
    }

  gConfig = (MSSWConfig_t *)Config;

  for(int i = 0; i < MAX_MSSW_NUM; i++)
    {
      gConfig[i].State = MSSW_RELEASED;
      gConfig[i].Counter = 0;
    }
}

/**
 * @brief Getter to the switch state
 * 
 * @param Index the index of a switch inside the configuration table.
 * @return MSSWState_t The state of the switch
 */
extern MSSWState_t
MSSW_GetState(MSSW_t Index) 
{
  if(!(Index < MAX_MSSW_NUM))
    {
      //TODO:choose your error handling method
      return MSSW_PRESSED;
    }
  return gConfig[Index].State;
}

/**
 * @brief Setter to the switch state
 * 
 * @param Index the index of a switch inside the configuration table.
 * @param State The state of the switch
 */
extern void 
MSSW_SetState(MSSW_t Index, MSSWState_t State) 
{
  if(!(State < MAX_MSSW_STATE && Index < MAX_MSSW_NUM))
    {
      //TODO:choose your error handling method
      return;
    }
  gConfig[Index].State = State;
}

/**
 * @brief Getter to the switch pressed time in ticks
 * 
 * @param Index the index of a switch inside the configuration table.
 * @return uint16_t the switch pressed time in ticks
 */
extern uint16_t
MSSW_GetCounter(MSSW_t Index) 
{
  if(!(Index < MAX_MSSW_NUM))
    {
      //TODO:choose your error handling method
      return 0;
    }
  return gConfig[Index].Counter;
}

/**
 * @brief Setter to the switch pressed time in ticks
 * 
 * @param Index the index of a switch inside the configuration table.
 * @param Counter the switch pressed time in ticks
 */
extern void 
MSSW_SetCounter(MSSW_t Index, uint16_t Counter) 
{
  if(!(Counter <= MSSW_LONGPRESSED_TICKS && Index < MAX_MSSW_NUM))
    {
      //TODO:choose your error handling method
      return;
    }
  gConfig[Index].Counter = Counter;
}

/*********************************************************************
* Function : MSSW_Update()
*//**
* \b Description: update the state of switches <br/><br/>
* \b PRE-CONDITION: MSSW_Init is called<br/>
* @return void
*
* @see MSSW_Init
**********************************************************************/
extern void
MSSW_Update(void)
{
  for(uint8_t i = 0; i < MAX_MSSW_NUM; i++)
    {
      DioState_t PinState = Dio_ChannelRead(gConfig[i].Channel);
      MSSW_FSM(PinState, &(gConfig[i].State), &(gConfig[i].Counter));
    }
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
MSSW_FSM(DioState_t PinValue, MSSWState_t* State, uint16_t* Counter)
{
  if(!(State != 0x0 &&
  Counter != 0x0 &&
  *State < MAX_MSSW_STATE &&
  PinValue < DIO_STATE_MAX))
    {
      //TODO:choose your error handling method
      return;
    }

  switch(*State) {
  case MSSW_RELEASED:
    if(PinValue == MSSW_PRESSED_LEVEL)
      {
        *State = MSSW_PREPRESSED;
      }
    else
      {
	      *State = MSSW_RELEASED;
      }
  break;
  case MSSW_PREPRESSED:
    if(PinValue == MSSW_PRESSED_LEVEL)
      {
	      *State = MSSW_PRESSED;
      }
    else
      {
	      *State = MSSW_RELEASED;
      }
  break;
  case MSSW_PRESSED:
    if(PinValue == MSSW_RELEASED_LEVEL)
      {
	      *State = MSSW_PRERELEASED;
      }
    else if(*Counter != MSSW_LONGPRESSED_TICKS)
      {
        *State = MSSW_PRESSED;
        (*Counter)++;
      }
    else
      {
	      *State = MSSW_LONGPRESSED;
      }
  break;
  case MSSW_PRERELEASED:
    if(PinValue == MSSW_RELEASED_LEVEL)
      {
        *State = MSSW_RELEASED;
        *Counter = 0;
      }
    else if(*Counter != MSSW_LONGPRESSED_TICKS)
      {
	      *State = MSSW_PRESSED;
      }
    else
      {
	      *State = MSSW_LONGPRESSED;
      }
  break;
  case MSSW_LONGPRESSED:
    if(PinValue == MSSW_RELEASED_LEVEL)
      {
	      *State = MSSW_PRERELEASED;
      }
    else
      {
	      *State = MSSW_LONGPRESSED;
      }
  break;
  default:
    /* DO NOTHING */
  break;
  }
}
/************************* END OF FILE ********************************/

