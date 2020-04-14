#pragma once
#include <iostream>
#include <string>
#include "GameComponent.h"

using namespace std;

enum Direction : unsigned char {
	Left = 1,
	Right = 2,
	Up = 3,
	Down = 4,
};

class DrawableGameComponent : public GameComponent {
public:
	DrawableGameComponent(int inputX, int inputY) {
		direction = Right;
		if (inputX < 0) {
			x = 0;
		}
		else if(inputX > 80) {
			x = 80;
		}
		else {
			x = inputX;
		}
		if (inputY < 0) {
			y = 0;
		}
		else if (inputY > 20) {
			y = 20;
		}
		else {
			y = inputY;
		}
	};
	Direction direction;
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_WIDTH = 80;
	void Update(const tm* eventTime) override;
private:
	void ChangeDirection();
	void Draw();
	void CalculatePosition();
	int x, y;
	string currentDirection;
};

void DrawableGameComponent::Update(const tm* eventTime) {

	GameComponent::Update(eventTime);
	//Change X or Y values based on direction
	CalculatePosition();
	Draw();
	ChangeDirection();
};

void DrawableGameComponent::ChangeDirection() {
	//assigns new direction randomly.
	int rng;

	// initialize random seed:
	srand(time(NULL));

	// generate secret number between 1 and 4:
	rng = (rand() % 4) + 1;
	Direction newDirection;

	// check if random generator number is same as current enum direction
	while (rng == direction)
		rng = (rand() % 4) + 1;
	
	// change enum direction
	direction = static_cast<Direction>(rng);

};

void DrawableGameComponent::Draw() {
	//Displays the current direction
	cout << currentDirection << " : " << "X:" << x << " Y:" << y << endl;
};

void DrawableGameComponent::CalculatePosition() {
	switch (direction) {
	case Left:
		x--;
		if (x < 0) {
			x = 0;
		}
		currentDirection = "Left";
		break;
	case Right:
		x++;
		if (x > SCREEN_WIDTH) {
			x = SCREEN_WIDTH;
		}
		currentDirection = "Right";
		break;
	case Up:
		y++;
		if (y > SCREEN_HEIGHT) {
			y = SCREEN_HEIGHT;
		}
		currentDirection = "Up";
		break;
	case Down:
		y--;
		if (y < 0) {
			y = 0;
		}
		currentDirection = "Down";
		break;
	default:
		break;
	}
}