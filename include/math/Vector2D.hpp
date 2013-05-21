#pragma once
/** @file
 * include/math/Vector2D.hpp
 * @since 2013/05/21
 */

#include <stdexcept>
#include <cmath>
#include <ios>
#include <sstream>

namespace BR {

using namespace std;
/**
 *  @brief 2D vector type
 *
 *  @ingroup math
 *
 *  @param  Tp  type of element
 */
template<class Tp>
struct Vector2D
{
	typedef Tp value_type;
	typedef Vector2D<value_type> self_type;

	value_type x, y;

	static self_type const ZERO;

	constexpr Vector2D(void) : x(), y() { }

	constexpr Vector2D(self_type const & source) : x(source.x), y(source.y) { }

	constexpr Vector2D(value_type const & xx, value_type const & yy) : x(xx), y(yy) { }

	self_type & assign(self_type const & source)
	{
		x = source.x;
		y = source.y;
		return *this;
	}

	self_type & assign(value_type const & xx, value_type const & yy = Tp())
	{
		x = xx;
		y = yy;
		return *this;
	}

	self_type add(self_type const & rhs) const { return self_type(x + rhs.x, y + rhs.y); }
	self_type sub(self_type const & rhs) const { return self_type(x - rhs.x, y - rhs.y); }

	self_type add(value_type const & rhs) const { return self_type(x + rhs, y); }
	self_type sub(value_type const & rhs) const { return self_type(x - rhs, y); }

	self_type add(value_type const & rhsx, value_type const & rhsy) const { return self_type(x + rhsx, y + rhsy); }
	self_type sub(value_type const & rhsx, value_type const & rhsy) const { return self_type(x - rhsx, y - rhsy); }

	self_type mul(value_type const & rhs) const { return self_type(x * rhs, y * rhs); }
	self_type div(value_type const & rhs) const { return self_type(x / rhs, y / rhs); }

	self_type self_add(self_type const & rhs) const
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	self_type self_sub(value_type const & rhs) const
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	self_type self_add(value_type const & rhs) const
	{
		x += rhs;
		return *this;
	}

	self_type self_sub(self_type const & rhs) const
	{
		x -= rhs;
		return *this;
	}

	self_type self_add(value_type const & rhsx, value_type const & rhsy) const
	{
		x += rhsx;
		y += rhsy;
		return *this;
	}

	self_type self_sub(value_type const & rhsx, value_type const & rhsy) const
	{
		x -= rhsx;
		y -= rhsy;
		return *this;
	}

	self_type self_mul(value_type const & rhs) const
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	self_type self_div(value_type const & rhs) const
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}


	value_type inner_product(self_type const & rhs) const { return x * rhs.x + y * rhs.y; }

	value_type dot_product(self_type const & rhs) const { return inner_product(rhs); }

	value_type outer_product(self_type const & rhs) const { return x * rhs.y - y * rhs.x; }

	value_type cross_product(self_type const & rhs) const { return outer_product(rhs); }

	value_type magnitude_sqr() const { return x * x + y * y; }

	value_type norm_sqr() const { return magnitude_sqr(); }

	value_type length_sqr() const { return magnitude_sqr(); }

	value_type magnitude() const { return sqrt(magnitude()); }

	value_type norm() const { return magnitude(); }

	value_type length() const { return magnitude(); }

	self_type & unitize()
	{
		value_type len = magnitude();
		x /= len;
		y /= len;
		return *this;
	}

	self_type & normalize() { return unitize(); }

	self_type unit() const
	{ 
		value_type len = magnitude();
		return self_type(x / len, y / len);
	}

	value_type arg() const { return atan2(y, x); }

	value_type tan_arg() const { return y / x; }

	self_type & rotate(value_type const & val_sin, value_type const & val_cos)
	{
		return assign(x * val_cos - y * val_sin, x * val_sin + y * val_cos);
	}

	self_type & rotate(value_type const & angle) { return rotate(sin(angle), cos(angle)); }

	
	/*
	 *  operator
	 */
	self_type & operator=(self_type const & source) { return assign(source); }

	self_type & operator=(value_type const & source) { return assign(source); }

	self_type operator+(self_type const & rhs) const { return add(rhs); }
	self_type operator-(self_type const & rhs) const { return sub(rhs); }

	self_type operator+(value_type const & rhs) const { return add(rhs); }
	self_type operator-(value_type const & rhs) const { return sub(rhs); }
	self_type operator*(value_type const & rhs) const { return mul(rhs); }
	self_type operator/(value_type const & rhs) const { return div(rhs); }

	self_type & operator+=(self_type const & rhs) { return self_add(rhs); }
	self_type & operator-=(self_type const & rhs) { return self_sub(rhs); }

	self_type & operator+=(value_type const & rhs)  { return self_add(rhs); }
	self_type & operator-=(value_type const & rhs)  { return self_sub(rhs); }
	self_type & operator*=(value_type const & rhs)  { return self_mul(rhs); }
	self_type & operator/=(value_type const & rhs)  { return self_div(rhs); }

	self_type operator+(void) const { return *this; }

	self_type operator-(void) const
	{
		x = -x;
		y = -y;
		return *this;
	}
};

/*
 *  helper function
 */
template<class value_type>
inline Vector2D<value_type> rotate(Vector2D<value_type> const & vec, value_type const & angle)
{
	return rotate(vec, sin(angle), cos(angle));
}

template<class value_type>
inline Vector2D<value_type> rotate(
	Vector2D<value_type> const & vec,
	value_type const & sin_val,
	value_type const & cos_val)
{
	return Vector2D<value_type>(vec.x * cos_val - vec.y * sin_val, vec.x * sin_val + vec.y * cos_val);
}

template<class value_type>
inline Vector2D<value_type> operator*(value_type const & lhs, Vector2D<value_type> const & rhs)
{
	return rhs*lhs;
}

template<class value_type>
inline value_type cos_angle(Vector2D<value_type> const & lhs, Vector2D<value_type> const & rhs)
{
	return lhs.inner_prod(rhs) / sqrt(lhs.magnitude() * rhs.magnitude());
}

template<class value_type>
inline value_type angle(Vector2D<value_type> const & lhs, Vector2D<value_type> const & rhs)
{
	return acos(cos_angle(lhs, rhs));
}

template<class value_type, class char_type, class char_traits>
basic_istream<char_type, char_traits> & operator>>(
	basic_istream<char_type, char_traits> & istr,
	Vector2D<value_type> & vec)
{
	value_type vecx, vecy;
	char_type ch;
	istr >> ch;
	if (ch == '(') {
		istr >> vecx >> ch;
		if (ch == ',') {
			istr >> vecy >> ch;
			if (ch == ')') {
				vec.assign(vecx, vecy);
			} else {
				istr.setstate(std::ios_base::failbit);
			}
		} else if (ch == ')') {
			vec.assign(vecx);
		} else {
			istr.setstate(std::ios_base::failbit);
		}
	} else {
		istr >> vecx;
		vec.assign(vecx);
	}
	return istr;
}

template<class value_type, class char_type, class char_traits>
basic_ostream<char_type, char_traits>& operator<<(
	basic_ostream<char_type, char_traits> & ostr,
	Vector2D<value_type> const & rhs)
{
	basic_ostringstream<char_type, char_traits> osstr;
	osstr.flags(ostr.flags());
	osstr.imbue(ostr.getloc());
	osstr.precision(ostr.precision());
	osstr << '(' << rhs.x << ',' << rhs.y << ')';
	return ostr << osstr.str();
}

}
