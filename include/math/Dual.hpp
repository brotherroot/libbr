#pragma once
/** @file
 *  @author brotherroot1993@gmail.com
 *  include/math/Dual.hpp
 *  @since 2013/05/22
 */

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>

namespace BR {
using namespace std;
/**
 *  @brief dual number type
 *  @ingroup math
 *  @param  Tp  type of element
 *  
 *  In linear algebra, the dual number extend the real numbers by adjoining one new element e
 *  with the property e^2 = 0. See more detail at http://en.wikipedia.org/wiki/Dual_number
 */
template<class Tp>
struct Dual
{
	typedef Tp value_type;

	value_type real, imag;

	constexpr Dual(void) : real(), imag() { }

	template<class Up, class =
		typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr Dual(Dual<Up> const & source) : real(source.real), imag(source.imag) { }

	template<class Up, class Vp, class =
		typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr Dual(Up const & r, Vp const & i) : real(r), imag(i) { }

	// Dual & real(value_type const & r) {
	// 	real = r;
	// 	return *this;
	// }

	// Dual & imag(value_type const & i) {
	// 	imag = i;
	// 	return *this;
	// }

	// constexpr value_type const & real(void) const { return real; }

	// constexpr value_type const & imag(void) const { return imag; }

	// constexpr value_type & real(void) { return real; }

	// constexpr value_type & imag(void) { return imag; }

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & assign(Dual<Up> const & source) {
		real = source.real;
		imag = source.imag;
		return *this;
	}

