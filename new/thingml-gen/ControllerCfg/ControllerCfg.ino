/*****************************************************************************
 * Headers for type : Controller
 *****************************************************************************/

// Definition of the instance stuct:
struct Controller_Instance {
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_Serial1;
// Variables for the current instance state
int Controller_C_State;
// Variables for the properties of the instance
uint8_t * Controller_pinInput__var;
uint32_t Controller_Serial__var;
uint32_t Controller_RefreshRate__var;
uint8_t Controller_SendBufferSize__var;
uint8_t * Controller_SendBuffer__var;
uint8_t Controller_SendBufferCurrentSize__var;

};
// Declaration of prototypes outgoing messages:
void Controller_C_OnEntry(int state, struct Controller_Instance *_instance);
void Controller_handle_Serial1_setPinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value);
void Controller_handle_Serial1_serialClearSendBuffer(struct Controller_Instance *_instance);
void Controller_handle_Serial1_serialDisplaySendBuffer(struct Controller_Instance *_instance);
void Controller_handle_Serial1_setRefreshRate(struct Controller_Instance *_instance, uint32_t r);
void Controller_handle_Serial1_pinMode(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Mode);
void Controller_handle_Serial1_serialAddToSendBuffer(struct Controller_Instance *_instance, unsigned char b);
void Controller_handle_Serial1_serialSendBuffer(struct Controller_Instance *_instance);
void Controller_handle_Serial1_setPinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level);
void Controller_handle_Serial1_serialBegin(struct Controller_Instance *_instance, uint32_t Baudrate);
void Controller_handle_Serial1_ping(struct Controller_Instance *_instance, int16_t i);
void Controller_handle_clock_timeout(struct Controller_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_Controller_send_clock_timer_start_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint32_t));
void register_external_Controller_send_clock_timer_start_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint32_t));
void register_Controller_send_clock_timer_cancel_listener(void (*_listener)(struct Controller_Instance *, uint8_t));
void register_external_Controller_send_clock_timer_cancel_listener(void (*_listener)(struct Controller_Instance *, uint8_t));
void register_Controller_send_Serial1_pong_listener(void (*_listener)(struct Controller_Instance *, int16_t));
void register_external_Controller_send_Serial1_pong_listener(void (*_listener)(struct Controller_Instance *, int16_t));
void register_Controller_send_Serial1_pinLevel_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint8_t));
void register_external_Controller_send_Serial1_pinLevel_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint8_t));
void register_Controller_send_Serial1_pinValue_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint16_t));
void register_external_Controller_send_Serial1_pinValue_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint16_t));
void register_Controller_send_Serial1_serialReceived_listener(void (*_listener)(struct Controller_Instance *, unsigned char));
void register_external_Controller_send_Serial1_serialReceived_listener(void (*_listener)(struct Controller_Instance *, unsigned char));
void register_Controller_send_Serial1_serialSendBufferContent_listener(void (*_listener)(struct Controller_Instance *, uint8_t, unsigned char));
void register_external_Controller_send_Serial1_serialSendBufferContent_listener(void (*_listener)(struct Controller_Instance *, uint8_t, unsigned char));

// Definition of the states:
#define CONTROLLER_C_STATE 0
#define CONTROLLER_C_ACTIVE_STATE 1



//timer0
/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();

/*SOFTWARE_SERIAL*/

#define Serial1_LISTENER_STATE_IDLE 0
#define Serial1_LISTENER_STATE_ERROR 1
#define Serial1_LISTENER_STATE_READ_TAIL 2

uint8_t Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;


struct Serial1_instance_type {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
} Serial1_instance;

int fifo_byte_available();
int _fifo_enqueue(byte b);

void Serial1_setup() {
	Serial1.begin(115200);
}

void Serial1_set_listener_id(uint16_t id) {
	Serial1_instance.listener_id = id;
}


