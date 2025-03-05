#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
*  autor: Leontev Valera Romanovith
*
* brief: The code is fully functional and works according
*		to the task conditions, it has all the requirements listed
*		in the task such as (Constructors, checks, operations,
*		Menu - with functionality for Adding engines, displaying all engines,
*		deleting by index, comparing by index, and exiting the program)
*		a lot of this task had to be searched for on the Internet,
*		also asking GPT since it was very difficult to understand
*		the implementation of the menu. But I also took information
*		with pointers and vectors from the book
*/

// Engine class
class Engine {

private:

	int SerialNumber; // Serial number

	string CombinedPistonEngine; // Engine type! for work, its internal part.

public:

	Engine() {

		this->SerialNumber = 1;
		this->CombinedPistonEngine = "Not-Announced";

	}

	Engine(int SerialNumber, string CombinedPistonEngine) {

		if (SerialNumber > 0 and SerialNumber <= 20000) { // works if the serial number is greater than 0 and not greater than 20000

			this->SerialNumber = SerialNumber;
			this->CombinedPistonEngine = CombinedPistonEngine;
		}
		else {
			cout << "Sorry, the program cannot continue to work if the entered value is 0 or 20000!" << endl;

			this->SerialNumber = 1;
			this->CombinedPistonEngine = "Not-Announced";
		}
	}

	// Getters
	int GetSerialNumber() { return SerialNumber; }
	string GetCombinedPistonEngine() { return CombinedPistonEngine; }

	// Setters
	void SetSerialNumber(int value) { SerialNumber = value; }
	void SetCombinedPistonEngine(string value) { CombinedPistonEngine = value; }

	// Less than operator!
	bool operator < (const Engine& other) {

		return ((this->SerialNumber) < (other.SerialNumber));
	}

	// Greater than operator!
	bool operator > (const Engine& other) {

		return ((this->SerialNumber) > (other.SerialNumber));
	}

	// Equal to operator!
	bool operator == (const Engine& other) {

		return ((this->SerialNumber) == (other.SerialNumber));
	}

	// Increment operator!
	Engine& operator ++ () {
		SerialNumber++;

		return *this;
	}

	Engine& operator ++ (int value) {
		Engine temp(*this);
		this->SerialNumber++;
		return *this;
	}

	virtual void PrintInfo() {
		cout << "Engine #" << SerialNumber << endl;
		cout << "Type: " << CombinedPistonEngine << endl;

	}
};

// Internal combustion engine class
class InternalCombustionEngine : public Engine {

private:

	int Volume; // Engine volume

	string Carrier; // carrier what type of equipment will pull such an engine

public:

	InternalCombustionEngine() : Engine() {

		this->Volume = 999;
		this->Carrier = "Not-Announced";

	}

	InternalCombustionEngine(int SerialNumber, string CombinedPistonEngine, int Volume, string Carrier) : Engine(SerialNumber, CombinedPistonEngine) {

		if (Volume >= 999 and Volume <= 25480) {

			this->Volume = Volume;
			this->Carrier = Carrier;

		}
		else {
			cout << "Sorry, the program cannot continue to work if the entered value is 998 or 25481!" << endl;

			this->Volume = 999;
			this->Carrier = "Not-Announced";
		}
	}

	// Getters
	int GetVolume() { return Volume; }
	string GetCarrier() { return Carrier; }

	// Setters
	void SetVolume(int value) { Volume = value; }
	void SetCarrier(string value) { Carrier = value; }

	// Less than operator!
	bool operator < (const InternalCombustionEngine& other) {

		return ((this->Volume) < (other.Volume));
	}

	// Greater than operator!
	bool operator > (const InternalCombustionEngine& other) {

		return ((this->Volume) > (other.Volume));
	}

	// Equal to operator!
	bool operator == (const InternalCombustionEngine& other) {

		return ((this->Volume) == (other.Volume));
	}

	// Increment operator!
	InternalCombustionEngine& operator ++ () {
		Volume++;

		return *this;
	}

	InternalCombustionEngine& operator ++ (int value) {
		InternalCombustionEngine temp(*this);
		this->Volume++;
		return *this;
	}

	virtual void PrintInfo() override {
		cout << "Engine #" << GetSerialNumber() << endl;
		cout << "Type: " << GetCombinedPistonEngine() << endl;
		cout << "Volume: " << Volume << endl;
		cout << "Carrier: " << Carrier << endl;

	}
};

// Diesel engine class
class DieselEngine : public InternalCombustionEngine {

private:

	float FuelConsumption; // Fuel consumption

	string ServiceLife; // Service life

public:

