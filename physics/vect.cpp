#include <math.h>

#include "vect.h"

using namespace std;

vect::vect() {

}

vect::vect(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}
vect vect::operator*(float scale) const {
	return vect(x * scale, y * scale, z * scale);
}

vect vect::operator/(float scale) const {
	return vect(x / scale, y / scale, z / scale);
}

vect vect::operator+(const vect &other) const {
	return vect(x + other.x, y + other.y, z + other.z);
}

vect vect::operator-(const vect &other) const {
	return vect(x - other.x, y - other.y, z - other.z);
}

vect vect::operator-() const {
	return vect(-x, -y, -z);
}

const vect &vect::operator*=(float scale) {
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}

const vect &vect::operator/=(float scale) {
	x /= scale;
	y /= scale;
	z /= scale;
	return *this;
}

const vect &vect::operator+=(const vect &other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

const vect &vect::operator-=(const vect &other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

float vect::magnitude() const {
	return sqrt(x * x + y * y + z * z);
}

float vect::magnitudeSquared() const {
	return x * x + y * y + z * z;
}

vect vect::normalize() const {
	float m = sqrt(x * x + y * y + z * z);
	if(m == 0)m = 1; 
	return vect(x / m, y / m, z / m);
}

float vect::dot(const vect &other) const {
	return x * other.x + y * other.y + z * other.z;
}


vect vect::cross(const vect &other) const {
	return vect(y * other.z - z * other.y,
				 z * other.x - x * other.z,
				 x * other.y - y * other.x);
}

vect operator*(float scale, const vect &v) {
	return v * scale;
}

vect vect::project(const vect &other) const {
	return (x * other.x + y * other.y + z * other.z)*other.normalize();
}
