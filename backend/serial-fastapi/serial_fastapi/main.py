import serial
from time import sleep
import time
import json
from fastapi import FastAPI

app = FastAPI()

sleep(5)


@app.get("/sqm")
async def sqm():
    sleep(0.5)
    ser = serial.Serial("/dev/ttyACM0", 9600)
    print(time.time())
    output = []
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    sleep(1)
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    sleep(1)
    output.append(json.loads(ser.readline().decode("utf-8").strip()))
    return {"data": output}
