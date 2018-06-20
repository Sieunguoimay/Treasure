#ifndef VEC2_H
#define VEC2_H
#include<math.h>
#include<iostream>
#include<limits>
const float  MaxDouble = (std::numeric_limits<float>::max)();
const float  MinDouble = (std::numeric_limits<float>::min)();
class Rectangle{
public:
	float x, y;
	float w, h;
	Rectangle(float x, float y, float w, float h)
		:x(x),y(y),w(w),h(h)
	{}
	bool intersects(Rectangle other){
		if(this->x+this->w<other.x)
			return false;
		if(this->x>other.x+other.w)
			return false;
		if(this->y+this->h<other.y)
			return false;
		if(this->y<other.y+other.h)
			return false;
		return true;
	}
	
};
class Size{
public:
	float w, h;
	Size(float w = 0, float h = 0):w(w),h(h){}
	void set(float w, float h){
		this->w = w;
		this->h = h;
	}
};
class vec2{
	enum {clockwise = 1, anticlockwise = -1};
public:
	float x, y;
	vec2(float x = 0.0, float y = 0.0);
	vec2(const vec2&v);
	float dot(const vec2&v)const;
	float cross(const vec2&v)const;
	float length();
	float lengthSq();
	vec2& normalize();
	void set(float x,float y);
	void set(vec2 v);
	void limit(float a);
	int sign(const vec2&v);
	void zero();
	bool isZero();
	vec2 perp();

	vec2 operator+(const vec2&v)const;
	vec2 operator-(const vec2&v)const;
	vec2 operator*(float a)const;
	vec2 operator/(float a)const;
	vec2 operator+=(const vec2&v);
	vec2 operator-=(const vec2&v);
	vec2 operator*=(float a);
	vec2 operator/=(float a);

	bool operator==(const vec2&v);
	bool operator!=(const vec2&v);
	friend std::ostream&operator<<(std::ostream&os, const vec2&v);
};
inline vec2 vec2Normalize(const vec2&v){
	vec2 vec = v;
	float vec_length = vec.length();
	if(vec_length>std::numeric_limits<float>::epsilon()){
		vec.x/=vec_length;
		vec.y/=vec_length;
	}
	return vec;
}
inline vec2 operator*(const vec2&lhs, float rhs){
	vec2 result(lhs);
	result*=rhs;
	return result;
}
inline vec2 operator*(float rhs,const vec2&lhs){
	vec2 result(lhs);
	result*=rhs;
	return result;
}
inline float vec2Distance(const vec2&v1, const vec2&v2){
	float xSeperation = v2.x-v1.x;
	float ySeperation = v2.y-v1.y;
	return sqrt(ySeperation*ySeperation+xSeperation*xSeperation);
}
inline float vec2DistanceSq(const vec2&v1, const vec2&v2){
	float xSeperation = v2.x-v1.x;
	float ySeperation = v2.y-v1.y;
	return (ySeperation*ySeperation+xSeperation*xSeperation);

}
#endif//VEC2_H