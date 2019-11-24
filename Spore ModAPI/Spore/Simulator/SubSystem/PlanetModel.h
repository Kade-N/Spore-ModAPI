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
#include <Spore\Simulator\cCity.h>
#include <Spore\MathUtils.h>

namespace Simulator
{
	using namespace Math;

	//sizeof 0x13208
	class cPlanetModel
		: public cStrategy
	{
	public:
		//TODO PLACEHOLDER

		// 24h.func0Ch() -> GetTerrainMapSet()

		// B7DC40 Get water level?

		/// Returns true if the given position is above or inside the water mass in the planet.
		/// To be exact, this method returns true if the water level is greater than GetHeightAt(position)
		bool IsInWater(const Vector3& position);

		cCity* GetNearestCity(const Vector3& position);

		/// Returns the position in the surface of the planet that is aligned with the center of the planet
		/// and the given position.
		Vector3 ToSurface(const Vector3& position);
		
		float GetHeightAt(const Vector3& position);

		/// Returns the gravity acceleration used. If the game is on the scenario mode, the 'scenarioGravity' will
		/// used. Otherwise, it returns -9.8
		float GetGravity() const;

		Vector4 GetOrientation(const Vector3& position, const Vector3& direction) const;

	public:
		static cPlanetModel* Get();
	};

	inline cPlanetModel* PlanetModel() {
		return cPlanetModel::Get();
	}

	namespace Addresses(cPlanetModel)
	{
		DeclareAddress(Get);

		DeclareAddress(IsInWater);
		DeclareAddress(GetNearestCity);
		DeclareAddress(ToSurface);
		DeclareAddress(GetGravity);
		DeclareAddress(GetHeightAt);
		DeclareAddress(GetOrientation);
	}
}