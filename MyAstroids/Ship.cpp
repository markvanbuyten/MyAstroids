#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"

Ship::Ship(Game * game)
	:Actor(game)
	,mLaserCooldown(0.0f)
{
	SpriteComponent* spriteComp = new SpriteComponent(this, 150);
	spriteComp->SetTexture(game->GetTexture("Assets/Ship.png"));

	InputComponent* inputComp = new InputComponent(this);
	inputComp->SetForwardKey(SDL_SCANCODE_W);
	inputComp->SetBackKey(SDL_SCANCODE_S);
	inputComp->SetClockwiseKey(SDL_SCANCODE_A);
	inputComp->SetCounterClockwiseKey(SDL_SCANCODE_D);
	inputComp->SetMaxForwardSpeed(300.0f);
	inputComp->SetMaxAngularSpeed(Math::TwoPi);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t * keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
	{
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		mLaserCooldown = 0.5f;
	}
}
