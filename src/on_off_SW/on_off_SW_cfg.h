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
* Defines an enumerated list of all the on/off switches in the project
*/
typedef enum {
  //TODO: add your switches here
  ON_OFF_SW_OPEN_VALVE,
  MAX_ON_OFF_SW_NUM
} OnOffSW_t;

/**
 * @brief the state of a switch: ON/OFF
 */ 
typedef enum {
  ON_OFF_SW_ON, /**< The switch is in ON state */
  ON_OFF_SW_INTER_ON, /**< The switch is about to be ON state */
  ON_OFF_SW_OFF, /**< The switch is in OFF state */
  ON_OFF_SW_INTER_OFF, /**< The switch is about to be OFF state */
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
* functions prototypes
**********************************************************************/
extern OnOffSWConfig_t *const OnOffSW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/
