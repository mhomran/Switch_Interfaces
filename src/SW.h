/**
 * @file SW.h
 * @author Mohamed Hassanin Mohamed
 * @brief A switch module to interface with switches.
 * @version 0.1
 * @date 2021-02-21
 */
#ifndef SW_H_
#define SW_H_
/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
#include <inttypes.h>
/// @endcond
#include "Dio_cfg.h"
#include "SW_cfg.h"
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
#define SW_PRESSED_LEVEL LOW
#define SW_RELEASED_LEVEL HIGH

/**********************************************************************
* Function Prototypes
**********************************************************************/
void SW_Init(const SWConfig_t * const Config);
SW_STATE_t SW_GetState(uint8_t Index);
void SW_Update(void);

#endif /* end SW_H_ */
/************************* END OF FILE ********************************/
