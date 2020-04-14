#pragma once
#include <iostream>
#include "GameComponent.h"
#include <string>

using namespace std;

enum Direction : unsigned char {
	Left,
	Right,
	Up,
	Down
};

class DrawableGameComponent : public GameComponent {
public:
	DrawableGameComponent(int inputX, int intputY) {
		direction = Right;
		x = inputX;
		y = intputY;
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
	
protected:
	
};

void DrawableGameComponent::Update(const tm* eventTime) {

	GameComponent::Update(eventTime);
	CalculatePosition();
	Draw();


	ChangeDirection();
};

void DrawableGameComponent::ChangeDirection() {
	//assigns a new random direction to the direction data member. This direction must be different to the current direction.
	int randomNumber;

	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 4: */
	randomNumber = rand() % 4 + 1;
	//TO DO Change direction depending on number

};

void DrawableGameComponent::Draw() {
	//Displays the current direction along with the x and y values on the same line.
	cout << currentDirection << " : " << "X:" << x << " Y:" << y << endl;
};

void DrawableGameComponent::CalculatePosition() {
	switch (direction) {
	case Left:
		x--;
		currentDirection = "Left";
		break;
	case Right:
		x++;
		currentDirection = "Right";
		break;
	case Up:
		y++;
		currentDirection = "Up";
		break;
	case Down:
		y--;
		currentDirection = "Down";
		break;
	default:
		break;
	}
}