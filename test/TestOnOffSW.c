/**
 * @file SW_test.c
 * @author Mohamed Hassanin
 * @brief Unit test file for the switch module
 * @version 0.1
 * @date 2021-02-27
 */
/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
/* Include Unity */
#include <stdio.h>
#include <string.h>
#include "unity.h"
/// @endcond

#include "on_off_SW.h"
#include "on_off_SW_cfg.h"
#include "Mock_SW.h"

/**********************************************************************
* Variable Definitions
**********************************************************************/
static OnOffSWConfig_t * gConfig;

void 
setUp(void)
{
	gConfig = OnOffSW_GetConfig();
	OnOffSW_Init(gConfig);
}

void 
tearDown(void)
{
}

/**********************************************************************
* Test cases
**********************************************************************/

void 
testSwitchesAreInOffStateAfterInit(void) 
{
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_OFF);
		}
}

void
test_0_switch_OFF_To_INTER_ON_WhenSwIsPressed(void)
{
	//given
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			SW_GetState_ExpectAndReturn(gConfig[i].Index, SW_PRESSED);
		}

	//act
	OnOffSW_Update();

	//assert
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_INTER_ON);
		}
}

void
test_0_switch_INTER_ON_To_ON_WhenSwIsReleased(void)
{
	//given
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			OnOffSW_SetState(i, ON_OFF_SW_INTER_ON);
			SW_GetState_ExpectAndReturn(gConfig[i].Index, SW_RELEASED);
		}

	//act
	OnOffSW_Update();

	//assert
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_ON);
		}
}

void
test_0_switch_ON_To_INTER_OFF_WhenSwIsPressed(void)
{
	//given
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			OnOffSW_SetState(i, ON_OFF_SW_ON);
			SW_GetState_ExpectAndReturn(gConfig[i].Index, SW_PRESSED);
		}

	//act
	OnOffSW_Update();

	//assert
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_INTER_OFF);
		}
}

void
test_0_switch_INTER_OFF_To_OFF_WhenSwIsReleased(void)
{
	//given
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			OnOffSW_SetState(i, ON_OFF_SW_INTER_OFF);
			SW_GetState_ExpectAndReturn(gConfig[i].Index, SW_RELEASED);
		}

	//act
	OnOffSW_Update();

	//assert
	for(int i = 0; i < MAX_ON_OFF_SW_NUM; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_OFF);
		}
}
