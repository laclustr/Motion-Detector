# Motion Detector
Works by detecting objects within a certain distance; if they are too close, a buzzer will go off. The sensitivity can be adjusted via a rotary dial, and the system can be enabled/disabled with the press of a button. An indicator light has been added to show status of the device (enabled/disabled).

## Pinout Scheme
```
  LED Pin - 6
  Button Pin - 2
  Ultrasonic Ranger Pin - 4
  Rotary Potentiometer Pin - A2
  Buzzer Pin - 5
```

## Build Requirements
 - Platformio cli

## Build
To build the project, open it in terminal and run `platformio run --target upload --upload-port /dev/cu.usbserial-0001` (change `/dev/cu.usbserial-0001` to the correct port).

## Picture & Demo Video
![Device Picture](media/device.jpeg)

[Demo Video](media/demo.mp4)
