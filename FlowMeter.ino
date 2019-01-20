#define LED 13
#define FLOWSENSOR 2
#define SENSOUT 9


volatile uint16_t flow_impulses = 0;

void setup()
{

	pinMode(LED, OUTPUT);
	pinMode(FLOWSENSOR, INPUT_PULLUP);
	pinMode(SENSOUT, OUTPUT);

	attachInterrupt(digitalPinToInterrupt(FLOWSENSOR), irq_flow, CHANGE);

	//digitalWrite(LED, 1);
	
}

void loop()
{

	flow_impulses = 0;
	delay(1000);
	if (flow_impulses > 5) {
		digitalWrite(LED, 1);
		digitalWrite(SENSOUT, 1);
	}
	else {
		digitalWrite(LED, 0);
		digitalWrite(SENSOUT, 0);
	}

}


void irq_flow()
{

	flow_impulses++;
}