void Serial1_forwardMessage(byte * msg, uint8_t size) {
  Serial1.write("");

  for(uint8_t i = 0; i < size; i++) {
    if((msg[i] == 18) || (msg[i] == 19) || (msg[i] == 125)) {
Serial1.write(125);
}

    Serial1.write(msg[i]);
  }
  Serial1.write("");

}

bool Serial1_parse() {
uint8_t msgbuf[8];
uint8_t bytebuf;
uint8_t index = 0;
index += Serial1.readBytes(&msgbuf[index], 2);
uint16_t msgID = (msgbuf[0] << 8) + msgbuf[1];
if(index != 2) return false;
switch(msgID) {
case 12:
while(index < 5) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 21:
while(index < 2) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 24:
while(index < 2) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 2:
while(index < 6) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 10:
while(index < 4) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 22:
while(index < 3) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 23:
while(index < 2) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 11:
while(index < 4) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 20:
while(index < 6) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
case 0:
while(index < 4) {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
if(bytebuf != 125) {
msgbuf[index] = bytebuf;
index++;
} else {
if(Serial1.readBytes(&bytebuf, 1) == 0) {
return false;
}
msgbuf[index] = bytebuf;
index++;
}
}
break;
}
externalMessageEnqueue(msgbuf, index, Serial1_instance.listener_id);
}


bool Serial1_read_header() {
 bool Serial1_res = true;
 uint8_t Serial1_buf;
 Serial1_res &= ((Serial1.readBytes(&Serial1_buf, 1) == 1) && (Serial1_buf == 18));
 return Serial1_res;
}
bool Serial1_read_footer() {
 bool Serial1_res = true;
 uint8_t Serial1_buf;
 Serial1_res &= ((Serial1.readBytes(&Serial1_buf, 1) == 1) && (Serial1_buf == 19));
 return Serial1_res;
}


void Serial1_read() {
  if (Serial1.available() > 0) {
    
    switch(Serial1_serialListenerState) {
      case Serial1_LISTENER_STATE_IDLE:
        if(Serial1_read_header()) {
              if(!Serial1_parse()) {
                Serial1_serialListenerState = Serial1_LISTENER_STATE_ERROR;
              }

              Serial1_serialListenerState = Serial1_LISTENER_STATE_READ_TAIL;

            } else {
              Serial1_serialListenerState = Serial1_LISTENER_STATE_ERROR;
            }
      break;
      
      case Serial1_LISTENER_STATE_ERROR:
        Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;
      break;
      
      case Serial1_LISTENER_STATE_READ_TAIL:
        if(Serial1_read_footer()) {
              Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;
            } else {
              Serial1_serialListenerState = Serial1_LISTENER_STATE_ERROR;
            }
      break;
    }
  }
  
}

#define MAX_INSTANCES 4
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

#define timer0_NB_SOFT_TIMER 4
uint32_t timer0_timer[timer0_NB_SOFT_TIMER];
uint32_t  timer0_prev_1sec = 0;

uint8_t timer0_interrupt_counter = 0;
SIGNAL(TIMER0_COMPA_vect) {
timer0_interrupt_counter++;
if(timer0_interrupt_counter >= 0) {
timer0_interrupt_counter = 0;
}
}



struct timer0_instance_type {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
} timer0_instance;

void timer0_setup() {
	// Plugging into timer0 
               OCR0A = 0xAF;
               TIMSK0 |= _BV(OCIE0A);


	timer0_prev_1sec = millis() + 1000;
}

void timer0_set_listener_id(uint16_t id) {
	timer0_instance.listener_id = id;
}

void timer0_timer_start(uint8_t id, uint32_t ms) {
if(id <timer0_NB_SOFT_TIMER) {
timer0_timer[id] = ms + millis();
}
}

void timer0_timer_cancel(uint8_t id) {
if(id <timer0_NB_SOFT_TIMER) {
timer0_timer[id] = 0;
}
}

