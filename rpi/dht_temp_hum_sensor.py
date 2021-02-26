import time
import board
import adafruit_dht

# Initial the dht device, with data pin connected to:
#dhtDevice = adafruit_dht.DHT22(board.D4)

# you can pass DHT22 use_pulseio=False if you wouldn't like to use pulseio.
# This may be necessary on a Linux single board computer like the Raspberry Pi,
# but it will not work in CircuitPython.
dhtDevice = adafruit_dht.DHT22(board.D4, use_pulseio=False)

#new .txt file created with header
file = open('sensor_readings.txt', 'w')
file.write('time and date, temperature (C),temperature (F), humidity\n')

#create a variable to control the while loop
running = True

while running:
    try:
        # Print the values to the serial port
        temperature_c = dhtDevice.temperature
        temperature_f = round(temperature_c * (9.0/ 5.0) + 32.0 , 1)
        humidity = dhtDevice.humidity
        print(
            "Temp: {:.1f} F / {:.1f} C    Humidity: {}% ".format(
                temperature_f, temperature_c, humidity
            )
        )
        #save time, date, temperature in Celsius, temperature in Fahrenheit and humidity in .txt file
        file.write(time.strftime('%H:%M:%S %d/%m/%Y') + ', ' + str(temperature_c) +
                   ', '+ str(temperature_f)+',' + str(humidity) + '\n')

    except RuntimeError as error:
        # Errors happen fairly often, DHT's are hard to read, just keep going
        print(error.args[0])
        time.sleep(1.0)
        continue
    except Exception as error:
        dhtDevice.exit()
        raise error
    except KeyboardInterrupt:
        print ('Program stopped')
        running = False
        file.close()

    time.sleep(1.0)
