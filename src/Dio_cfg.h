/** 
 * @file Dio_cfg.h
 * @author Mohamed Hassanin
 * @brief This module contains interface definitions for the
 * Dio configuration. This is the header file for the definition of the
 * interface for retrieving the digital input/output configuration table.
 * @version 0.1
 * @date 2021-01-12
*/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/**********************************************************************
* Includes
**********************************************************************/
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**
* Defines the number of pins on each processor port.
*/
#define DIO_CHANNELS_PER_PORT 8U
/**
* Defines the number of ports on the processor.
*/
#define DIO_NUMBER_OF_PORTS 3U
/**********************************************************************
* Features Support
**********************************************************************/
/**
 * The feature is supported
 */
#define STD_ON 1
/**
 * The feature is not supported
 */
#define STD_OFF 0

/**
 * Does this target support toggling.
 */
#define DIO_TOGGLE STD_OFF
/**
 * Does this target support pullup resistors.
 */
#define DIO_PULLUP STD_OFF
/**
 * Does this target support pulldown resistors.
 */
#define DIO_PULLDOWN STD_OFF
/**
 * Does this target support output speed change
 */
#define DIO_SPEED_CHANGE STD_OFF
/**
 * Does this target support mode change
 */
#define DIO_MODE_CHANGE STD_OFF

/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
	LOW, /**< Defines digital state ground */
	HIGH /**< Defines digital state power */
}DioPinState_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
	INPUT, 
	OUTPUT
}DioDirection_t;

/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
	/* TODO: Populate this list based on available MCU pins */
	PORTB_0,
	PORTB_1,
	PORTB_2,
	DIO_MAX_PIN_NUMBER 
}DioChannel_t;

/**
* Defines the digital input/output configuration table’s elements that are used
* by Dio_Init to configure the Dio peripheral.
*/
typedef struct
{
	DioChannel_t Channel; /**< The I/O pin */
	DioDirection_t Direction; /**< OUTPUT or INPUT */
	DioPinState_t Data; /**< HIGH or LOW */
#if DIO_PULLUP == STD_ON
	DioResistor_t PullUpResistor; /**< ENABLED or DISABLED */
#endif
#if DIO_PULLDOWN == STD_ON
	DioResistor_t PullDownResistor; /**< ENABLED or DISABLED */
#endif	
#if DIO_MODE_CHANGE == STD_ON
	DioMode_t Mode; /**< The Mode of the channel */
#endif
#if DIO_SPEED_CHANGE == STD_ON
	DioSpeed_t Speed; /**< The speed of the channel */
#endif
}DioConfig_t;

#if DIO_MODE_CHANGE == STD_ON
/**
* Defines the possible DIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
	/* TODO: Populate with possible mode options */
	DIO_MAX_MODE
}DioMode_t;
#endif

#if DIO_PULLUP == STD_ON || DIO_PULLDOWN == STD_ON
/**
* Defines the possible states of the channel pull-up/down resistors
*/
typedef enum
{
	DISABLED, /**< Used to disable the internal pull-up/down resistors */
	ENABLED, /**< Used to enable the internal pull-up/down resistors */
	MAX_RESISTOR /**< Resistor states should be below this value */
}DioResistor_t;
#endif

#if DIO_SPEED_CHANGE == STD_ON
/**
* The speed of the output changing state.
*/
typedef enum
{
	/* TODO: populate */
}DioSpeed_t;
#endif

/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const DioConfig_t* Dio_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DIO_H_*/
/************************* END OF FILE ********************************/
