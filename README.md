# train

## setup

* download the raspbian headless version
* flash the sd card
* wpa_supplicant.conf edit network 
```
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=<Insert country code here>

network={
 ssid="<Name of your WiFi>"
 psk="<Password for your WiFi>"
}
```
* enable ssh
* SSH can be enabled by placing a file called ssh in to the boot folder. This flags the Pi to enable the SSH system on the next boot.

* install python3, python3-pip and pipenv

## getting started

```
pi@raspberrypi:~/train $ pipenv run python3 main.py
tx: <t 1 1 20 1>
rx:  b'<iDCC++ BASE STATION FOR ARDUINO UNO / ARDUINO MOTOR SHIELD: V-1.2.1+ / Mar  9 2020 17:50:41><N0: SERIAL>'
tx: <t 1 2 20 1>
rx:  b'<T1 20 1>'
tx: <t 1 3 20 1>
rx:  b'<T1 20 1>'
...
```

## links

https://github.com/DccPlusPlus/BaseStation/wiki/Commands-for-DCCpp-BaseStation

https://docs.python-guide.org/dev/virtualenvs/

https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/

