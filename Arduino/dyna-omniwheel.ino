#include <DynamixelShield.h>
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#endif

const uint8_t DXL_ID_1 = 1;
const uint8_t DXL_ID_2 = 2;
const uint8_t DXL_ID_3 = 3;
const uint8_t DXL_ID_4 = 4;

const float DXL_PROTOCOL_VERSION = 2.0;
DynamixelShield dxl;
using namespace ControlTableItem;

byte PWM_THR = 3;
byte PWM_AIL = 5;
byte PWM_ELE = 6;

int thr_value;
int ail_value;
int ele_value;

double thr_norm;
double ail_norm;
double ele_norm;

int wheel_1;
int wheel_2;
int wheel_3;
int wheel_4;

void setup() {
  Serial.begin(57600); 
 
  dxl.begin(1000000); // Set Port baudrate
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION); // Set Port Protocol Version
  dxl.torqueOff(DXL_ID_1);
  dxl.setOperatingMode(DXL_ID_1, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_1);
  dxl.torqueOff(DXL_ID_2);
  dxl.setOperatingMode(DXL_ID_2, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_2); 
  dxl.torqueOff(DXL_ID_3);
  dxl.setOperatingMode(DXL_ID_3, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_3); 
  dxl.torqueOff(DXL_ID_4);
  dxl.setOperatingMode(DXL_ID_4, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_4); 
}
 
void loop() {
  ele_value = pulseIn(PWM_ELE, HIGH);
  ail_value = pulseIn(PWM_AIL, HIGH);
  thr_value = pulseIn(PWM_THR, HIGH);
  
  ail_norm = map(ail_value, 1000, 2000, -100, 100);
  ele_norm = map(ele_value, 1000, 2000, -100, 100);
  thr_norm = map(thr_value, 1000, 2000, -100, 100);

  if (abs(ail_norm) < 10){
    ail_norm = 0;
  }
  if (abs(ele_norm) < 10){
    ele_norm = 0;
  }
  if (abs(thr_norm) < 10){
    thr_norm = 0;
  }

  wheel_1 =  2.0*(ail_norm + ele_norm - thr_norm);
  wheel_2 = -2.0*(ail_norm + ele_norm + thr_norm);
  wheel_3 = -2.0*(ail_norm - ele_norm + thr_norm);
  wheel_4 =  2.0*(ail_norm - ele_norm - thr_norm);

  dxl.setGoalVelocity(DXL_ID_1, wheel_1);
  dxl.setGoalVelocity(DXL_ID_2, wheel_2);
  dxl.setGoalVelocity(DXL_ID_3, wheel_3);
  dxl.setGoalVelocity(DXL_ID_4, wheel_4);
}
