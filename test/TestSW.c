/**
 * @file SW_test.c
 * @author Mohamed Hassanin
 * @brief Unit test file for the switch module
 * @version 0.1
 * @date 2021-02-21
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

#include "SW.h"
#include "SW_cfg.h"
#include "MockDio.h"


/**********************************************************************
* Variable Definitions
**********************************************************************/
static SWConfig_t * gConfig;

/**********************************************************************/

void setUp(void)
{
	gConfig = SW_GetConfig();
	SW_Init(gConfig);
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
	for(int i = 0; i < SW_NUM_SWITCHES; i++) 
		{
			TEST_ASSERT_EQUAL(SW_GetState(i), SW_RELEASED);
		}
}

void 
test_0_switch_FromReleasedToPrepressed(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_PRESSED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_PREPRESSED);
}

void 
test_0_switch_FromPrepressedToPressed(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PREPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_PRESSED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_PRESSED);
}

void 
test_0_switch_FromPrepressedToReleased(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PREPRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_RELEASED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_RELEASED);
}

void 
test_0_switch_FromPressedToPrereleased(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_RELEASED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_PRERELEASED);
}

void 
test_0_switch_FromPrereleasedToReleased(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PRERELEASED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_RELEASED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_RELEASED);
}

void 
test_0_switch_FromPressedToPressed(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PRESSED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_PRESSED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_PRESSED);
}

void 
test_0_switch_FromReleasedToReleased(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_RELEASED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_RELEASED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_RELEASED);
}

void 
test_0_switch_FromPrereleasedToPressed(void)
{
	//given
	for(int i = 0; i < SW_NUM_SWITCHES; i++)
		{
			SW_SetState(i, SW_PRERELEASED);
			Dio_ChannelRead_ExpectAndReturn(gConfig[i].Channel, SW_PRESSED_LEVEL);
		}
	//act
	SW_Update();
	//assert
	TEST_ASSERT_EQUAL(SW_GetState(0), SW_PRESSED);
}