	template<class Up, class Vp, class
		= typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	Dual & assign(Up const & r, Vp const & i) {
		real = r;
		imag = i;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & assign(Up const & r) {
		real = r;
		imag = Tp();
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual add(Dual<Up> const & rhs) const {
		return Dual(real + rhs.real, imag + rhs.imag);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual add(Up const & rhs) const {
		return Dual(real + rhs, imag);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual sub(Dual<Up> const & rhs) const {
		return Dual(real - rhs.real, imag - rhs.imag);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual sub(Up const & rhs) const {
		return Dual(real - rhs, imag);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual mul(Dual<Up> const & rhs) const {
		return Dual(real * rhs.real, real*rhs.imag + imag*rhs.real);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual mul(Up const & rhs) const {
		return Dual(real * rhs, imag * rhs);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual div(Dual<Up> const & rhs) const {
		return Dual(real / rhs.real, (imag*rhs.real - real*rhs.imag) / (rhs.real * rhs.real));
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual div(Up const & rhs) const {
		return Dual(real / rhs, imag / rhs);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_add(Dual<Up> const & rhs) {
		real += rhs.real;
		imag += rhs.imag;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_add(Up const & rhs) {
		real += rhs;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_sub(Dual<Up> const & rhs) {
		real -= rhs.real;
		imag -= rhs.imag;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_sub(Up const & rhs) {
		real -= rhs;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_mul(Dual<Up> const & rhs) {
		imag = real*rhs.imag + imag*rhs.real;
		real *= rhs.real;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_mul(Up const & rhs) {
		real *= rhs;
		imag *= rhs;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_div(Dual<Up> const & rhs) {
		imag = (imag*rhs.real - real*rhs.imag) /  (rhs.real * rhs.real);
		real /= rhs.real;
		return *this;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	Dual & self_div(Up const & rhs) {
		real /= rhs;
		imag /= rhs;
		return *this;
	}
	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr bool eql(Dual<Up> const & rhs) const {
		return real == rhs.real && imag == rhs.imag;
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr bool neq(Dual<Up> const & rhs) const {
		return real != rhs.real || imag != rhs.imag;
	}

	template<class Up, class Vp, class
		= typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr bool eql(Up const & r, Vp const & i) const {
		return real == r && imag == i;
	}

	template<class Up, class Vp, class
		= typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr bool neq(Up const & r, Vp const & i) const {
		return real != r || imag != i;
	}

	constexpr Dual pos(void) const {
		return Dual(real, imag);
	}

	constexpr Dual neg(void) const {
		return Dual(-real, -imag);
	}

	constexpr Dual conj(void) const {
		return Dual(real, -imag);
	}

	constexpr value_type abs(void) const {
		return abs(real);
	}

	constexpr value_type arg(void) const {
		return imag / real;
	}

	constexpr value_type norm(void) const {
		return real * real;
	}

	template<class Up, class Vp, class
		= typename enable_if<is_convertible<Up, Tp>::value && is_convertible<Vp, Tp>::value>::type>
	constexpr static Dual polar(Up const & rho, Vp const & theta) {
		return Dual(rho, rho*theta);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr inline Dual & operator=(Dual<Up> const & source) {
		return assign(source);
	}

	template<class Up, class
		= typename enable_if<is_convertible<Up, Tp>::value>::type>
	constexpr inline Dual & operator=(Up const & source) {
		return assign(source);
	}
};

template<class Tp, class Up>
constexpr inline Dual<Tp> operator+(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return lhs.add(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator-(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return lhs.sub(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator*(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return lhs.mul(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator/(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return lhs.div(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator+(Dual<Tp> const lhs, Up const & rhs) {
	return lhs.add(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator-(Dual<Tp> const lhs, Up const & rhs) {
	return lhs.sub(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator*(Dual<Tp> const lhs, Up const & rhs) {
	return lhs.mul(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> operator/(Dual<Tp> const lhs, Up const & rhs) {
	return lhs.div(rhs);
}


template<class Tp,class Up>
constexpr inline Dual<Tp> operator+(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.add(lhs);
}

template<class Tp,class Up>
constexpr inline Dual<Tp> operator-(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.sub(lhs);
}

template<class Tp,class Up>
constexpr inline Dual<Tp> operator*(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.mul(lhs);
}

template<class Tp,class Up>
constexpr inline Dual<Tp> operator/(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.div(lhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> & operator+=(Dual<Tp> & lhs, Dual<Up> const & rhs) {
	return lhs.self_add(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> & operator-=(Dual<Tp> & lhs, Dual<Up> const & rhs) {
	return lhs.self_sub(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> & operator*=(Dual<Tp> & lhs, Dual<Up> const & rhs) {
	return lhs.self_mul(rhs);
}

template<class Tp, class Up>
constexpr inline Dual<Tp> & operator/=(Dual<Tp> & lhs, Dual<Up> const & rhs) {
	return lhs.self_div(rhs);
}

template<class Tp, class Up>
constexpr Dual<Tp> & operator+=(Dual<Tp> & lhs, Up const & rhs) {
	return lhs.self_add(rhs);
}

template<class Tp, class Up>
constexpr Dual<Tp> & operator-=(Dual<Tp> & lhs, Up const & rhs) {
	return lhs.self_sub(rhs);
}

template<class Tp, class Up>
constexpr Dual<Tp> & operator*=(Dual<Tp> & lhs, Up const & rhs) {
	return lhs.self_mul(rhs);
}

template<class Tp, class Up>
constexpr Dual<Tp> & operator/=(Dual<Tp> & lhs, Up const & rhs) {
	return lhs.self_div(rhs);
}

template<class Tp, class Up>
constexpr inline bool operator==(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return eql(rhs);
}

template<class Tp, class Up>
constexpr inline bool operator!=(Dual<Tp> const & lhs, Dual<Up> const & rhs) {
	return neq(rhs);
}

template<class Tp, class Up>
constexpr inline bool operator==(Dual<Tp> const & lhs, Up const & rhs) {
	return lhs.eql(rhs);
}
template<class Tp, class Up>
constexpr inline bool operator!=(Dual<Tp> const & lhs, Up const & rhs) {
	return lhs.neq(rhs);
}


template<class Tp, class Up>
constexpr inline bool operator==(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.eql(lhs);
}

template<class Tp, class Up>
constexpr inline bool operator!=(Tp const & lhs, Dual<Up> const & rhs) {
	return rhs.neq(lhs);
}

template<class Tp>
constexpr Dual<Tp> operator+(Dual<Tp> const & z) {
	return z.pos();
}

template<class Tp>
constexpr Dual<Tp> operator-(Dual<Tp> const & z) {
	return z.neg();
}

template<class Tp>
constexpr Dual<Tp> operator~(Dual<Tp> const & z) {
	return z.conj();
}

template<class Tp>
constexpr inline Tp real(Dual<Tp> const & z) {
	return z.real;
}

template<class Tp>
constexpr inline Tp imag(Dual<Tp> const & z) {
	return z.imag;
}

template<class Tp>
constexpr inline Tp abs(Dual<Tp> const & z) {
	return z.abs();
}

template<class Tp>
constexpr inline Tp arg(Dual<Tp> const & z) {
	return z.arg();
}

template<class Tp>
constexpr inline Tp norm(Dual<Tp> const & z) {
	return z.norm();
}

template<class Tp>
constexpr inline Dual<Tp> conj(Dual<Tp> const & z) {
	return z.conj();
}

template<class Tp, class Up>
constexpr inline Dual<Tp> polar(Tp const & rho, Up const & theta) {
	return Dual<Tp>::polar(rho, theta);
}

template<class Tp>
constexpr inline Dual<Tp> sin(Dual<Tp> const & z) {
	return Dual<Tp>(std::sin(z.real), z.imag * std::cos(z.real));
}

template<class Tp>
constexpr inline Dual<Tp> cos(Dual<Tp> const & z) {
	return Dual<Tp>(std::cos(z.real), -z.imag * std::sin(z.real));
}

template<class Tp>
inline Dual<Tp> tan(Dual<Tp> const & z) {
	Tp res_cos = std::cos(z.real);
	return Dual<Tp>(std::tan(z.real), z.imag / (res_cos * res_cos));
}

template<class Tp>
constexpr inline Dual<Tp> asin(Dual<Tp> const & z) {
	return Dual<Tp>(std::asin(z.real), z.imag / std::sqrt(1 - z.real * z.real));
}

template<class Tp>
constexpr inline Dual<Tp> acos(Dual<Tp> const & z) {
	return Dual<Tp>(std::acos(z.real), -z.imag / std::sqrt(1 - z.real * z.real));
}

template<class Tp>
constexpr inline Dual<Tp> atan(Dual<Tp> const & z) {
	return Dual<Tp>(std::atan(z.real), z.imag / (1 + z.real * z.real));
}

template<class Tp>
constexpr inline Dual<Tp> sinh(Dual<Tp> const & z) {
	return Dual<Tp>(std::sinh(z.real), z.imag * std::cosh(z.real));
}

template<class Tp>
constexpr inline Dual<Tp> cosh(Dual<Tp> const & z) {
	return Dual<Tp>(std::cosh(z.real), z.imag * std::sinh(z.real));
}

template<class Tp>
inline Dual<Tp> tanh(Dual<Tp> const & z) {
	Tp res_cosh = std::cosh(z.real);
	return Dual<Tp>(std::tanh(z.real), z.imag / (res_cosh * res_cosh));
}

template<class Tp>
constexpr inline Dual<Tp> asinh(Dual<Tp> const & z) {
	return Dual<Tp>(std::asinh(z.real), z.imag / std::sqrt(z.real * z.real + 1));
}

template<class Tp>
constexpr inline Dual<Tp> acosh(Dual<Tp> const & z) {
	return Dual<Tp>(std::acosh(z.real), z.imag / std::sqrt(z.real * z.real - 1));
}

template<class Tp>
constexpr inline Dual<Tp> atanh(Dual<Tp> const & z) {
	return Dual<Tp>(std::atanh(z.real), z.imag / (1 - z.real * z.real));
}

template<class Tp>
inline Dual<Tp> exp(Dual<Tp> const & z) {
	Tp res_exp = std::exp(z.real);
	return Dual<Tp>(res_exp,  z.imag * res_exp);
}

template<class Tp>
constexpr inline Dual<Tp> log(Dual<Tp> const & z) {
	return Dual<Tp>(std::log(z.real),  z.imag / z.real);
}

template<class Tp>
inline Dual<Tp> log10(Dual<Tp> const & z) {
	static Tp const VAL_LOG10 = std::log(Tp(10));
	return Dual<Tp>(std::log10(z.real), z.imag / (z.real * VAL_LOG10));
}

template<class Tp, class Up>
constexpr inline Dual<Tp> pow(Dual<Tp> const & z, Up k) {
	Tp res_pow = std::pow(z.real, k-1);
	return Dual<Tp>(z.real * res_pow, k * z.imag * res_pow);
}

template<class Tp>
inline Dual<Tp> sqrt(Dual<Tp> const & z) {
	static Tp const VAL_TWO = 2;
	Tp res_sqrt = std::sqrt(z.real);
	return Dual<Tp>(res_sqrt, z.imag / (res_sqrt * VAL_TWO));
}

template<class Tp>
inline Dual<Tp> cbrt(Dual<Tp> const & z) {
	static Tp const VAL_THREE = 3;
	Tp res_cbrt = std::cbrt(z.real);
	return Dual<Tp>(res_cbrt, z.imag / (res_cbrt * res_cbrt * VAL_THREE));
}

template<class value_type, class char_type, class char_traits>
basic_istream<char_type, char_traits> & operator>>(
	basic_istream<char_type, char_traits> & istr,
	Dual<value_type> & z)
{
	value_type zr, zi;
	char_type ch;
	istr >> ch;
	if (ch == '(') {
		istr >> zr >> ch;
		if (ch == ',') {
			istr >> zi >> ch;
			if (ch == ')') {
				z.assign(zr, zi);
			} else {
				istr.setstate(std::ios_base::failbit);
			}
		} else if (ch == ')') {
			z.assign(zr);
		} else {
			istr.setstate(std::ios_base::failbit);
		}
	} else {
		istr >> zr;
		z.assign(zr);
	}
	return istr;
}

template<class value_type, class char_type, class char_traits>
basic_ostream<char_type, char_traits>& operator<<(
	basic_ostream<char_type, char_traits> & ostr,
	Dual<value_type> const & rhs)
{
	basic_ostringstream<char_type, char_traits> osstr;
	osstr.flags(ostr.flags());
	osstr.imbue(ostr.getloc());
	osstr.precision(ostr.precision());
	osstr << '(' << rhs.real << ',' << rhs.imag << ')';
	return ostr << osstr.str();
}

}
