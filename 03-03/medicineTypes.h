#pragma once
#include "medicine.h"


/// 薬物クラスを継承し、違う薬種を定義する

class Oseltamivir : public Medicine
{
public:
	Oseltamivir() {
		name = "Oseltamivir";
		target_illness = FLU;
	}
};

class Paracetamol : public Medicine
{
public:
	Paracetamol() {
		name = "Paracetamol";
		target_illness = COLD;
	}
};

class Loratadine : public Medicine
{
public:
	Loratadine() {
		name = "ALLERGY";
		target_illness = ALLERGY;
	}
};

class Amoxicillin : public Medicine
{
public:
	Amoxicillin() {
		name = "INFECTION";
		target_illness = INFECTION;
	}
};

