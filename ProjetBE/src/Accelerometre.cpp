#include "..\include\Accelerometre.h"
#include <Arduino.h>
#include <Wire.h> // Wire library - used for I2C communication

#define ADXL345 0x53 // The ADXL345 sensor I2C address

void Accelerometre::initAccelerometre()
{
    Wire.begin(); // Initiate the Wire library
    // Set ADXL345 in measuring mode
    Wire.beginTransmission(ADXL345); // Start communicating with the device
    Wire.write(0x2D);                // Access/ talk to POWER_CTL Register - 0x2D
    // Enable measurement
    Wire.write(8); // Bit D3 High for measuring enable (8dec -> 0000 1000 binary)
    Wire.endTransmission();
    delay(10);

    // Off-set Calibration
    // X-axis
    Wire.beginTransmission(ADXL345);
    Wire.write(0x1E);
    Wire.write(1);
    Wire.endTransmission();
    delay(10);

    // Y-axis
    Wire.beginTransmission(ADXL345);
    Wire.write(0x1F);
    Wire.write(-2);
    Wire.endTransmission();
    delay(10);

    // Z-axis
    Wire.beginTransmission(ADXL345);
    Wire.write(0x20);
    Wire.write(-9);
    Wire.endTransmission();
    delay(10);
}

data Accelerometre::acquisition()
{
    float roll, pitch;
    float rollF = 0 ;
    float pitchF = 0;
    data d;

    for (int k = 0; k < 100; k++)
    {
        yield();
        // === Read acceleromter data === //
        Wire.beginTransmission(ADXL345);
        Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
        Wire.endTransmission(false);
        Wire.requestFrom(ADXL345, 6, true);       // Read 6 registers total, each axis value is stored in 2 registers
        this->X_out = (Wire.read() | Wire.read() << 8); // X-axis value
        this->X_out = this->X_out / 256;                      // For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
        this->Y_out = (Wire.read() | Wire.read() << 8); // Y-axis value
        this->Y_out = this->Y_out / 256;
        this->Z_out = (Wire.read() | Wire.read() << 8); // Z-axis value
        this->Z_out = this->Z_out / 256;

        // Calculate Roll and Pitch (rotation around X-axis, rotation around Y-axis)
        roll = atan(this->Y_out / sqrt(pow(this->X_out, 2) + pow(this->Z_out, 2))) * 180 / PI;
        pitch = atan(-1 * this->X_out / sqrt(pow(this->Y_out, 2) + pow(this->Z_out, 2))) * 180 / PI;

        // Low-pass filter
        rollF = 0.94 * rollF + 0.06 * roll;
        pitchF = 0.94 * pitchF + 0.06 * pitch;
    }

    d.tab_float[0] = rollF;
    d.tab_float[1] = pitchF;
    return d;
}