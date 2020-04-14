#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip> // put_time

using namespace std;

class GameComponent {
public:
	GameComponent() {
		id = ++instances;
	};
	~GameComponent() {
		--id;
	}
	virtual void Update(const tm* eventTime);
private:
	int id;
	static int instances;
};

int GameComponent::instances;

void GameComponent::Update(const tm* eventTime) {
	cout << "ID : " << id << " Updated : " << put_time(eventTime, "%X") << endl;
};
