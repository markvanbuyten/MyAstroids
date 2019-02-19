#pragma once

#include "SDL/include/SDL/SDL.h"
#include <unordered_map>
#include <string>
#include <vector>

class Game
{
public:
	Game();

	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	SDL_Texture* GetTexture(const std::string& fileName);

	//Astroid Game-specific
	void AddAsteroid(class Astroid* asteroid);
	void RemoveAsteroid(class Astroid* asteroid);
	std::vector<class Astroid*>& GetAstroid() { return mAsteroids; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	//Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	//All actors in the game
	std::vector<class Actor*> mActors;

	//Any pending actors
	std::vector<class Actor*> mPendingActors;

	//All the sprite components drawn
	std::vector<class SpriteComponents*> mSprites;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;

	//Track if the game is updating actors right now
	bool mUpdatingActors;

	//Astroid Game-specifics
	class Ship* mShip;
	std::vector<class Asteroid*> mAsteroids;

};