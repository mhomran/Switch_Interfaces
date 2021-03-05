/**
 * @file multistate_SW_cfg.h
 * @author Mohamed Hassanin
 * @brief multistate switch pattern 
 * @version 0.1
 * @date 2021-03-01
 */
#ifndef MULTISTATE_SW_CFG_H
#define MULTISTATE_SW_CFG_H
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
#define MSSW_PRESSED_LEVEL LOW
#define MSSW_RELEASED_LEVEL HIGH
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "../dio/dio_cfg.h"
/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines an enumerated list of all multistate swithes in the project
*/
typedef enum {
  MSSW_MY_MSSW,
  MAX_MSSW_NUM
} MSSW_t;

/**
 * @brief The state of the switches.
 */
typedef enum {
  MSSW_PREPRESSED, /**< The switch is about to be pressed*/
  MSSW_PRESSED, /**< The switch is pressed */
  MSSW_PRERELEASED, /**< The switch is about to be released*/
  MSSW_RELEASED, /**< The switch is released */
  MSSW_LONGPRESSED, /**< The switch is pressed long*/
  MAX_MSSW_STATE /**< Number of states */
} MSSWState_t;

/**
 * @brief Switch structure
 */
typedef struct {
  MSSWState_t State; /**< The switch state */
  DioChannel_t Channel; /**< the physical channel that the switch is connected to */
  uint16_t Counter; /**< counter for the number of ticks the switch is pressed */
} MSSWConfig_t;
/**********************************************************************
* Module Configuration parameters
**********************************************************************/
/**< the number of Switch ticks required to go in long-pressed state */
#define MSSW_LONGPRESSED_TICKS 50
/**********************************************************************
* functions prototypes
**********************************************************************/
MSSWConfig_t *const MSSW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/
