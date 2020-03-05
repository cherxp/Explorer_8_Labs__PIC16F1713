/**
  Explorer 8 High-Endurance Flash (HEF) Lab Source File

  @Company
    Microchip Technology Inc.

  @File Name
    HEF.c 

  @Summary
    This is the source file for the HEF lab

  @Description
    This source file contains the code for the HEF lab.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F1713
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
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

/**
  Section: Included Files
 */
#include "../../mcc_generated_files/memory.h"
#include "../../mcc_generated_files/pin_manager.h"
#include "../../mcc_generated_files/adc.h"
#include "../../labs.h"
#include "../../lcd.h"

/**
  Section: Macro Declaration
 */
#define ADDR    0xF850     // HEF address

/**
  Section: Local Variable Declarations
 */
uint16_t adcResult;

/*
                             Application    
 */
void HEF(void) {
    if (labState == NOT_RUNNING) {
        LEDs_SetLow();

        LCD_GoTo(0, 0);
        LCD_WriteString("      HEF       ");
        LCD_GoTo(1, 0);
        LCD_WriteString("Voltage = 0.00 V");

        adcResult = 0;

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        uint16_t readData;
        uint16_t voltVal;
        uint16_t HefAddr = ADDR;
        uint16_t Buf[ERASE_FLASH_BLOCKSIZE];

        if (SWITCH_S1_PORT == LOW) {
            // Debounce by delaying
            __delay_ms(120);

            // Check if S1 is still pressed
            if (SWITCH_S1_PORT == LOW) {

                adcResult = ADC_GetConversion(POT_CHANNEL);
                adcResult /= 2;

                FLASH_WriteWord(HefAddr, Buf, adcResult);

                readData = FLASH_ReadWord(HefAddr);

                voltVal = readData;

                // Display the voltage value to the LCD
                LCD_GoTo(1, 10);
                LCD_WriteByte((voltVal / 100) + '0');
                LCD_WriteByte('.');
                LCD_WriteByte((voltVal / 10) % 10 + '0');
                LCD_WriteByte((voltVal % 10) + '0');
            }
        }
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