	DieselEngine() : InternalCombustionEngine() {

		this->FuelConsumption = 5;
		this->ServiceLife = "Not-Announced";

	}

	DieselEngine(int SerialNumber, string CombinedPistonEngine, int Volume, string Carrier, float FuelConsumption, string ServiceLife)
		: InternalCombustionEngine(SerialNumber, CombinedPistonEngine, Volume, Carrier) {

		if (FuelConsumption >= 5 and FuelConsumption <= 6.4) {

			this->FuelConsumption = FuelConsumption;
			this->ServiceLife = ServiceLife;

		}

		else {
			cout << "Sorry, the program cannot continue to work if the entered value is 4.9 or 6.5!" << endl;

			this->FuelConsumption = 5;
			this->ServiceLife = "Not-Announced";
		}
	}

	// Getters
	float GetFuelConsumption() { return FuelConsumption; }
	string GetServiceLife() { return ServiceLife; }

	// Setters
	void SetFuelConsumption(int value) { FuelConsumption = value; }
	void SetServiceLife(string value) { ServiceLife = value; }

	// Less than operator!
	bool operator < (const DieselEngine& other) {

		return ((this->FuelConsumption) < (other.FuelConsumption));
	}

	// Greater than operator!
	bool operator > (const DieselEngine& other) {

		return ((this->FuelConsumption) > (other.FuelConsumption));
	}

	// Equal to operator!
	bool operator == (const DieselEngine& other) {

		return ((this->FuelConsumption) == (other.FuelConsumption));
	}

	// Increment operator!
	DieselEngine& operator ++ () {
		FuelConsumption++;

		return *this;
	}

	DieselEngine& operator ++ (int value) {
		DieselEngine temp(*this);
		this->FuelConsumption++;
		return *this;
	}

	virtual void PrintInfo() override {
		cout << "Engine #" << GetSerialNumber() << endl;
		cout << "Type: " << GetCombinedPistonEngine() << endl;
		cout << "Volume: " << GetVolume() << endl;
		cout << "Carrier: " << GetCarrier() << endl;
		cout << "Fuel Consumption: " << FuelConsumption << endl;
		cout << "ServiceLife: " << ServiceLife << endl;

	}
};

// Jet engine class
class JetEngine : public InternalCombustionEngine {

private:

	float FuelConsumption; // Fuel consumption

	string ServiceLife; // Service life

public:

	JetEngine() : InternalCombustionEngine() {

		this->FuelConsumption = 6.6;
		this->ServiceLife = "Not-Announced";

	}

	JetEngine(int SerialNumber, string CombinedPistonEngine, int Volume, string Carrier, float FuelConsumption, string ServiceLife)
		: InternalCombustionEngine(SerialNumber, CombinedPistonEngine, Volume, Carrier) {

		if (FuelConsumption >= 6.6 and FuelConsumption <= 11.7) {

			this->FuelConsumption = FuelConsumption;
			this->ServiceLife = ServiceLife;

		}
		else {
			cout << "Sorry, the program cannot continue to work if the entered value is 6.5 or 11.7!" << endl;

			this->FuelConsumption = 6.6;
			this->ServiceLife = "Not-Announced";
		}
	}

	// Getters
	float GetFuelConsumption() { return FuelConsumption; }
	string GetServiceLife() { return ServiceLife; }

	// Setters
	void SetFuelConsumption(int value) { FuelConsumption = value; }
	void SetServiceLife(string value) { ServiceLife = value; }

	// Less than operator!
	bool operator < (const JetEngine& other) {

		return ((this->FuelConsumption) < (other.FuelConsumption));
	}

	// Greater than operator!
	bool operator > (const JetEngine& other) {

		return ((this->FuelConsumption) > (other.FuelConsumption));
	}

	// Equal to operator!
	bool operator == (const JetEngine& other) {

		return ((this->FuelConsumption) == (other.FuelConsumption));
	}

	// Increment operator!
	JetEngine& operator ++ () {
		FuelConsumption++;

		return *this;
	}

	JetEngine& operator ++ (int value) {
		JetEngine temp(*this);
		this->FuelConsumption++;
		return *this;
	}

	virtual void PrintInfo() override {
		cout << "Engine #" << GetSerialNumber() << endl;
		cout << "Type: " << GetCombinedPistonEngine() << endl;
		cout << "Volume: " << GetVolume() << endl;
		cout << "Carrier: " << GetCarrier() << endl;
		cout << "Fuel Consumption: " << FuelConsumption << endl;
		cout << "ServiceLife: " << ServiceLife << endl;

	}
};

