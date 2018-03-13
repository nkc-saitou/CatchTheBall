#include "GoalObject.h"

GoalObject::GoalObject(float x, float y, int order) : Object(order){
	
	PositionX(x);
	PositionX(y);

	destroy = nullptr;

	GraphHandle(FileManager::Instance()->GetFileHandle("GoalObject.png"));

	collider = new Collision(16, 32, 32, 64, CollisionType::Square, this, [this](auto other) { OnHit(other); });

}

GoalObject::~GoalObject() {
	delete collider;
}


void GoalObject::Update() {

	//ˆÚ“®
	float movespeed = 100 * Time::GetDeltaTime();
	if (Input::Instance()->Button(KEY_INPUT_D)) {
		PositionX(PositionX() + movespeed);
	}

	if (Input::Instance()->Button(KEY_INPUT_A)) {
		PositionX(PositionX() - movespeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_W)) {
		PositionY(PositionY() - movespeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_S)) {
		PositionY(PositionY() + movespeed);
	}

	//‰ñ“]
	float rotSpeed = 1.5f * Time::GetDeltaTime();
	if (Input::Instance()->Button(KEY_INPUT_Q)) {
		Rotation(Rotation() + rotSpeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_E)) {
		Rotation(Rotation() - rotSpeed);
	}

	//Šg‘å
	float scaleSpeed = 1.5f * Time::GetDeltaTime();
	if (Input::Instance()->Button(KEY_INPUT_SPACE)) {
		Scale(Scale() + scaleSpeed);
	}
	if (Input::Instance()->Button(KEY_INPUT_LSHIFT)) {
		Scale(Scale() - scaleSpeed);
	}

	if (destroy) {
		delete destroy;
		destroy = nullptr;
	}
}

void GoalObject::OnHit(Collision *other) {

	auto obj = other->getObject();
	if (obj->GetTag() == FireworkObject::GetTagName()) {
		delete obj;
	}

}