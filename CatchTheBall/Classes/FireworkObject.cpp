#include "FireworkObject.h"

FireworkObject::FireworkObject() {
	force = 0;
	moveVecX = 0;
	moveVecY = 0;

	_t = 0;

	playEffectType = EffectType::ExplosionFireworkClear;
	CheckEffect();
	
	GraphHandle(FileManager::Instance()->GetFileHandle("Ball.png"));

	collider = new Collision(16, 16, 32, 32, CollisionType::Circle, this, [this](Collision* other) { OnHit(other); });

}


FireworkObject::~FireworkObject() {
	delete collider;
}

void FireworkObject::Update() {

	_t += Time::GetDeltaTime();
	if (_t > 5) return;

	float prevX = PositionX();
	float prevY = PositionY();

	float nextX = prevX;
	float nextY = prevY;

	//重力の更新
	ObjGravity();
	nextY += Fall_y();

	//移動後の位置を計算
	nextX += moveVecX * force * Time::GetDeltaTime();
	nextY += moveVecY * force * Time::GetDeltaTime();

	PositionX(nextX);
	PositionY(nextY);

	//向き計算
	if (child != nullptr) {

		VECTOR in;
		in.x = nextX - prevX;
		in.y = nextY - prevY;
		in.z = 0;

		VECTOR out;

		VectorNormalize(&out, &in);

		auto sita = acos(out.x);
		auto rot = sita * 180.0 / 3.141519;
		if (in.y < 0) rot += 180;
		child->Rotation(rot);
	}
}

void FireworkObject::SetForce(float force, float moveVecX, float moveVecY) {
	FireworkObject::moveVecX = moveVecX;
	FireworkObject::moveVecY = moveVecY;
	FireworkObject::force = force;

	//重力をリセット
	GravityReset();
	
	CheckEffect();
}

void FireworkObject::CheckEffect() {

	EffectType type;
	if (force < 10) {
		type = EffectType::FireworkTrailLv1;
	}
	else if (force < 20) {
		type = EffectType::FireworkTrailLv2;
	}
	else {
		type = EffectType::FireworkTrailLv3;
	}

	if (type == playEffectType) return;
	playEffectType = type;

	if (child != nullptr) delete child;
	child = EffectManager::CreateEffect(playEffectType, 0, 0, false);
	child->Parent(this);
	child->SetLocalPosition(16, 16);
}

void FireworkObject::OnHit(Collision *other) {

	if (other->getObject()->GetTag() == "Wall") {
		//壁にヒットした場合はゲームオーバー

	}
}