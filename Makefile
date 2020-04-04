SOURCE=main.ino
all:
	arduino --upload $(SOURCE) --port /dev/ttyUSB*
