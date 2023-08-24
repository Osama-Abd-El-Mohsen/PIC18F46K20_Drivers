/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    GPIO                   ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/
#ifndef GPIO_INTERFAC_H_
#define GPIO_INTERFAC_H_

/*section : Includes*/
#include <./pic18f4620.h>
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "GPIO_Private.h"
#include "GPIO_Cfg.h"
/*section : Macro Declarations */
#define BIT_MASK (uint8)1
#define INITIAL_ENUM_VALUE 0
#define PORT_PIN_MAX_INDEX 7
#define PORT_MAX_INDEX 4
#define PORT_INPUT 0xff
#define PORT_OUTPUT 0x00
#define PORT_HIGH 0xff
#define PORT_LOW 0x00
/*section : Macro Functions Declarations */
#define SET_BIT(REG, BITPOS) (REG |= (BIT_MASK << BITPOS))
#define CLR_BIT(REG, BITPOS) (REG &= ~(BIT_MASK << BITPOS))
#define TOG_BIT(REG, BITPOS) (REG ^= (BIT_MASK << BITPOS))
#define GET_BIT(REG, BITPOS) ((REG >> BITPOS) & BIT_MASK)
/*section : Data Types Declearations */
typedef enum
{
    LOW = INITIAL_ENUM_VALUE,
    HIGH
} logic_t;

typedef enum
{
    OUTPUT = INITIAL_ENUM_VALUE,
    INPUT
} direction_t;

typedef enum
{
    PIN0 = INITIAL_ENUM_VALUE,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_index_t;

typedef enum
{
    PORTA_INDEX = INITIAL_ENUM_VALUE,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
} port_index_t;

typedef struct
{
    uint8 port : 3;      /*@ref port_index_t*/
    uint8 pin : 3;       /*@ref pin_index_t*/
    uint8 direction : 1; /*@ref direction_t*/
    uint8 logic : 1;     /*@ref logic_t*/
} pin_config_t;

/*section : Functions Declarations*/
/*pin*/
/**
 * @brief
 *
 * @param _pin_config
 * @return Std_ReturnType
 */
Std_ReturnType gpio_pin_direction_init(pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(pin_config_t *_pin_config, direction_t *_direction_status);
Std_ReturnType gpio_pin_write_logic(pin_config_t *_pin_config, logic_t _pin_logic);
Std_ReturnType gpio_pin_read_logic(pin_config_t *_pin_config, logic_t *_pin_logic);
Std_ReturnType gpio_pin_toggle_logic(pin_config_t *_pin_config);
Std_ReturnType gpio_pin_init(pin_config_t *_pin_config);

/*port*/
Std_ReturnType gpio_port_direction_init(port_index_t _port, uint8 _direction_status);
Std_ReturnType gpio_port_get_direction_status(port_index_t _port, uint8 *_direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t _port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t _port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t _port);

#endif
