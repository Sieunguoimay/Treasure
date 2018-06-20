#include"vec2.h"
vec2::vec2(float x, float y)
:x(x),y(y)
{}
vec2::vec2(const vec2&v)
:x(v.x),y(v.y)
{}

float vec2::dot(const vec2&v)const{
	return (x*v.x+y*v.y);
}
float vec2::cross(const vec2&v)const{
	return (x*v.y - v.x*y);
}
float vec2::length(){
	return sqrt(x*x+y*y);
}
float vec2::lengthSq(){
	return (x*x+y*y);
}
vec2& vec2::normalize(){
	float l = length();
	if(l != 0)
		(*this)/=l;
	return *this;
}
void vec2::set(float x,float y){
	this->x = x;
	this->y = y;
}
void vec2::set(vec2 v){
	this->x = v.x;
	this->y = v.y;
}
void vec2::limit(float max){
	if (this->length() > max){
		normalize();
		*this *= max;
	} 
}
int vec2::sign(const vec2&v){
	if (y*v.x > x*v.y)
	{ 
	return anticlockwise;
	}
	else 
	{
	return clockwise;
	}
}
void vec2::zero(){
	x=0.0;
	y=0.0;
}
bool vec2::isZero(){
	return (x*x + y*y) < MinDouble;
}
vec2 vec2::perp(){
	return vec2(y,-x).normalize();
}

vec2 vec2::operator+(const vec2&v)const{
	return vec2(x+v.x,y+v.y);
}
vec2 vec2::operator-(const vec2&v)const{
	return vec2(x-v.x,y-v.y);
}
vec2 vec2::operator*(float a)const{
	return vec2(x*a, y*a);
}
vec2 vec2::operator/(float a)const{
	if(a==0)
		return vec2();
	return vec2(x/a, y/a);
}
vec2 vec2::operator+=(const vec2&v){
	x+=v.x;
	y+=v.y;
	return (*this);
}
vec2 vec2::operator-=(const vec2&v){
	x-=v.x;
	y-=v.y;
	return (*this);
}
vec2 vec2::operator*=(float a){
	x*=a;
	y*=a;
	return (*this);
}
vec2 vec2::operator/=(float a){
	if(a != 0){
		x/=a;
		y/=a;
	}
	return (*this);

}

bool vec2::operator==(const vec2&v){
	return (x==v.x&&y==v.y);
}
bool vec2::operator!=(const vec2&v){
	return (x!=v.x||y!=v.y);
}
std::ostream&operator<<(std::ostream&os, const vec2&v){
	os<<v.x<<" "<<v.y;
	return os;
}
