import util
import datasender as datasender

util.activate_wlan()
print("Device A")
print(util.get_mac())

print("Sending forever to {}".format(util.mac_address_b))
datasender.send_forever(util.mac_address_b)
