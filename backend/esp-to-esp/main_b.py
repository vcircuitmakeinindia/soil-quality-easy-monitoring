import util
import datasender as datasender

util.activate_wlan()
print("Device B")
print(util.get_mac())

print("Receiving forever...")
datasender.receive_forever()
