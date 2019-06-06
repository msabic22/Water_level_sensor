import serial
import paho.mqtt.client as mqtt
import time

BROKER = "broker.hivemq.com"
CLIENTID = "MQTTExample"
TOPIC_ONE = "A507/sensors/temperature"
TOPIC_TWO = "A507/sensors/humidity"
TEST_TOPIC = "A507/sensors/test"
COMPORT = "COM8" # please replace this with your port number
QOS = 1


mqttc = mqtt.Client(CLIENTID)
mqttc.connect(BROKER)

# counter =  0

# ser = serial.Serial(COMPORT, 115200, timeout=5) 

def test():
	test = "0.5"
	mqttc.publish(TOPIC_TWO, payload=test, qos=QOS, retain=False)



while True:

	# while True:
	# 	test()
	# 	time.sleep(5)

	message = ser.readline().decode()

	# if counter < 100:
	# 	message = ("TEST: " + str(counter))
	# 	time.sleep(1)
	# 	counter = counter+1
	# 	if counter == 100:
	# 		counter = 0
	
	print (message)
	if "Temperature : " in message:
		string, x, temp = message.split(" ")
		mqttc.publish(TOPIC_ONE, payload=temp, qos=QOS, retain=False)
	if "Humidity : " in message:
		string, x, hum = message.split(" ")
		mqttc.publish(TOPIC_TWO, payload=hum, qos=QOS, retain=False)
	# if "TEST:" in message:
	# 	string, test = message.split(" ")
	# 	mqttc.publish(TEST_TOPIC, payload=test, qos=QOS, retain=False)
	time.sleep(0.01)
mqttc.disconnect()
time.sleep(1)