#pragma once
/** @file
 * include/math/Vector2D.hpp
 * @since 2013/05/21
 */
#include <stdexcept>
#include <cmath>
#include <ios>
#include <sstream>
#include <type_traits>
#include <functional>

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

	value_type x, y;

	constexpr Vector2D(void) : x(), y() { }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D(Vector2D<Up> const & source) : x(source.x), y(source.y) { }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr Vector2D(Up const & xx, Vp const & yy) : x(xx), y(yy) { }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & assign(Vector2D<Up> const & source) {
		x = source.x;
		y = source.y;
		return *this;
	}

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	Vector2D & assign(Up const & xx, Vp const & yy) {
		x = xx;
		y = yy;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & assign(Up const & xx) {
		x = xx;
		y = Tp();
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D add(Vector2D<Up> const & rhs) const { return Vector2D(x + rhs.x, y + rhs.y); }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D add(Up const & rhs) const { return Vector2D(x + rhs, y); }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr Vector2D add(Up const & rhsx, Vp const & rhsy) const {
		return Vector2D(x + rhsx, y + rhsy);
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D sub(Vector2D<Up> const & rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
	
	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D sub(Up const & rhs) const { return Vector2D(x - rhs, y); }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr Vector2D sub(Up const & rhsx, Vp const & rhsy) const {
		return Vector2D(x - rhsx, y - rhsy);
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D mul(Up const & rhs) const { return Vector2D(x * rhs, y * rhs); }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D div(Up const & rhs) const { return Vector2D(x / rhs, y / rhs); }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_add(Vector2D<Up> const & rhs) const {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_add(Up const & rhs) const {
		x += rhs;
		return *this;
	}

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	Vector2D & self_add(Up const & rhsx, Vp const & rhsy) const {
		x += rhsx;
		y += rhsy;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_sub(Vector2D<Up> const & rhs) const {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_sub(Up const & rhs) const {
		x -= rhs;
		return *this;
	}

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	Vector2D & self_sub(Up const & rhsx, Vp const & rhsy) const {
		x -= rhsx;
		y -= rhsy;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_mul(Up const & rhs) const {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	Vector2D & self_div(Up const & rhs) const {
		x /= rhs;
		y /= rhs;
		return *this;
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr value_type inner_product(Vector2D<Up> const & rhs) const { return x * rhs.x + y * rhs.y; }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr value_type dot_product(Vector2D<Up> const & rhs) const { return inner_product(rhs); }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr value_type outer_product(Vector2D<Up> const & rhs) const { return x * rhs.y - y * rhs.x; }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr value_type cross_product(Vector2D<Up> const & rhs) const { return outer_product(rhs); }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr bool eql(Vector2D<Up> const & rhs) const { return x == rhs.x && y == rhs.y; }

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr bool neq(Vector2D<Up> const & rhs) const { return x != rhs.x || y != rhs.y; }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr bool eql(Up const & rhsx, Vp const & rhsy) const { return x == rhsx && y == rhsy; }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr bool neq(Up const & rhsx, Vp const & rhsy) const { return x != rhsx || y != rhsy; }


	constexpr value_type magnitude_sqr() const { return x * x + y * y; }

	constexpr value_type norm_sqr() const { return magnitude_sqr(); }

	constexpr value_type length_sqr() const { return magnitude_sqr(); }

	constexpr value_type magnitude() const { return sqrt(magnitude()); }

	constexpr value_type norm() const { return magnitude(); }

	constexpr value_type length() const { return magnitude(); }

	Vector2D & unitize() {
		value_type len = magnitude();
		x /= len;
		y /= len;
		return *this;
	}

	constexpr Vector2D & normalize() { return unitize(); }

	Vector2D unit() const { 
		value_type len = magnitude();
		return Vector2D(x / len, y / len);
	}

	constexpr value_type arg() const { return atan2(y, x); }

	constexpr value_type tan_arg() const { return y / x; }

	template<class Up, class Vp,
		class = typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr Vector2D & rotate(Up const & val_sin, Vp const & val_cos) {
		return assign(x * val_cos - y * val_sin, x * val_sin + y * val_cos);
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Vector2D & rotate(Up const & angle) { return rotate(sin(angle), cos(angle)); }


	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr inline Vector2D & operator=(Vector2D<Up> const & source) {
		return assign(source);
	}

	template<class Up,
		class = typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr inline Vector2D & operator=(Up const & source) {
		return assign(source);
	}

	constexpr inline Vector2D<Tp> operator+(Vector2D<Tp> const & lhs) const {
		return lhs;
	}

	constexpr inline Vector2D<Tp> operator-(Vector2D<Tp> const & lhs) const {
		return Vector2D(-lhs.x, -lhs.y);
	}
};

template<class Tp, class Up, class Vp>
constexpr inline Vector2D<Tp> rotate(Vector2D<Tp> const & vec, Up const & sin_val, Vp const & cos_val) {
	return vec.rotate(sin_val, cos_val);
}


template<class Tp, class Up>
constexpr inline Vector2D<Tp> rotate(Vector2D<Tp> const & vec, Up const & angle) {
	return vec.rotate(angle);
}

template<class Tp, class Up>
constexpr inline Tp cos_angle(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return lhs.inner_prod(rhs) / sqrt(lhs.magnitude() * rhs.magnitude());
}

template<class Tp, class Up>
constexpr inline Tp angle(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return acos(cos_angle(lhs, rhs));
}
	
template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator+(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return lhs.add(rhs);
}
	
template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator-(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return lhs.sub(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator+(Vector2D<Tp> const & lhs, Up const & rhs) {
	return lhs.add(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator-(Vector2D<Tp> const & lhs, Up const & rhs) {
	return lhs.sub(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator*(Vector2D<Tp> const & lhs, Up const & rhs) {
	return lhs.mul(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator/(Vector2D<Tp> const & lhs, Up const & rhs) {
	return lhs.div(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator+(Tp const & lhs, Vector2D<Up> const & rhs) {
	return rhs.add(lhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator-(Tp const & lhs, Vector2D<Up> const & rhs) {
	return rhs.sub(lhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> operator*(Tp const & lhs, Vector2D<Up> const & rhs) {
	return rhs.mul(lhs);
}
	
template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator+=(Vector2D<Tp> & lhs, Vector2D<Up> const & rhs) {
	return lhs.self_add(rhs);
}
	
template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator-=(Vector2D<Tp> & lhs, Vector2D<Up> const & rhs) {
	return lhs.self_sub(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator+=(Vector2D<Tp> & lhs, Up const & rhs)  {
	return lhs.self_add(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator-=(Vector2D<Tp> & lhs, Up const & rhs)  {
	return lhs.self_sub(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator*=(Vector2D<Tp> & lhs, Up const & rhs)  {
	return lhs.self_mul(rhs);
}

template<class Tp, class Up>
constexpr inline Vector2D<Tp> & operator/=(Vector2D<Tp> & lhs, Up const & rhs)  {
	return lhs.self_div(rhs);
}

template<class Tp, class Up>
constexpr inline bool operator==(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

template<class Tp, class Up>
constexpr inline bool operator!=(Vector2D<Tp> const & lhs, Vector2D<Up> const & rhs) {
	return lhs.x != rhs.x || lhs.y != rhs.y;
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
