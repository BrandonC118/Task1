// CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include <iostream>



void Initialise() {
	cout << "Initialising Game" << endl;
};

void Terminate() {
	cout << "Terminating Game" << endl;
};


int main()
{
	Game game(10);
	GameComponent *gc;
	DrawableGameComponent *dgc;
	gc = new GameComponent();
	dgc = new DrawableGameComponent(-2, -2);

	//Initialise
	game.SetInitialise(*Initialise);
	game.SetTerminate(*Terminate);

	//Add components
	game.Add(gc);
	game.Add(dgc);

	//Run Game
	game.Run();

	//Break down components
	gc->~GameComponent();
	dgc->~DrawableGameComponent();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
