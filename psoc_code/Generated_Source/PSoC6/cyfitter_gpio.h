/*******************************************************************************
* File Name: cyfitter_gpio.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_GPIO_H
#define INCLUDED_CYFITTER_GPIO_H
#include "cy_device_headers.h"

/* I2C_scl */
#define I2C_scl_0_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_scl_0_INBUF_ENABLED 1u
#define I2C_scl_0_INIT_DRIVESTATE 1u
#define I2C_scl_0_INIT_MUXSEL 19u
#define I2C_scl_0_INPUT_SYNC 2u
#define I2C_scl_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define I2C_scl_0_NUM 0u
#define I2C_scl_0_PORT GPIO_PRT6
#define I2C_scl_0_SLEWRATE CY_GPIO_SLEW_FAST
#define I2C_scl_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define I2C_scl_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_scl_INBUF_ENABLED 1u
#define I2C_scl_INIT_DRIVESTATE 1u
#define I2C_scl_INIT_MUXSEL 19u
#define I2C_scl_INPUT_SYNC 2u
#define I2C_scl_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define I2C_scl_NUM 0u
#define I2C_scl_PORT GPIO_PRT6
#define I2C_scl_SLEWRATE CY_GPIO_SLEW_FAST
#define I2C_scl_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* I2C_sda */
#define I2C_sda_0_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_sda_0_INBUF_ENABLED 1u
#define I2C_sda_0_INIT_DRIVESTATE 1u
#define I2C_sda_0_INIT_MUXSEL 19u
#define I2C_sda_0_INPUT_SYNC 2u
#define I2C_sda_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define I2C_sda_0_NUM 1u
#define I2C_sda_0_PORT GPIO_PRT6
#define I2C_sda_0_SLEWRATE CY_GPIO_SLEW_FAST
#define I2C_sda_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define I2C_sda_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_sda_INBUF_ENABLED 1u
#define I2C_sda_INIT_DRIVESTATE 1u
#define I2C_sda_INIT_MUXSEL 19u
#define I2C_sda_INPUT_SYNC 2u
#define I2C_sda_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define I2C_sda_NUM 1u
#define I2C_sda_PORT GPIO_PRT6
#define I2C_sda_SLEWRATE CY_GPIO_SLEW_FAST
#define I2C_sda_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_1_rx */
#define UART_1_rx_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_1_rx_0_INBUF_ENABLED 1u
#define UART_1_rx_0_INIT_DRIVESTATE 1u
#define UART_1_rx_0_INIT_MUXSEL 18u
#define UART_1_rx_0_INPUT_SYNC 2u
#define UART_1_rx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_1_rx_0_NUM 0u
#define UART_1_rx_0_PORT GPIO_PRT5
#define UART_1_rx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_1_rx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_1_rx_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_1_rx_INBUF_ENABLED 1u
#define UART_1_rx_INIT_DRIVESTATE 1u
#define UART_1_rx_INIT_MUXSEL 18u
#define UART_1_rx_INPUT_SYNC 2u
#define UART_1_rx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_1_rx_NUM 0u
#define UART_1_rx_PORT GPIO_PRT5
#define UART_1_rx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_1_rx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_1_tx */
#define UART_1_tx_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_1_tx_0_INBUF_ENABLED 0u
#define UART_1_tx_0_INIT_DRIVESTATE 1u
#define UART_1_tx_0_INIT_MUXSEL 18u
#define UART_1_tx_0_INPUT_SYNC 2u
#define UART_1_tx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_1_tx_0_NUM 1u
#define UART_1_tx_0_PORT GPIO_PRT5
#define UART_1_tx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_1_tx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_1_tx_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_1_tx_INBUF_ENABLED 0u
#define UART_1_tx_INIT_DRIVESTATE 1u
#define UART_1_tx_INIT_MUXSEL 18u
#define UART_1_tx_INPUT_SYNC 2u
#define UART_1_tx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_1_tx_NUM 1u
#define UART_1_tx_PORT GPIO_PRT5
#define UART_1_tx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_1_tx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_Rx */
#define CapSense_Rx_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Rx_0_INBUF_ENABLED 0u
#define CapSense_Rx_0_INIT_DRIVESTATE 1u
#define CapSense_Rx_0_INIT_MUXSEL 4u
#define CapSense_Rx_0_INPUT_SYNC 2u
#define CapSense_Rx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Rx_0_NUM 1u
#define CapSense_Rx_0_PORT GPIO_PRT8
#define CapSense_Rx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Rx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Rx_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Rx_1_INBUF_ENABLED 0u
#define CapSense_Rx_1_INIT_DRIVESTATE 1u
#define CapSense_Rx_1_INIT_MUXSEL 4u
#define CapSense_Rx_1_INPUT_SYNC 2u
#define CapSense_Rx_1_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Rx_1_NUM 2u
#define CapSense_Rx_1_PORT GPIO_PRT8
#define CapSense_Rx_1_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Rx_1_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_Tx */
#define CapSense_Tx_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Tx_0_INBUF_ENABLED 0u
#define CapSense_Tx_0_INIT_DRIVESTATE 1u
#define CapSense_Tx_0_INIT_MUXSEL 0u
#define CapSense_Tx_0_INPUT_SYNC 2u
#define CapSense_Tx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Tx_0_NUM 0u
#define CapSense_Tx_0_PORT GPIO_PRT1
#define CapSense_Tx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Tx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Tx_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Tx_INBUF_ENABLED 0u
#define CapSense_Tx_INIT_DRIVESTATE 1u
#define CapSense_Tx_INIT_MUXSEL 0u
#define CapSense_Tx_INPUT_SYNC 2u
#define CapSense_Tx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Tx_NUM 0u
#define CapSense_Tx_PORT GPIO_PRT1
#define CapSense_Tx_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Tx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_Sns */
#define CapSense_Sns_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Sns_0_INBUF_ENABLED 0u
#define CapSense_Sns_0_INIT_DRIVESTATE 1u
#define CapSense_Sns_0_INIT_MUXSEL 0u
#define CapSense_Sns_0_INPUT_SYNC 2u
#define CapSense_Sns_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Sns_0_NUM 3u
#define CapSense_Sns_0_PORT GPIO_PRT8
#define CapSense_Sns_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Sns_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Sns_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Sns_1_INBUF_ENABLED 0u
#define CapSense_Sns_1_INIT_DRIVESTATE 1u
#define CapSense_Sns_1_INIT_MUXSEL 0u
#define CapSense_Sns_1_INPUT_SYNC 2u
#define CapSense_Sns_1_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Sns_1_NUM 4u
#define CapSense_Sns_1_PORT GPIO_PRT8
#define CapSense_Sns_1_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Sns_1_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Sns_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Sns_2_INBUF_ENABLED 0u
#define CapSense_Sns_2_INIT_DRIVESTATE 1u
#define CapSense_Sns_2_INIT_MUXSEL 0u
#define CapSense_Sns_2_INPUT_SYNC 2u
#define CapSense_Sns_2_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Sns_2_NUM 5u
#define CapSense_Sns_2_PORT GPIO_PRT8
#define CapSense_Sns_2_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Sns_2_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Sns_3_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Sns_3_INBUF_ENABLED 0u
#define CapSense_Sns_3_INIT_DRIVESTATE 1u
#define CapSense_Sns_3_INIT_MUXSEL 0u
#define CapSense_Sns_3_INPUT_SYNC 2u
#define CapSense_Sns_3_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Sns_3_NUM 6u
#define CapSense_Sns_3_PORT GPIO_PRT8
#define CapSense_Sns_3_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Sns_3_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Sns_4_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Sns_4_INBUF_ENABLED 0u
#define CapSense_Sns_4_INIT_DRIVESTATE 1u
#define CapSense_Sns_4_INIT_MUXSEL 0u
#define CapSense_Sns_4_INPUT_SYNC 2u
#define CapSense_Sns_4_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Sns_4_NUM 7u
#define CapSense_Sns_4_PORT GPIO_PRT8
#define CapSense_Sns_4_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Sns_4_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_Cmod */
#define CapSense_Cmod_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Cmod_0_INBUF_ENABLED 0u
#define CapSense_Cmod_0_INIT_DRIVESTATE 1u
#define CapSense_Cmod_0_INIT_MUXSEL 0u
#define CapSense_Cmod_0_INPUT_SYNC 2u
#define CapSense_Cmod_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Cmod_0_NUM 7u
#define CapSense_Cmod_0_PORT GPIO_PRT7
#define CapSense_Cmod_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Cmod_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_Cmod_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_Cmod_INBUF_ENABLED 0u
#define CapSense_Cmod_INIT_DRIVESTATE 1u
#define CapSense_Cmod_INIT_MUXSEL 0u
#define CapSense_Cmod_INPUT_SYNC 2u
#define CapSense_Cmod_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_Cmod_NUM 7u
#define CapSense_Cmod_PORT GPIO_PRT7
#define CapSense_Cmod_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_Cmod_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_CintA */
#define CapSense_CintA_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_CintA_0_INBUF_ENABLED 0u
#define CapSense_CintA_0_INIT_DRIVESTATE 1u
#define CapSense_CintA_0_INIT_MUXSEL 0u
#define CapSense_CintA_0_INPUT_SYNC 2u
#define CapSense_CintA_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_CintA_0_NUM 1u
#define CapSense_CintA_0_PORT GPIO_PRT7
#define CapSense_CintA_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_CintA_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_CintA_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_CintA_INBUF_ENABLED 0u
#define CapSense_CintA_INIT_DRIVESTATE 1u
#define CapSense_CintA_INIT_MUXSEL 0u
#define CapSense_CintA_INPUT_SYNC 2u
#define CapSense_CintA_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_CintA_NUM 1u
#define CapSense_CintA_PORT GPIO_PRT7
#define CapSense_CintA_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_CintA_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* CapSense_CintB */
#define CapSense_CintB_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_CintB_0_INBUF_ENABLED 0u
#define CapSense_CintB_0_INIT_DRIVESTATE 1u
#define CapSense_CintB_0_INIT_MUXSEL 0u
#define CapSense_CintB_0_INPUT_SYNC 2u
#define CapSense_CintB_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_CintB_0_NUM 2u
#define CapSense_CintB_0_PORT GPIO_PRT7
#define CapSense_CintB_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_CintB_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CapSense_CintB_DRIVEMODE CY_GPIO_DM_ANALOG
#define CapSense_CintB_INBUF_ENABLED 0u
#define CapSense_CintB_INIT_DRIVESTATE 1u
#define CapSense_CintB_INIT_MUXSEL 0u
#define CapSense_CintB_INPUT_SYNC 2u
#define CapSense_CintB_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CapSense_CintB_NUM 2u
#define CapSense_CintB_PORT GPIO_PRT7
#define CapSense_CintB_SLEWRATE CY_GPIO_SLEW_FAST
#define CapSense_CintB_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

#endif /* INCLUDED_CYFITTER_GPIO_H */
