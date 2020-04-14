#pragma once
#include <iostream>
#include "GameComponent.h"
#include <chrono>  // chrono::system_clock
#include <thread>  // std::this_thread::sleep_for

using namespace std;

class Game {
public:
	Game(int maxComponents) {
		this->maxArrayCount = maxComponents;
	};
	void Add(GameComponent* gameComponent);
	void Run();
	void SetInitialise(void (*init)());
	void SetTerminate(void(*term)());
private:
	int componentCount = 0;
	int maxArrayCount; //not included in class diagram - Refactor purposes
	GameComponent* components[10];
	void (*initialise)();
	void (*terminate)();
	void TimerSleep(int tick); //not included in class diagram - Refactor purposes
	tm* GetSystemTime(); //not included in class diagram - Refactor purposes
	const int TICKS_1000MS = 1000;
	const int MAX_UPDATES = 5; //not included in class diagram - Refactor purposes
	
};

void Game::Add(GameComponent* gameComponent) {
	cout << "Adding Component" << endl;
	//Check if component count is at max
	if (componentCount != maxArrayCount) {
		components[componentCount] = gameComponent;
		componentCount++;
	}
	else {
		return;
	}
};

void Game::Run() {
	(*initialise)();
	//Iterate through 5 updates.
	for (int i = 0; i < MAX_UPDATES; i++) {
		//Iterate through each component to update.
		for (int i = 0; i < componentCount; i++) {
			tm* time = GetSystemTime();
			components[i]->Update(time);
			
		}
		TimerSleep(TICKS_1000MS);
	}
	(*terminate)();
};

void Game::SetInitialise(void (*init)()) {
	cout << "Setting Initialise" << endl;
	initialise = *init;
};

void Game::SetTerminate(void (*term)()) {
	cout << "Setting Terminate" << endl;
	terminate = *term;
};

tm* Game::GetSystemTime() {
	//Grabs current time on your system.
	auto currentTime = chrono::system_clock::now();
	auto inTimeT = chrono::system_clock::to_time_t(currentTime);
	tm* time = localtime(&inTimeT);
	return time;
};

void Game::TimerSleep(int tick) {
	//Sleeps for tick amount in ms
	chrono::milliseconds sleep(tick);
	this_thread::sleep_for(sleep);
}