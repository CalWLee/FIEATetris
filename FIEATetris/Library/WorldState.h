#pragma once
#include "GameTime.h"
/**
	World State provides information to any interested classes.
	Interested Classes range from Worlds, Sectors, Entities, Actions, and all derived sub classes

	In a broader sense, WorldState is the means for different instances of World and etc. to communicate with each other.
	All the afformentioned classes a Subscribed to an EventQueue and upon an Event Dispatch
	receives all the relvant information regarding changes between classes.
*/
namespace Library
{
	//Forward declarations
	class World;
	class Sector;
	class Entity;
	class Action;

	class WorldState
	{

	public:
		/**
		Constructor
		*/
		WorldState();

		/**
		Destructor
		*/
		~WorldState();

		/**
		Get our gametime object
		*/
		GameTime& GetGameTime();

		/**
		Const version of getter for game time
		*/
		const  GameTime& GetGameTime()  const;

		/**
		Set our current time
		*/
		void SetGameTime(const GameTime& newTime);

		/**
		Getter for current world
		*/
		World* GetWorld() const;

		/**
		Setter for current world
		*/
		void SetWorld(World* newWorld);

		/**
		Getter for current sector
		*/
		Sector* GetSector() const;


		/**
		Setter for current sector
		*/
		void SetSector(Sector* newSector);

		/**
		Getter for current entity
		*/
		Entity* GetEntity() const;


		/**
		Setter for current entity
		*/
		void SetEntity(Entity* newEntity);

	private:
		/**
		Opaque pointer to the current World
		*/
		World* mCurWorld;

		/**
		Opaque pointer to the current Sector
		*/
		Sector* mCurSector;
		
		/**
		Opaque pointer to the current Entity
		*/
		Entity* mCurEntity;

		/**
		Opaque pointer to the current Action
		*/
		Action* mCurAction;

		/**
		Current game time object
		*/
		GameTime mTime;
	};
}