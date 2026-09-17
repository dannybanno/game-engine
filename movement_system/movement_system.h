


class movementSystem {

private:


public:

	void update(std::vector<Entity>& entityList, double deltaTime) {
		for (auto& ent : entityList) {
			ent.getTransform().setTransformX(ent.getTransform().getTransformX() + ent.getVelocity()[0] * deltaTime);
			ent.getTransform().setTransformY(ent.getTransform().getTransformY() + ent.getVelocity()[1] * deltaTime);

			std::cout << "X: " << ent.getTransform().getTransformX() << std::endl;
			std::cout << "Y: " << ent.getTransform().getTransformY() << std::endl;
		}
	}

};