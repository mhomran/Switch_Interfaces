/**
 * @file SW_cfg.h
 * @author Mohamed Hassanin Mohamed
 * @brief A configuration file for the switches
 * @version 0.1
 * @date 2021-02-25
 */
#ifndef SW_CFG_H
#define SW_CFG_H
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
    SW_PREPRESSED, /**< The switch is about to be pressed*/
    SW_PRESSED, /**< The switch is pressed */
    SW_PRERELEASED, /**< The switch is about to be released*/
    SW_RELEASED /**< The switch is released */
} SW_STATE_t;

/**
 * @brief Switch structure
 */
typedef struct {
    SW_STATE_t State; /**< The switch state */
    DioChannel_t Channel; /**< the physical channel that the switch is connected to */
} SWConfig_t;
/**********************************************************************
* Module Configuration parameters
**********************************************************************/
#define NUM_SWITCHES 3
/**********************************************************************
* functions prototypes
**********************************************************************/
SWConfig_t *const SW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/
