#pragma once
#include "eslabon.h";

using namespace System;
using namespace System::Collections::Generic;


namespace Model {
	public ref class cadenaCinematica
	{
	public:
		List<eslabon^>^ eslabones;
		PointF basePos;

		cadenaCinematica(float x, float y) {
			this->basePos = PointF(x, y);
			eslabones = gcnew List<eslabon^>();
		}

		void agregarEslabon(float longitud, float angulo) {
			eslabones->Add(gcnew eslabon(longitud, angulo));
		}

		void actualizar() {
			PointF origenActual = basePos;
			for each (eslabon ^ e in eslabones) {
				e->actualizar(origenActual);
				origenActual = e->extremo;
			}
		}
	};
}