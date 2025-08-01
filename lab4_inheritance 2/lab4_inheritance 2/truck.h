/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 * @modified in Spring 2025 by Anna LaValle and Elmeri Uotila
 */

#ifndef TRUCK_H_
#define TRUCK_H_

#include <vector>

#include "circle.h"
#include "drawable.h"
#include "rectangle.h"
#include "vector2.h"

class Truck : public Drawable
{
	private:
		Vector2 center_;
		std::vector<Circle> wheels;
		Rectangle trailer;
		Rectangle cabin;
		Rectangle window;
		Rectangle engine;

		void copy(const Truck& other);
		void clear();
	public:
		Truck(const Vector2& center);
		Truck(const Truck& other);
		~Truck();
		Truck& operator=(const Truck& rhs);
		Vector2 center() const;
		void set_center(const Vector2& center);
};

#endif  // TRUCK_H_