void timer0_timeout(uint8_t id) {
uint8_t enqueue_buf[3];
enqueue_buf[0] = (3 >> 8) & 0xFF;
enqueue_buf[1] = 3 & 0xFF;
enqueue_buf[2] = id;
externalMessageEnqueue(enqueue_buf, 3, timer0_instance.listener_id);
}





void timer0_read() {
	uint32_t tms = millis();
	uint8_t t;
for(t = 0; t < 4; t++) {
if((timer0_timer[t] > 0) && (timer0_timer[t] < tms)) {
timer0_timer[t] = 0;
timer0_timeout(t);
}
}

	if (timer0_prev_1sec < tms) {
		timer0_prev_1sec += 1000;
	}
}
/*****************************************************************************
 * Implementation for type : Controller
 *****************************************************************************/

// Declaration of prototypes:
void Controller_C_OnExit(int state, struct Controller_Instance *_instance);
void Controller_send_clock_timer_start(struct Controller_Instance *_instance, uint8_t id, uint32_t time);
void Controller_send_clock_timer_cancel(struct Controller_Instance *_instance, uint8_t id);
void Controller_send_Serial1_pong(struct Controller_Instance *_instance, int16_t i);
void Controller_send_Serial1_pinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level);
void Controller_send_Serial1_pinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value);
void Controller_send_Serial1_serialReceived(struct Controller_Instance *_instance, unsigned char b);
void Controller_send_Serial1_serialSendBufferContent(struct Controller_Instance *_instance, uint8_t i, unsigned char b);
void f_Controller_initialization(struct Controller_Instance *_instance);
void f_Controller_refresh(struct Controller_Instance *_instance);
// Declaration of functions:
// Definition of function initialization
void f_Controller_initialization(struct Controller_Instance *_instance) {
for(uint8_t i = 0; i < 20 ; i++) {
_instance->Controller_pinInput__var[i] = 0;
}
}
// Definition of function refresh
void f_Controller_refresh(struct Controller_Instance *_instance) {
for(uint8_t i = 0; i < 14 ; i++) {
if(_instance->Controller_pinInput__var[i]
) {
Controller_send_Serial1_pinLevel(_instance, i, (uint8_t) digitalRead(i));

}
}
for(uint8_t i = 0; i < 6 ; i++) {
if(_instance->Controller_pinInput__var[i + 14]
) {
Controller_send_Serial1_pinValue(_instance, i + 14, (uint16_t) analogRead(i));

}
}
if(((_instance->Controller_Serial__var != 0))) {
while(Serial.available() > 0) {
Controller_send_Serial1_serialReceived(_instance, Serial.read());
}

}
}

// On Entry Actions:
void Controller_C_OnEntry(int state, struct Controller_Instance *_instance) {
switch(state) {
case CONTROLLER_C_STATE:
_instance->Controller_C_State = CONTROLLER_C_ACTIVE_STATE;
f_Controller_initialization(_instance);
Controller_send_clock_timer_start(_instance, 0, _instance->Controller_RefreshRate__var);
Controller_C_OnEntry(_instance->Controller_C_State, _instance);
break;
case CONTROLLER_C_ACTIVE_STATE:
break;
default: break;
}
}

