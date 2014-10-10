//TLPerc.ino

#include <SoftwareSerial.h>

#define BT_RX 11
#define BT_TX 10

SoftwareSerial btSerial(BT_RX, BT_TX);

int i;
int signal;

void setup(){
	for(i = 0;i < 8;i++){
		pinMode(i+2,INPUT);
	}
	signal = 0;
	Serial.begin(115200);
	btSerial.begin(115200);
}
void loop(){
	for(i = 0;i < 8;i++){
		if(digitalRead(i+2) == LOW){
			temp = pow(2,i);
			if(temp > 2){
				temp++;
			}
			signal += temp;
		}
	}
	if(signal < 16){
		Serial.write("0");
		btSerial.write("0");
	}
	Sirial.println(signal,HEX);
	btSirial.println(signal,HEX);
	signal = 0;
}
