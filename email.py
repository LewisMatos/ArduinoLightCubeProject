import serial, sys, feedparser

#Settings - Change these to match your account details
USERNAME="Enter your email here"
PASSWORD=" enter your password here"
PROTO="https://"
SERVER="mail.google.com"
PATH="/gmail/feed/atom"

SERIALPORT = "COM7" # Change this to your serial port!

# Set up serial port
try:
    ser = serial.Serial("COM7", 9600)
except serial.SerialException:
    sys.exit()

newmails = int(feedparser.parse(
    PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH
)["feed"]["fullcount"])

ser.write('M')
# Output data to serial port
if newmails > 0: ser.write('M')
else: ser.write('N')

# Close serial port
ser.close()
