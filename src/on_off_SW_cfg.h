/**
 * @file on_off_SW_cfg.h
 * @author Mohamed Hassanin Mohamed
 * @brief A module for the ON/OFF switch pattern
 * @version 0.1
 * @date 2021-02-27
 */
#ifndef ON_OFF_SW_CFG_H
#define ON_OFF_SW_CFG_H
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
/**********************************************************************
* Typedefs
**********************************************************************/
/**
 * @brief the state of a switch: ON/OFF
 */ 
typedef enum {
	ON_OFF_SW_ON, /**< The switch is in ON state */
	ON_OFF_SW_OFF, /**< The switch is in OFF state */
	MAX_ON_OFF_SW_STATE /**< Number of states */
} OnOffSWState_t;

/**
 * @brief A structure for the ON/OFF switch module configuration
 */
typedef struct {
	uint8_t Index; /**< the switch index */
	OnOffSWState_t State;
} OnOffSWConfig_t;
/**********************************************************************
* Module Configuration parameters
**********************************************************************/
#define ON_OFF_SW_NUM_SWITCHES 1
/**********************************************************************
* functions prototypes
**********************************************************************/
OnOffSWConfig_t *const OnOffSW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/
