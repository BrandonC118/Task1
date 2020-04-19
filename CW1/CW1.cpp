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

