/**
 * @file TestMultistateSW.c
 * @author Mohamed Hassanin
 * @brief unit testing for multistate switch pattern
 * @version 0.1
 * @date 2021-03-01
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

#include "multistate_SW.h"
#include "multistate_SW_cfg.h"
#include "MockDio.h"

/**********************************************************************
* Variable Definitions
**********************************************************************/
static MSSWConfig_t * gConfig;

void setUp(void)
{
	gConfig = MSSW_GetConfig();
	MSSW_Init(gConfig);
}

void tearDown(void)
{
}

/**********************************************************************
* Test cases
**********************************************************************/
void 
test_SwitchesAreReleasedAfterInit(void) 
{
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++) 
		{
			TEST_ASSERT_EQUAL(MSSW_GetState(i), MSSW_RELEASED);
		}
}
