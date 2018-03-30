# DHT11-webapp

This app is an Arduino and Node.js combination that uses DHT11 temperature sensor in order to display temperature and humidity in real-time.

![Screenshot](https://i.imgur.com/1fBCIFE.png)

The Arduino part of this project was developed on PlatformIO, therefore I'm not sure whether this is going to work on the original Arduino IDE.

This project was tested and developed on Arduino Uno board. However, it should work on any other Ardiono board.

## Setup
- Connect DHT11 to your Arduino board digital pin 2 (if you want to connect it to a different pin, edit the `DHT_PIN` constant in `src/main.cpp`)
- Compile and upload the code to your Arduino board
- Install node packages - `yarn` or `npm i`
- Edit `config.json` to match your serial connection location and the HTTP port
- Launch the app by running `node main.js` in the terminal

## Used libraries
- https://github.com/bblanchon/ArduinoJson
- https://github.com/markruys/arduino-DHT
