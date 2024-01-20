#pragma once
#include <iostream>

namespace eon {
	class Entity {
	public:
		Entity (int _id) :
			id(_id) {}

		virtual void displayID()
			{ std::cout << "Entity ID: " <<  id << "\n"; };

	protected:
		int id = 0;
		// position
		// render
	};

	class PhysicsEntity : public Entity {
	public:
		PhysicsEntity (int _id) :
			Entity(_id) {}

		void displayID() 
			{ std::cout << "PhysicsEntity ID: " << id << "\n"; };

	protected:
		// physics
	};

	class Player : public PhysicsEntity {
	public:
		Player (int _id) :
			PhysicsEntity (_id) {}

		void displayID() 
			{ std::cout << "Player ID: " << id << "\n"; };

	private:
		// player input
	};

	class Zombie : public PhysicsEntity {
	public:
		Zombie(int _id) :
			PhysicsEntity(_id) {}

		void displayID()
			{ std::cout << "Zombie ID: " << id << "\n"; };
	private:
		// ai imput
	};
}