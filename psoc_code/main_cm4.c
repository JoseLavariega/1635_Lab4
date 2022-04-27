/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "bmi160.h" 

// Section 1, read and write with I2C

static struct bmi160_dev sensor;  // interface to your specific bmi160 sensor
static double MAX_SPEED = 500;
static double MIN_SPEED = 100; 
static double slider_factor = 4; 

static int8_t bmi_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    Cy_SCB_I2C_MasterSendStart(I2C_HW, dev_addr, CY_SCB_I2C_WRITE_XFER, 0, &I2C_context);
    Cy_SCB_I2C_MasterWriteByte(I2C_HW, reg_addr, 0, &I2C_context);
    for (int i =0; i < len; i++) 
    {
        Cy_SCB_I2C_MasterWriteByte(I2C_HW, data[i], 0, &I2C_context);    
    }
    Cy_SCB_I2C_MasterSendStop(I2C_HW, 0, &I2C_context);
    
    return 0;
}

static int8_t bmi_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    Cy_SCB_I2C_MasterSendStart(I2C_HW, dev_addr, CY_SCB_I2C_WRITE_XFER, 0, &I2C_context);
    Cy_SCB_I2C_MasterWriteByte(I2C_HW, reg_addr, 0, &I2C_context);
    Cy_SCB_I2C_MasterSendReStart(I2C_HW, dev_addr, CY_SCB_I2C_READ_XFER, 0, &I2C_context);
    for (int i =0; i < len-1; i++) 
    {
        Cy_SCB_I2C_MasterReadByte(I2C_HW, CY_SCB_I2C_ACK, &data[i], 0, &I2C_context);    
    }
    
    Cy_SCB_I2C_MasterReadByte(I2C_HW, CY_SCB_I2C_NAK, &data[len-1], 0, &I2C_context);    

    Cy_SCB_I2C_MasterSendStop(I2C_HW, 0, &I2C_context);
    
    return 0;
}

// Section 2, initialize bmi160

static void bmiInit(void) 
{
    vTaskDelay(100);
    sensor.id = BMI160_I2C_ADDR;
    //sensor.interface = BMI160_I2C_INTF;
    sensor.read = (bmi160_com_fptr_t) bmi_read;
    sensor.write = (bmi160_com_fptr_t) bmi_write;
    sensor.delay_ms = (bmi160_delay_fptr_t) vTaskDelay;


    int8_t rslt = BMI160_OK;
    //rslt = bmi160_init(&sensor);

    
    // Select the Output data rate, range of accelerometer sensor
    
    sensor.accel_cfg.odr = BMI160_ACCEL_ODR_1600HZ;
    sensor.accel_cfg.range = BMI160_ACCEL_RANGE_2G;    // sets to 2g
    sensor.accel_cfg.bw = BMI160_ACCEL_BW_OSR4_AVG1;
    
    // Select the power mode of accelerometer sensor 
    sensor.accel_cfg.power = BMI160_ACCEL_NORMAL_MODE;

    // Select the Output data rate, range of Gyroscope sensor 
    sensor.gyro_cfg.odr = BMI160_GYRO_ODR_800HZ;
    sensor.gyro_cfg.range = BMI160_GYRO_RANGE_125_DPS;
    sensor.gyro_cfg.bw = BMI160_GYRO_BW_OSR4_MODE;

    // Select the power mode of Gyroscope sensor 
    sensor.gyro_cfg.power = BMI160_GYRO_NORMAL_MODE; 

    //Set the sensor configuration 
    rslt = bmi160_set_sens_conf(&sensor);
    
    sensor.delay_ms(50);
}

void send_accel_data(void *arg){
    
    (void) arg;
    
    // Start accelerometer and Capsense
    bmiInit(); 
    CapSense_Start(); 
    CapSense_ScanAllWidgets(); 
    
    struct bmi160_sensor_data accel_data; 
    double speed = MIN_SPEED; 
    
    
    while(1){
        
        // Check for Capsense 
        if(CapSense_NOT_BUSY == CapSense_IsBusy()){
            CapSense_ProcessAllWidgets();
            
            if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID)){
                // Decrement speed by 10
                speed -= 10; 
            } else if (CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID)){
                // Increment speed by 10
                speed += 10;
            } else if (CapSense_IsWidgetActive(CapSense_LINEARSLIDER0_WDGT_ID)){
                // Get slider part pressed
                speed = MIN_SPEED + slider_factor * CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
               
            }
            CapSense_UpdateAllBaselines(); 
            CapSense_ScanAllWidgets();
        }
        // Read accelerometer data 
        bmi160_get_sensor_data(BMI160_ACCEL_ONLY, &accel_data,
                                NULL, &sensor); 
        
        printf("%4f,%4f,%4f,%4f end\r\n",accel_data.x/16384.0,accel_data.y/16384.0,accel_data.z/16384.0,speed); 
      
        vTaskDelay(100);
    }
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    

    
    UART_1_Start(); 
    I2C_Start(); 
    
    xTaskCreate(
        
        send_accel_data,
        "Send Accelerometer Data",
        4000,
        0,
        1,
        0); 
    
    vTaskStartScheduler();   
}


/* [] END OF FILE */
