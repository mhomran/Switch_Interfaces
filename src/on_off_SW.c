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
#include "SW.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static OnOffSWConfig_t * gConfig;
/**********************************************************************
* Function Prototypes
**********************************************************************/
static void OnOffSW_FSM(SWState_t, uint8_t);
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

/**
 * @brief getter to the ON/OFF switch state
 * 
 * @param Index the idnex of the switch
 * @return OnOffSWState_t the state of the switch
 */
OnOffSWState_t
OnOffSW_GetState(uint8_t Index)
{
  return gConfig[Index].State;
}

/**
 * @brief Setter to the ON/OFF switch state
 * 
 * @param Index the index of the switch
 * @param State the state of the switch
 */
void
OnOffSW_SetState(uint8_t Index, OnOffSWState_t State)
{
  if(!(State < MAX_ON_OFF_SW_STATE && Index < SW_NUM_SWITCHES))
    {
      //TODO:choose your error handling method
      return;
    }
  gConfig[Index].State = State;
}

/*********************************************************************
* Function : OnOffSW_FSM()
*//**
* \b Description:  function to be called from OnOffSW_Update to update
* the state of a ON/OFF switch<br/><br/>
* \b PRE-CONDITION: SW_Init is called<br/>
* @param SwIndex the switch index
* @param state a pointer to the state of the switch (pressed, released, etc.)
*
* @see SW_Init
**********************************************************************/
static void
OnOffSW_FSM(SWState_t SwState, uint8_t SwIndex)
{
  switch (gConfig[SwIndex].State)
  {
  case ON_OFF_SW_OFF:
    if(SwState == SW_PRESSED)
      {
	OnOffSW_SetState(SwIndex, ON_OFF_SW_INTER_ON);
      }
  break;
  case ON_OFF_SW_INTER_ON:
    if(SwState == SW_RELEASED)
      {
	OnOffSW_SetState(SwIndex, ON_OFF_SW_ON);
      }
  break;
  case ON_OFF_SW_ON:
    if(SwState == SW_PRESSED)
      {
	OnOffSW_SetState(SwIndex, ON_OFF_SW_INTER_OFF);
      }
  break;
  case ON_OFF_SW_INTER_OFF:
    if(SwState == SW_RELEASED)
      {
	OnOffSW_SetState(SwIndex, ON_OFF_SW_OFF);
      }
  break;
  default:
  //do nothing
  break;
  }
}

/*********************************************************************
* Function : SW_Update()
*//**
* \b Description: update the state of ON/OFF switches <br/><br/>
* \b PRE-CONDITION: OnOffSW_Init is called<br/>
* @return void
*
* @see OnOffSW_Init
**********************************************************************/
void 
OnOffSW_Update(void)
{
  for(int i = 0; i < ON_OFF_SW_NUM_SWITCHES; i++)
    {
      SWState_t SwState = SW_GetState(i);
      OnOffSW_FSM(SwState, i);
    }
}
/************************* END OF FILE ********************************/