// User menu!
void Menu() {
	vector<shared_ptr<Engine>> engines; // Vector for storing pointers to engines

	int numberUserInput;
	do {
		cout << "\n--- Menu ---" << endl;
		cout << "1. Add diesel engine" << endl; // <- Add diesel engine
		cout << "2. Add jet engine" << endl; // <- Add jet engine
		cout << "3. Show information about all engines" << endl; // <- Show information about all engines
		cout << "4. Remove engine by index" << endl; // <- Remove engine by index
		cout << "5. Compare two engines by indices" << endl; // <- Compare two engines by indices
		cout << "0. Exit" << endl;
		cout << "Choose an option: ";
		cin >> numberUserInput;

		switch (numberUserInput) {

		case 1: {
			int serialNumber, volume;
			string combinedEngineType, carrier, serviceLife;
			float fuelConsumption;

			cout << "Enter serial number (0 - 20000): "; // <-
			cin >> serialNumber;
			cout << "Enter engine type: "; // <-
			cin >> combinedEngineType;
			cout << "Enter engine volume (999 - 25480): "; // <-
			cin >> volume;
			cout << "Enter carrier: "; // <-
			cin >> carrier;
			cout << "Enter fuel consumption (5 - 6.4): "; // <-
			cin >> fuelConsumption;
			cout << "Enter service life : "; // <-
			cin >> serviceLife;

			/* make_shared<DieselEngine>(...) —
			* this function creates a new
			* object of type DieselEngine and returns
			* a smart pointer (shared_ptr) to this object.
			*/
			engines.push_back(make_shared<DieselEngine>(serialNumber, combinedEngineType, volume, carrier, fuelConsumption, serviceLife));
			cout << "Diesel engine added." << endl;
			break;
		}

		case 2: {
			int serialNumber, volume;
			string combinedEngineType, carrier, serviceLife;
			float fuelConsumption;

			cout << "Enter serial number (0 - 20000): "; // <-
			cin >> serialNumber;
			cout << "Enter engine type: "; // <-
			cin >> combinedEngineType;
			cout << "Enter engine volume (999 - 25480): "; // <-
			cin >> volume;
			cout << "Enter carrier: "; // <-
			cin >> carrier;
			cout << "Enter fuel consumption (6.6 - 11.7): "; // <-
			cin >> fuelConsumption;
			cout << "Enter service life : "; // <-
			cin >> serviceLife;

			engines.push_back(make_shared<JetEngine>(serialNumber, combinedEngineType, volume, carrier, fuelConsumption, serviceLife));
			cout << "Jet engine added." << endl;
			break;
		}

		case 4: {
			int index;
			cout << "Enter engine index to remove (starting from 0): ";
			cin >> index;

			if (index >= 0 && index < engines.size()) {
				engines.erase(engines.begin() + index); // erase -> delete // begin -> Moves the object pointer to the specified index and deletes it
				cout << "Engine removed." << endl;
			}
			else {
				cout << "Error: index out of range!" << endl;
			}
			break;
		}

		case 3: {
			cout << "\n=== Information about all engines ===" << endl;
			if (engines.empty()) { /*
									* vector has an empty() method that returns true,
									* if the vector contains no elements, and false,
									* if the vector contains at least one element
									*/
				cout << "Engine list is empty." << endl;
			}
			else {
				cout << "Total engines: " << engines.size() << endl;
				for (size_t i = 0; i < engines.size(); ++i) {
					engines[i]->PrintInfo();
				}
				cout << "-----------------------------" << endl;
			}
			break;
		}

		case 5: {
			int index1, index2;
			cout << "Enter the index of the first engine to compare (starting from 0): ";
			cin >> index1;
			cout << "Enter the index of the second engine to compare (starting from 0): ";
			cin >> index2;

			if (index1 >= 0 && index1 < engines.size() && index2 >= 0 && index2 < engines.size()) {
				if (*engines[index1] == *engines[index2]) {
					cout << "Engines are equal." << endl;
				}
				else {
					cout << "Engines are not equal." << endl;
				}
			}
			else {
				cout << "Error: one of the indices is out of range!" << endl;
			}
			break;
		}

		case 0:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}

	} while (numberUserInput != 0);
}

int main() {

	Menu();

	InternalCombustionEngine* Output_one = new InternalCombustionEngine;

	Output_one->SetSerialNumber(15);
	cout << "Serial Number -> " << Output_one->GetSerialNumber() << endl;

	Engine* OutputTwoo = dynamic_cast<Engine*>(Output_one);

	cout << "Serial Number -> " << OutputTwoo->GetSerialNumber() << endl;


}

