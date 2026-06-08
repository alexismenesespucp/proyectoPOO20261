#pragma once

using namespace System;
using namespace System::Drawing;

namespace Model {
	public ref class eslabon
	{
	public:
		float longitud;
		float angulo;
		PointF origen;
		PointF extremo;

		eslabon(float longitud, float angulo) {
			this->longitud = longitud;
			this->angulo = angulo;
		}
		// TODO: Add your methods for this class here.
		void actualizar(PointF nuevoOrigen) {
			this->origen = nuevoOrigen;
			this->extremo.X = this->origen.X + this->longitud * Math::Cos(angulo);
			this->extremo.Y = this->origen.Y + this->longitud * Math::Sin(angulo);
		}
	};
}