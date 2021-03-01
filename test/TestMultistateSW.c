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

void 
test_SwitchesCountersAreZeroAfterInit(void) 
{
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++) 
		{
			TEST_ASSERT_EQUAL(MSSW_GetCounter(i), 0);
		}
}

void 
test_0_switch_FromReleasedToPrepressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PREPRESSED);
}


void 
test_0_switch_FromPrepressedToPressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PREPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PRESSED);
}

void 
test_0_switch_FromPressedToPrereleased(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_RELEASED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PRERELEASED);
}


void 
test_0_switch_FromPrereleasedToReleased(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRERELEASED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_RELEASED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_RELEASED);
}


void 
test_0_switch_FromPressedToPressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRESSED);
			MSSW_SetCounter(i, 0);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PRESSED);
}


void 
test_0_switch_FromReleasedToReleased(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_RELEASED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_RELEASED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_RELEASED);
}

void 
test_0_switch_FromPrereleasedToPressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRERELEASED);
			MSSW_SetCounter(i, 0);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PRESSED);
}

void 
test_0_switch_FromPrepressedToReleased(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PREPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_RELEASED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_RELEASED);
}

void 
test_0_switch_FromPressedToLongpressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRESSED);
			MSSW_SetCounter(i, MSSW_LONGPRESSED_TICKS);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_LONGPRESSED);
}

void 
test_0_switch_FromLongpressedToLongpressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_LONGPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_LONGPRESSED);
}


void 
test_0_switch_FromLongpressedToPrereleased(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_LONGPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_RELEASED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_PRERELEASED);
}

void 
test_0_switch_FromPrereleasedToLongpressed(void)
{
	//given
	for(int i = 0; i < MSSW_NUM_SWITCHES; i++)
		{
			MSSW_SetState(i, MSSW_PRERELEASED);
			MSSW_SetCounter(i, MSSW_LONGPRESSED_TICKS);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, MSSW_PRESSED_LEVEL);
		}
	//act
	MSSW_Update();
	//assert
	TEST_ASSERT_EQUAL(MSSW_GetState(0), MSSW_LONGPRESSED);
}