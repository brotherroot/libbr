/*
 * @file  include/math/Dual.hpp
 */
#pragma once

#include <config.hpp>

#include <cmath>
#include <ios>
#include <sstream>

namespace BR {
/**
 *  @brief ¶ÔÅ¼Êý
 *  @ingroup math
 *  @param  Tp  type of element
 *  
 *  In linear algebra, the dual number extend the real numbers 
 *  by adjoining one new element e with the property e^2 = 0.
 *  See more detail at http://en.wikipedia.org/wiki/Dual_number
 */
template< class Tp >
struct Dual {
public:
	BR_VALTYPE_SERIES( Tp )
	BR_SELFTYPE_SERIES( Dual<ValType> )

	typedef ValType value_type;

	ValType real, imag;

	BR_CONSTEXPR Dual( void ) : real(), imag() { }

	template< class Up >
	BR_CONSTEXPR explicit Dual( Dual<Up> const & src )
		: real( src.real ), imag( src.imag ) { }

	template< class Up >
	BR_CONSTEXPR Dual( Up const & r)
		: real( r ), imag( ) { }

	template< class Up, class Vp >
	BR_CONSTEXPR Dual( Up const & r, Vp const & i )
		: real( r ), imag( i ) { }

	template< class Up >
	SelfRefType assign( Dual< Up > const & src ) {
		real = src.real;
		imag = src.imag;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType assign( Up const & r, Vp const & i ) {
		real = r;
		imag = i;
		return *this;
	}

	template< class Up >
	SelfRefType assign( Up const & r ) {
		real = r;
		imag = ValType( );
		return *this;
	}

	template< class Up >
	SelfType add( Dual< Up > const & rhs ) const {
		return SelfType( real + rhs.real, imag + rhs.imag );
	}

	template< class Up, class Vp >
	SelfType add( Up const & rhsr, Vp const & rhsi ) const {
		return SelfType( real + rhsr, imag + rhsi );
	}

	template< class Up >
	SelfType add( Up const & rhs ) const {
		return SelfType( real + rhs, imag );
	}

	template< class Up >
	SelfType sub( Dual< Up > const & rhs ) const {
		return SelfType( real - rhs.real, imag - rhs.imag );
	}

	template< class Up, class Vp >
	SelfType sub( Up const & rhsr, Vp const & rhsi ) const {
		return SelfType( real - rhsr, imag - rhsi );
	}

	template< class Up >
	SelfType sub( Up const & rhs ) const {
		return SelfType( real - rhs, imag );
	}

	template< class Up >
	SelfType mul( Dual< Up > const & rhs ) const {
		return SelfType( real * rhs.real, real*rhs.imag + imag*rhs.real );
	}

	template< class Up >
	SelfType mul( Up const & rhs ) const {
		return SelfType( real * rhs, imag * rhs );
	}

	template< class Up >
	SelfType div( Dual< Up > const & rhs ) const {
		return SelfType( real / rhs.real, ( imag*rhs.real - real*rhs.imag ) / ( rhs.real * rhs.real ) );
	}

	template< class Up >
	SelfType div( Up const & rhs ) const {
		return SelfType( real / rhs, imag / rhs );
	}

	template< class Up >
	SelfRefType add_assign( Dual< Up > const & rhs ) {
		real += rhs.real;
		imag += rhs.imag;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType add_assign( Up const & rhsr, Vp const & rhsi ) {
		real += rhsr;
		imag += rhsi;
		return *this;
	}

	template< class Up >
	SelfRefType add_assign( Up const & rhs ) {
		real += rhs;
		return *this;
	}

	template< class Up >
	SelfRefType sub_assign( Dual< Up > const & rhs ) {
		real -= rhs.real;
		imag -= rhs.imag;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType sub_assign( Up const & rhsr, Vp const & rhsi ) {
		real -= rhsr;
		imag -= rhsi;
		return *this;
	}

	template< class Up >
	SelfRefType sub_assign( Up const & rhs ) {
		real -= rhs;
		return *this;
	}

	template< class Up >
	SelfRefType mul_assign( Dual< Up > const & rhs ) {
		imag = real*rhs.imag + imag*rhs.real;
		real *= rhs.real;
		return *this;
	}

	template< class Up >
	SelfRefType mul_assign( Up const & rhs ) {
		real *= rhs;
		imag *= rhs;
		return *this;
	}

	template< class Up >
	SelfRefType div_assign( Dual< Up > const & rhs ) {
		imag = ( imag*rhs.real - real*rhs.imag) /  (rhs.real * rhs.real );
		real /= rhs.real;
		return *this;
	}

	template< class Up >
	SelfRefType div_assign( Up const & rhs ) {
		real /= rhs;
		imag /= rhs;
		return *this;
	}
	
	template< class Up >
	BR_CONSTEXPR bool eql( Dual< Up > const & rhs ) const {
		return real == rhs.real && imag == rhs.imag;
	}

	template< class Up >
	BR_CONSTEXPR bool neq( Dual< Up > const & rhs ) const {
		return real != rhs.real || imag != rhs.imag;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR bool eql( Up const & r, Vp const & i ) const {
		return real == r && imag == i;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR bool neq( Up const & r, Vp const & i ) const {
		return real != r || imag != i;
	}

	BR_CONSTEXPR SelfRefType pos( void ) {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType pos( void ) const {
		return *this;
	}

	BR_CONSTEXPR SelfType neg( void ) const {
		return SelfType( -real, -imag );
	}

	BR_CONSTEXPR SelfType conj( void ) const {
		return SelfType( real, -imag );
	}

	BR_CONSTEXPR ValType abs( void ) const {
		return abs( real );
	}

	BR_CONSTEXPR ValType arg( void ) const {
		return imag / real;
	}

	BR_CONSTEXPR ValType norm( void ) const {
		return real * real;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR static SelfType polar( Up const & rho, Vp const & theta ) {
		return SelfType( rho, rho*theta );
	}

	template< class Up >
	BR_CONSTEXPR inline SelfRefType operator=( Dual< Up > const & src ) {
		return assign( src );
	}

	template< class Up >
	BR_CONSTEXPR inline SelfRefType operator=( Up const & src ) {
		return assign( src );
	}
};

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator+(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.add( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator-(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator*(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.mul( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator/(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.div( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator+(
	Dual< Tp > const lhs,
	Up const & rhs
) {
	return lhs.add( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator-(
	Dual< Tp > const lhs,
	Up const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator*(
	Dual< Tp > const lhs,
	Up const & rhs
) {
	return lhs.mul( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > operator/(
	Dual< Tp > const lhs,
	Up const & rhs
) {
	return lhs.div( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Up > operator+(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.add( lhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Up > operator-(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.sub( lhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Up > operator*(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.mul( lhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Up > operator/(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.div( lhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > & operator+=(
	Dual< Tp > & lhs,
	Dual< Up > const & rhs
) {
	return lhs.add_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > & operator-=(
	Dual< Tp > & lhs,
	Dual< Up > const & rhs
) {
	return lhs.sub_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > & operator*=(
	Dual< Tp > & lhs,
	Dual< Up > const & rhs
) {
	return lhs.mul_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > & operator/=(
	Dual< Tp > & lhs,
	Dual< Up > const & rhs
) {
	return lhs.div_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR Dual< Tp > & operator+=(
	Dual< Tp > & lhs,
	Up const & rhs
) {
	return lhs.add_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR Dual< Tp > & operator-=(
	Dual< Tp > & lhs,
	Up const & rhs
) {
	return lhs.sub_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR Dual< Tp > & operator*=(
	Dual< Tp > & lhs,
	Up const & rhs
) {
	return lhs.mul_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR Dual< Tp > & operator/=(
	Dual< Tp > & lhs,
	Up const & rhs
) {
	return lhs.div_assign( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator==(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.eql( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator!=(
	Dual< Tp > const & lhs,
	Dual< Up > const & rhs
) {
	return lhs.neq( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator==(
	Dual< Tp > const & lhs,
	Up const & rhs
) {
	return lhs.eql( rhs );
}
template< class Tp, class Up >
BR_CONSTEXPR inline bool operator!=(
	Dual< Tp > const & lhs,
	Up const & rhs
) {
	return lhs.neq( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator==(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.eql( lhs );
}

template<class Tp, class Up>
BR_CONSTEXPR inline bool operator!=(
	Tp const & lhs,
	Dual< Up > const & rhs
) {
	return rhs.neq( lhs );
}

template< class Tp >
BR_CONSTEXPR Dual< Tp > & operator+( Dual< Tp > & z ) {
	return z;
}

template< class Tp >
BR_CONSTEXPR Dual< Tp > const & operator+( Dual< Tp > const & z ) {
	return z;
}

template< class Tp >
BR_CONSTEXPR Dual< Tp > operator-( Dual< Tp > const & z ) {
	return z.neg();
}

template< class Tp >
BR_CONSTEXPR Dual< Tp > operator~( Dual< Tp > const & z ) {
	return z.conj();
}

template< class Tp >
BR_CONSTEXPR inline Tp real( Dual< Tp > const & z ) {
	return z.real;
}

template< class Tp >
BR_CONSTEXPR inline Tp imag( Dual< Tp > const & z ) {
	return z.imag;
}

template< class Tp >
BR_CONSTEXPR inline Tp abs( Dual< Tp > const & z ) {
	return z.abs();
}

template< class Tp >
BR_CONSTEXPR inline Tp arg( Dual< Tp > const & z ) {
	return z.arg();
}

template< class Tp >
BR_CONSTEXPR inline Tp norm( Dual< Tp > const & z ) {
	return z.norm();
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > conj( Dual< Tp > const & z ) {
	return z.conj();
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > polar( Tp const & rho, Up const & theta ) {
	return Dual<Tp>::polar( rho, theta );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > sin( Dual< Tp > const & z ) {
	return Dual< Tp >( std::sin( z.real ), z.imag * std::cos( z.real ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > cos( Dual< Tp > const & z ) {
	return Dual< Tp >( std::cos( z.real ), -z.imag * std::sin( z.real ) );
}

template< class Tp >
inline Dual< Tp > tan( Dual< Tp > const & z ) {
	Tp res_cos = std::cos( z.real );
	return Dual< Tp >( std::tan( z.real ), z.imag / ( res_cos * res_cos ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual<Tp> asin( Dual< Tp > const & z ) {
	return Dual< Tp >( std::asin( z.real ), z.imag / std::sqrt( 1 - z.real * z.real ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual<Tp> acos( Dual< Tp > const & z ) {
	return Dual< Tp >( std::acos( z.real ), -z.imag / std::sqrt( 1 - z.real * z.real ));
}

template< class Tp >
BR_CONSTEXPR inline Dual<Tp> atan( Dual< Tp > const & z ) {
	return Dual< Tp >( std::atan( z.real ), z.imag / ( 1 + z.real * z.real ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > sinh( Dual< Tp > const & z ) {
	return Dual< Tp >( std::sinh( z.real ), z.imag * std::cosh( z.real ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > cosh( Dual< Tp > const & z ) {
	return Dual< Tp >( std::cosh( z.real ), z.imag * std::sinh( z.real ) );
}

template< class Tp >
inline Dual< Tp > tanh( Dual< Tp > const & z ) {
	Tp res_cosh = std::cosh( z.real );
	return Dual< Tp >( std::tanh( z.real ), z.imag / (res_cosh * res_cosh) );
}

#ifdef USING_STD_CPP11
template< class Tp >
BR_CONSTEXPR inline Dual< Tp > asinh( Dual< Tp > const & z ) {
	return Dual< Tp >( std::asinh( z.real ), z.imag / std::sqrt( z.real * z.real + 1 ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > acosh( Dual< Tp > const & z ) {
	return Dual< Tp >( std::acosh( z.real ), z.imag / std::sqrt( z.real * z.real - 1 ) );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > atanh( Dual< Tp > const & z ) {
	return Dual< Tp >( std::atanh(z.real), z.imag / (1 - z.real * z.real) );
}

template< class Tp >
inline Dual< Tp > cbrt( Dual< Tp > const & z ) {
	static Tp const VAL_THREE = 3;
	Tp res_cbrt = std::cbrt( z.real );
	return Dual< Tp >( res_cbrt, z.imag / ( res_cbrt * res_cbrt * VAL_THREE ) );
}
#endif // USING_STD_CPP11

template< class Tp >
inline Dual< Tp > exp( Dual< Tp > const & z ) {
	Tp res_exp = std::exp( z.real );
	return Dual< Tp >( res_exp,  z.imag * res_exp );
}

template< class Tp >
BR_CONSTEXPR inline Dual< Tp > log( Dual< Tp > const & z ) {
	return Dual< Tp >( std::log( z.real ),  z.imag / z.real );
}

template< class Tp >
inline Dual< Tp > log10( Dual< Tp > const & z ) {
	static Tp const VAL_LOG10 = log( Tp( 10 ) );
	return Dual< Tp >( std::log10( z.real ), z.imag / ( z.real * VAL_LOG10 ) );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Dual< Tp > pow( Dual< Tp > const & z, Up k ) {
	Tp res_pow = std::pow( z.real, k-1 );
	return Dual< Tp >( z.real * res_pow, k * z.imag * res_pow );
}

template< class Tp >
inline Dual< Tp > sqrt( Dual< Tp > const & z ) {
	static Tp const VAL_TWO = 2;
	Tp res_sqrt = std::sqrt(z.real);
	return Dual< Tp >( res_sqrt, z.imag / ( res_sqrt * VAL_TWO ) );
}

template< class ValType, class CharType, class CharTraits >
std::basic_istream< CharType, CharTraits > & operator>>(
	std::basic_istream< CharType, CharTraits > & istr,
	Dual< ValType > & z
) {
	ValType zr, zi;
	CharType ch;
	istr >> ch;
	if ( ch == '(' ) {
		istr >> zr >> ch;
		if ( ch == ',' ) {
			istr >> zi >> ch;
			if ( ch == ')' ) {
				z.assign( zr, zi );
			} else {
				istr.setstate( std::ios_base::failbit );
			}
		} else if ( ch == ')' ) {
			z.assign( zr );
		} else {
			istr.setstate( std::ios_base::failbit );
		}
	} else {
		istr >> zr;
		z.assign( zr );
	}
	return istr;
}

template< class ValType, class CharType, class CharTraits >
std::basic_ostream< CharType, CharTraits >& operator<<(
	std::basic_ostream< CharType, CharTraits > & ostr,
	Dual< ValType > const & rhs
) {
	std::basic_ostringstream< CharType, CharTraits > osstr;
	osstr.flags( ostr.flags() );
	osstr.imbue( ostr.getloc() );
	osstr.precision( ostr.precision() );
	osstr << '(' << rhs.real << ',' << rhs.imag << ')';
	return ostr << osstr.str();
}

}

