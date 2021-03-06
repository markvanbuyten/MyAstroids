#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game * game)
	:Actor(game)
	,mCircle(nullptr)
{
	Vector2 randomPosition = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));

	SetPosition(randomPosition);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	SpriteComponent* spriteComp = new SpriteComponent(this);
	spriteComp->SetTexture(game->GetTexture("Assets/Asteroid.png"));

	MoveComponent* moveComp = new MoveComponent(this);
	moveComp->SetForwardSpeed(150.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}
