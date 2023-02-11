// #define DEBUG
#define array_length(x)  (sizeof(x) / sizeof((x)[0]))


constexpr uint8_t LED_RED[] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH,HIGH};
constexpr uint8_t LED_LFT[] = {HIGH,LOW ,LOW ,LOW ,LOW ,LOW ,HIGH,LOW ,HIGH,LOW ,LOW ,LOW ,HIGH,LOW ,LOW ,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH,HIGH};
constexpr uint8_t LED_MID[] = {LOW ,LOW ,HIGH,LOW ,LOW ,LOW ,HIGH,LOW ,LOW ,LOW ,LOW ,LOW ,LOW ,LOW ,HIGH,LOW ,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH,HIGH};
constexpr uint8_t LED_RGH[] = {LOW ,LOW ,LOW ,LOW ,HIGH,LOW ,LOW ,LOW ,HIGH,LOW ,HIGH,LOW ,LOW ,LOW ,HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH,HIGH};
constexpr int LED_PIN[] = {2,3,4,5};
constexpr int LFTLEDPIN = 0;
constexpr int MIDLEDPIN = 1;
constexpr int RGHLEDPIN = 2;
constexpr int REDLEDPIN = 3;
constexpr int NO_SLEEP  = 0;
constexpr int WAITFOR   = 600;
constexpr int PORT      = 9600;


void init_logger( int iSerialPort) {
#ifdef DEBUG
  Serial.begin( iSerialPort) ;
#endif
  return;
}
#ifdef DEBUG
void dbg(  String func, String title, String msg) {
  Serial.println("[DBG] " + func + ":: " + title + " - " + msg);
}
#endif

void setup() {
  init_logger(PORT);
  for (int i = 0 ; i <= array_length(LED_PIN) ; i++)
    pinMode(LED_PIN[i], OUTPUT);
}

void wait ( int milliseconds ) {
  if (milliseconds <= NO_SLEEP)  
    return;
  delay (milliseconds);  
  return;
}
void led(int pin,uint8_t action, int second ) {
  digitalWrite(pin,action);
  wait(second);
  return;
}

void loop() {
  for (int i = 0 ; i < array_length(LED_RED); i++){
      led(LED_PIN[REDLEDPIN],LED_RED[i],NO_SLEEP);
      led(LED_PIN[LFTLEDPIN],LED_LFT[i],NO_SLEEP);
      led(LED_PIN[MIDLEDPIN],LED_MID[i],NO_SLEEP);
      led(LED_PIN[RGHLEDPIN],LED_RGH[i],WAITFOR); 
  }
}
