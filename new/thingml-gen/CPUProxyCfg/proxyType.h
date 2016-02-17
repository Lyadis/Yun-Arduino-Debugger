/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing proxyType
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef proxyType_H_
#define proxyType_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : proxyType
 *****************************************************************************/

// Definition of the instance stuct:
struct proxyType_Instance {
// Variables for the ID of the ports of the instance
uint16_t id_Browser;
uint16_t id_Debug;
// Variables for the current instance state
int proxyType_proxChart_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages:
void proxyType_proxChart_OnEntry(int state, struct proxyType_Instance *_instance);
void proxyType_handle_Debug_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b);
void proxyType_handle_Debug_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level);
void proxyType_handle_Debug_serialReceived(struct proxyType_Instance *_instance, unsigned char b);
void proxyType_handle_Debug_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value);
void proxyType_handle_Debug_pong(struct proxyType_Instance *_instance, int16_t i);
void proxyType_handle_Browser_ping(struct proxyType_Instance *_instance, int16_t i);
void proxyType_handle_Browser_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate);
void proxyType_handle_Browser_serialSendBuffer(struct proxyType_Instance *_instance);
void proxyType_handle_Browser_serialDisplaySendBuffer(struct proxyType_Instance *_instance);
void proxyType_handle_Browser_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b);
void proxyType_handle_Browser_serialClearSendBuffer(struct proxyType_Instance *_instance);
void proxyType_handle_Browser_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value);
void proxyType_handle_Browser_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode);
void proxyType_handle_Browser_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level);
void proxyType_handle_Browser_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r);
// Declaration of callbacks for incoming messages:
void register_proxyType_send_Browser_pong_listener(void (*_listener)(struct proxyType_Instance *, int16_t));
void register_external_proxyType_send_Browser_pong_listener(void (*_listener)(struct proxyType_Instance *, int16_t));
void register_proxyType_send_Browser_pinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_external_proxyType_send_Browser_pinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_proxyType_send_Browser_pinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t));
void register_external_proxyType_send_Browser_pinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t));
void register_proxyType_send_Browser_serialReceived_listener(void (*_listener)(struct proxyType_Instance *, unsigned char));
void register_external_proxyType_send_Browser_serialReceived_listener(void (*_listener)(struct proxyType_Instance *, unsigned char));
void register_proxyType_send_Browser_serialSendBufferContent_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, unsigned char));
void register_external_proxyType_send_Browser_serialSendBufferContent_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, unsigned char));
void register_proxyType_send_Debug_ping_listener(void (*_listener)(struct proxyType_Instance *, int16_t));
void register_external_proxyType_send_Debug_ping_listener(void (*_listener)(struct proxyType_Instance *, int16_t));
void register_proxyType_send_Debug_setRefreshRate_listener(void (*_listener)(struct proxyType_Instance *, uint32_t));
void register_external_proxyType_send_Debug_setRefreshRate_listener(void (*_listener)(struct proxyType_Instance *, uint32_t));
void register_proxyType_send_Debug_pinMode_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_external_proxyType_send_Debug_pinMode_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_proxyType_send_Debug_setPinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_external_proxyType_send_Debug_setPinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t));
void register_proxyType_send_Debug_setPinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t));
void register_external_proxyType_send_Debug_setPinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t));
void register_proxyType_send_Debug_serialBegin_listener(void (*_listener)(struct proxyType_Instance *, uint32_t));
void register_external_proxyType_send_Debug_serialBegin_listener(void (*_listener)(struct proxyType_Instance *, uint32_t));
void register_proxyType_send_Debug_serialClearSendBuffer_listener(void (*_listener)(struct proxyType_Instance *));
void register_external_proxyType_send_Debug_serialClearSendBuffer_listener(void (*_listener)(struct proxyType_Instance *));
void register_proxyType_send_Debug_serialAddToSendBuffer_listener(void (*_listener)(struct proxyType_Instance *, unsigned char));
void register_external_proxyType_send_Debug_serialAddToSendBuffer_listener(void (*_listener)(struct proxyType_Instance *, unsigned char));
void register_proxyType_send_Debug_serialSendBuffer_listener(void (*_listener)(struct proxyType_Instance *));
void register_external_proxyType_send_Debug_serialSendBuffer_listener(void (*_listener)(struct proxyType_Instance *));
void register_proxyType_send_Debug_serialDisplaySendBuffer_listener(void (*_listener)(struct proxyType_Instance *));
void register_external_proxyType_send_Debug_serialDisplaySendBuffer_listener(void (*_listener)(struct proxyType_Instance *));

// Definition of the states:
#define PROXYTYPE_PROXCHART_STATE 0
#define PROXYTYPE_PROXCHART_ACTIVE_STATE 1



#ifdef __cplusplus
}
#endif

#endif //proxyType_H_
