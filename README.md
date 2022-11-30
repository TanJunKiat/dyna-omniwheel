# Dyna-omniwheel

<img src="https://github.com/TanJunKiat/dyna-omniwheel/blob/main/images/isoview.jpeg" width=50% height=50%>


## Description
We are sharing a omniwheel land rover that is capable of independent forward and sideward motion, and the ability to rotation on the spot. Unlike a conventional land rover that operates like car, a omniwheel system is highly manuverable and agile, suitable for position-critical operations. We use dynamixels for the precision and the reliability in terms of performance and the convenience of using a dynamixel shield coupled with the library to control the servos.

## Components
* [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3)
* [Dynamixel Shield](https://www.robotis.us/dynamixel-shield/)
* [Buck boost converter](https://www.amazon.com/ALAMSCN-Automatic-Converter-Regulator-Charging/dp/B0B96WH3DJ/ref=sr_1_39_sspa?crid=OKW9E5B8RTVA&keywords=buck+boost+converter&qid=1669705482&sprefix=buck+boost+conver%2Caps%2C659&sr=8-39-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzTjE1QjNKUTVJSzlIJmVuY3J5cHRlZElkPUEwMTk1Nzk0MVRIWTZHQkdINDhLWSZlbmNyeXB0ZWRBZElkPUEwMzQ2Mjg5MldTOFhYRU1JTklRMSZ3aWRnZXROYW1lPXNwX210ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
* [Dynamixel XL430-W250-T](https://www.robotis.us/dynamixel-xl430-w250-t/)
* [Omniwheels - 80mm](https://item.taobao.com/item.htm?spm=a230r.1.14.16.2e026ebbaeszDv&id=625248821045&ns=1&abbucket=4#detail)
* [Zippy lipo battery](https://hobbyking.com/en_us/zippy-compact-1400mah-4s-65c-lipo-pack-w-xt60.html)
* [Spektrum RC AR8010T](https://www.amazon.sg/Spektrum-8-Channel-Integrated-Telemetry-Receiver/dp/B01LWQ1OL7)

## Software pre-requisite
* Arduino IDE
* Dynamixel library from Arduino

## Setup instructions 
### Arduino

<img src="https://github.com/TanJunKiat/dyna-omniwheel/blob/main/images/connection.jpeg" width=100% height=100%>

Initialisation
* The servos are initialised to 1Mbps and ID 1 to 4 (ID 1 - FORWARD-RIGHT, ID 2 - BACKWARD-LEFT, ID 3 - FORWARD-LEFT, ID 4 - BACKWARD RIGHT)

Power distribution
* We used a 4 cell Lipo battery with a step-down buck converter to ensure a consistent voltage to the Arduino and the servos (operating voltage of 11.1V norminal)
* Please ensure that the Arduino that you are using has a voltage regulator built within the board
* The output of the buck converter is connected to the Vin and GND pins of the Arduino Dynamixel shield to power both the shield and the controller
* The receiver is powered via the 5V output from the Arduino

Communication
* The Arduino reads PWM from the receiver; each channel of the receiver corresponds to one command (forward-backward, leftward-rightward, yaw)
* The Dynaxmiel shield output TTL signals to the servos and command a certain velocity depending on the command given by the user.

## Operation

<img src="https://github.com/TanJunKiat/dyna-omniwheel/blob/main/images/operation.jpeg" width=100% height=100%>

## Troubleshooting

Q: Not all the dynamixel are spinning when the system is powered on

A: Try pressing the reset button on the Arduino. This behaviour might be due to the disparity between the servo powering up and the intialisation of the servos from Arduino

Q: The system is able to go forward and backwards, but is unable to go sidewards

A: Try to match the orientation of the small rollers of the omniwheels with the figures above, the roller orientations matter for sidewards motion

## Appendix

### Dynamics

$$ \begin{bmatrix}
v_{xd}\\
v_{yd}\\
\psi_d
\end{bmatrix} = \begin{bmatrix}
1 & 1 & 1 & 1 \\
1 & 1 & -1 & -1 \\
1 & -1 & -1 & 1 \\
\end{bmatrix}\begin{bmatrix}
\omega_1 d \\
\omega_2 d \\
\omega_3 d \\
\omega_4 d \\
\end{bmatrix}$$
Where $ v_{xd} $ is the desired forward speed, $ v_{yd} $ is the desired leftward speed,and $ \psi_d $ is the desired yaw rate.
## Contact
Tan Jun Kiat (junkiat@hotmail.com)
