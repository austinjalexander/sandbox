#include <iostream>
#include <string>

using namespace std;

// sensors
class SensorRoom {
	SensorRoom();
	string room = " ";

	set

};
string sensor_room(string room) {
	cin >> room;
	return room;
}
string sensor_cleanliness(string cleanliness) {
	cin >> cleanliness;
	return cleanliness;
}
// activate sensors
string activate_sensors(string room, string cleanliness) {
	return room + "." + cleanliness;
}
// find rule
int

int main() {

	string room = " ", cleanliness = " ";

	room = sensor_room(room);
	cleanliness = sensor_cleanliness(cleanliness);

	activate_sensors(room, cleanliness);


	return 0;
}