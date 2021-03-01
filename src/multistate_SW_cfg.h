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
* Includes
**********************************************************************/
#include <inttypes.h>
#include "Dio_cfg.h"
/**********************************************************************
* Typedefs
**********************************************************************/
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
} MSSWConfig_t;
/**********************************************************************
* Module Configuration parameters
**********************************************************************/
#define MSSW_NUM_SWITCHES 1
/**********************************************************************
* functions prototypes
**********************************************************************/
MSSWConfig_t *const MSSW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/