#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED

/** this class contains vector operation
as add ,sub, dot product cross product of vectors*/
class vect {
public:

		float x,y,z;/** orthographic component of vector*/
		vect();
		vect(float,float,float);
		
		vect operator*(float scale) const;
		vect operator/(float scale) const;
		vect operator+(const vect &other) const;
		vect operator-(const vect &other) const;
		vect operator-() const;

		const vect &operator*=(float scale);
		const vect &operator/=(float scale);
		const vect &operator+=(const vect &other);
		const vect &operator-=(const vect &other);

		float magnitude() const;
		float magnitudeSquared() const;
		vect normalize() const;
		float dot(const vect &other) const;
		vect cross(const vect &other) const;
		vect project(const vect &other) const;
};

vect operator*(float scale, const vect &v);
#endif
