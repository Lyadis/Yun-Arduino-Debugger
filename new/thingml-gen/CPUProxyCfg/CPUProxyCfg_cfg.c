/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application CPUProxyCfg
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "proxyType.h"
#include "p_Browser_Websocket.h"
#include "p_Debug_Serial1.h"





/*****************************************************************************
 * Definitions for configuration : CPUProxyCfg
 *****************************************************************************/

//Declaration of instance variables
//Instance p
// Variables for the properties of the instance
struct proxyType_Instance p_var;



//New dispatcher for messages
void dispatch_ping(uint16_t sender, int16_t param_i) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_ping(&p_var, param_i);

}

}


//New dispatcher for messages
void dispatch_serialBegin(uint16_t sender, uint32_t param_Baudrate) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_serialBegin(&p_var, param_Baudrate);

}

}


//New dispatcher for messages
void dispatch_serialSendBuffer(uint16_t sender) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_serialSendBuffer(&p_var);

}

}


//New dispatcher for messages
void dispatch_serialClearSendBuffer(uint16_t sender) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_serialClearSendBuffer(&p_var);

}

}


//New dispatcher for messages
void dispatch_pinLevel(uint16_t sender, uint8_t param_Pin, uint8_t param_Level) {
if (sender == Serial1_instance.listener_id) {
proxyType_handle_Debug_pinLevel(&p_var, param_Pin, param_Level);

}

}


//New dispatcher for messages
void dispatch_setPinValue(uint16_t sender, uint8_t param_Pin, uint16_t param_Value) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_setPinValue(&p_var, param_Pin, param_Value);

}

}


//New dispatcher for messages
void dispatch_setRefreshRate(uint16_t sender, uint32_t param_r) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_setRefreshRate(&p_var, param_r);

}

}


//New dispatcher for messages
void dispatch_serialDisplaySendBuffer(uint16_t sender) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_serialDisplaySendBuffer(&p_var);

}

}


//New dispatcher for messages
void dispatch_serialAddToSendBuffer(uint16_t sender, unsigned char param_b) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_serialAddToSendBuffer(&p_var, param_b);

}

}


//New dispatcher for messages
void dispatch_serialSendBufferContent(uint16_t sender, uint8_t param_i, unsigned char param_b) {
if (sender == Serial1_instance.listener_id) {
proxyType_handle_Debug_serialSendBufferContent(&p_var, param_i, param_b);

}

}


//New dispatcher for messages
void dispatch_serialReceived(uint16_t sender, unsigned char param_b) {
if (sender == Serial1_instance.listener_id) {
proxyType_handle_Debug_serialReceived(&p_var, param_b);

}

}


//New dispatcher for messages
void dispatch_pinValue(uint16_t sender, uint8_t param_Pin, uint16_t param_Value) {
if (sender == Serial1_instance.listener_id) {
proxyType_handle_Debug_pinValue(&p_var, param_Pin, param_Value);

}

}


//New dispatcher for messages
void dispatch_pinMode(uint16_t sender, uint8_t param_Pin, uint8_t param_Mode) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_pinMode(&p_var, param_Pin, param_Mode);

}

}


//New dispatcher for messages
void dispatch_setPinLevel(uint16_t sender, uint8_t param_Pin, uint8_t param_Level) {
if (sender == Websocket_instance.listener_id) {
proxyType_handle_Browser_setPinLevel(&p_var, param_Pin, param_Level);

}

}


//New dispatcher for messages
void dispatch_pong(uint16_t sender, int16_t param_i) {
if (sender == Serial1_instance.listener_id) {
proxyType_handle_Debug_pong(&p_var, param_i);

}

}


int processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[6];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 0:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_ping_i_t {
int16_t p;
byte bytebuffer[2];
} u_ping_i;
u_ping_i.bytebuffer[1] = mbuf[2];
u_ping_i.bytebuffer[0] = mbuf[3];
dispatch_ping((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_ping_i.p /* i */ );
break;
case 20:
while (mbufi < 6) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_serialBegin_Baudrate_t {
uint32_t p;
byte bytebuffer[4];
} u_serialBegin_Baudrate;
u_serialBegin_Baudrate.bytebuffer[3] = mbuf[2];
u_serialBegin_Baudrate.bytebuffer[2] = mbuf[3];
u_serialBegin_Baudrate.bytebuffer[1] = mbuf[4];
u_serialBegin_Baudrate.bytebuffer[0] = mbuf[5];
dispatch_serialBegin((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_serialBegin_Baudrate.p /* Baudrate */ );
break;
case 23:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_serialSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 30:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_pinLevel_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_pinLevel_Pin;
u_pinLevel_Pin.bytebuffer[0] = mbuf[2];
union u_pinLevel_Level_t {
uint8_t p;
byte bytebuffer[1];
} u_pinLevel_Level;
u_pinLevel_Level.bytebuffer[0] = mbuf[3];
dispatch_pinLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pinLevel_Pin.p /* Pin */ ,
 u_pinLevel_Level.p /* Level */ );
break;
case 21:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_serialClearSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 12:
while (mbufi < 5) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_setPinValue_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_setPinValue_Pin;
u_setPinValue_Pin.bytebuffer[0] = mbuf[2];
union u_setPinValue_Value_t {
uint16_t p;
byte bytebuffer[2];
} u_setPinValue_Value;
u_setPinValue_Value.bytebuffer[1] = mbuf[3];
u_setPinValue_Value.bytebuffer[0] = mbuf[4];
dispatch_setPinValue((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_setPinValue_Pin.p /* Pin */ ,
 u_setPinValue_Value.p /* Value */ );
break;
case 2:
while (mbufi < 6) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_setRefreshRate_r_t {
uint32_t p;
byte bytebuffer[4];
} u_setRefreshRate_r;
u_setRefreshRate_r.bytebuffer[3] = mbuf[2];
u_setRefreshRate_r.bytebuffer[2] = mbuf[3];
u_setRefreshRate_r.bytebuffer[1] = mbuf[4];
u_setRefreshRate_r.bytebuffer[0] = mbuf[5];
dispatch_setRefreshRate((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_setRefreshRate_r.p /* r */ );
break;
case 24:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_serialDisplaySendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 41:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_serialSendBufferContent_i_t {
uint8_t p;
byte bytebuffer[1];
} u_serialSendBufferContent_i;
u_serialSendBufferContent_i.bytebuffer[0] = mbuf[2];
union u_serialSendBufferContent_b_t {
unsigned char p;
byte bytebuffer[1];
} u_serialSendBufferContent_b;
u_serialSendBufferContent_b.bytebuffer[0] = mbuf[3];
dispatch_serialSendBufferContent((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_serialSendBufferContent_i.p /* i */ ,
 u_serialSendBufferContent_b.p /* b */ );
break;
case 22:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_serialAddToSendBuffer_b_t {
unsigned char p;
byte bytebuffer[1];
} u_serialAddToSendBuffer_b;
u_serialAddToSendBuffer_b.bytebuffer[0] = mbuf[2];
dispatch_serialAddToSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_serialAddToSendBuffer_b.p /* b */ );
break;
case 40:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_serialReceived_b_t {
unsigned char p;
byte bytebuffer[1];
} u_serialReceived_b;
u_serialReceived_b.bytebuffer[0] = mbuf[2];
dispatch_serialReceived((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_serialReceived_b.p /* b */ );
break;
case 31:
while (mbufi < 5) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_pinValue_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_pinValue_Pin;
u_pinValue_Pin.bytebuffer[0] = mbuf[2];
union u_pinValue_Value_t {
uint16_t p;
byte bytebuffer[2];
} u_pinValue_Value;
u_pinValue_Value.bytebuffer[1] = mbuf[3];
u_pinValue_Value.bytebuffer[0] = mbuf[4];
dispatch_pinValue((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pinValue_Pin.p /* Pin */ ,
 u_pinValue_Value.p /* Value */ );
break;
case 10:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_pinMode_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_pinMode_Pin;
u_pinMode_Pin.bytebuffer[0] = mbuf[2];
union u_pinMode_Mode_t {
uint8_t p;
byte bytebuffer[1];
} u_pinMode_Mode;
u_pinMode_Mode.bytebuffer[0] = mbuf[3];
dispatch_pinMode((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pinMode_Pin.p /* Pin */ ,
 u_pinMode_Mode.p /* Mode */ );
break;
case 11:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_setPinLevel_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_setPinLevel_Pin;
u_setPinLevel_Pin.bytebuffer[0] = mbuf[2];
union u_setPinLevel_Level_t {
uint8_t p;
byte bytebuffer[1];
} u_setPinLevel_Level;
u_setPinLevel_Level.bytebuffer[0] = mbuf[3];
dispatch_setPinLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_setPinLevel_Pin.p /* Pin */ ,
 u_setPinLevel_Level.p /* Level */ );
break;
case 1:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
union u_pong_i_t {
int16_t p;
byte bytebuffer[2];
} u_pong_i;
u_pong_i.bytebuffer[1] = mbuf[2];
u_pong_i.bytebuffer[0] = mbuf[3];
dispatch_pong((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pong_i.p /* i */ );
break;
}
return 1;
}

// Forwarding of messages Serial1::proxyType::Debug::ping
void forward_Serial1_proxyType_send_Debug_ping(struct proxyType_Instance *_instance, int16_t i){
byte forward_buf[4];
forward_buf[0] = (0 >> 8) & 0xFF;
forward_buf[1] =  0 & 0xFF;


// parameter i
union u_i_t {
int16_t p;
byte bytebuffer[2];
} u_i;
u_i.p = i;
forward_buf[2] =  (u_i.bytebuffer[1] & 0xFF);
forward_buf[3] =  (u_i.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 4);
}

// Forwarding of messages Serial1::proxyType::Debug::setRefreshRate
void forward_Serial1_proxyType_send_Debug_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r){
byte forward_buf[6];
forward_buf[0] = (2 >> 8) & 0xFF;
forward_buf[1] =  2 & 0xFF;


// parameter r
union u_r_t {
uint32_t p;
byte bytebuffer[4];
} u_r;
u_r.p = r;
forward_buf[2] =  (u_r.bytebuffer[3] & 0xFF);
forward_buf[3] =  (u_r.bytebuffer[2] & 0xFF);
forward_buf[4] =  (u_r.bytebuffer[1] & 0xFF);
forward_buf[5] =  (u_r.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 6);
}

// Forwarding of messages Serial1::proxyType::Debug::pinMode
void forward_Serial1_proxyType_send_Debug_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode){
byte forward_buf[4];
forward_buf[0] = (10 >> 8) & 0xFF;
forward_buf[1] =  10 & 0xFF;


// parameter Pin
union u_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_Pin;
u_Pin.p = Pin;
forward_buf[2] =  (u_Pin.bytebuffer[0] & 0xFF);

// parameter Mode
union u_Mode_t {
uint8_t p;
byte bytebuffer[1];
} u_Mode;
u_Mode.p = Mode;
forward_buf[3] =  (u_Mode.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 4);
}

// Forwarding of messages Serial1::proxyType::Debug::setPinLevel
void forward_Serial1_proxyType_send_Debug_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
byte forward_buf[4];
forward_buf[0] = (11 >> 8) & 0xFF;
forward_buf[1] =  11 & 0xFF;


// parameter Pin
union u_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_Pin;
u_Pin.p = Pin;
forward_buf[2] =  (u_Pin.bytebuffer[0] & 0xFF);

// parameter Level
union u_Level_t {
uint8_t p;
byte bytebuffer[1];
} u_Level;
u_Level.p = Level;
forward_buf[3] =  (u_Level.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 4);
}

// Forwarding of messages Serial1::proxyType::Debug::setPinValue
void forward_Serial1_proxyType_send_Debug_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
byte forward_buf[5];
forward_buf[0] = (12 >> 8) & 0xFF;
forward_buf[1] =  12 & 0xFF;


// parameter Pin
union u_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_Pin;
u_Pin.p = Pin;
forward_buf[2] =  (u_Pin.bytebuffer[0] & 0xFF);

// parameter Value
union u_Value_t {
uint16_t p;
byte bytebuffer[2];
} u_Value;
u_Value.p = Value;
forward_buf[3] =  (u_Value.bytebuffer[1] & 0xFF);
forward_buf[4] =  (u_Value.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 5);
}

