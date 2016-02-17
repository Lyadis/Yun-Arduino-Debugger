/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing proxyType
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "proxyType.h"

/*****************************************************************************
 * Implementation for type : proxyType
 *****************************************************************************/

// Declaration of prototypes:
void proxyType_proxChart_OnExit(int state, struct proxyType_Instance *_instance);
void proxyType_send_Browser_pong(struct proxyType_Instance *_instance, int16_t i);
void proxyType_send_Browser_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level);
void proxyType_send_Browser_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value);
void proxyType_send_Browser_serialReceived(struct proxyType_Instance *_instance, unsigned char b);
void proxyType_send_Browser_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b);
void proxyType_send_Debug_ping(struct proxyType_Instance *_instance, int16_t i);
void proxyType_send_Debug_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r);
void proxyType_send_Debug_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode);
void proxyType_send_Debug_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level);
void proxyType_send_Debug_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value);
void proxyType_send_Debug_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate);
void proxyType_send_Debug_serialClearSendBuffer(struct proxyType_Instance *_instance);
void proxyType_send_Debug_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b);
void proxyType_send_Debug_serialSendBuffer(struct proxyType_Instance *_instance);
void proxyType_send_Debug_serialDisplaySendBuffer(struct proxyType_Instance *_instance);
// Declaration of functions:

// On Entry Actions:
void proxyType_proxChart_OnEntry(int state, struct proxyType_Instance *_instance) {
switch(state) {
case PROXYTYPE_PROXCHART_STATE:
_instance->proxyType_proxChart_State = PROXYTYPE_PROXCHART_ACTIVE_STATE;
proxyType_proxChart_OnEntry(_instance->proxyType_proxChart_State, _instance);
break;
case PROXYTYPE_PROXCHART_ACTIVE_STATE:
break;
default: break;
}
}

