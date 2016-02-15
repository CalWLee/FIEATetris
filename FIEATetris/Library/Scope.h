#pragma once
#include "Hashmap.h"
#include "Datum.h"

namespace Library
{
	/**
	Scope class. 
	
	Takes name from the programming Scope where data can and cannot exist.

	A table of Datums (See datum definition) that can add and remove data at runtime instead of at compile time. 
	Used a foundation for scripting language.

	In this Engine, Scopes are are particularly useful since this is the most basic of types in the designed hierarchy,
	and enable Runtime Type Information.
	*/
	class Scope : public RTTI
	{

		RTTI_DECLARATIONS(Scope, RTTI);

	public:


		/**
		Constructor
		*/
		explicit Scope(std::uint32_t size = 0);

		/**
		Destructor
		*/
		virtual ~Scope();

		/**
		Copy constructor
		*/
		Scope(const Scope& rhs);

		/**
		Assignment operator
		*/
		Scope& operator=(const Scope& rhs);

		/**
		Return a reference to the datum associated with a given name if it exists. otherwise, create a new datum
		*/
		Datum& Append(const std::string& name);

		/**
		Add a scope (datum table) to the scope. If it alraedy exists, return that one
		*/
		Scope& AppendScope(const std::string& name);

		/**
		Find a reference to a datum associated with a given name
		*/
		Datum* Find(const std::string& name) const;

		/**
		Get the address of the most closely related ancestor of our scope
		*/
		Datum* Search(const std::string& name, Scope** address = nullptr);

		/**
		Take a reference to a scope, a name, and an index, and place a child wiht these properties into our table
		*/
		void Adopt(Scope* newChild, const std::string& name, std::uint32_t index);


		/**
		Return the address of the scope which contains this one
		*/
		Scope* GetParent() const;

		/**
		A syntacticly convenient wrapper for append
		*/
		Datum& operator[](const std::string& name);

		/**
		Get a reference to a datum by index
		*/
		Datum& operator[](std::uint32_t index);

		/**
		Equality operator
		*/
		bool operator==(const Scope& rhs) const;

		/**
		Not equal operator
		*/
		bool operator!=(const Scope& rhs) const;

		/**
		Return the name of a scope at a constant address
		*/
		std::string FindName(const Scope* toName) const;

		/**
		Remove references from parent
		*/
		void Orphan();

		/**
		Delete everything
		*/
		void Clear();

		/**
		Get the number of name datum pairs we currently contain

		@return the size of the order vector
		*/
		std::uint32_t Size();
		
		Vector<std::pair<std::string, Datum>*>::Iterator begin() const;
		Vector<std::pair<std::string, Datum>*>::Iterator end() const;

	protected:
		/**
		Hashmap used to store data
		*/
		Hashmap<std::string, Datum> mHashMap;

		/**
		Vector used to store pointers to data and access it by index
		*/
		Vector<std::pair<std::string, Datum>*> mOrderVector;

		/**
		Pointer to our parent scope
		*/
		Scope* mParent;

	};
}