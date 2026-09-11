


class movementSystem {

private:


public:

	void update(std::vector<Entity>& entityList, double deltaTime) {
		for (auto& ent : entityList) {
			ent.setPosX(ent.getTransformX() + ent.getVelocity()[0] * deltaTime);
			ent.setPosY(ent.getTransformY() + ent.getVelocity()[1] * deltaTime);

			std::cout << "X: " << ent.getTransformX() << std::endl;
			std::cout << "Y: " << ent.getTransformY() << std::endl;
		}
	}

};