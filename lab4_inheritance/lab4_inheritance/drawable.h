/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 * @modified in Spring 2025 by Anna LaValle and Elmeri Uotila
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "png.h"

/**
 * @brief A pure virtual interface class that can draw itself to a canvas.
 */
class Drawable
{
	public:
	virtual ~Drawable() { /* Nothing */ }

		/**
		 * @brief This method will draw the object onto the canvas.
		 *
		 * @param canvas to draw onto.
		 */
		virtual void draw(PNG& canvas) const = 0;
};

#endif  // DRAWABLE_H_