// On Exit Actions:
void proxyType_proxChart_OnExit(int state, struct proxyType_Instance *_instance) {
switch(state) {
case PROXYTYPE_PROXCHART_STATE:
proxyType_proxChart_OnExit(_instance->proxyType_proxChart_State, _instance);
break;
case PROXYTYPE_PROXCHART_ACTIVE_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void proxyType_handle_Debug_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Browser_serialSendBufferContent(_instance, i, b);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Debug_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Browser_pinLevel(_instance, Pin, Level);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Debug_serialReceived(struct proxyType_Instance *_instance, unsigned char b) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Browser_serialReceived(_instance, b);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Debug_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Browser_pinValue(_instance, Pin, Value);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Debug_pong(struct proxyType_Instance *_instance, int16_t i) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Browser_pong(_instance, i);
fprintf(stdout, "pong ");
fprintf(stdout, "%i",i);
fprintf(stdout, "\n");
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_ping(struct proxyType_Instance *_instance, int16_t i) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_ping(_instance, i);
fprintf(stdout, "ping ");
fprintf(stdout, "%i",i);
fprintf(stdout, "\n");
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_serialBegin(_instance, Baudrate);
fprintf(stdout, "serialBegin ");
fprintf(stdout, "%i",Baudrate);
fprintf(stdout, "\n");
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_serialSendBuffer(struct proxyType_Instance *_instance) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_serialSendBuffer(_instance);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_serialDisplaySendBuffer(struct proxyType_Instance *_instance) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_serialDisplaySendBuffer(_instance);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_serialAddToSendBuffer(_instance, b);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_serialClearSendBuffer(struct proxyType_Instance *_instance) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_serialClearSendBuffer(_instance);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_setPinValue(_instance, Pin, Value);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_pinMode(_instance, Pin, Mode);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_setPinLevel(_instance, Pin, Level);
proxyType_proxChart_State_event_consumed = 1;
}
}
}
void proxyType_handle_Browser_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r) {
uint8_t proxyType_proxChart_State_event_consumed = 0;
if (_instance->proxyType_proxChart_State == PROXYTYPE_PROXCHART_ACTIVE_STATE) {
if (proxyType_proxChart_State_event_consumed == 0 && 1) {
proxyType_send_Debug_setRefreshRate(_instance, r);
proxyType_proxChart_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*external_proxyType_send_Browser_pong_listener)(struct proxyType_Instance *, int16_t)= 0x0;
void (*proxyType_send_Browser_pong_listener)(struct proxyType_Instance *, int16_t)= 0x0;
void register_external_proxyType_send_Browser_pong_listener(void (*_listener)(struct proxyType_Instance *, int16_t)){
external_proxyType_send_Browser_pong_listener = _listener;
}
void register_proxyType_send_Browser_pong_listener(void (*_listener)(struct proxyType_Instance *, int16_t)){
proxyType_send_Browser_pong_listener = _listener;
}
void proxyType_send_Browser_pong(struct proxyType_Instance *_instance, int16_t i){
if (proxyType_send_Browser_pong_listener != 0x0) proxyType_send_Browser_pong_listener(_instance, i);
if (external_proxyType_send_Browser_pong_listener != 0x0) external_proxyType_send_Browser_pong_listener(_instance, i);
;
}
void (*external_proxyType_send_Browser_pinLevel_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void (*proxyType_send_Browser_pinLevel_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_proxyType_send_Browser_pinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
external_proxyType_send_Browser_pinLevel_listener = _listener;
}
void register_proxyType_send_Browser_pinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
proxyType_send_Browser_pinLevel_listener = _listener;
}
void proxyType_send_Browser_pinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
if (proxyType_send_Browser_pinLevel_listener != 0x0) proxyType_send_Browser_pinLevel_listener(_instance, Pin, Level);
if (external_proxyType_send_Browser_pinLevel_listener != 0x0) external_proxyType_send_Browser_pinLevel_listener(_instance, Pin, Level);
;
}
void (*external_proxyType_send_Browser_pinValue_listener)(struct proxyType_Instance *, uint8_t, uint16_t)= 0x0;
void (*proxyType_send_Browser_pinValue_listener)(struct proxyType_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_proxyType_send_Browser_pinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t)){
external_proxyType_send_Browser_pinValue_listener = _listener;
}
void register_proxyType_send_Browser_pinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t)){
proxyType_send_Browser_pinValue_listener = _listener;
}
void proxyType_send_Browser_pinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
if (proxyType_send_Browser_pinValue_listener != 0x0) proxyType_send_Browser_pinValue_listener(_instance, Pin, Value);
if (external_proxyType_send_Browser_pinValue_listener != 0x0) external_proxyType_send_Browser_pinValue_listener(_instance, Pin, Value);
;
}
void (*external_proxyType_send_Browser_serialReceived_listener)(struct proxyType_Instance *, unsigned char)= 0x0;
void (*proxyType_send_Browser_serialReceived_listener)(struct proxyType_Instance *, unsigned char)= 0x0;
void register_external_proxyType_send_Browser_serialReceived_listener(void (*_listener)(struct proxyType_Instance *, unsigned char)){
external_proxyType_send_Browser_serialReceived_listener = _listener;
}
void register_proxyType_send_Browser_serialReceived_listener(void (*_listener)(struct proxyType_Instance *, unsigned char)){
proxyType_send_Browser_serialReceived_listener = _listener;
}
void proxyType_send_Browser_serialReceived(struct proxyType_Instance *_instance, unsigned char b){
if (proxyType_send_Browser_serialReceived_listener != 0x0) proxyType_send_Browser_serialReceived_listener(_instance, b);
if (external_proxyType_send_Browser_serialReceived_listener != 0x0) external_proxyType_send_Browser_serialReceived_listener(_instance, b);
;
}
void (*external_proxyType_send_Browser_serialSendBufferContent_listener)(struct proxyType_Instance *, uint8_t, unsigned char)= 0x0;
void (*proxyType_send_Browser_serialSendBufferContent_listener)(struct proxyType_Instance *, uint8_t, unsigned char)= 0x0;
void register_external_proxyType_send_Browser_serialSendBufferContent_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, unsigned char)){
external_proxyType_send_Browser_serialSendBufferContent_listener = _listener;
}
void register_proxyType_send_Browser_serialSendBufferContent_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, unsigned char)){
proxyType_send_Browser_serialSendBufferContent_listener = _listener;
}
void proxyType_send_Browser_serialSendBufferContent(struct proxyType_Instance *_instance, uint8_t i, unsigned char b){
if (proxyType_send_Browser_serialSendBufferContent_listener != 0x0) proxyType_send_Browser_serialSendBufferContent_listener(_instance, i, b);
if (external_proxyType_send_Browser_serialSendBufferContent_listener != 0x0) external_proxyType_send_Browser_serialSendBufferContent_listener(_instance, i, b);
;
}
void (*external_proxyType_send_Debug_ping_listener)(struct proxyType_Instance *, int16_t)= 0x0;
void (*proxyType_send_Debug_ping_listener)(struct proxyType_Instance *, int16_t)= 0x0;
void register_external_proxyType_send_Debug_ping_listener(void (*_listener)(struct proxyType_Instance *, int16_t)){
external_proxyType_send_Debug_ping_listener = _listener;
}
void register_proxyType_send_Debug_ping_listener(void (*_listener)(struct proxyType_Instance *, int16_t)){
proxyType_send_Debug_ping_listener = _listener;
}
void proxyType_send_Debug_ping(struct proxyType_Instance *_instance, int16_t i){
if (proxyType_send_Debug_ping_listener != 0x0) proxyType_send_Debug_ping_listener(_instance, i);
if (external_proxyType_send_Debug_ping_listener != 0x0) external_proxyType_send_Debug_ping_listener(_instance, i);
;
}
void (*external_proxyType_send_Debug_setRefreshRate_listener)(struct proxyType_Instance *, uint32_t)= 0x0;
void (*proxyType_send_Debug_setRefreshRate_listener)(struct proxyType_Instance *, uint32_t)= 0x0;
void register_external_proxyType_send_Debug_setRefreshRate_listener(void (*_listener)(struct proxyType_Instance *, uint32_t)){
external_proxyType_send_Debug_setRefreshRate_listener = _listener;
}
void register_proxyType_send_Debug_setRefreshRate_listener(void (*_listener)(struct proxyType_Instance *, uint32_t)){
proxyType_send_Debug_setRefreshRate_listener = _listener;
}
void proxyType_send_Debug_setRefreshRate(struct proxyType_Instance *_instance, uint32_t r){
if (proxyType_send_Debug_setRefreshRate_listener != 0x0) proxyType_send_Debug_setRefreshRate_listener(_instance, r);
if (external_proxyType_send_Debug_setRefreshRate_listener != 0x0) external_proxyType_send_Debug_setRefreshRate_listener(_instance, r);
;
}
void (*external_proxyType_send_Debug_pinMode_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void (*proxyType_send_Debug_pinMode_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_proxyType_send_Debug_pinMode_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
external_proxyType_send_Debug_pinMode_listener = _listener;
}
void register_proxyType_send_Debug_pinMode_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
proxyType_send_Debug_pinMode_listener = _listener;
}
void proxyType_send_Debug_pinMode(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Mode){
if (proxyType_send_Debug_pinMode_listener != 0x0) proxyType_send_Debug_pinMode_listener(_instance, Pin, Mode);
if (external_proxyType_send_Debug_pinMode_listener != 0x0) external_proxyType_send_Debug_pinMode_listener(_instance, Pin, Mode);
;
}
void (*external_proxyType_send_Debug_setPinLevel_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void (*proxyType_send_Debug_setPinLevel_listener)(struct proxyType_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_proxyType_send_Debug_setPinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
external_proxyType_send_Debug_setPinLevel_listener = _listener;
}
void register_proxyType_send_Debug_setPinLevel_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint8_t)){
proxyType_send_Debug_setPinLevel_listener = _listener;
}
void proxyType_send_Debug_setPinLevel(struct proxyType_Instance *_instance, uint8_t Pin, uint8_t Level){
if (proxyType_send_Debug_setPinLevel_listener != 0x0) proxyType_send_Debug_setPinLevel_listener(_instance, Pin, Level);
if (external_proxyType_send_Debug_setPinLevel_listener != 0x0) external_proxyType_send_Debug_setPinLevel_listener(_instance, Pin, Level);
;
}
void (*external_proxyType_send_Debug_setPinValue_listener)(struct proxyType_Instance *, uint8_t, uint16_t)= 0x0;
void (*proxyType_send_Debug_setPinValue_listener)(struct proxyType_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_proxyType_send_Debug_setPinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t)){
external_proxyType_send_Debug_setPinValue_listener = _listener;
}
void register_proxyType_send_Debug_setPinValue_listener(void (*_listener)(struct proxyType_Instance *, uint8_t, uint16_t)){
proxyType_send_Debug_setPinValue_listener = _listener;
}
void proxyType_send_Debug_setPinValue(struct proxyType_Instance *_instance, uint8_t Pin, uint16_t Value){
if (proxyType_send_Debug_setPinValue_listener != 0x0) proxyType_send_Debug_setPinValue_listener(_instance, Pin, Value);
if (external_proxyType_send_Debug_setPinValue_listener != 0x0) external_proxyType_send_Debug_setPinValue_listener(_instance, Pin, Value);
;
}
void (*external_proxyType_send_Debug_serialBegin_listener)(struct proxyType_Instance *, uint32_t)= 0x0;
void (*proxyType_send_Debug_serialBegin_listener)(struct proxyType_Instance *, uint32_t)= 0x0;
void register_external_proxyType_send_Debug_serialBegin_listener(void (*_listener)(struct proxyType_Instance *, uint32_t)){
external_proxyType_send_Debug_serialBegin_listener = _listener;
}
void register_proxyType_send_Debug_serialBegin_listener(void (*_listener)(struct proxyType_Instance *, uint32_t)){
proxyType_send_Debug_serialBegin_listener = _listener;
}
void proxyType_send_Debug_serialBegin(struct proxyType_Instance *_instance, uint32_t Baudrate){
if (proxyType_send_Debug_serialBegin_listener != 0x0) proxyType_send_Debug_serialBegin_listener(_instance, Baudrate);
if (external_proxyType_send_Debug_serialBegin_listener != 0x0) external_proxyType_send_Debug_serialBegin_listener(_instance, Baudrate);
;
}
void (*external_proxyType_send_Debug_serialClearSendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void (*proxyType_send_Debug_serialClearSendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void register_external_proxyType_send_Debug_serialClearSendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
external_proxyType_send_Debug_serialClearSendBuffer_listener = _listener;
}
void register_proxyType_send_Debug_serialClearSendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
proxyType_send_Debug_serialClearSendBuffer_listener = _listener;
}
void proxyType_send_Debug_serialClearSendBuffer(struct proxyType_Instance *_instance){
if (proxyType_send_Debug_serialClearSendBuffer_listener != 0x0) proxyType_send_Debug_serialClearSendBuffer_listener(_instance);
if (external_proxyType_send_Debug_serialClearSendBuffer_listener != 0x0) external_proxyType_send_Debug_serialClearSendBuffer_listener(_instance);
;
}
void (*external_proxyType_send_Debug_serialAddToSendBuffer_listener)(struct proxyType_Instance *, unsigned char)= 0x0;
void (*proxyType_send_Debug_serialAddToSendBuffer_listener)(struct proxyType_Instance *, unsigned char)= 0x0;
void register_external_proxyType_send_Debug_serialAddToSendBuffer_listener(void (*_listener)(struct proxyType_Instance *, unsigned char)){
external_proxyType_send_Debug_serialAddToSendBuffer_listener = _listener;
}
void register_proxyType_send_Debug_serialAddToSendBuffer_listener(void (*_listener)(struct proxyType_Instance *, unsigned char)){
proxyType_send_Debug_serialAddToSendBuffer_listener = _listener;
}
void proxyType_send_Debug_serialAddToSendBuffer(struct proxyType_Instance *_instance, unsigned char b){
if (proxyType_send_Debug_serialAddToSendBuffer_listener != 0x0) proxyType_send_Debug_serialAddToSendBuffer_listener(_instance, b);
if (external_proxyType_send_Debug_serialAddToSendBuffer_listener != 0x0) external_proxyType_send_Debug_serialAddToSendBuffer_listener(_instance, b);
;
}
void (*external_proxyType_send_Debug_serialSendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void (*proxyType_send_Debug_serialSendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void register_external_proxyType_send_Debug_serialSendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
external_proxyType_send_Debug_serialSendBuffer_listener = _listener;
}
void register_proxyType_send_Debug_serialSendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
proxyType_send_Debug_serialSendBuffer_listener = _listener;
}
void proxyType_send_Debug_serialSendBuffer(struct proxyType_Instance *_instance){
if (proxyType_send_Debug_serialSendBuffer_listener != 0x0) proxyType_send_Debug_serialSendBuffer_listener(_instance);
if (external_proxyType_send_Debug_serialSendBuffer_listener != 0x0) external_proxyType_send_Debug_serialSendBuffer_listener(_instance);
;
}
void (*external_proxyType_send_Debug_serialDisplaySendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void (*proxyType_send_Debug_serialDisplaySendBuffer_listener)(struct proxyType_Instance *)= 0x0;
void register_external_proxyType_send_Debug_serialDisplaySendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
external_proxyType_send_Debug_serialDisplaySendBuffer_listener = _listener;
}
void register_proxyType_send_Debug_serialDisplaySendBuffer_listener(void (*_listener)(struct proxyType_Instance *)){
proxyType_send_Debug_serialDisplaySendBuffer_listener = _listener;
}
void proxyType_send_Debug_serialDisplaySendBuffer(struct proxyType_Instance *_instance){
if (proxyType_send_Debug_serialDisplaySendBuffer_listener != 0x0) proxyType_send_Debug_serialDisplaySendBuffer_listener(_instance);
if (external_proxyType_send_Debug_serialDisplaySendBuffer_listener != 0x0) external_proxyType_send_Debug_serialDisplaySendBuffer_listener(_instance);
;
}



