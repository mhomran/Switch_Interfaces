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
#include "MockSW.h"

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
	for(int i = 0; i < ON_OFF_SW_NUM_SWITCHES; i++)
		{
			TEST_ASSERT_EQUAL(OnOffSW_GetState(i), ON_OFF_SW_OFF);
		}
}