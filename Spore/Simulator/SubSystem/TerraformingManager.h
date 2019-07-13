/****************************************************************************
* Copyright (C) 2019 Eric Mor
*
* This file is part of Spore ModAPI.
*
* Spore ModAPI is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
#pragma once

#include <Spore\Simulator\SubSystem\cStrategy.h>
#include <Spore\Simulator\cPlanetRecord.h>
#include <EASTL\hash_map.h>
#include <EASTL\map.h>
#include <EASTL\vector.h>

namespace Simulator
{
	class cCommodityNode;  //PLACEHOLDER

	class cTerraformingManager
		: public cStrategy
	{
	public:
		
		/// Returns the TScore of the current planet, or the planet specified in the parameter.
		/// The TScore is calculated using the planet atmosphere and temperature scores.
		int GetTScore(const cPlanetRecord* pPlanet = nullptr);

		int CalculateTScore(float atmosphereScore, float temperatureScore);

	protected:
		/* 1Ch */	hash_map<int, int> field_1C;
		/* 3Ch */	bool field_3C;  // true
		/* 40h */	int field_40;  // -1
		/* 44h */	bool field_44;
		/* 48h */	map<int, int> field_48;
		/* 64h */	int field_64;
		/* 68h */	vector<intrusive_ptr<cCommodityNode>> mCommodityNodes;
		/* 7Ch */	int field_7C;
		/* 80h */	int field_80;
		/* 84h */	int field_84;
		/* 88h */	int field_88;
		/* 8Ch */	int field_8C;
		/* 90h */	int field_90;

	public:
		static cTerraformingManager* Get();
	};

	inline cTerraformingManager* TerraformingManager() {
		return cTerraformingManager::Get();
	}

	/////////////////////////////////
	//// INTERNAL IMPLEMENTATION ////
	/////////////////////////////////

	static_assert(sizeof(cTerraformingManager) == 0x94, "sizeof(cTerraformingManager) != 94h");

	namespace Addresses(cTerraformingManager)
	{
		DeclareAddress(Get, SelectAddress(0xB3D390, NO_ADDRESS, 0xB3D530));

		DeclareAddress(GetTScore, SelectAddress(0xBBB750, NO_ADDRESS, 0xBBC7E0));
		DeclareAddress(CalculateTScore, SelectAddress(0xFC2760, NO_ADDRESS, 0xFC2040));
	}
}