// Forwarding of messages Serial1::proxyType::Debug::serialBegin
void forward_Serial1_proxyType_send_Debug_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate){
byte forward_buf[6];
forward_buf[0] = (20 >> 8) & 0xFF;
forward_buf[1] =  20 & 0xFF;


// parameter Baudrate
union u_Baudrate_t {
uint32_t p;
byte bytebuffer[4];
} u_Baudrate;
u_Baudrate.p = Baudrate;
forward_buf[2] =  (u_Baudrate.bytebuffer[3] & 0xFF);
forward_buf[3] =  (u_Baudrate.bytebuffer[2] & 0xFF);
forward_buf[4] =  (u_Baudrate.bytebuffer[1] & 0xFF);
forward_buf[5] =  (u_Baudrate.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 6);
}

// Forwarding of messages Serial1::proxyType::Debug::serialClearSendBuffer
void forward_Serial1_proxyType_send_Debug_serialClearSendBuffer(struct proxyType_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (21 >> 8) & 0xFF;
forward_buf[1] =  21 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::proxyType::Debug::serialAddToSendBuffer
void forward_Serial1_proxyType_send_Debug_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b){
byte forward_buf[3];
forward_buf[0] = (22 >> 8) & 0xFF;
forward_buf[1] =  22 & 0xFF;


// parameter b
union u_b_t {
unsigned char p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
forward_buf[2] =  (u_b.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 3);
}

// Forwarding of messages Serial1::proxyType::Debug::serialSendBuffer
void forward_Serial1_proxyType_send_Debug_serialSendBuffer(struct proxyType_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (23 >> 8) & 0xFF;
forward_buf[1] =  23 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::proxyType::Debug::serialDisplaySendBuffer
void forward_Serial1_proxyType_send_Debug_serialDisplaySendBuffer(struct proxyType_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (24 >> 8) & 0xFF;
forward_buf[1] =  24 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::proxyType::Browser::pong
void forward_Websocket_proxyType_send_Browser_pong(struct proxyType_Instance *_instance, int16_t i){
byte forward_buf[13];
sprintf((unsigned char *) &forward_buf[0], "%03i", (unsigned char) ((1 >> 8) & 0xFF));
sprintf((unsigned char *) &forward_buf[3], "%03i", (unsigned char) (1 & 0xFF));

// parameter i
union u_i_t {
int16_t p;
byte bytebuffer[2];
} u_i;
u_i.p = i;
sprintf((unsigned char *) &forward_buf[6], "%03i", (unsigned char) (u_i.bytebuffer[1] & 0xFF));
sprintf((unsigned char *) &forward_buf[9], "%03i", (unsigned char) (u_i.bytebuffer[0] & 0xFF));

//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 13);
}

// Forwarding of messages Websocket::proxyType::Browser::pinLevel
void forward_Websocket_proxyType_send_Browser_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
byte forward_buf[13];
sprintf((unsigned char *) &forward_buf[0], "%03i", (unsigned char) ((30 >> 8) & 0xFF));
sprintf((unsigned char *) &forward_buf[3], "%03i", (unsigned char) (30 & 0xFF));

// parameter Pin
union u_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_Pin;
u_Pin.p = Pin;
sprintf((unsigned char *) &forward_buf[6], "%03i", (unsigned char) (u_Pin.bytebuffer[0] & 0xFF));

// parameter Level
union u_Level_t {
uint8_t p;
byte bytebuffer[1];
} u_Level;
u_Level.p = Level;
sprintf((unsigned char *) &forward_buf[9], "%03i", (unsigned char) (u_Level.bytebuffer[0] & 0xFF));

//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 13);
}

// Forwarding of messages Websocket::proxyType::Browser::pinValue
void forward_Websocket_proxyType_send_Browser_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
byte forward_buf[16];
sprintf((unsigned char *) &forward_buf[0], "%03i", (unsigned char) ((31 >> 8) & 0xFF));
sprintf((unsigned char *) &forward_buf[3], "%03i", (unsigned char) (31 & 0xFF));

// parameter Pin
union u_Pin_t {
uint8_t p;
byte bytebuffer[1];
} u_Pin;
u_Pin.p = Pin;
sprintf((unsigned char *) &forward_buf[6], "%03i", (unsigned char) (u_Pin.bytebuffer[0] & 0xFF));

// parameter Value
union u_Value_t {
uint16_t p;
byte bytebuffer[2];
} u_Value;
u_Value.p = Value;
sprintf((unsigned char *) &forward_buf[9], "%03i", (unsigned char) (u_Value.bytebuffer[1] & 0xFF));
sprintf((unsigned char *) &forward_buf[12], "%03i", (unsigned char) (u_Value.bytebuffer[0] & 0xFF));

//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 16);
}

// Forwarding of messages Websocket::proxyType::Browser::serialReceived
void forward_Websocket_proxyType_send_Browser_serialReceived(struct proxyType_Instance *_instance, unsigned char b){
byte forward_buf[10];
sprintf((unsigned char *) &forward_buf[0], "%03i", (unsigned char) ((40 >> 8) & 0xFF));
sprintf((unsigned char *) &forward_buf[3], "%03i", (unsigned char) (40 & 0xFF));

// parameter b
union u_b_t {
unsigned char p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
sprintf((unsigned char *) &forward_buf[6], "%03i", (unsigned char) (u_b.bytebuffer[0] & 0xFF));

//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 10);
}

// Forwarding of messages Websocket::proxyType::Browser::serialSendBufferContent
void forward_Websocket_proxyType_send_Browser_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b){
byte forward_buf[13];
sprintf((unsigned char *) &forward_buf[0], "%03i", (unsigned char) ((41 >> 8) & 0xFF));
sprintf((unsigned char *) &forward_buf[3], "%03i", (unsigned char) (41 & 0xFF));

// parameter i
union u_i_t {
uint8_t p;
byte bytebuffer[1];
} u_i;
u_i.p = i;
sprintf((unsigned char *) &forward_buf[6], "%03i", (unsigned char) (u_i.bytebuffer[0] & 0xFF));

// parameter b
union u_b_t {
unsigned char p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
sprintf((unsigned char *) &forward_buf[9], "%03i", (unsigned char) (u_b.bytebuffer[0] & 0xFF));

//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 13);
}

void forward_proxyType_send_Debug_ping(struct proxyType_Instance *_instance, int16_t i){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_ping(_instance, i);
}
}
void forward_proxyType_send_Debug_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_serialBegin(_instance, Baudrate);
}
}
void forward_proxyType_send_Debug_serialSendBuffer(struct proxyType_Instance *_instance){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_serialSendBuffer(_instance);
}
}
void forward_proxyType_send_Browser_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
if(_instance->id_Browser == p_var.id_Browser) {
forward_Websocket_proxyType_send_Browser_pinLevel(_instance, Pin, Level);
}
}
void forward_proxyType_send_Debug_serialClearSendBuffer(struct proxyType_Instance *_instance){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_serialClearSendBuffer(_instance);
}
}
void forward_proxyType_send_Debug_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_setPinValue(_instance, Pin, Value);
}
}
void forward_proxyType_send_Debug_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_setRefreshRate(_instance, r);
}
}
void forward_proxyType_send_Debug_serialDisplaySendBuffer(struct proxyType_Instance *_instance){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_serialDisplaySendBuffer(_instance);
}
}
void forward_proxyType_send_Browser_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b){
if(_instance->id_Browser == p_var.id_Browser) {
forward_Websocket_proxyType_send_Browser_serialSendBufferContent(_instance, i, b);
}
}
void forward_proxyType_send_Debug_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_serialAddToSendBuffer(_instance, b);
}
}
void forward_proxyType_send_Browser_serialReceived(struct proxyType_Instance *_instance, unsigned char b){
if(_instance->id_Browser == p_var.id_Browser) {
forward_Websocket_proxyType_send_Browser_serialReceived(_instance, b);
}
}
void forward_proxyType_send_Browser_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
if(_instance->id_Browser == p_var.id_Browser) {
forward_Websocket_proxyType_send_Browser_pinValue(_instance, Pin, Value);
}
}
void forward_proxyType_send_Debug_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_pinMode(_instance, Pin, Mode);
}
}
void forward_proxyType_send_Debug_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
if(_instance->id_Debug == p_var.id_Debug) {
forward_Serial1_proxyType_send_Debug_setPinLevel(_instance, Pin, Level);
}
}
void forward_proxyType_send_Browser_pong(struct proxyType_Instance *_instance, int16_t i){
if(_instance->id_Browser == p_var.id_Browser) {
forward_Websocket_proxyType_send_Browser_pong(_instance, i);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 0:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 20:
if(msgSize == 6) {
msgSizeOK = 1;}
break;
case 23:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 21:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 30:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 12:
if(msgSize == 5) {
msgSizeOK = 1;}
break;
case 2:
if(msgSize == 6) {
msgSizeOK = 1;}
break;
case 24:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 22:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
case 41:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 40:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
case 31:
if(msgSize == 5) {
msgSizeOK = 1;}
break;
case 10:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 11:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 1:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
fifo_lock();
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
fifo_unlock_and_notify();
}
}
}

