#pragma once

#include "Vector2D.h"
#include "Component.h"

class Transform : public Component {
public:
    Transform() = default;

    Transform(float x, float y) {
		position.X = x;
		position.Y = y;
    }

    Transform(float x, float y, float xscale, float yscale) {
        position.X = x;
        position.Y = y;
        scale.X = xscale;
        scale.Y = yscale;
    }

    Transform(float x, float y, float xscale, float yscale, float rot) {
        position.X = x;
		position.Y = y;
		scale.X = xscale;
        scale.Y = yscale;
		rotation = rot; 
    }


    virtual ~Transform() = default;

public:
	Vector2D<float> position = Vector2D<float>(0, 0);
	Vector2D<float> scale = Vector2D<float>(1, 1);
	float rotation = 0.0f;

public:
    //inline void TranslateX(float x) { X += x; }
    //inline void TranslateY(float y) { Y += y; }
    //inline void Translate(Vector2D v) { X += v.X; Y += v.Y; }
};