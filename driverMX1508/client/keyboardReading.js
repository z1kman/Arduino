const { SerialPort }= require('serialport'); 
const keypress = require('keypress');

const port = new SerialPort( {
  path: 'COM6',
  baudRate: 9600,
  autoOpen: false,
});

let debounceTimer;


port.open((err) => {
  if (err) {
    return console.log('Error opening port:', err.message);
  }
  console.log('Port opened successfully');
});


keypress(process.stdin);
process.stdin.setRawMode(true);
process.stdin.resume();

process.stdin.on('keypress', (ch, key) => {
  if (key) {

    if (key.name === 'escape') {
      port.close((err) => {
        if (err) {
          console.log('Error closing port:', err.message);
        } else {
          console.log('Port closed');
        }
      });
      process.exit();
    }
 
    if (key.name === 'up') {
      port.write('UP\n');
      clearTimeout(debounceTimer);
      console.log('Sent: UP');
    } else if (key.name === 'down') {
      port.write('DOWN\n');
      console.log('Sent: DOWN');
    } else if (key.name === 'left') {
      port.write('LEFT\n');
      console.log('Sent: LEFT');
    } else if (key.name === 'right') {
      port.write('RIGHT\n');
      console.log('Sent: RIGHT');
    }
    debounceTimer = setTimeout(() => {
      port.write('STOP\n');
      console.log('Sent: STOP');
    }, 500);
  }
});