void initialize_configuration_CPUProxyCfg() {
// Initialize connectors
register_external_proxyType_send_Browser_pong_listener(&forward_proxyType_send_Browser_pong);
register_external_proxyType_send_Browser_pinLevel_listener(&forward_proxyType_send_Browser_pinLevel);
register_external_proxyType_send_Browser_pinValue_listener(&forward_proxyType_send_Browser_pinValue);
register_external_proxyType_send_Browser_serialReceived_listener(&forward_proxyType_send_Browser_serialReceived);
register_external_proxyType_send_Browser_serialSendBufferContent_listener(&forward_proxyType_send_Browser_serialSendBufferContent);
register_external_proxyType_send_Debug_ping_listener(&forward_proxyType_send_Debug_ping);
register_external_proxyType_send_Debug_setRefreshRate_listener(&forward_proxyType_send_Debug_setRefreshRate);
register_external_proxyType_send_Debug_pinMode_listener(&forward_proxyType_send_Debug_pinMode);
register_external_proxyType_send_Debug_setPinLevel_listener(&forward_proxyType_send_Debug_setPinLevel);
register_external_proxyType_send_Debug_setPinValue_listener(&forward_proxyType_send_Debug_setPinValue);
register_external_proxyType_send_Debug_serialBegin_listener(&forward_proxyType_send_Debug_serialBegin);
register_external_proxyType_send_Debug_serialClearSendBuffer_listener(&forward_proxyType_send_Debug_serialClearSendBuffer);
register_external_proxyType_send_Debug_serialAddToSendBuffer_listener(&forward_proxyType_send_Debug_serialAddToSendBuffer);
register_external_proxyType_send_Debug_serialSendBuffer_listener(&forward_proxyType_send_Debug_serialSendBuffer);
register_external_proxyType_send_Debug_serialDisplaySendBuffer_listener(&forward_proxyType_send_Debug_serialDisplaySendBuffer);

// Init the ID, state variables and properties for external connector Websocket
// Init the ID, state variables and properties for external connector Serial1

// Network Initilization 


Websocket_instance.listener_id = add_instance(&Websocket_instance);

//Websocket:
Websocket_setup();
pthread_t thread_p_Browser_Websocket;
pthread_create( &thread_p_Browser_Websocket, NULL, Websocket_start_receiver_process, NULL);


Serial1_instance.listener_id = add_instance(&Serial1_instance);

//Serial1:
Serial1_setup();
pthread_t thread_p_Debug_Serial1;
pthread_create( &thread_p_Debug_Serial1, NULL, Serial1_start_receiver_process, NULL);


// End Network Initilization 

// Init the ID, state variables and properties for instance p
p_var.id_Browser = add_instance( (void*) &p_var);
p_var.id_Debug = add_instance( (void*) &p_var);
p_var.proxyType_proxChart_State = PROXYTYPE_PROXCHART_ACTIVE_STATE;

proxyType_proxChart_OnEntry(PROXYTYPE_PROXCHART_STATE, &p_var);
}




int main(int argc, char *argv[]) {
  init_runtime();
  
  initialize_configuration_CPUProxyCfg();

  while (1) {
    
// Network Listener
int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

    processMessageQueue();
  }
}