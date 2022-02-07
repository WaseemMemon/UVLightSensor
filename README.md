# UVLightSensor

VEML6070 is an advanced ultraviolet (UV) light sensor with I2C protocol interface and designed by the CMOS process. It is easily operated via a simple I2C command. The active acknowledge (ACK) feature with threshold windows setting
allows the UV sensor to send out a UVI alert message. Under a strong solar UVI condition, the smart ACK signal can be easily implemented by the software programming. VEML6070 incorporates a photodiode, amplifiers, and analog / digital circuits into a single chip. VEML6070’s adoption of FiltronTM UV technology provides the best spectral sensitivity to cover UV spectrum sensing. It has an excellent temperature compensation and a robust refresh rate setting that does not use an external RC low pass filter.

VEML6070 has linear sensitivity to solar UV light and is easily adjusted by an external resistor. Software shutdown mode is provided, which reduces power consumption to be less than 1 μA. VEML6070’s operating voltage ranges from 2.7 V to 5.5 V.

# Prerequisite

- Docker
- Nuclio
- RabitMq
- ArduinoIDE
- MQTIZER
- MQTTLENS
- IFTTT
- Node.js

# Instruction

Clone this repository, then you need to start a Docker to start up a docker instance of Nuclio, use this command on nuclio:

$ sudo docker run -p 8070:8070 -v /var/run/docker.sock:/var/run/docker.sock -v /tmp:/tmp nuclio/dashboard:stable-amd64

And to start up a docker instance of RabbitMQ, use the following command:

$ sudo docker run -p 9000:15672 -p 1883:1883 -p 5672:5672 cyrilix/rabbitmq-mqtt

Make an applet on IFTTT to send a notificaton, or a SMS, through Webhooks service After that in nuclio code changing the IP address, the event name and the secret key from IFTTT in the post-Url section and deploy it.You can retrieve your secret key through the webhooks service documentation on IFTTT. 
In This Project there are two events SMS and Email , When the UV Rays Level are High It will send a warning message to User.

MQTIZER is a mobile MQTT client that can connect to any broker which shares the network with your phone, and to any broker on the cloud as well To show Message on Mobile App download Mobile App MQTIZER than Add the Broker on the app having same Ip as RabbitMQ. Now you will be able to see messages on Mobile Application and for the Web APP Download the Google Chrome extension called "MQTT Lens" add the host ip , username and password subscribe to it then it will show the Messages

# Libraries

[ESP8266WiFi]

The ESP8266WiFi library provides a wide collection of C++ methods (functions) and properties to configure and operate an ESP8266 module in station and / or soft access point mode.

[Pubsub Client]

A client library for MQTT messaging. MQTT is a lightweight messaging protocol ideal for small devices. This library allows you to send and receive MQTT messages.

[Adafruit VEML6070]

This is a library for the Adafruit VEML6070 UV sensor breakout.