// On Exit Actions:
void Controller_C_OnExit(int state, struct Controller_Instance *_instance) {
switch(state) {
case CONTROLLER_C_STATE:
Controller_C_OnExit(_instance->Controller_C_State, _instance);
break;
case CONTROLLER_C_ACTIVE_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void Controller_handle_Serial1_setPinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
if((Pin > 13) && (Pin < 20)) {
if( !((_instance->Controller_pinInput__var[Pin]
))) {
analogWrite(Pin, LOW);

}

}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_serialClearSendBuffer(struct Controller_Instance *_instance) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
_instance->Controller_SendBufferCurrentSize__var = 0;
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_serialDisplaySendBuffer(struct Controller_Instance *_instance) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
for(uint16_t i = 0; i < _instance->Controller_SendBufferCurrentSize__var; i++) {
Controller_send_Serial1_serialSendBufferContent(_instance, (uint8_t) i, _instance->Controller_SendBuffer__var[_instance->Controller_SendBufferCurrentSize__var]
);
}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_setRefreshRate(struct Controller_Instance *_instance, uint32_t r) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
_instance->Controller_RefreshRate__var = r;
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_pinMode(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Mode) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
if(Mode) {
if(Pin < 14) {
_instance->Controller_pinInput__var[Pin] = 1;
pinMode(Pin,INPUT);

}
if((Pin > 13) && (Pin < 20)) {
_instance->Controller_pinInput__var[Pin] = 1;

}

} else {
if(Pin < 14) {
_instance->Controller_pinInput__var[Pin] = 0;
pinMode(Pin,OUTPUT);
digitalWrite(Pin, LOW);

}
if((Pin > 13) && (Pin < 20)) {
_instance->Controller_pinInput__var[Pin] = 0;

}

}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_serialAddToSendBuffer(struct Controller_Instance *_instance, unsigned char b) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
_instance->Controller_SendBuffer__var[_instance->Controller_SendBufferCurrentSize__var] = b;
_instance->Controller_SendBufferCurrentSize__var = _instance->Controller_SendBufferCurrentSize__var + 1;
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_serialSendBuffer(struct Controller_Instance *_instance) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
if( !((_instance->Controller_Serial__var == 0))) {
for(uint16_t i = 0; i < _instance->Controller_SendBufferCurrentSize__var; i++) {
					Serial.write(_instance->Controller_SendBuffer__var[i]
);
				}
_instance->Controller_SendBufferCurrentSize__var = 0;

}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_setPinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
if(Pin < 14) {
if( !((_instance->Controller_pinInput__var[Pin]
))) {
if(Level) {
digitalWrite(Pin, HIGH);

} else {
digitalWrite(Pin, LOW);

}

}

}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_serialBegin(struct Controller_Instance *_instance, uint32_t Baudrate) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
if(((Baudrate != 0))) {
_instance->Controller_Serial__var = Baudrate;
Serial.begin(Baudrate);

}
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_Serial1_ping(struct Controller_Instance *_instance, int16_t i) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
Controller_send_Serial1_pong(_instance, i);
Controller_C_State_event_consumed = 1;
}
}
void Controller_handle_clock_timeout(struct Controller_Instance *_instance, uint8_t id) {
uint8_t Controller_C_State_event_consumed = 0;
if (1) {
Controller_send_clock_timer_start(_instance, 0, _instance->Controller_RefreshRate__var);
f_Controller_refresh(_instance);
Controller_C_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_Controller_send_clock_timer_start_listener)(struct Controller_Instance *, uint8_t, uint32_t)= 0x0;
void (*Controller_send_clock_timer_start_listener)(struct Controller_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_Controller_send_clock_timer_start_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint32_t)){
external_Controller_send_clock_timer_start_listener = _listener;
}
void register_Controller_send_clock_timer_start_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint32_t)){
Controller_send_clock_timer_start_listener = _listener;
}
void Controller_send_clock_timer_start(struct Controller_Instance *_instance, uint8_t id, uint32_t time){
if (Controller_send_clock_timer_start_listener != 0x0) Controller_send_clock_timer_start_listener(_instance, id, time);
if (external_Controller_send_clock_timer_start_listener != 0x0) external_Controller_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_Controller_send_clock_timer_cancel_listener)(struct Controller_Instance *, uint8_t)= 0x0;
void (*Controller_send_clock_timer_cancel_listener)(struct Controller_Instance *, uint8_t)= 0x0;
void register_external_Controller_send_clock_timer_cancel_listener(void (*_listener)(struct Controller_Instance *, uint8_t)){
external_Controller_send_clock_timer_cancel_listener = _listener;
}
void register_Controller_send_clock_timer_cancel_listener(void (*_listener)(struct Controller_Instance *, uint8_t)){
Controller_send_clock_timer_cancel_listener = _listener;
}
void Controller_send_clock_timer_cancel(struct Controller_Instance *_instance, uint8_t id){
if (Controller_send_clock_timer_cancel_listener != 0x0) Controller_send_clock_timer_cancel_listener(_instance, id);
if (external_Controller_send_clock_timer_cancel_listener != 0x0) external_Controller_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_Controller_send_Serial1_pong_listener)(struct Controller_Instance *, int16_t)= 0x0;
void (*Controller_send_Serial1_pong_listener)(struct Controller_Instance *, int16_t)= 0x0;
void register_external_Controller_send_Serial1_pong_listener(void (*_listener)(struct Controller_Instance *, int16_t)){
external_Controller_send_Serial1_pong_listener = _listener;
}
void register_Controller_send_Serial1_pong_listener(void (*_listener)(struct Controller_Instance *, int16_t)){
Controller_send_Serial1_pong_listener = _listener;
}
void Controller_send_Serial1_pong(struct Controller_Instance *_instance, int16_t i){
if (Controller_send_Serial1_pong_listener != 0x0) Controller_send_Serial1_pong_listener(_instance, i);
if (external_Controller_send_Serial1_pong_listener != 0x0) external_Controller_send_Serial1_pong_listener(_instance, i);
;
}
void (*external_Controller_send_Serial1_pinLevel_listener)(struct Controller_Instance *, uint8_t, uint8_t)= 0x0;
void (*Controller_send_Serial1_pinLevel_listener)(struct Controller_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_Controller_send_Serial1_pinLevel_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint8_t)){
external_Controller_send_Serial1_pinLevel_listener = _listener;
}
void register_Controller_send_Serial1_pinLevel_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint8_t)){
Controller_send_Serial1_pinLevel_listener = _listener;
}
void Controller_send_Serial1_pinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level){
if (Controller_send_Serial1_pinLevel_listener != 0x0) Controller_send_Serial1_pinLevel_listener(_instance, Pin, Level);
if (external_Controller_send_Serial1_pinLevel_listener != 0x0) external_Controller_send_Serial1_pinLevel_listener(_instance, Pin, Level);
;
}
void (*external_Controller_send_Serial1_pinValue_listener)(struct Controller_Instance *, uint8_t, uint16_t)= 0x0;
void (*Controller_send_Serial1_pinValue_listener)(struct Controller_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_Controller_send_Serial1_pinValue_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint16_t)){
external_Controller_send_Serial1_pinValue_listener = _listener;
}
void register_Controller_send_Serial1_pinValue_listener(void (*_listener)(struct Controller_Instance *, uint8_t, uint16_t)){
Controller_send_Serial1_pinValue_listener = _listener;
}
void Controller_send_Serial1_pinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value){
if (Controller_send_Serial1_pinValue_listener != 0x0) Controller_send_Serial1_pinValue_listener(_instance, Pin, Value);
if (external_Controller_send_Serial1_pinValue_listener != 0x0) external_Controller_send_Serial1_pinValue_listener(_instance, Pin, Value);
;
}
void (*external_Controller_send_Serial1_serialReceived_listener)(struct Controller_Instance *, unsigned char)= 0x0;
void (*Controller_send_Serial1_serialReceived_listener)(struct Controller_Instance *, unsigned char)= 0x0;
void register_external_Controller_send_Serial1_serialReceived_listener(void (*_listener)(struct Controller_Instance *, unsigned char)){
external_Controller_send_Serial1_serialReceived_listener = _listener;
}
void register_Controller_send_Serial1_serialReceived_listener(void (*_listener)(struct Controller_Instance *, unsigned char)){
Controller_send_Serial1_serialReceived_listener = _listener;
}
void Controller_send_Serial1_serialReceived(struct Controller_Instance *_instance, unsigned char b){
if (Controller_send_Serial1_serialReceived_listener != 0x0) Controller_send_Serial1_serialReceived_listener(_instance, b);
if (external_Controller_send_Serial1_serialReceived_listener != 0x0) external_Controller_send_Serial1_serialReceived_listener(_instance, b);
;
}
void (*external_Controller_send_Serial1_serialSendBufferContent_listener)(struct Controller_Instance *, uint8_t, unsigned char)= 0x0;
void (*Controller_send_Serial1_serialSendBufferContent_listener)(struct Controller_Instance *, uint8_t, unsigned char)= 0x0;
void register_external_Controller_send_Serial1_serialSendBufferContent_listener(void (*_listener)(struct Controller_Instance *, uint8_t, unsigned char)){
external_Controller_send_Serial1_serialSendBufferContent_listener = _listener;
}
void register_Controller_send_Serial1_serialSendBufferContent_listener(void (*_listener)(struct Controller_Instance *, uint8_t, unsigned char)){
Controller_send_Serial1_serialSendBufferContent_listener = _listener;
}
void Controller_send_Serial1_serialSendBufferContent(struct Controller_Instance *_instance, uint8_t i, unsigned char b){
if (Controller_send_Serial1_serialSendBufferContent_listener != 0x0) Controller_send_Serial1_serialSendBufferContent_listener(_instance, i, b);
if (external_Controller_send_Serial1_serialSendBufferContent_listener != 0x0) external_Controller_send_Serial1_serialSendBufferContent_listener(_instance, i, b);
;
}






