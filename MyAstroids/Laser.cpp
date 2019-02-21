#include "Laser.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Asteroid.h"

Laser::Laser(Game * game)
	:Actor(game)
	,mDeathTimer(1.0f)
{
	SpriteComponent* sprite = new SpriteComponent(this);
	sprite->SetTexture(game->GetTexture("Assets/Laser.png"));

	MoveComponent* moveComp = new MoveComponent(this);
	moveComp->SetForwardSpeed(11.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.f);
}

void Laser::UpdateActor(float deltaTime)
{
	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		for (auto asteroid : GetGame()->GetAstroids())
		{
			if (Intersect(*mCircle, *(asteroid->GetCircle())))
			{
				SetState(EDead);
				asteroid->SetState(EDead);
				break;
			}
		}
	}
}
