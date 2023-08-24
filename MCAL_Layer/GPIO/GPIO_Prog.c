/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    GPIO                   ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "GPIO_Interfac.h"

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/*pin*/
/**
 * @brief Initialize the direction of specific bin
 *
 * @param _pin_config pointer to a configration struct @ref pin_config_t
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_init(pin_config_t *_pin_config)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        switch (_pin_config->direction)
        {
        case OUTPUT:
            CLR_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
            break;

        case INPUT:
            SET_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
            break;

        default:
            Local_u8StateError = E_NOT_OK;
            break;
        }
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Get direction state of specific pin
 *
 * @param _pin_config pointer to a configration struct @ref  pin_config_t
 * @param _direction_status @ref direction_t
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(pin_config_t *_pin_config, direction_t *_direction_status)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config || NULL == _direction_status || _pin_config->pin > PORT_PIN_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        *_direction_status = GET_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Write logic to specific pin @ref logic_t
 *
 * @param _pin_config pointer to a configration struct @ref _pin_config
 * @param _pin_logic
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(pin_config_t *_pin_config, logic_t _pin_logic)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        switch (_pin_logic)
        {
        case HIGH:
            SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
            break;

        case LOW:
            CLR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
            break;

        default:
            Local_u8StateError = E_NOT_OK;
            break;
        }
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Read logic to specific pin @ref logic_t
 *
 * @param _pin_config pointer to a configration struct @ref pin_config_t
 * @param _pin_logic
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(pin_config_t *_pin_config, logic_t *_pin_logic)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config || NULL == _pin_logic || _pin_config->pin > PORT_PIN_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        *_pin_logic = GET_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief  Toggle logic to specific pin
 *
 * @param _pin_config pointer to a configration struct @ref pin_config_t
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(pin_config_t *_pin_config)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        TOG_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Initialize Pin direction with logic low
 *
 * @param _pin_config pointer to a configration struct @ref pin_config_t
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_init(pin_config_t *_pin_config)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _pin_config)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        gpio_pin_direction_init(&_pin_config);
        gpio_pin_write_logic(&_pin_config, _pin_config->logic);
    }

    return Local_u8StateError;
}
#endif

/*port*/
/**
 * @brief Initialize the direction of specific port
 *
 * @param _port
 * @param _direction_status
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_init(port_index_t _port, uint8 _direction_status)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (_port > PORT_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {

        *tris_registers[_port] = _direction_status;
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Get direction state of specific port
 *
 * @param _port @ref port_index_t
 * @param _direction_status @ref unit8
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t _port, uint8 *_direction_status)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == _direction_status || _port > PORT_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        *_direction_status = *tris_registers[_port];
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief  Write logic to specific port
 *
 * @param _port @ref port_index_t
 * @param logic @ref unit8
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t _port, uint8 logic)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if ( _port > PORT_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {

        *lat_registers[_port] = logic;
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Read logic to specific port
 *
 * @param _port @ref port_index_t
 * @param logic @ref unit8 *
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t _port, uint8 *logic)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (NULL == logic || _port > PORT_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        *logic = *port_registers[_port];
    }

    return Local_u8StateError;
}
#endif

/**
 * @brief Toggle logic to specific port
 *
 * @param _port @ref port_index_t
 * @return Std_ReturnType state of the function
 *          ( E_OK )     : the function done successfully
 *          ( E_NOT_OK ) : the function has issue
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t _port)
{
    Std_ReturnType Local_u8StateError = E_OK;
    if (_port > PORT_MAX_INDEX)
    {
        Local_u8StateError = E_NOT_OK;
    }

    else
    {
        *lat_registers[_port] = ~*lat_registers[_port];
    }

    return Local_u8StateError;
}
#endif
