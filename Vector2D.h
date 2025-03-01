#pragma once
#include <iostream>

template <typename T>
struct Vector2D {
    T X, Y;

    Vector2D() {
        this->X;
        this->Y;
    }

    Vector2D(T x, T y) {
        this->X = x;
        this->Y = y;
    }

    //addition v1+v2
    inline Vector2D<T> operator+(const Vector2D<T>& v2) const {
        return Vect2D<T>(X + v2.x, Y + v2.y )
    }

	//addition v1+=v2
	inline friend Vector2D<T>& operator+=(Vector2D<T>& v1, const Vector2D<T>& v2) {
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	//subtraction v1-v2
	inline Vector2D<T> operator-(const Vector2D<T>& v2) const {
		return Vect2D<T>(X - v2.x, Y - v2.y);
	}

	//subtraction v1-=v2
	inline friend Vector2D<T>& operator-=(Vector2D<T>& v1, const Vector2D<T>& v2) {
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	//multiplication v1*f
	inline Vector2D<T> operator*(const T scalar) const {
		return Vect2D<T>(X * scalar, Y * scalar);
	}

	//division v1/f
	inline Vector2D<T> operator/(const T d) const {
		return (d != 0) ? Vect2D<T>(X / d, Y / d) : Vect2D<T>();
	}

	inline Vector2D<T>& zero() {
		this->X = 0;
		this->Y = 0;
		return *this;
	}

	inline Vector2D<T>& ones() {
		this->X = 1;
		this->Y = 1;
		return *this;
	}

	inline friend std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& v) {
		stream << "(" << v.X << ", " << v.Y << ")";
		return stream;
	}
};

using Vector2Df = Vector2D<float>;
using Vector2Di = Vector2D<int>;
using Vector2Du = Vector2D<unsigned int>;
using Vector2Dd = Vector2D<double>;

//class Vector2D {
//public:
//    float X, Y;
//
//public:
//    Vector2D(float x=0, float y=0) : X(x), Y(y) {}
//public:
//    //addition +
//    inline Vector2D operator+(const Vector2D& v2) const {
//        return Vector2D(X + v2.X, Y + v2.Y);
//    }
//
//    //difference -
//    inline Vector2D operator-(const Vector2D& v2) const {
//        return Vector2D(X - v2.X, Y - v2.Y);
//    }
//
//    //multiplication *
//    inline Vector2D operator*(const float scalar) const {
//        return Vector2D(X * scalar, Y * scalar);
//    }
//
//    void Log(std::string msg = "") {
//        std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
//    }
//
//};