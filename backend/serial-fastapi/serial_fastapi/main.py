import serial
from time import sleep
import time
import json
from flask import Flask

app = Flask(__name__)

ser = serial.Serial("/dev/ttyACM0", 9600)

@app.route("/sqm")
def sqm():
    sleep(3)
    print(time.time())
    output = []
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    sleep(1)
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    sleep(1)
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    print(output)
    return {"data": output}