/*****************************************************************************
 * Definitions for configuration : ControllerCfg
 *****************************************************************************/

//Declaration of instance variables
//Instance c
// Variables for the properties of the instance
uint8_t array_c_Controller_pinInput__var[20];
uint8_t array_c_Controller_SendBuffer__var[32];
struct Controller_Instance c_var;



//New dispatcher for messages
void dispatch_serialClearSendBuffer(uint16_t sender) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_serialClearSendBuffer(&c_var);

}

}


//New dispatcher for messages
void dispatch_setRefreshRate(uint16_t sender, uint32_t param_r) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_setRefreshRate(&c_var, param_r);

}

}


//New dispatcher for messages
void dispatch_pinMode(uint16_t sender, uint8_t param_Pin, uint8_t param_Mode) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_pinMode(&c_var, param_Pin, param_Mode);

}

}


//New dispatcher for messages
void dispatch_serialBegin(uint16_t sender, uint32_t param_Baudrate) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_serialBegin(&c_var, param_Baudrate);

}

}


//New dispatcher for messages
void dispatch_ping(uint16_t sender, int16_t param_i) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_ping(&c_var, param_i);

}

}


//New dispatcher for messages
void dispatch_setPinValue(uint16_t sender, uint8_t param_Pin, uint16_t param_Value) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_setPinValue(&c_var, param_Pin, param_Value);

}

}


