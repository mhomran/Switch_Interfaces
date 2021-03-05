/** @file dio_cfg.h
* @brief This module contains interface definitions for the
* Dio configuration. This is the header file for the definition of the
* interface for retrieving the digital input/output configuration table.
*/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**
 * Means that this feature is supported
 */
#define STD_ON 1
/**
 * Means that this feature is not supported
 */
#define STD_OFF 0
/**
* Defines the number of pins on each processor port.
*/
#define NUMBER_OF_CHANNELS_PER_PORT 8U
/**
* Defines the number of ports on the processor.
*/
#define NUMBER_OF_PORTS 4U

/**
 * Does this target support toggling.
 */
#define DIO_TOGGLE STD_OFF
/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
  LOW, /**< Defines digital state ground */
  HIGH, /**< Defines digital state power */
  MAX_DIO_PIN_STATE /**< Defines the maximum digital state */
}DioPinState_t;
/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
  PORTA_0,
  PORTA_1,
  PORTA_2,
  PORTA_3,
  PORTA_4,
  PORTA_5,
  PORTA_6,
  PORTA_7,
  PORTB_0,
  PORTB_1,
  PORTB_2,
  PORTB_3,
  PORTB_4,
  PORTB_5,
  PORTB_6,
  PORTB_7,
  PORTC_0,
  PORTC_1,
  PORTC_2,
  PORTC_3,
  PORTC_4,
  PORTC_5,
  PORTC_6,
  PORTC_7,
  PORTD_0,
  PORTD_1,
  PORTD_2,
  PORTD_3,
  PORTD_4,
  PORTD_5,
  PORTD_6,
  PORTD_7,
  DIO_MAX_PIN_NUMBER
}DioChannel_t;

/**
* Defines the possible DIO pin multiplexing values. The datasheet
* should be reviewed for proper muxing options.
*/
typedef enum
{
  DIO_MAX_MODE
}DioMode_t;

/**
* Defines the possible states of the channel pull-ups
*/
typedef enum
{
  PULLUP_DISABLED, /**< Used to disable the internal pull-ups */
  PULLUP_ENABLED, /**< Used to enable the internal pull-ups */
  MAX_RESISTOR /**< Resistor states should be below this value */
}DioResistor_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
  INPUT,
  OUTPUT
}DioDirection_t;

/**
* Defines the digital input/output configuration table’s elements that are used
* by Dio_Init to configure the Dio peripheral.
*/
typedef struct
{
  DioChannel_t Channel; /**< The I/O pin */
  DioResistor_t Resistor; /**< ENABLED or DISABLED */
  DioDirection_t Direction; /**< OUTPUT or INPUT */
  DioPinState_t Data; /**< HIGH or LOW */
}DioConfig_t;

/**
* The speed of the output changing state.
*/
typedef enum
{
  FAST, /**< Fast slew rate is configured on the corresponding pin, */
  SLOW /**< Slow slew rate is configured on the corresponding pin, */
}DioSlew_t;

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

#endif /*DIO_H_*/
/***End of File****************************************************/
