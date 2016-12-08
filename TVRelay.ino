#include <IRremote.h>

int Relay = 13; // Relay pin connection

int RECV_PIN = 0; // IR receiver pin

float incoming; // Means of storing which button was pushed last

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  // initialize the digital pin as an output.
  pinMode(Relay, OUTPUT);

  // initialize receiver pin
  irrecv.enableIRIn(); // Start the receiver
}

// the loop routine runs over and over again forever:
void loop() {
  if (irrecv.decode(&results)) {
     
     incoming = (results.value);
     if(incoming == 551529024.00){
        digitalWrite(Relay, HIGH);
     } else if(incoming == 551496384.00){
        digitalWrite(Relay, LOW);
     }
     irrecv.resume(); // Receive the next value
  }
  delay(500);
}
    
