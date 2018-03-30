const SerialPort = require('serialport')
const ReadLine = SerialPort.parsers.Readline
const app = require('express')()
const http = require('http').Server(app)
const io = require('socket.io')(http)
const config = require('./config')

let parser = new ReadLine() // Initialise SerialPort parser
let port = new SerialPort(config.serial_port, {
  baudRate: 9600
})
port.pipe(parser) // Assign ReadLine parser to SerialPort instance

// Set initial data
let serialData = {
  temperature: 0,
  humidity: 0
}

parser.on('data', (data) => {
  serialData = JSON.parse(data.trim()) // Parse buffer data as JSON
  io.emit('data', serialData) // Emit data to all connections
})

// Once a new connection is made, send serialData
io.on('connection', () => {
  io.emit('data', serialData)
})

// Create HTTP server
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/www/index.html')
})
http.listen(config.http_port)