//New dispatcher for messages
void dispatch_serialDisplaySendBuffer(uint16_t sender) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_serialDisplaySendBuffer(&c_var);

}

}


//New dispatcher for messages
void dispatch_serialAddToSendBuffer(uint16_t sender, unsigned char param_b) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_serialAddToSendBuffer(&c_var, param_b);

}

}


//New dispatcher for messages
void dispatch_serialSendBuffer(uint16_t sender) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_serialSendBuffer(&c_var);

}

}


//New dispatcher for messages
void dispatch_setPinLevel(uint16_t sender, uint8_t param_Pin, uint8_t param_Level) {
if (sender == Serial1_instance.listener_id) {
Controller_handle_Serial1_setPinLevel(&c_var, param_Pin, param_Level);

}

}


//New dispatcher for messages
void dispatch_timeout(uint16_t sender, uint8_t param_id) {
if (sender == timer0_instance.listener_id) {
Controller_handle_clock_timeout(&c_var, param_id);

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

byte mbuf[6];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 12:
while (mbufi < 5) mbuf[mbufi++] = fifo_dequeue();
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
case 21:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_serialClearSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 24:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_serialDisplaySendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 2:
while (mbufi < 6) mbuf[mbufi++] = fifo_dequeue();
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
case 10:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
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
case 22:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
union u_serialAddToSendBuffer_b_t {
unsigned char p;
byte bytebuffer[1];
} u_serialAddToSendBuffer_b;
u_serialAddToSendBuffer_b.bytebuffer[0] = mbuf[2];
dispatch_serialAddToSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_serialAddToSendBuffer_b.p /* b */ );
break;
case 23:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_serialSendBuffer((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 11:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
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
case 3:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
union u_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timeout_id;
u_timeout_id.bytebuffer[0] = mbuf[2];
dispatch_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timeout_id.p /* id */ );
break;
case 20:
while (mbufi < 6) mbuf[mbufi++] = fifo_dequeue();
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
case 0:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
union u_ping_i_t {
int16_t p;
byte bytebuffer[2];
} u_ping_i;
u_ping_i.bytebuffer[1] = mbuf[2];
u_ping_i.bytebuffer[0] = mbuf[3];
dispatch_ping((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_ping_i.p /* i */ );
break;
}
return 1;
}

// Forwarding of messages Serial1::Controller::Serial1::pong
void forward_Serial1_Controller_send_Serial1_pong(struct Controller_Instance *_instance, int16_t i){
byte forward_buf[4];
forward_buf[0] = (1 >> 8) & 0xFF;
forward_buf[1] =  1 & 0xFF;


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

// Forwarding of messages Serial1::Controller::Serial1::pinLevel
void forward_Serial1_Controller_send_Serial1_pinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level){
byte forward_buf[4];
forward_buf[0] = (30 >> 8) & 0xFF;
forward_buf[1] =  30 & 0xFF;


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

// Forwarding of messages Serial1::Controller::Serial1::pinValue
void forward_Serial1_Controller_send_Serial1_pinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value){
byte forward_buf[5];
forward_buf[0] = (31 >> 8) & 0xFF;
forward_buf[1] =  31 & 0xFF;


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

// Forwarding of messages Serial1::Controller::Serial1::serialReceived
void forward_Serial1_Controller_send_Serial1_serialReceived(struct Controller_Instance *_instance, unsigned char b){
byte forward_buf[3];
forward_buf[0] = (40 >> 8) & 0xFF;
forward_buf[1] =  40 & 0xFF;


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

// Forwarding of messages Serial1::Controller::Serial1::serialSendBufferContent
void forward_Serial1_Controller_send_Serial1_serialSendBufferContent(struct Controller_Instance *_instance, uint8_t i, unsigned char b){
byte forward_buf[4];
forward_buf[0] = (41 >> 8) & 0xFF;
forward_buf[1] =  41 & 0xFF;


// parameter i
union u_i_t {
uint8_t p;
byte bytebuffer[1];
} u_i;
u_i.p = i;
forward_buf[2] =  (u_i.bytebuffer[0] & 0xFF);

// parameter b
union u_b_t {
unsigned char p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
forward_buf[3] =  (u_b.bytebuffer[0] & 0xFF);

//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 4);
}

// Forwarding of messages timer0::Controller::clock::timer_start
void forward_timer0_Controller_send_clock_timer_start(struct Controller_Instance *_instance, uint8_t id, uint32_t time){
timer0_timer_start(id, time);}

// Forwarding of messages timer0::Controller::clock::timer_cancel
void forward_timer0_Controller_send_clock_timer_cancel(struct Controller_Instance *_instance, uint8_t id){
timer0_timer_cancel(id);}

void forward_Controller_send_Serial1_pinLevel(struct Controller_Instance *_instance, uint8_t Pin, uint8_t Level){
if(_instance->id_Serial1 == c_var.id_Serial1) {
forward_Serial1_Controller_send_Serial1_pinLevel(_instance, Pin, Level);
}
}
void forward_Controller_send_Serial1_serialSendBufferContent(struct Controller_Instance *_instance, uint8_t i, unsigned char b){
if(_instance->id_Serial1 == c_var.id_Serial1) {
forward_Serial1_Controller_send_Serial1_serialSendBufferContent(_instance, i, b);
}
}
void forward_Controller_send_Serial1_serialReceived(struct Controller_Instance *_instance, unsigned char b){
if(_instance->id_Serial1 == c_var.id_Serial1) {
forward_Serial1_Controller_send_Serial1_serialReceived(_instance, b);
}
}
void forward_Controller_send_Serial1_pong(struct Controller_Instance *_instance, int16_t i){
if(_instance->id_Serial1 == c_var.id_Serial1) {
forward_Serial1_Controller_send_Serial1_pong(_instance, i);
}
}
void forward_Controller_send_clock_timer_cancel(struct Controller_Instance *_instance, uint8_t id){
if(_instance->id_clock == c_var.id_clock) {
forward_timer0_Controller_send_clock_timer_cancel(_instance, id);
}
}
void forward_Controller_send_clock_timer_start(struct Controller_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_clock == c_var.id_clock) {
forward_timer0_Controller_send_clock_timer_start(_instance, id, time);
}
}
void forward_Controller_send_Serial1_pinValue(struct Controller_Instance *_instance, uint8_t Pin, uint16_t Value){
if(_instance->id_Serial1 == c_var.id_Serial1) {
forward_Serial1_Controller_send_Serial1_pinValue(_instance, Pin, Value);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 12:
if(msgSize == 5) {
msgSizeOK = 1;}
break;
case 21:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 24:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 2:
if(msgSize == 6) {
msgSizeOK = 1;}
break;
case 10:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 22:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
case 23:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 11:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 3:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
case 20:
if(msgSize == 6) {
msgSizeOK = 1;}
break;
case 0:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
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
}
}
}

void initialize_configuration_ControllerCfg() {
// Initialize connectors
register_external_Controller_send_clock_timer_start_listener(&forward_Controller_send_clock_timer_start);
register_external_Controller_send_clock_timer_cancel_listener(&forward_Controller_send_clock_timer_cancel);
register_external_Controller_send_Serial1_pong_listener(&forward_Controller_send_Serial1_pong);
register_external_Controller_send_Serial1_pinLevel_listener(&forward_Controller_send_Serial1_pinLevel);
register_external_Controller_send_Serial1_pinValue_listener(&forward_Controller_send_Serial1_pinValue);
register_external_Controller_send_Serial1_serialReceived_listener(&forward_Controller_send_Serial1_serialReceived);
register_external_Controller_send_Serial1_serialSendBufferContent_listener(&forward_Controller_send_Serial1_serialSendBufferContent);

// Init the ID, state variables and properties for external connector timer0
// Init the ID, state variables and properties for external connector Serial1

// Network Initilization 


Serial1_instance.listener_id = add_instance(&Serial1_instance);

Serial1_setup();


timer0_instance.listener_id = add_instance(&timer0_instance);

timer0_setup();


// End Network Initilization 

// Init the ID, state variables and properties for instance c
c_var.id_clock = add_instance( (void*) &c_var);
c_var.id_Serial1 = add_instance( (void*) &c_var);
c_var.Controller_C_State = CONTROLLER_C_ACTIVE_STATE;
c_var.Controller_Serial__var = 0;
c_var.Controller_RefreshRate__var = 200;
c_var.Controller_SendBufferSize__var = 32;
c_var.Controller_SendBufferCurrentSize__var = 0;
c_var.Controller_pinInput__var = array_c_Controller_pinInput__var;
c_var.Controller_SendBuffer__var = array_c_Controller_SendBuffer__var;

Controller_C_OnEntry(CONTROLLER_C_STATE, &c_var);
}




void setup() {
initialize_configuration_ControllerCfg();

}

void loop() {

// Network Listener

Serial1_read();

timer0_read();

    processMessageQueue();
}
