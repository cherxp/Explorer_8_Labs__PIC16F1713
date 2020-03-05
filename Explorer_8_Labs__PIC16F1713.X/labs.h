/**
  Main Header File

  @Company
    Microchip Technology Inc.

  @File Name
    main.h

  @Summary
    This is the header file for the variables declarations and function prototypes

  @Description
    This header file provides all the variables and function prototypes used in this project.
    Generation Information :
        Product Revision  :  MPLAB? Code Configurator - v3.45
        Device            :  PIC16F1713
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.45
        MPLAB             :  MPLAB X v4.15
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */


#ifndef LABS_H
#define	LABS_H

#include <xc.h>
#include <stdint.h>
    

/**
  Section: Macro Declarations
 */
    #define _XTAL_FREQ          8000000
    #define PRESSED             1
    #define NOT_PRESSED         0
    #define RUNNING             1
    #define NOT_RUNNING         0
    #define RIGHT               1
    #define LEFT                0
    #define LEDs                LATB
    #define LEDs_SetLow()       do { LATB = 0; } while(0)
    #define LEDs_ShiftRight()   do { LATB <<= 1; } while(0)
    #define LEDs_ShiftLeft()    do { LATB >>= 1; } while(0)

    #define INTERRUPT_TMR0InterruptEnable()         do { TMR0IE = 1; } while(0)
    #define INTERRUPT_InterruptOnChangeEnable()     do { INTCONbits.IOCIE = 1; } while(0)
    #define INTERRUPT_IOCPositiveEnable()           do { IOCBP0 = 1; } while(0)
    #define INTERRUPT_TMR0InterruptDisable()        do { TMR0IE = 0; } while(0)
    #define INTERRUPT_InterruptOnChangeDisable()    do { INTCONbits.IOCIE = 0; } while(0)
    #define INTERRUPT_IOCPositiveDisable()          do { IOCBP0 = 0; } while(0)


/**
  Section: Variable Definitions
 */
    uint8_t labNumber = 0;
    uint8_t switchEvent = 0;
    uint8_t labState = NOT_RUNNING;
    uint8_t btnState = NOT_PRESSED;    

/**
  Section: Function Prototypes
 */
    
/**
  @Summary
    Performs the HelloWorld Lab.

  @Description
    This turns on LED_D8 on the Explorer8 Board. The LED status is displayed on 
    the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void HelloWorld(void);

/**
  @Summary
    Performs the Blink Lab.

  @Description
    LED_D8 blinks at a rate of approximately 1.5 seconds. The LED status is
    displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Blink(void);

/**
  @Summary
    Performs the Rotate Lab.

  @Description
    The LEDs rotate from left to right at a rate of 0.5s. The status of the LEDs are
    displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Rotate(void);

/**
  @Summary
    Performs the Analog to Digital Conversion Lab.

  @Description
    The top 3 MSbs of the ADC are displayed on the LEDs. Rotate the potentiometer 
    to change the display. The same is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void ADC(void);

/**
  @Summary
    Performs the Variable Speed Rotate Lab.

  @Description
    The LEDs rotate from left to right similar to Rotate Lab with varying speed.
    Rotate the POT counterclockwise to see the LEDs shift faster.
    The approximate total delay value is displayed on the LCD. 

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void VSR(void);

/**
  @Summary
    Performs the Debounce Lab.

  @Description
    When SWITCH_S1 is pressed, it will light one LED in the array.
    Pressing it again will light the next LED to the right and so on.
    When the switch is held down, it will show a rotating pattern like Lab 3.
    The LEDs' status is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Debounce(void);

/**
  @Summary
    Performs the Pulse Width Modulation Lab.

  @Description
    Rotating the potentiometer will adjust the brightness of a single LED, LED_D8. 
    The duty cycle is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void PWM(void);

/**
  @Summary
    Performs the Timer1 Lab.

  @Description
    The LEDs rotate from left to right, similar to Rotate Lab, at a rate of ~0.5 seconds.
    A counter also increments every ~1 second and is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Timer1(void);

/**
  @Summary
    Performs the Interrupt Lab.

  @Description
    The LEDs rotate at a constant speed and the switch reverses their direction.
    The direction is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Interrupt(void);

/**
  @Summary
    Performs the Sleep-Wakeup Lab.

  @Description
    LED_D7 is ON while the MCU is in sleep mode. After 8 seconds, the Watchdog 
    Timer will wake up the device from sleep then both LED_D6 and LED_D8 will turn ON, 
    while LED_D7 will turn OFF. The status of the device is displayed on the LCD.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void SleepWakeUp(void);

/**
  @Summary
    Performs the High Endurance Flash Lab.

  @Description
   Whenever SWITCH_S1 is pressed, the current voltage reading of the device is written to HEF.
   These are read afterwards and displayed on the LCD. Rotating the potentiometer changes
   voltage value to be stored/read to/from HEF.

  @Preconditions
    SYSTEM_Initialize() and LCD_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void HEF(void);

#endif	/* LABS_H */
/**
 End of File
 */